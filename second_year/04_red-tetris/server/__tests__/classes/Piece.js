const Piece = require("../../classes/Piece");

describe("Piece class", () => {
		let tetrigen = new Piece();

		it('I_tetrimino', () => {
			const tetri = {
			shape: [
				{ x: 0, y: 0 }, { x: 1, y: 0, center: true },
				{ x: 2, y: 0 }, { x: 3, y: 0 }
			],
			letter: 'I',
			color: 'aqua'
		};
		expect(tetrigen.I_tetrimino()).toEqual(tetri);
		});

		it('O_tetrimino', () => {
			const tetri = {
			shape: [
				{ x: 0, y: 0 }, { x: 1, y: 0 }, { x: 0, y: 1, center: true },
				{ x: 1, y: 1 }],
			letter: 'O',
			color: 'yellow'
		};
		expect(tetrigen.O_tetrimino()).toEqual(tetri);
		});

		it('T_tetrimino', () => {
			const tetri = {
			shape: [
				{ x: 1, y: 0 }, { x: 0, y: 1 }, { x: 1, y: 1, center: true },
				{ x: 2, y: 1 }
			],
			letter: 'T',
			color: 'purple'
		};
		expect(tetrigen.T_tetrimino()).toEqual(tetri);
		});

		it('L_tetrimino', () => {
			const tetri = {
			shape: [
				{ x: 2, y: 0 }, { x: 0, y: 1 }, { x: 1, y: 1, center: true },
				{ x: 2, y: 1 }
			],
			letter: 'L',
			color: 'orange'
		};
		expect(tetrigen.L_tetrimino()).toEqual(tetri);
		});

		it('J_tetrimino', () => {
			const tetri = {
			shape: [
				{ x: 0, y: 0 }, { x: 0, y: 1 }, { x: 1, y: 1, center: true },
				 { x: 2, y: 1 }
			],
			letter: 'J',
			color: 'blue'
		}
		expect(tetrigen.J_tetrimino()).toEqual(tetri);
		});

		it('Z_tetrimino', () => {
			const tetri = {
			shape: [
				{ x: 0, y: 0 }, { x: 1, y: 0 }, { x: 1, y: 1, center: true },
				{ x: 2, y: 1 }
			],
			letter: 'Z',
			color: 'red'
		};
		expect(tetrigen.Z_tetrimino()).toEqual(tetri);
		});

		it('S_tetrimino', () => {
			const tetri = {
			shape: [
				{ x: 1, y: 0 }, { x: 2, y: 0 }, { x: 0, y: 1 },
				{ x: 1, y: 1, center: true }
			],
			letter: 'S',
			color: 'green'
		};
		expect(tetrigen.S_tetrimino()).toEqual(tetri);
		});

		it('generateColor', () => {
			expect(tetrigen.generateColor()).toEqual(expect.stringMatching(/[a-f0-9]/))
		});

		it('generateShape', () => {
			const tetri_I = {
			shape: [
				{ x: 0, y: 0 }, { x: 1, y: 0, center: true },
				{ x: 2, y: 0 }, { x: 3, y: 0 }
			],
			pos: 0,
			letter: 'I',
			color: 'aqua'
		};
			const tetri_S = {
			shape: [
				{ x: 1, y: 0 }, { x: 2, y: 0 }, { x: 0, y: 1 },
				{ x: 1, y: 1, center: true }
			],
			pos: 0,
			letter: 'S',
			color: 'green'
		};
		expect(tetrigen.generateShape('sfddsf')).toEqual(tetri_I);
		expect(tetrigen.generateShape()).toEqual(tetri_I);
		expect(tetrigen.generateShape('S')).toEqual(tetri_S);
		expect(tetrigen.generateShape('I', 'random').color).not.toBe('aqua');
		expect(tetrigen.generateShape('I', 'red').color).toBe('red');
		});

		it('getRandomShape', () => {
			const tetri = tetrigen.getRandomShape();
			expect(tetri).toHaveProperty('shape');
			expect(tetri).toHaveProperty('color');
			expect(tetri).toHaveProperty('letter');
		});

	});