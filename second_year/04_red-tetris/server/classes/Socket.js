const Action = require("../utils/Action");
const Getter = require('../utils/Getter');
const io = require("socket.io");

class Socket {
    constructor(server) {
        this.nsp = io(server).of("/game");
        this.games = [];
        this.users = [];
        this.marks = { solo: [], multi: [] };
    }

    listenToEvents() {
        this.nsp.on('connection', (socket) => {
            /*
            ** Send the multi games available
            */

            socket.on("REQUEST_LIST_GAME", () => {
                let gamesAvailable = Getter.listGameAvailable(this.games);
                return socket.emit("LIST_GAME_SUCCESS", gamesAvailable);
            });

            /*
            ** Get the name input from connection form (=data), check if there
            ** is already one user connected with this name. If not it creates a
            ** unique ID and push the new user in this.users, else send error if
            ** a user with the same name is connected
            */

            socket.on("REQUEST_CONNECT", (data) => {
                if (Action.checkName(data)) {
                    let takenIdx = this.users.findIndex(e => e.name === data);
                    if (takenIdx !== -1) {
                        if (this.users[takenIdx].disconnected)
                            this.users.splice(takenIdx, 1);
                        else
                            return (this.sendError(socket.id,
                                "This name is already taken."));
                    }
                    let id = Getter.randomId(data);
                    this.users.push({ name: data, socketId: socket.id, id });
                    return (socket.emit("CONNECT_SUCCESS", { name: data, id }));
                }
                return (this.sendError(socket.id,
                    "Only alphanumeric character [a-zA-Z0-9] (3min-20max)"));
            });

            /*
            ** When user create a new solo or multi game. It create the game and
            ** add it to this.games + send back game data
            */

            socket.on("REQUEST_NEW_GAME", (data) => {
                let user = this.users.find(e => e.socketId === socket.id);
                if (!user)
                    return (this.sendError(socket.id));
                return (Action.createNewGame(this.games, user, {type: data}, socket));
            });

            /*
            ** when a user join a multi game, it adds him to the list of the
            ** players and send back game data to him and updatedPlayers to others
            */

            socket.on("REQUEST_JOIN_GAME", (data) => {
                let user = this.users.find(e => e.socketId === socket.id);
                let currentGame = Getter.findGameWithRoomName(this.games, data);
                if (!user || !currentGame
                    || (currentGame && !currentGame.isJoinable()))
                    return (this.sendError(socket.id));
                return (Action.requestJoinGame(currentGame, user, socket));
            });

            /*
            ** Send back best score arrays
            */

            socket.on("REQUEST_BEST_GAMES", () => {
                return (socket.emit("BEST_GAMES_SUCCESS", this.marks));
            });

            /*
            ** Send to everybody in the room the option change
            */

            socket.on("REQUEST_CHANGE_OPTION", (data) => {
                let res = Action.requestChangeOption(this.games, data);
                if (res.error)
                    return (this.sendError(socket.id, res.error));
                return (this.nsp.in(data.room)
                    .emit("CHANGE_OPTION_SUCCESS", res));
            });

            /*
            ** When the game is starting or is replayed it sends back to all 
            ** players their 2 first tetris, the spectrums of players and 
            ** startingLevel of the game
            */

            socket.on("REQUEST_START_GAME", (data) => {
                let currentGame = Getter.findGameWithRoomName(this.games, data);
                if (!currentGame)
                    return (this.sendError(socket.id));
                let res = Action.requestStartGame(currentGame);
                if (res.error)
                    return (this.nsp.in(data.room).emit("ERROR", res.error));
                let spectrums;
                res.currentGame.players.forEach(e => {
                    spectrums = res.spectrums.filter(f => f.playerName !== e.name);
                    this.nsp.to(e.socketId).emit("START_GAME_SUCCESS", {
                        tetris: res.tetris,
                        spectrums: spectrums,
                        board: res.currentGame.players[0].spectrum,
                        startingLevel: res.currentGame.options.startingLevel
                    });
                });
            });

            /*
            ** Toggle the request leave room : quit the game and actualize it 
            ** (or delete it if needed)
            */

            socket.on("REQUEST_LEAVE_ROOM", () => {
                let currentGame = Getter.findGameWithSocketId(this.games, socket.id);
                let playerIdx = Getter.playerIdxWhithSocketId(currentGame, socket.id);
                if (!currentGame || playerIdx === -1)
                    return (this.sendError(socket.id));
                Action.updateGameAfterPlayerLeft(this.nsp, socket, this.games,
                    currentGame, playerIdx);
            });

            /*
            ** Send back the next piece for the player who is asking it
            */

            socket.on("REQUEST_NEW_PIECE", (data) => {
                let res = Action.requestNewPiece(this.games, data);
                if (res && res.error)
                    return (this.nsp.in(data.room)
                        .emit("ERROR", "An error occured, please reload your page"));
                return socket.emit("NEW_PIECE_SUCCESS", res);
            });

            /*
            ** Send to all players !== of the sender the new sender spectrum
            */

            socket.on("UPDATE_SPECTRUM", (data) => {
                let res = Action.updatePlayerSpectrum(this.games, data);
                if (res.error)
                    return (this.nsp.in(data.room).emit('ERROR', res.error));
                return (socket.to(data.room)
                    .emit("UPDATE_SPECTRUM_SUCCESS", res));
            });

            /*
            ** Send to all players !== of the sender the new penalty lines
            */

            socket.on("ADD_PENALTY_LINES", (data) => {
                let penaltyLines = [];
                for (let idx = 0; idx < data.penaltyLines; idx++)
                    penaltyLines.push(Math.floor(Math.random() * Math.floor(10)));
                socket.to(data.room)
                    .emit("ADD_PENALTY_LINES_SUCCESS", penaltyLines);
            });

            /*
            ** Send to everyone in the room the chat content in data
            */

            socket.on("REQUEST_CHAT_MESSAGE", (data) => {
                let date = Date.now();
                this.nsp.in(data.room).emit("CHAT_MESSAGE_SUCCESS", {
                    chat: data.chat, playerName: data.playerName, date
                });
            });

            /*
            ** Whenever a player lost it toggles the game state and if needed
            ** if stops the game with a winner. Bests scores are registred here
            */

            socket.on("REQUEST_GAME_OVER", (data) => {
                let { winner, error, currentGame } = Action
                    .setPlayerGameOver(this.games, socket.id);
                if (error)
                    return (this.sendError(socket.id, error));
                if (winner) {
                    if (currentGame.type === 'solo'
                        || (winner.socketId === socket.id && currentGame.isOver)) {
                        Action.updateBestScores(this.marks, currentGame, data, winner.name);
                        if (currentGame.type === 'multi')
                            this.nsp.in(currentGame.room.name)
                                .emit("WIN_GAME_SUCCESS", {
                                    ...data,
                                    winner: winner.name
                                });
                    }
                    else
                        return (this.nsp.to(winner.socketId).emit("YOU_WIN"));
                }
            });

            /*
            ** When leader wants to go back to options it reset game so the 
            ** options menu will show up
            */

            socket.on("REQUEST_BACK_TO_OPTION", () => {
                let currentGame = Getter.findGameWithSocketId(this.games, socket.id);
                if (!currentGame)
                    return (this.sendError(socket.id));
                return (this.nsp.in(currentGame.room.name).emit("RESET_GAME_SUCCESS"));
            });

            /*
            ** When a user click on the disconnect header button, it deletes him
            ** from this.users and send him back EXIT socket
            */

            socket.on("REQUEST_DISCONNECT", () => {
                let userIdx = this.users.findIndex(e => e.socketId === socket.id);
                if (userIdx === -1)
                    return (this.sendError(socket.id));
                this.users.splice(userIdx, 1);
                return (socket.emit("EXIT"));
            });

            /*
            ** Whenever a socket connect on the serv. If he was connected then
            ** data contained his ID. If he was in a room and room is still
            ** joinable it makes him join the room (or create it).
            */

            socket.on("REQUEST_CHECK_RELOAD", (data) => {
                let userIdx = this.users.findIndex(e => e.id === data);
                if (userIdx === -1)
                    return (socket.emit("EXIT"));
                this.users[userIdx].disconnected = false;
                this.users[userIdx].socketId = socket.id;
                let user = this.users[userIdx];
                if (user.oldGame) {
                    let currentGame = Getter.findGameWithRoomName(this.games, user.oldGame.room);
                    if (currentGame && currentGame.isJoinable()) {
                        Action.requestJoinGame(currentGame, user, socket)
                    }
                    else if (!currentGame) {
                        Action.createNewGame(this.games, user, user.oldGame, socket);
                    }
                    else
                        socket.emit("CONNECT_SUCCESS", { name: user.name, id: user.id })
                    this.users[userIdx].oldGame = null;
                }
                else
                    return (socket.emit("CONNECT_SUCCESS", { name: user.name, id: user.id }));
            });

            /*
            ** Marks the user with boolean disconnected and add his old room in
            ** this.users (for reconnection purpose)
            */

            socket.on('disconnect', () => {
                let userIdx = this.users.findIndex(e => e.socketId === socket.id);
                if (userIdx !== -1) {
                    let currentGame = Getter.findGameWithSocketId(this.games, this.users[userIdx].socketId);
                    if (currentGame) {
                        this.users[userIdx].oldGame = {
                            room: currentGame.room.name,
                            type: currentGame.type,
                            options: currentGame.options
                        };
                        let playerIdx = Getter.playerIdxWhithSocketId(currentGame, socket.id);
                        Action.updateGameAfterPlayerLeft(this.nsp, socket, this.games,
                            currentGame, playerIdx);
                    }
                    this.users[userIdx].disconnected = true;
                }
            });
        });
        return "listening";
    }

    /*
    ** Send back a ERROR socket with default error message if not provided
    */

    sendError(socketId, error="An error occured, please reload your page") {
        this.nsp.to(socketId).emit("ERROR", error);
    }

    close() {
        delete this.nsp['/game'];
    }
}

module.exports = Socket;