import { gameReducer as reducer, initialState } from '../../reducers/gameReducer';

it('should return the initial state', () => {
	expect(reducer(undefined, {})).toEqual(initialState);
});

it('shoud handle REQUEST_LIST_GAME', () => {
	expect(reducer(undefined, { type: "REQUEST_LIST_GAME" }))
		.toEqual(initialState);
});

it('should hande REQUEST_CONNECT', () => {
	expect(reducer(undefined, { type: "REQUEST_CONNECT" }))
		.toEqual(initialState);
});

it('shoud handle REQUEST_JOIN_GAME', () => {
	expect(reducer(undefined, { type: "REQUEST_JOIN_GAME" }))
		.toEqual(initialState);
});

it('shoud handle REQUEST_START_GAME', () => {
	expect(reducer(undefined, { type: "REQUEST_START_GAME" }))
		.toEqual(initialState);
});

it('shoud handle REQUEST_CHECK_RELOAD', () => {
	expect(reducer(initialState, { type: "REQUEST_CHECK_RELOAD" }))
		.toEqual(initialState);
});

it('should handle LIST_GAME_SUCCESS (from serv)', () => {
	const payload = ['room1', 'room2'];
	expect(reducer(undefined, { type: "LIST_GAME_SUCCESS", payload })).toEqual({
		...initialState,
		gameAvailable: payload,
	});
});

it('should handle CONNECT_SUCCESS (from serv)', () => {
	const playerName = 'roster';
	const id = "test_id"
	expect(reducer(undefined, { type: "CONNECT_SUCCESS", payload: { name: playerName, id } })).toEqual({
		...initialState,
		playerName,
		id,
		isLoading: false,
		error: null
	});
});

it('should handle CREATE_GAME_SUCCESS', () => {
	const payload = {
		type: 'multi',
		players: ['roster,', 'madufour'],
		room: 'testroom',
		options: initialState.options,
	};
	expect(reducer(undefined, { type: "CREATE_GAME_SUCCESS", payload })).toEqual({
		...initialState,
		...payload,
		isLoading: false
	});
	expect(reducer(undefined, {
		type: "CREATE_GAME_SUCCESS",
		payload: { ...payload, type: 'solo' }
	})).toEqual({
		...initialState,
		...payload,
		type: 'solo',
		isLoading: false
	});
});

it('should handle JOIN_GAME_SUCCESS', () => {
	const payload = {
		type: 'solo',
		players: ['roster'],
		room: 'testroom',
		options: initialState.options,
	};
	expect(reducer(undefined, { type: "JOIN_GAME_SUCCESS", payload })).toEqual({
		...initialState,
		...payload,
		isLoading: false
	});
});

it('should handle CHANGE_OPTION_SUCCESS', () => {
	const payload = 'test';
	expect(reducer(undefined, { type: "CHANGE_OPTION_SUCCESS", payload })).toEqual({
		...initialState,
		options: 'test'
	});
});

it('should handle LEAVE_ROOM_SUCCESS', () => {
	const payload = 'test';
	expect(reducer({ ...initialState, playerName: payload }, { type: "LEAVE_ROOM_SUCCESS", payload })).toEqual({
		...initialState,
		playerName: 'test'
	});
});

it('should handle UPDATE_PLAYERS_SUCCESS (from serv)', () => {
	const payload = ['roster', 'madufour'];
	expect(reducer(undefined, { type: "UPDATE_PLAYERS_SUCCESS", payload })).toEqual({
		...initialState,
		players: payload
	})
});

it('should handle EXIT', () => {
	expect(reducer(undefined, { type: "EXIT" })).toEqual({
		...initialState,
		isLoading: false
	});
});

it('should handle ERROR', () => {
	const payload = 'error';
	expect(reducer(initialState, { type: "ERROR", payload })).toEqual({
		...initialState,
		error: payload,
		isLoading: false
	});
});

it('should handle REMOVE_ERROR', () => {
	expect(reducer(initialState, { type: "REMOVE_ERROR" })).toEqual({
		...initialState,
		error: null,
	});
});