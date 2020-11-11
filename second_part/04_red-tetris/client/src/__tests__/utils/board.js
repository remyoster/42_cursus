import { createBoard, isBoardFillable, fillBoard, findEcartInArray,
	checkAndPopCompleteLine, addPenaltyLinesToBoard } from '../../utils/board';

it('createBoard function', () => {
	expect(createBoard(1, 1)).toEqual({ '0,0': { occuped: false, color: null } });
	expect(createBoard(1, 2)).toEqual({
		'0,0': { occuped: false, color: null },
		'0,1': { occuped: false, color: null }
	});
	expect(createBoard(2, 6)).toEqual({
		'0,0': { occuped: false, color: null },
		'0,1': { occuped: false, color: null },
		'0,2': { occuped: false, color: null },
		'0,3': { occuped: false, color: null },
		'0,4': { occuped: false, color: null },
		'0,5': { occuped: false, color: null },
		'1,0': { occuped: false, color: null },
		'1,1': { occuped: false, color: null },
		'1,2': { occuped: false, color: null },
		'1,3': { occuped: false, color: null },
		'1,4': { occuped: false, color: null },
		'1,5': { occuped: false, color: null },
	});
});

it('isBoardFillable function', () => {
	const board = createBoard(6, 6);
	const shape = [
		{ x: 0, y: 0 }, { x: 1, y: 0 }, { x: 0, y: 1, center: true },
		{ x: 1, y: 1 }];
	const shape2 = [
		{ x: 0, y: 1 }, { x: 1, y: 1 }, { x: 0, y: 2, center: true },
		{ x: 1, y: 2 }];
	expect(isBoardFillable(board, shape, null)).toBeFalsy();
	expect(isBoardFillable(board, null, shape)).toBeTruthy();
	expect(isBoardFillable(board, shape, shape2)).toBeTruthy();
	for (let point in board)
		board[point].occuped = true;
	expect(isBoardFillable(board, null, shape)).toBeFalsy();
});

it('fillBoard function', () => {
	let board = createBoard(2, 6);
	const shape = [
		{ x: 0, y: 0 }, { x: 1, y: 0 }, { x: 0, y: 1, center: true },
		{ x: 1, y: 1 }];
	expect(fillBoard(board, null, shape, 'blue')).toEqual({
		'0,0': { occuped: true, color: 'blue' },
		'0,1': { occuped: true, color: 'blue' },
		'0,2': { occuped: false, color: null },
		'0,3': { occuped: false, color: null },
		'0,4': { occuped: false, color: null },
		'0,5': { occuped: false, color: null },
		'1,0': { occuped: true, color: 'blue' },
		'1,1': { occuped: true, color: 'blue' },
		'1,2': { occuped: false, color: null },
		'1,3': { occuped: false, color: null },
		'1,4': { occuped: false, color: null },
		'1,5': { occuped: false, color: null },
	});
	board['1,5'] = { occuped: true, color: 'red' };
	expect(fillBoard(board, [{x: 1, y: 5}], shape, 'blue')).toEqual({
		'0,0': { occuped: true, color: 'blue' },
		'0,1': { occuped: true, color: 'blue' },
		'0,2': { occuped: false, color: null },
		'0,3': { occuped: false, color: null },
		'0,4': { occuped: false, color: null },
		'0,5': { occuped: false, color: null },
		'1,0': { occuped: true, color: 'blue' },
		'1,1': { occuped: true, color: 'blue' },
		'1,2': { occuped: false, color: null },
		'1,3': { occuped: false, color: null },
		'1,4': { occuped: false, color: null },
		'1,5': { occuped: false, color: null },
	});
	expect(fillBoard(board, [{x: 1, y: 5}], shape, 'blue', true)).toEqual({
		'0,0': { occuped: true, color: 'blue', ghost: true },
		'0,1': { occuped: true, color: 'blue', ghost: true },
		'0,2': { occuped: false, color: null },
		'0,3': { occuped: false, color: null },
		'0,4': { occuped: false, color: null },
		'0,5': { occuped: false, color: null },
		'1,0': { occuped: true, color: 'blue', ghost: true },
		'1,1': { occuped: true, color: 'blue', ghost: true },
		'1,2': { occuped: false, color: null },
		'1,3': { occuped: false, color: null },
		'1,4': { occuped: false, color: null },
		'1,5': { occuped: false, color: null, ghost: false },
	});
});

