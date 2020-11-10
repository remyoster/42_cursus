/*
** Piece class is a tetrimino generator. Each tetrimino is in the dispatcher.
** The shape getter return an array of the provided shape or 'I' shape.
** getRandomShape return an array of a random shape
*/

class Piece {
	constructor() {
		this.shapeDispatcher = {
			'I': this.I_tetrimino(),
			'O': this.O_tetrimino(),
			'T': this.T_tetrimino(),
			'L': this.L_tetrimino(),
			'J': this.J_tetrimino(),
			'Z': this.Z_tetrimino(),
			'S': this.S_tetrimino(),
		};
		this.shapeKeys = Object.keys(this.shapeDispatcher);
	}

	/*
	[1,1,1,1]
	*/
	I_tetrimino() {
		return ({
			shape: [
				{ x: 0, y: 0 }, { x: 1, y: 0, center: true },
				{ x: 2, y: 0 }, { x: 3, y: 0 }
			],
			letter: 'I',
			color: 'aqua'
		});
	}

	/*
	[1,1],
	[1,1]
	*/
	O_tetrimino() {
		return ({
			shape: [
				{ x: 0, y: 0 }, { x: 1, y: 0 }, { x: 0, y: 1, center: true },
				{ x: 1, y: 1 }],
			letter: 'O',
			color: 'yellow'
		});
	}

	/*
	[0,1,0],
	[1,1,1]
	*/
	T_tetrimino() {
		return ({
			shape: [
				{ x: 1, y: 0 }, { x: 0, y: 1 }, { x: 1, y: 1, center: true },
				{ x: 2, y: 1 }
			],
			letter: 'T',
			color: 'purple'
		});
	}

	/*
	[0, 0, 1],
	[1, 1, 1],
	[0, 0, 0]
*/
	L_tetrimino() {
		return ({
			shape: [
				{ x: 2, y: 0 }, { x: 0, y: 1 }, { x: 1, y: 1, center: true },
				{ x: 2, y: 1 }
			],
			letter: 'L',
			color: 'orange'
		});
	}

	/*
	[1, 0, 0],
	[1, 1, 1],
	[0, 0, 0]
*/
	J_tetrimino() {
		return ({
			shape: [
				{ x: 0, y: 0 }, { x: 0, y: 1 }, { x: 1, y: 1, center: true },
				{ x: 2, y: 1 }
			],
			letter: 'J',
			color: 'blue'
		});
	}

	/*
	[1, 1, 0],
	[0, 1, 1],
	[0, 0, 0]
*/
	Z_tetrimino() {
		return ({
			shape: [
				{ x: 0, y: 0 }, { x: 1, y: 0 }, { x: 1, y: 1, center: true },
				{ x: 2, y: 1 }
			],
			letter: 'Z',
			color: 'red'
		});
	}

	/*
	[0, 1, 1],
	[1, 1, 0],
	[0, 0, 0]
	*/
	S_tetrimino() {
		return ({
			shape: [
				{ x: 1, y: 0 }, { x: 2, y: 0 }, { x: 0, y: 1 },
				{ x: 1, y: 1, center: true }
			],
			letter: 'S',
			color: 'green'
		});
	}

	generateColor() {
		let red = this.getRandomIntInclusive(0, 255);
		let blue = this.getRandomIntInclusive(0, 255);
		let green = this.getRandomIntInclusive(0, 255);
		return (`rgb(${red},${blue},${green})`);
	}

	generateShape(shape = 'I', colorMode='normal') {
		let tetri = this.shapeDispatcher[shape] || this.I_tetrimino();
		tetri.pos = 0;
		if (colorMode == 'random') {
			tetri.color = this.generateColor();
		}
		else if (colorMode == 'red')
			tetri.color = colorMode;
		return (tetri);
	}

	getRandomShape(colorMode = 'normal') {
		let random = this.getRandomIntInclusive(0, 6);
		return (this.generateShape(this.shapeKeys[random], colorMode));
	}

	getRandomIntInclusive(min, max) {
		min = Math.ceil(min);
		max = Math.floor(max);
		return (Math.floor(Math.random() * (max - min + 1)) + min);
	}
}

module.exports = Piece;