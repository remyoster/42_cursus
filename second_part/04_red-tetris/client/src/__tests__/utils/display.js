import { displayCounterModal, displayGameOverModal,
	displayBoard, 
	displayGridSpectrum,
	searchFirstOccupedLine,
	displaySpectrums,
	displayNextTetri} from '../../utils/display';
import { createBoard } from '../../utils/board';
import { render } from '@testing-library/react';


it('displayCounterModal function which render a TransitionModal component', () => {
	const { getByText } = render(displayCounterModal("42"));
	expect(getByText("42")).toBeInTheDocument();
	expect(displayCounterModal()).toBeUndefined();
});

it('displayGameOverModal function which render a TransitionModal component', () => {
	const dispatch = jest.fn();
	const data = {
		score: {
			points: 42,
		},
		result: {
			winner: 'roster',
			score: {
				points: 420,
			},
	},
	isLeader: true,
	dispatch
};
	const { getByText } = render(displayGameOverModal(data));
	expect(getByText("Points: 42")).toBeInTheDocument();
	//expect(displayGameOverModal()).toBeUndefined();
});

it('displayBoard function with empty board', () => {
	let board = createBoard(4,4);
	const { container } = render(displayBoard(board));
	expect(container.querySelectorAll("div")).toHaveLength(16);

});

it('displayBoard function with occuped board (ghost and classic)', () => {
	let board = createBoard(4,4);
	board['0,0'] = { occuped :true, color: 'blue'};
	board['1,0'] = { occuped : false, color: 'blue', ghost: true};
	const { container } = render(displayBoard(board));
	expect(container.querySelectorAll("div.tetri-cell")).toHaveLength(2);
	expect(container.querySelectorAll("div")).toHaveLength(16);
});

it('searchFirstOccupedLine function', () => {
	let board = createBoard(10,20);
	expect(searchFirstOccupedLine(board)).toBe(20);
	board['0,19'] = { occuped : true, color: 'blue'};
	expect(searchFirstOccupedLine(board)).toBe(19);
	for (let cell in board)
		board[cell].occuped = true;
	expect(searchFirstOccupedLine(board)).toBeNull();
});

it('displayGridSpectrum function', () => {
	let board = createBoard(10, 20);
	board['0,19'] = { occuped : true, color: 'blue'};
	const { container, rerender } = render(displayGridSpectrum(board));
	expect(container.querySelectorAll("div.tetri-cell")).toHaveLength(10);
	rerender(displayGridSpectrum(board, true));
	expect(container.querySelectorAll("div.tetri-cell")).toHaveLength(1);
});

it('displaySpectrums function', () => {
	let spectrums = [{playerName : 'roster', spectrum: createBoard(10,20)}];
	spectrums.push({playerName: 'madufour', spectrum: createBoard(10,20)});
	expect(displaySpectrums([])).toBeUndefined();
	const { container, getByText } = render(displaySpectrums(spectrums));
	expect(container.querySelectorAll("div.spectrum-name")).toHaveLength(2);
	expect(container.querySelectorAll("div.spectrum-grid")).toHaveLength(2);
	expect(getByText("roster")).toBeInTheDocument();
	expect(getByText("madufour")).toBeInTheDocument();
});

it('displayNextTetri function', () => {
	const nextTetri = {
		shape: [
		{ x: 1, y: 0 }, { x: 2, y: 0 }, { x: 0, y: 1 },
		{ x: 1, y: 1, center: true }
		],
		color: 'blue'
	};
	expect(displayNextTetri()).toBeUndefined();
	const { container } = render(displayNextTetri(nextTetri));
	expect(container.querySelectorAll("div.tetri-cell")).toHaveLength(4);
	expect(container.querySelectorAll("div")).toHaveLength(8);
});