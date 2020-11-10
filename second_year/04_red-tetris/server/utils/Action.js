const Game = require("../classes/Game");
const Getter = require('./Getter');

class Action {

    /*
    ** Boolean check string has only alphabetical and numerical chars between 
    ** 3 to 20 length and must begin with 3 alpha chars
    */

    static checkName(name) {
        let reg = /^[a-zA-Z]{3,}([0-9]+)?$/;
        if (name.length <= 20 && reg.test(name))
            return (true);
        return (false);
    }

    static createNewGame(games, user, gameData, socket) {
        let newGame = new Game(gameData);
        newGame.addPlayer(user);
        games.push(newGame);
        socket.join(newGame.room.name);
        return (socket.emit("CREATE_GAME_SUCCESS", {
            room: newGame.room.name,
            type: newGame.type,
            players: [{ name: user.name, leader: true }],
            options: newGame.options
        }));
    }

    static requestJoinGame(currentGame, user, socket) {
        currentGame.addPlayer(user);
        socket.join(currentGame.room.name);
        let players = currentGame.players.map(
            e => ({ name: e.name, leader: e.leader }));
        socket.to(currentGame.room.name).emit("UPDATE_PLAYERS_SUCCESS", players);
        return (socket.emit("JOIN_GAME_SUCCESS", {
            room: currentGame.room.name,
            type: currentGame.type,
            players,
            options: currentGame.options
        }));
    }

    static requestChangeOption(games, data) {
        let currentGame = Getter.findGameWithRoomName(games, data.room);
        if (!currentGame)
            return ({ error: "Game doesn't exist. Try again !" });
        currentGame.changeOption(data.option, data.value);
        return (currentGame.options);
    }

    static requestStartGame(currentGame) {
        if (!currentGame.isStartable()) {
            return { error: "Please wait at least one more player" };
        }
        else {
            if (currentGame.isOver) {
                currentGame.restartGame();
            }
            let tetri = currentGame.setIsStart();
            let spectrums = currentGame.players.map(e => {
                return ({ playerName: e.name, spectrum: e.spectrum });
            });
            return ({ currentGame, tetris: tetri, spectrums: spectrums });
        }
    }

    static requestNewPiece(games, data) {
        let currentGame = Getter.findGameWithRoomName(games, data.room);
        let idxPlayer = Getter.playerIdxWithName(currentGame, data.playerName);
        if (idxPlayer === -1 || !currentGame)
            return ({ error: true });
        let idxNextTetri = currentGame.players[idxPlayer].getIndexNextTetri();
        if (idxNextTetri % 99 === 0)
            currentGame.setNewPieces();
        let nextTetri = currentGame.pieces[idxNextTetri];
        if (!nextTetri)
            return ({ error: true });
        return (nextTetri);
    }

    static updatePlayerSpectrum(games, data) {
        let currentGame = Getter.findGameWithRoomName(games, data.room);
        let indexPlayer = Getter.playerIdxWithName(currentGame, data.playerName);
        if (indexPlayer === -1 || indexPlayer === "undefined" || !currentGame)
            return ({ error: "An error occured, please reload your page" });
        let player = currentGame.players[indexPlayer];
        let spectrum = player.updateSpectrum(data.board);
        return ({ playerName: player.name, spectrum: spectrum });
    }

    static setPlayerGameOver(games, socketId) {
        let currentGame = Getter.findGameWithSocketId(games, socketId);
        let indexPlayer = Getter.playerIdxWhithSocketId(currentGame, socketId);
        if (!currentGame || indexPlayer === -1)
            return ({ error: "An error occured, please reload your page" });
        if (currentGame.players[indexPlayer].isOver)
            return ;
        currentGame.players[indexPlayer].setIsOver(true);
        let winner = null;
        if (currentGame.type === "multi") {
            let playerNotOver = currentGame.players.filter(e => e.isOver === false);
            if (playerNotOver.length === 1)
                winner = playerNotOver[0];
            else if (playerNotOver.length === 0)
                winner = currentGame.players[indexPlayer];
        }
        else
            winner = currentGame.players[indexPlayer];
        if (winner && winner.socketId === socketId)
            currentGame.setGameOver();
        return ({ winner, currentGame });
    }

    static updateGameAfterPlayerLeft(nsp, socket, games, currentGame, playerIdx) {
        currentGame.removePlayer(playerIdx);
        socket.leave(currentGame.room.name);
        if (!currentGame.players.length) {
            let gameIdx = games.findIndex(
                e => e.room.name === currentGame.room.name);
            games.splice(gameIdx, 1);
        }
        else if (currentGame.type === 'multi') {//ICI VOIR UPDATE SPECTRUMS AUSSI
            let updatedPlayers = currentGame.players
                .map(e => ({ name: e.name, leader: e.leader }));
            nsp.in(currentGame.room.name)
                .emit("UPDATE_PLAYERS_SUCCESS", updatedPlayers);
            if (currentGame.players.length === 1)
                return (nsp.in(currentGame.room.name)
                    .emit("YOU_WIN"));
        }
    }

    static updateBestScores(marks, currentGame, score, winner) {
        marks[currentGame.type].push({
            pseudo: winner,
            score: score,
            options: currentGame.options
        });
        marks[currentGame.type]
            .sort((a, b) => b.score.points - a.score.points);
        if (marks[currentGame.type].length > 10)
            marks[currentGame.type].splice(10, 1);
    }
}

module.exports = Action;