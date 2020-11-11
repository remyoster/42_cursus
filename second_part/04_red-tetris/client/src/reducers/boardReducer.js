import { addPenaltyLinesToBoard } from '../utils/board';
import { updateScore } from '../utils/scoring';

/*
** Initial board state. Tetri and next tetri represents tetriminos. Board is a
** object of coordinates, locked is a boolean to know if the piece attempt the
** stack.
*/

export const initialState = {
    tetri: null,
    nextTetri: null,
    ghostShape: null,
    board: null,
    spectrums: [],
    score: {
        line: 0,
        points: 0,
        level: 0,
    },
    penaltyLines: 0,
    startCounter: 3,
    locked: true,
    isOver: false,
    result: null,
};

/*
** Reducer to deal with piece reception and board animation
*/

export function boardReducer(state = initialState, action) {
    switch (action.type) {
        case "START_GAME_SUCCESS":
            return {
                ...state,
                tetri: action.payload.tetris.first,
                nextTetri: action.payload.tetris.next,
                spectrums: action.payload.spectrums,
                board: action.payload.board,
                score: {
                    ...initialState.score,
                    level: action.payload.startingLevel
                },
                penaltyLines: 0,
                startCounter: 3,
                ghostShape: null,
                isOver: false,
                result: null
            };
        case "NEW_PIECE_SUCCESS":
            return ({
                ...state,
                tetri: state.nextTetri,
                nextTetri: action.payload,
                locked: false
            });
        case "MOVE_TETRI":
            return ({ ...state, tetri: action.tetri, board: action.board });
        case "MOVE_TETRI_AND_LOCK":
            return ({
                ...state,
                tetri: action.tetri,
                board: action.board,
                locked: true,
            });
        case "UPDATE_BOARD":
            return ({ ...state, board: action.board });
        case "UPDATE_SCORE":
            return ({
                ...state,
                score: updateScore(state.score, action.fullLine, action.downMove)
            });
        case "UPDATE_START_COUNTER":
            return ({ ...state, startCounter: state.startCounter - 1 });
        case "ADD_PENALTY_LINES_SUCCESS":
            if (state.isOver)
                return (state);
            let { tmpBoard, newShape } = addPenaltyLinesToBoard(state.board,
                state.tetri, action.payload);
            return ({
                ...state,
                board: tmpBoard,
                tetri: { ...state.tetri, shape: newShape },
                penaltyLines: state.penaltyLines + action.payload.length,
                locked: false
            });
        case "UPDATE_SPECTRUM_SUCCESS":
            let tmpSpectrums = [...state.spectrums];
            const spectrumIndex = tmpSpectrums
                .findIndex(e => e.playerName === action.payload.playerName);
            if (spectrumIndex > -1)
                tmpSpectrums[spectrumIndex].spectrum = action.payload.spectrum;
            return ({ ...state, spectrums: tmpSpectrums });
        case "UPDATE_GHOST":
            return ({
                ...state,
                ghostShape: action.ghostShape,
                board: action.board
            });
        case "UPDATE_PLAYERS_SUCCESS":
            if (state.spectrums.length) {
                let names = action.payload.map(e => e.name);
                let diff = state.spectrums.filter(e => names.includes(e.playerName));
                return ({...state, spectrums: diff});
            }
            else
                return (state);
        case "LOCK":
            return { ...state, locked: true };
        case "UNLOCK":
            return ({ ...state, locked: false });
        case "RESET_GAME_SUCCESS":
            return (initialState);
        case "REQUEST_GAME_OVER":
            return ({ ...state, isOver: true, locked: true });
        case "YOU_WIN":
            return ({ ...state, isOver: true });
        case "WIN_GAME_SUCCESS":
            return ({
                ...state,
                result: action.payload
            });
        case "REQUEST_LEAVE_ROOM":
            return (initialState);
        case "EXIT":
            return (initialState);
        default:
            return (state);
    }
}