it('checkAndPopCompleteLine function', () => {
	let tetri = { shape: [
		{ x: 0, y: 0 }, { x: 0, y: 1 }, { x: 0, y: 2, center: true },
		{ x: 0, y: 3 }],
	};
	let board = createBoard(10, 4);
	expect(checkAndPopCompleteLine(board, tetri)).toEqual({
		fullLine: 0,
		tmpBoard: null
	});

	for (let cell in board) {
		board[cell] = { occuped : true, color : 'blue' };
	}
	expect(checkAndPopCompleteLine(board, tetri)).toEqual({
		fullLine : 4, 
		tmpBoard: {
		'0,0': { occuped: false, color: null },
		'1,0': { occuped: false, color: null },
		'2,0': { occuped: false, color: null },
		'3,0': { occuped: false, color: null },
		'4,0': { occuped: false, color: null },
		'5,0': { occuped: false, color: null },
		'6,0': { occuped: false, color: null },
		'7,0': { occuped: false, color: null },
		'8,0': { occuped: false, color: null },
		'9,0': { occuped: false, color: null },
		'0,1': { occuped: false, color: null },
		'1,1': { occuped: false, color: null },
		'2,1': { occuped: false, color: null },
		'3,1': { occuped: false, color: null },
		'4,1': { occuped: false, color: null },
		'5,1': { occuped: false, color: null },
		'6,1': { occuped: false, color: null },
		'7,1': { occuped: false, color: null },
		'8,1': { occuped: false, color: null },
		'9,1': { occuped: false, color: null },
		'0,2': { occuped: false, color: null },
		'1,2': { occuped: false, color: null },
		'2,2': { occuped: false, color: null },
		'3,2': { occuped: false, color: null },
		'4,2': { occuped: false, color: null },
		'5,2': { occuped: false, color: null },
		'6,2': { occuped: false, color: null },
		'7,2': { occuped: false, color: null },
		'8,2': { occuped: false, color: null },
		'9,2': { occuped: false, color: null },
		'0,3': { occuped: false, color: null },
		'1,3': { occuped: false, color: null },
		'2,3': { occuped: false, color: null },
		'3,3': { occuped: false, color: null },
		'4,3': { occuped: false, color: null },
		'5,3': { occuped: false, color: null },
		'6,3': { occuped: false, color: null },
		'7,3': { occuped: false, color: null },
		'8,3': { occuped: false, color: null },
		'9,3': { occuped: false, color: null },
		}
	});
});

it('findEcartInArray function', () => {
	let tab = [11,10];
	expect(findEcartInArray([2])).toBeNull();
	expect(findEcartInArray(tab)).toBeNull();
	tab.push(8);
	expect(findEcartInArray(tab)).toEqual({
		lines: [9],
		offset: 1
	});
	expect(findEcartInArray([15, 13, 12])).toEqual({
		lines: [14, 13],
		offset: 2
	});
});

it('addPenaltyLinesToBoard function', () => {
	let board = createBoard(10, 20);
	let tetri = { 
		shape: [
		{ x: 0, y: 0 }, { x: 0, y: 1 }, { x: 0, y: 2, center: true },
		{ x: 0, y: 3 }
	],
		color: 'yellow'
	};
	let { tmpBoard, newShape } = addPenaltyLinesToBoard(board, tetri, [2,4,8]);
	expect(tmpBoard['2,19']).toEqual({
		occuped: false,
		color: null,
	});
	expect(tmpBoard['2,18']).toEqual({
		occuped: true,
		color: 'firebrick',
	});
	expect(tmpBoard['2,17']).toEqual({
		occuped: true,
		color: 'firebrick',
	});
	expect(newShape).toEqual(tetri.shape);
});
