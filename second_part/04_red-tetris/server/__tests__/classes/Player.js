const Player = require("../../classes/Player");

describe("Player class", () => {
	it('constructor', () => {
		let player = new Player()
		expect(player).toBeInstanceOf(Player);
	});

	let player = new Player();

	it('getIndexNextTetri', () => {
		expect(player.getIndexNextTetri()).toBe(2);
		expect(player.getIndexNextTetri()).toBe(3);
	})

	it('updateSpectrum', () => {
		expect(player.updateSpectrum('spectrum')).toBe('spectrum');
	});

	it('createBoard', () => {
		const board = {"0,0" : {occuped: false, color: null}};
		expect(player.createBoard(1, 1)).toEqual(board);
		expect(player.createBoard('test', null)).toEqual(board);
	});

	it('resetCounterPieces', () => {
		player.resetcounterPieces(0);
		expect(player.counterPieces).toBe(0);
	});

	it('setNewLeader', () => {
		player.setNewLeader();
		expect(player.leader).toBeTruthy();
	});

	it('setIsOver', () => {
		player.setIsOver(true);
		expect(player.isOver).toBeTruthy();
		player.setIsOver('yes');
		expect(player.isOver).toBe('yes');
	});

	it('resetSpectrum', () => {
		player.resetSpectrum();
		expect(player.spectrum).toEqual(player.createBoard(10, 20));
	})
});