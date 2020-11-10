import { chatReducer as reducer, initialState } from '../../reducers/chatReducer';

it('should return the initial state', () => {
	expect(reducer(undefined, {})).toEqual(initialState);
});

it('should handle CHAT_MESSAGE_SUCCESS (send by serv)', () => {
	const payload = {playerName: 'roster', chat: 'Coucou'};
	expect(reducer(undefined, {type : "CHAT_MESSAGE_SUCCESS",  payload})).toEqual({
		...initialState,
		messages: [payload]
	});
})