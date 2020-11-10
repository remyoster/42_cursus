export function moveTetri({ tetri, board }) {
	return ({ type: "MOVE_TETRI", tetri, board });
}

export function moveTetriAndLock({ tetri, board, dropedLines }) {
	return ({ type: "MOVE_TETRI_AND_LOCK", tetri, board, dropedLines });
}

export function updateGhost({ ghostShape, board }) {
	return ({ type: "UPDATE_GHOST", ghostShape, board });
}

export function updateBoard({ board }) {
	return ({ type: "UPDATE_BOARD", board });
}

export function lockBoard() {
	return ({ type: "LOCK" });
}

export function unlockBoard() {
	return ({ type: "UNLOCK" });
}

export function updateScore(fullLine, downMove) {
	return ({type: "UPDATE_SCORE", fullLine, downMove});
}

export function updateStartCounter() {
	return ({type : "UPDATE_START_COUNTER"});
}