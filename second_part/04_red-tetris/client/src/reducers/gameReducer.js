
/*
** Bonuses : 
** - startingLevel is the starting level of the game
** - dropTimeRef is the lower value of the gravity (decrease it to
**   increase difficulties)
** - fullSpectrum to activate or not the fullspectrum visibility
** - ghostMode to activate or not the position of the piece on the stack
*/

export const initialState = {
    gameAvailable: [],
    type: null,
    players: [],
    room: null,
    playerName: null,
    id: null,
    isLoading: true,
    options: {
        ghostMode: true,
        fullSpectrum: false,
        colorMode: 'normal',
        startingLevel: 0,
        dropTimeRef: 1000,
    },
    error: null,
    marks: { solo: [], multi: [] },
};

export function gameReducer(state = initialState, action) {
    switch (action.type) {
        case "LIST_GAME_SUCCESS":
            return {
                ...state,
                gameAvailable: action.payload,
            };
        case "CONNECT_SUCCESS":
            return ({
                ...state,
                playerName: action.payload.name,
                id: action.payload.id,
                isLoading: false,
                error: null
            });
        case "CREATE_GAME_SUCCESS":
            return {
                ...state,
                type: action.payload.type,
                players: action.payload.players,
                room: action.payload.room,
                options: action.payload.options,
                isLoading: false,
            };
        case "BEST_GAMES_SUCCESS":
            return {
                ...state,
                marks: action.payload
            };
        case "JOIN_GAME_SUCCESS":
            return {
                ...state,
                type: action.payload.type,
                players: action.payload.players,
                room: action.payload.room,
                options: action.payload.options,
                isLoading: false,
            };
        case "CHANGE_OPTION_SUCCESS":
            return ({ ...state, options: action.payload });
        case "REQUEST_LEAVE_ROOM":
            return ({ 
                ...initialState,
                playerName: state.playerName,
                id: state.id,
                isLoading: false
            });
        case "UPDATE_PLAYERS_SUCCESS":
            return {
                ...state,
                players: action.payload
            }
        case "EXIT":
            return ({...initialState, isLoading: false});
        case "ERROR":
            return ({ ...state, error: action.payload, isLoading: false });
        case "REMOVE_ERROR":
            return ({ ...state, error: null });
        default:
            return (state);
    }
}
