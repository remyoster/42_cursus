const Action = require("../../utils/Action");
const Game = require("../../classes/Game");

describe("Action class", () => {
    it('checkName', () => {
        expect(Action.checkName('test')).toBeTruthy();
        expect(Action.checkName('tes fd t')).toBeFalsy();
    });

    it("requestNewGame", () => {
        let testGame = new Game();
        let games = [];
        const gameData = {type: 'solo', room: 'test'};
        const user = {socketId: 'testId', name: 'roster'};
        const socket = {emit: jest.fn(), join: jest.fn()};
        Action.createNewGame(games, user, gameData, socket);
        expect(socket.join.mock.calls.length).toBe(1);
        expect(socket.join).toHaveBeenCalledWith('test');
        expect(socket.emit.mock.calls.length).toBe(1);
        expect(socket.emit).toHaveBeenCalledWith("CREATE_GAME_SUCCESS", {
            ...gameData,
            players: [{name: 'roster', leader: true}],
            options: testGame.options
        });
        expect(games.length).toBe(1);
    });

    const players = [
        {socketId: 'socketId_1', name: 'player1'},
        {socketId: 'socketId_2', name: 'player2'},
        {socketId: 'socketId_3', name: 'player3'},
        {socketId: 'socketId_4', name: 'player4'},
        {socketId: 'socketId_5', name: 'player5'},
    ];

    let gameSolo = new Game({type: 'solo', room: 'test_solo'});
    gameSolo.addPlayer(players[0]);
    let gameSolo_2 = new Game({type: 'solo', room: 'test_solo_2'});
    gameSolo_2.addPlayer(players[1]);
    let gameMulti = new Game({type: 'multi', room: 'test_multi'});
    gameMulti.addPlayer(players[2]);
    let gameMulti_2 = new Game({type: 'multi', room: 'test_multi_2'});
    gameMulti_2.addPlayer(players[3]);
    gameMulti_2.addPlayer(players[4]);

    it("requestChangeOption", () => {
        let games = [gameSolo, gameMulti];
        const expected = {
            ghostMode: false,
            colorMode: 'normal',
            fullSpectrum: false,
            startingLevel: 0,
            dropTimeRef: 1000
        };
        let data = { room: "test_multi", option: "ghostMode", value: false }
        expect(Action.requestChangeOption(games, data)).toEqual(expected);
    });

    it("requestStartGame", () => {
        const expected = Action.requestStartGame(gameSolo_2);
        expect(expected).toHaveProperty('currentGame', gameSolo_2);
    });

    it("requestNewPiece", () => {
        gameSolo.setIsStart()
        let games = [gameSolo, gameMulti];
        let data = { room: "test_solo", playerName: "player1" };
        const nextTetri = Action.requestNewPiece(games, data);
        expect(nextTetri).toHaveProperty('shape');
    });

    it("updatePlayerSpectrum", () => {
        let games = [gameSolo, gameMulti_2];
        let board = gameMulti_2.players[0].spectrum;
        let data = { room: "test_multi_2", playerName: "player4", board };
        const expected = { playerName: "player4", spectrum: board };
        expect(Action.updatePlayerSpectrum(games, data)).toEqual(expected);
    });

    it("setPlayerGameOver", () => {
        let games = [gameSolo, gameMulti];
        let socketId = "socketId_1";
        const expected = { winner: gameSolo.players[0], currentGame: gameSolo };
        expect(Action.setPlayerGameOver(games, socketId)).toEqual(expected);
    });
});