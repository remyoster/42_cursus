export const initialState = {
	messages: []
};

export function chatReducer(state = initialState, action) {
	switch (action.type) {
		case "CHAT_MESSAGE_SUCCESS":
			return ({...state, messages: [action.payload, ...state.messages]});
		case "JOIN_GAME_SUCCESS":
			return (initialState);
		case "REQUEST_LEAVE_ROOM":
			return (initialState);
		default:
			return (state);
	}
}