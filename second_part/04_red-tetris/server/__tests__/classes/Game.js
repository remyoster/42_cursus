const Game = require("../../classes/Game");
const Player = require("../../classes/Player");

describe("Game class", () => {
    it("create new Game", () => {
        const newGame = new Game({type: 'solo', options: 'test', room:'testroom'});
        expect(newGame.type).toBe('solo');
        expect(newGame.options).toBe('test');
        expect(newGame.room.name).toBe('testroom');
    });

    it("setPieces", () => {
        let game = new Game({type: 'solo'});
        expect(game.setPieces()).toHaveLength(100);
        game.type = 'multi';
        expect(game.setPieces()).toHaveLength(100);

    });

    it("setIsStart", () => {
        let newGame = new Game();
        newGame.players = [new Player('testId', 'roster', true)];
        newGame.setIsStart();
        expect(newGame.isStart).toBeTruthy();
        expect(newGame.players[0].counterPieces).toBe(2);

    });
    it("changeOption", () => {
        let newGame = new Game();
        const options = {
            ghostMode: true,
            colorMode: 'normal',
            fullSpectrum: false,
            startingLevel: 0,
            dropTimeRef: 1000,
        };
        expect(newGame.changeOption("test", false)).toEqual(options);
        expect(newGame.changeOption("ghostMode", false)).toEqual({
            ...options,
            ghostMode: false});
    });
    it("addPlayer", () => {
        let newGame = new Game();
        let player1 = new Player('testId', 'roster', true);
        let player2 = new Player('testId2', 'roster2', false);
        expect(newGame.addPlayer({socketId: 'testId', name: 'roster'})).toBe(1);
        expect(newGame.players[0]).toEqual(player1);
        expect(newGame.addPlayer({socketId: 'testId2', name: 'roster2'})).toBe(2);
        expect(newGame.players[1]).toEqual(player2);

    });

    it("removePlayer", () => {
       let game = new Game();
        let player = new Player('testId', 'roster', true);
        let player2 = new Player('testId', 'roster', false);
        game.addPlayer({socketId: 'testId', name: 'madufour'});
        game.addPlayer({socketId: 'testId', name: 'roster'});
        game.addPlayer({socketId: 'testId', name: 'roster'});
       expect(game.removePlayer(0)).toEqual([player, player2]);
       expect(game.removePlayer(1)).toEqual([player]);
    });

    it("resetGame", () => {
        let newGame = new Game({type: 'solo'});
        newGame.resetGame();
        expect(newGame.isStart).toBeFalsy();
    });

    it("setGameOver", () => {
        let newGame = new Game({type: 'solo'});
        newGame.setGameOver();
        expect(newGame.isOver).toBeTruthy();
        expect(newGame.isStart).toBeFalsy();
    });

    it('restartGame', () => {
        let game = new Game();
        game.addPlayer({socketId: 'testId', name: 'madufour'});
        game.restartGame();
        expect(game.isOver).toBeFalsy();
    });

    it('setNewPieces', () => {
        let game = new Game({type: 'multi'});
        game.setNewPieces();
        expect(game.pieces).toHaveLength(100);
        game.setNewPieces();
        expect(game.pieces).toHaveLength(200);

    });

    it('isJoinable', () => {
        let game = new Game({type: 'solo'});
        expect(game.isJoinable()).toBeTruthy();
        game.isStart = true;
        expect(game.isJoinable()).toBeFalsy();
    });

    it('isStartable', () => {
        let game = new Game({type: 'solo'});
        expect(game.isStartable()).toBeTruthy();
        game.type = 'multi';
        expect(game.isStartable()).toBeFalsy();
        game.addPlayer({socketId: 'testId', name: 'madufour'});
        game.addPlayer({socketId: 'testId', name: 'madufour'});
        expect(game.isStartable()).toBeTruthy();
    });

    it('getLeader', () => {
        let game = new Game();
        expect(game.getLeader()).toBeUndefined();
        game.addPlayer({socketId: 'testId', name: 'madufour'});
        expect(game.getLeader()).toEqual(game.players[0]);
    });
});