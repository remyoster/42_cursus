import { boardReducer as reducer, initialState } from '../../reducers/boardReducer';
import { createBoard, addPenaltyLinesToBoard } from '../../utils/board';

it('should return the initial state', () => {
	expect(reducer(undefined, {})).toEqual(initialState);
});

it('should handle START_GAME_SUCCES (from serv)', () => {
	const payload = {
		tetris: {
			first: 'first',
			next: 'next'
		},
		board: 'spectrum',
		spectrums: ['roster', 'madufour'],
		startingLevel: 5,
	};
	expect(reducer(undefined, { type: "START_GAME_SUCCESS", payload })).toEqual({
		tetri: 'first',
		nextTetri: 'next',
		ghostShape: null,
		board: 'spectrum',
		spectrums: ['roster', 'madufour'],
		penaltyLines: 0,
		score: {
			level: 5,
			line: 0,
			points: 0
		},
		startCounter: 3,
		locked: true,
		result: null,
		isOver: false,
	});
});

it('should handle NEW_PIECE_SUCCESS (from serv)', () => {
	const payload = 'new tetri';
	const expectedState = { ...initialState, nextTetri: payload, locked: false };
	expect(reducer(undefined, { type: "NEW_PIECE_SUCCESS", payload }))
		.toEqual(expectedState);
	expect(reducer(expectedState, { type: "NEW_PIECE_SUCCESS", payload }))
		.toEqual({ ...expectedState, tetri: 'new tetri' });
})

it('should handle MOVE_TETRI', () => {
	const tetri = 'tetri';
	const board = 'board';
	expect(reducer(initialState, { type: "MOVE_TETRI", tetri, board })).toEqual({
		...initialState, tetri, board
	});
})

it('should handle MOVE_TETRI_AND_LOCK', () => {
	const tetri = 'tetri';
	const board = 'board';
	expect(reducer(initialState, { type: "MOVE_TETRI_AND_LOCK", tetri, board }))
		.toEqual({
			...initialState, tetri, board, locked: true
		});
});

it('should handle UPDATE_BOARD', () => {
	const board = 'board';
	expect(reducer(initialState, { type: "UPDATE_BOARD", board })).toEqual({
		...initialState, board
	});
});

it('should handle ADD_PENALTY_LINES_SUCCESS', () => {
	const board = createBoard(10, 20);
	const tetri = {
		shape: [
			{ x: 0, y: 0 }, { x: 0, y: 1 }, { x: 0, y: 2, center: true },
			{ x: 0, y: 3 }
		],
		color: 'yellow'
	};
	const penaltyLines = [4, 5];
	let { tmpBoard, newShape } = addPenaltyLinesToBoard(board, tetri, penaltyLines);
	expect(reducer({ ...initialState, tetri: tetri, board: board },
		{ type: "ADD_PENALTY_LINES_SUCCESS", payload: penaltyLines })).toEqual({
			...initialState,
			board: tmpBoard,
			tetri: { ...tetri, shape: newShape },
			penaltyLines: 2,
			locked: false
		});
});

it('should handle UPDATE_SPECTRUM_SUCCESS', () => {
	const payload = {
		playerName: 'roster',
		spectrum: 'spectrum'
	};
	const spectrums = [{ playerName: 'roster' }];
	expect(reducer({ ...initialState, spectrums },
		{ type: "UPDATE_SPECTRUM_SUCCESS", payload })).toEqual({
			...initialState,
			spectrums: [{ playerName: 'roster', spectrum: 'spectrum' }]
		});
	expect(reducer({ ...initialState, spectrums },
		{ type: "UPDATE_SPECTRUM_SUCCESS", payload: { playerName: 'test' } })).toEqual({
			...initialState,
			spectrums
		});
});

it('should handle UPDATE_GHOST', () => {
	const ghostShape = 'ghostShape';
	const board = 'board';
	expect(reducer(initialState, { type: "UPDATE_GHOST", ghostShape, board }))
		.toEqual({
			...initialState,
			ghostShape,
			board
		});
});

it('should handle LOCK', () => {
	expect(reducer(initialState, { type: "LOCK" })).toEqual({
		...initialState,
		locked: true
	});
});

it('should handle UNLOCK', () => {
	expect(reducer(initialState, { type: "UNLOCK" })).toEqual({
		...initialState,
		locked: false
	});
});

it('should handle RESET_GAME_SUCCESS', () => {
	expect(reducer(undefined, { type: "RESET_GAME_SUCCESS" })).toBe(initialState);
});

it('should handle REQUEST_GAME_OVER', () => {
	expect(reducer(undefined, { type: "REQUEST_GAME_OVER" })).toEqual({
		...initialState,
		isOver: true,
		locked: true
	});
});

it('should handle YOU_WIN (from serv)', () => {
	expect(reducer(undefined, {type: "YOU_WIN"})).toEqual({
		...initialState,
		isOver: true
	})
})

it('should handle WIN_GAME_SUCCESS', () => {
	const payload = 'You win !'
	expect(reducer(undefined, {type:"WIN_GAME_SUCCESS", payload})).toEqual({
		...initialState,
		locked: true,
		result: payload
	});
});

it('should handle EXIT', () => {
	expect(reducer(undefined, { type: "EXIT" })).toBe(initialState);
});
