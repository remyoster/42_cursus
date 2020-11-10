const Getter = require("../../utils/Getter");
const Game = require("../../classes/Game");
const Player = require("../../classes/Player");

describe("Getter static method", () => {
    const players = [
        {socketId: 'roster42', name: 'roster'},
        {socketId: 'roster84', name: 'rosterr'},
        {socketId: 'madufour42', name: 'madufour'},
        {socketId: 'madufour84', name: 'madufourr'},
    ];
    let gameSolo = new Game({type: 'solo', room: "test_solo"});
    gameSolo.addPlayer(players[0]);
    let gameMulti_1 = new Game({type: "multi", room: "test_multi_1"});
    gameMulti_1.addPlayer(players[1]);
    let gameMulti_2 = new Game({type: "multi", room: "test_multi_2"});
    gameMulti_2.addPlayer(players[2]);
    gameMulti_2.addPlayer(players[3]);
    let games = [gameSolo, gameMulti_1, gameMulti_2];

    it("listGameAvailable", () => {
        const expected = [gameMulti_1, gameMulti_2].map(e => ({
            name: e.room.name,
            options: e.options,
            leader: e.getLeader().name,
            nbPlayers: e.players.length
        }));
        expect(Getter.listGameAvailable(games)).toEqual(expected);
        expect(Getter.listGameAvailable([gameSolo])).toEqual([]);
    });

    it("findGameWithRoomName", () => {
        const expected = gameMulti_1;
        expect(Getter.findGameWithRoomName(games, "test_multi_1")).toEqual(expected);
    });

    it("findGameWithPlayerName", () => {
        const expected = { findGame: gameMulti_1, indexPlayer: 0 };
        expect(Getter.findGameWithPlayerName(games, "rosterr")).toEqual(expected);
        expect(Getter.findGameWithPlayerName(games, "player_42")).toEqual({
            findGame: null, indexPlayer: -1});
    });

    it("findGameWithSocketId", () => {
        expect(Getter.findGameWithSocketId(games, "roster84")).toEqual(gameMulti_1);
    });

    it("playerIdxWithName", () => {
        expect(Getter.playerIdxWithName(gameMulti_2, "madufour")).toBe(0);
    });
    
    it("playerWhithSocketId", () => {
        const player = new Player(players[3].socketId, players[3].name);
        expect(Getter.playerWhithSocketId(gameMulti_2, "madufour84")).toEqual(player);
        expect(Getter.playerWhithSocketId()).toBeUndefined();
    });

    it("playerIdxWhithSocketId", () => {
        expect(Getter.playerIdxWhithSocketId(gameMulti_2, "madufour42")).toBe(0);
    });

    it('randomId method', () => {
        const name = 'roster';
        expect(Getter.randomId(name)).toEqual(
            expect.stringMatching(/^roster_[a-zA-Z0-9]{5}$/));
    });
});