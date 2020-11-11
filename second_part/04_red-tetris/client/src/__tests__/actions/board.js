import * as actions from '../../actions/board';

it('should create an action to move a tetri', () => {
	const tetri = 'tetri';
	const board = 'board';
    const expectedAction = {
      type: "MOVE_TETRI",
			tetri,
			board,
    };
    expect(actions.moveTetri({tetri, board})).toEqual(expectedAction);
});

it('should create an action to move a tetri, lock the board and count dropedLines', () => {
	const tetri = 'tetri';
	const board = 'board';
	const dropedLines = 0;
    const expectedAction = {
      type: "MOVE_TETRI_AND_LOCK",
			tetri,
			board,
			dropedLines
    };
    expect(actions.moveTetriAndLock({tetri, board, dropedLines})).toEqual(expectedAction);
});

it('should create an action to update the ghost shape', () => {
	const ghostShape = 'tetri';
	const board = 'board';
    const expectedAction = {
      type: "UPDATE_GHOST",
			ghostShape,
			board,
    };
    expect(actions.updateGhost({ghostShape, board})).toEqual(expectedAction);
});

it('should create an action to update the board', () => {
	const board = 'board';
    const expectedAction = {
      type: "UPDATE_BOARD",
			board,
    };
    expect(actions.updateBoard({board})).toEqual(expectedAction);
});

it('should create an action to lock the board', () => {
    const expectedAction = {
      type: "LOCK",
    };
    expect(actions.lockBoard()).toEqual(expectedAction);
});

it('should create an action to unlock the board', () => {
    const expectedAction = {
      type: "UNLOCK",
    };
    expect(actions.unlockBoard()).toEqual(expectedAction);
});

it('should create an action to update the score', () => {
  const fullLine = 2;
  const downMove = {soft: 1, hard: 5};
    const expectedAction = {
      type: "UPDATE_SCORE",
      fullLine,
      downMove
    };
    expect(actions.updateScore(fullLine, downMove)).toEqual(expectedAction);
});

it('should create an action to update the startCounter', () => {
    const expectedAction = {
      type: "UPDATE_START_COUNTER",
    };
    expect(actions.updateStartCounter()).toEqual(expectedAction);
});