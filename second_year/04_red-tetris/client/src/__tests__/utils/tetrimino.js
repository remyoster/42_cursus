import {
	offsetPiece, rotatePoint, rotateTetri,
	offsetDispatcher,
	toggleRotationOffset,
	toggleSimpleOffset,
	toggleHardDrop,
	toggleGhost
} from '../../utils/tetrimino';
import { fillBoard, createBoard } from '../../utils/board';

it('offsetPiece function', () => {
	let shape = [{ x: 0, y: 0 }, { x: 1, y: 1 }];
	expect(offsetPiece(shape, { x: 4, y: 2 })).toEqual(
		[{ x: 4, y: 2 }, { x: 5, y: 3 }]
	);
	expect(offsetPiece(shape, { x: 0, y: 2 })).toEqual(
		[{ x: 0, y: 2 }, { x: 1, y: 3 }]
	);
	expect(offsetPiece(shape, { x: 0, y: 0 })).toBe(shape);
});

it('rotatePoint function', () => {
	let center = { x: 4, y: 2 };
	let point = { x: 5, y: 2 };
	expect(rotatePoint(center, point)).toEqual({ x: 5, y: 1 });
	expect(rotatePoint(center, point, false)).toEqual({ x: 5, y: 3 });
});

it('rotateTetri function', () => {
	let shape = [
		{ x: 1, y: 0 }, { x: 2, y: 0 }, { x: 0, y: 1 },
		{ x: 1, y: 1, center: true }
	];
	expect(rotateTetri(shape)).toEqual([
		{ x: 2, y: 1 }, { x: 2, y: 2 }, { x: 1, y: 0 },
		{ x: 1, y: 1, center: true }
	]);
	expect(rotateTetri(shape, false)).toEqual([
		{ x: 0, y: 1 }, { x: 0, y: 0 }, { x: 1, y: 2 },
		{ x: 1, y: 1, center: true }
	]);
	expect(
		rotateTetri(
			rotateTetri(
				rotateTetri(
					rotateTetri(shape)
				)
			)
		)
	).toEqual(shape);
});

it('OffsetDispatcher function', () => {
	expect(offsetDispatcher(3, 2, 'I', 2)).toEqual({ x: 2, y: 0 });
	expect(offsetDispatcher(1, 2, 'O', 2)).toEqual({ x: 1, y: 0 });
	expect(offsetDispatcher(0, 1, 'S', 0)).toEqual({ x: 0, y: 0 });
	expect(offsetDispatcher(0, 1, 'Z', 1)).toEqual({ x: -1, y: 0 });
	expect(offsetDispatcher(2, 1, 'J', 1)).toEqual({ x: -1, y: 0 });
	expect(offsetDispatcher(2, 3, 'L', 4)).toEqual({ x: 1, y: 2 });
	expect(offsetDispatcher(1, 2, 'T', 3)).toEqual({ x: 0, y: -2 });
});

it('toggleRotationOffset function', () => {
	const tetri = {
		shape: [
			{ x: 3, y: 2 }, { x: 4, y: 2 }, { x: 2, y: 3 },
			{ x: 3, y: 3, center: true }
		],
		color: 'green',
		pos: 0
	};
	let key = 38;
	let board = createBoard(10, 20);
	let newShape = rotateTetri(tetri.shape, true);
	expect(toggleRotationOffset(key, tetri, board)).toEqual({
		type: "MOVE_TETRI",
		tetri: { ...tetri, shape: newShape, pos: 1 },
		board: fillBoard(board, null, newShape, tetri.color)
	});
	newShape = rotateTetri(tetri.shape, false);
	expect(toggleRotationOffset(47, tetri, board)).toEqual({
		type: "MOVE_TETRI",
		tetri: { ...tetri, shape: newShape, pos: 3 },
		board: fillBoard(board, null, newShape, tetri.color)
	});
	for (let cell in board)
		board[cell].occuped = true;
	expect(toggleRotationOffset(key, tetri, board)).toBeNull();
});

it('toggleSimpleOffset function', () => {
	let tetri = {
		shape: [
			{ x: 3, y: 2 }, { x: 4, y: 2 }, { x: 2, y: 3 },
			{ x: 3, y: 3, center: true }
		],
		color: 'green',
	};
	let board = createBoard(10, 20);
	let newShape = offsetPiece(tetri.shape, { x: 0, y: 1 });
	expect(toggleSimpleOffset(40, tetri, board)).toEqual({
		type: "MOVE_TETRI",
		tetri: { ...tetri, shape: newShape },
		board: fillBoard(board, null, newShape, tetri.color)
	});
	tetri = {...tetri, shape: newShape};
	newShape = offsetPiece(tetri.shape, { x: 1, y: 0 });
	expect(toggleSimpleOffset(39, tetri, board)).toEqual({
		type: "MOVE_TETRI",
		tetri: { ...tetri, shape: newShape },
		board: fillBoard(board, null, newShape, tetri.color)
	});
	newShape = offsetPiece(tetri.shape, { x: -1, y: 0 });
	expect(toggleSimpleOffset(37, tetri, board)).toEqual({
		type: "MOVE_TETRI",
		tetri: { ...tetri, shape: newShape },
		board: fillBoard(board, null, newShape, tetri.color)
	});
	for (let cell in board)
		board[cell].occuped = true;
	expect(toggleSimpleOffset(44, tetri, board)).toBeNull();
});

it('toggleHardDrop function', () => {
let tetri = {
		shape: [
			{ x: 3, y: 2 }, { x: 4, y: 2 }, { x: 2, y: 3 },
			{ x: 3, y: 3, center: true }
		],
		color: 'green',
	};
	let board = createBoard(10, 20);	
	let newShape = [
		{x: 3, y: 18}, {x:4, y:18}, {x:2, y:19}, {x:3, y:19, center: true}
	];
	expect(toggleHardDrop(tetri, board)).toEqual({
		type: "MOVE_TETRI_AND_LOCK",
		tetri: {...tetri, shape: newShape},
		board: fillBoard(board, tetri.shape, newShape, tetri.color),
		dropedLines: 16
	});
});

it('toggleGhost function', () => {
let tetri = {
		shape: [
			{ x: 3, y: 2 }, { x: 4, y: 2 }, { x: 2, y: 3 },
			{ x: 3, y: 3, center: true }
		],
		color: 'green',
	};
	let board = createBoard(10, 20);	
	let newShape = [
		{x: 3, y: 18}, {x:4, y:18}, {x:2, y:19}, {x:3, y:19, center: true}
	];
	expect(toggleGhost(newShape, tetri, board)).toEqual({
		type: "UPDATE_GHOST",
		ghostShape: newShape,
		board: fillBoard(board, null, newShape, tetri.color, true)
	});
});