const Socket = require("../../classes/Socket");
const Piece = require("../../classes/Piece");

// const Server = require("../../classes/Server");
const express = require("express");
const http = require("http");
const PORT = process.env.PORT || 3001;
const ioClient = require('socket.io-client');
const Game = require("../../classes/Game");

const playerLeader = {socketId: 'socketId_1', name: 'player_1'};
const playerJoiner = {socketId: 'socketId_2', name: 'player_2'};
let gameSolo = new Game({type: 'solo', room: 'test_solo'})
gameSolo.addPlayer(playerLeader);
let gameMulti_1 = new Game({type: "multi", room: "test_multi_1"});
gameMulti_1.addPlayer(playerLeader);
let gameMulti_1Bis = new Game({type: "multi", room: "test_multi_1"});
gameMulti_1Bis.addPlayer(playerLeader);
gameMulti_1Bis.addPlayer(playerJoiner);

let app;
let server;
let socketClient;
let socketServer;
let ioServer;

/**
 * Setup WS & HTTP servers
 */
app = express();
server = http.Server(app);
server.listen(PORT);
let playerName = "player";
let room = "room";
require('events').EventEmitter.prototype._maxListeners = 100;

/**
 *  Cleanup WS & HTTP servers
 */
afterAll((done) => {
    server.close();
    done();
});

/**
 * Run before each test
 */
beforeEach((done) => {
    socketClient = ioClient.connect('http://localhost:3001/game');
    socketClient.on('connect', () => {
        done();
    });
});

/**
 * Run after each test
 */
afterEach((done) => {
    // Cleanup
    if (socketClient.connected) {
        socketClient.close();
    }
    socketServer.close();
    done();
});


describe('basic socket.io example', () => {
    socketServer = new Socket(server);
    ioServer = socketServer.listenToEvents();
    socketServer.games = [gameMulti_1, gameSolo];
    socketServer.players = [playerLeader, playerJoiner];
    socketServer.idRoom = 3;
    socketServer.marksSolo = [];
    socketServer.marksMulti = [];
    it("should communicate", () => {
        socketServer.nsp.on('connection', (mySocket) => {
            expect(mySocket).toBeDefined();
        });
    });
    it("test listenEvents", () => {
        expect(ioServer).toEqual("listening");
    });
    it('REQUEST_LIST_GAME', () => {
        socketClient.emit('REQUEST_LIST_GAME');
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_LIST_GAME', (data) => {
                expect(data).toEqual(undefined);
            });
        });
    });
    it('REQUEST_CONNECT', () => {
        socketClient.emit('REQUEST_CONNECT', 'Hello');
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_CONNECT', (data) => {
                expect(data).toEqual('Hello');
            });
        });
    });
    it('REQUEST_NEW_GAME', () => {
        socketClient.emit('REQUEST_NEW_GAME', { type: "solo", playerName, test: true });
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_NEW_GAME', (data) => {
                expect(data).toEqual({ type: "solo", playerName, test: true });
            });
        });
    });
    it('REQUEST_JOIN_GAME', () => {
        socketClient.emit("REQUEST_JOIN_GAME", { idGame: 0, playerName: playerJoiner.name });
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_JOIN_GAME', (data) => {
                expect(data).toEqual({ idGame: 0, playerName: playerJoiner.name });
            });
        });
    });
    it('REQUEST_BEST_GAMES', () => {
        socketClient.emit("REQUEST_BEST_GAMES");
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_BEST_GAMES', (data) => {
                expect(data).toEqual(undefined);
            });
        });
    });
    it('REQUEST_CHANGE_OPTION', () => {
        socketClient.emit("REQUEST_CHANGE_OPTION", { room, option: "ghostMode", value: "false" });
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_CHANGE_OPTION', (data) => {
                expect(data).toEqual({ room, option: "ghostMode", value: "false" });
            });
        });
    });
    it('REQUEST_START_GAME', () => {
        socketClient.emit("REQUEST_START_GAME", { gameType: "solo", room, test: true });
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_START_GAME', (data) => {
                expect(data).toEqual({ gameType: "solo", room, test: true });
            });
        });
    });
    it('REQUEST_LEAVE_ROOM', () => {
        socketClient.emit("REQUEST_LEAVE_ROOM");
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_LEAVE_ROOM', (data) => {
                expect(data).toEqual(undefined);
            });
        });
    });
    it('REQUEST_NEW_PIECE', () => {
        socketClient.emit("REQUEST_NEW_PIECE", { room, playerName });
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_NEW_PIECE', (data) => {
                expect(data).toEqual({ room, playerName });
            });
        });
    });
    it('UPDATE_SPECTRUM', () => {
        socketClient.emit("UPDATE_SPECTRUM", { room, playerName, board: "board", test: true });
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('UPDATE_SPECTRUM', (data) => {
                expect(data).toEqual({ room, playerName, board: "board", test: true });
            });
        });
    });
    it('ADD_PENALTY_LINES', () => {
        socketClient.emit("ADD_PENALTY_LINES", { room, penaltyLines: 2 });
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('ADD_PENALTY_LINES', (data) => {
                expect(data).toEqual({ room, penaltyLines: [1,6] });
            });
        });
    });
    it('REQUEST_CHAT_MESSAGE', () => {
        socketClient.emit("REQUEST_CHAT_MESSAGE", { room, chat: "chat", playerName });
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_CHAT_MESSAGE', (data) => {
                expect(data).toEqual({ room, chat: "chat", playerName });
            });
        });
    });
    it('REQUEST_GAME_OVER', () => {
        socketClient.emit("REQUEST_GAME_OVER", { points: 123, level: 5, score: 345 });
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_GAME_OVER', (data) => {
                expect(data).toEqual({ points: 123, level: 5, score: 345 });
            });
        });
    });
    it('REQUEST_BACK_TO_OPTION', () => {
        socketClient.emit("REQUEST_BACK_TO_OPTION");
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_BACK_TO_OPTION', (data) => {
                expect(data).toEqual(undefined);
            });
        });
    });
    it('REQUEST_RESTART_GAME', () => {
        socketClient.emit("REQUEST_RESTART_GAME");
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_RESTART_GAME', (data) => {
                expect(data).toEqual(undefined);
            });
        });
    });
    it('REQUEST_DISCONNECT', () => {
        socketClient.emit("REQUEST_DISCONNECT");
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_DISCONNECT', (data) => {
                expect(data).toEqual(undefined);
            });
        });
    });
    it('REQUEST_CHECK_RELOAD', () => {
        socketClient.emit("REQUEST_CHECK_RELOAD", playerName);
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('REQUEST_CHECK_RELOAD', (data) => {
                expect(data).toEqual(playerName);
            });
        });
    });
    it('disconnect', () => {
        socketClient.emit("disconnect");
        socketServer.nsp.on('connection', (mySocket) => {
            mySocket.on('disconnect', (data) => {
                expect(data).toEqual(undefined);
            });
        });
    });
    it('close', () => {
        expect(socketServer.close()).toBe(undefined);
    });
});