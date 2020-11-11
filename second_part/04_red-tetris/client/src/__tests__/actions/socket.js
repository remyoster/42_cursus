import * as actions from '../../actions/socket';

it('should send a REQUEST_LIST_GAME socket event to serv', () => {
    const expectedAction = {
        type: "REQUEST_LIST_GAME",
    };
    expect(actions.requestListGame()).toEqual(expectedAction);
});

it('should send a REQUEST_CONNECT socket event to serv', () => {
    const name = 'roster-madufour';
    const expectedAction = {
        type: "REQUEST_CONNECT",
        payload: name
    };
    expect(actions.requestConnect(name)).toEqual(expectedAction);
});


it('should send a REQUEST_NEW_GAME socket event to serv', () => {
    const name = 'roster-madufour';
    const expectedAction = {
        type: "REQUEST_NEW_GAME",
        payload: name
    };
    expect(actions.requestNewGame(name)).toEqual(expectedAction);
});

it('should send a REQUEST_JOIN_GAME socket event to serv', () => {
    const name = 'roster-madufour';
    const expectedAction = {
        type: "REQUEST_JOIN_GAME",
        payload: name
    };
    expect(actions.requestJoinGame(name)).toEqual(expectedAction);
});

it('should send a REQUEST_CHANGE_OPTION socket event to serv', () => {
    const name = 'roster-madufour';
    const expectedAction = {
        type: "REQUEST_CHANGE_OPTION",
        payload: name
    };
    expect(actions.requestChangeOption(name)).toEqual(expectedAction);
});

it('should send a REQUEST_START_GAME socket event to serv', () => {
    const name = 'roster-madufour';
    const expectedAction = {
        type: "REQUEST_START_GAME",
        payload: name
    };
    expect(actions.requestStartGame(name)).toEqual(expectedAction);
});

it('should send a REQUEST_LEAVE_ROOM socket event to serv', () => {
    const expectedAction = {
        type: "REQUEST_LEAVE_ROOM",
    };
    expect(actions.requestLeaveRoom()).toEqual(expectedAction);
});

it('should send a REQUEST_NEW_PIECE socket event to serv', () => {
    const name = 'roster-madufour';
    const expectedAction = {
        type: "REQUEST_NEW_PIECE",
        payload: name
    };
    expect(actions.requestNewPiece(name)).toEqual(expectedAction);
});

it('should send a UPDATE_SPECTRUM socket event to serv', () => {
    const name = 'roster-madufour';
    const expectedAction = {
        type: "UPDATE_SPECTRUM",
        payload: name
    };
    expect(actions.updateSpectrum(name)).toEqual(expectedAction);
});

it('should send a ADD_PENALTY_LINES socket event to serv', () => {
    const name = 'roster-madufour';
    const expectedAction = {
        type: "ADD_PENALTY_LINES",
        payload: name
    };
    expect(actions.addPenaltyLines(name)).toEqual(expectedAction);
});

it('should send a ERROR socket event to serv', () => {
    const name = 'roster-madufour';
    const expectedAction = {
        type: "ERROR",
        payload: name
    };
    expect(actions.actionError(name)).toEqual(expectedAction);
});

it('should send a REMOVE_ERROR socket event to serv ', () => {
    const expectedAction = {
        type: "REMOVE_ERROR",
    };
    expect(actions.removeError()).toEqual(expectedAction);
});

it('should send a REQUEST_CHECK_RELOAD socket event to serv', () => {
    const name = 'roster-madufour';
    const expectedAction = {
        type: "REQUEST_CHECK_RELOAD",
        payload: name
    };
    expect(actions.requestCheckReload(name)).toEqual(expectedAction);
});

it('should send a REQUEST_DISCONNECT socket event to serv', () => {
    const expectedAction = {
        type: "REQUEST_DISCONNECT",
    };
    expect(actions.requestDisconnect()).toEqual(expectedAction);
});

it('should send a REQUEST_GAME_OVER socket event to serv', () => {
    const name = 'roster-madufour';
    const expectedAction = {
        type: "REQUEST_GAME_OVER",
        payload: name
    };
    expect(actions.requestGameOver(name)).toEqual(expectedAction);
});

it('should send a REQUEST_BACK_TO_OPTION socket event to serv', () => {
    const expectedAction = {
        type: "REQUEST_BACK_TO_OPTION",
    };
    expect(actions.requestBackToOption()).toEqual(expectedAction);
});

it('should send a REQUEST_QUIT_GAME socket event to serv', () => {
    const expectedAction = {
        type: "REQUEST_QUIT_GAME",
    };
    expect(actions.requestQuitGame()).toEqual(expectedAction);
});

it('should send a REQUEST_CHAT_MESSAGE socket event to serv', () => {
    const chat = 'roster-madufour';
    const expectedAction = {
        type: "REQUEST_CHAT_MESSAGE",
        payload: chat
    };
    expect(actions.requestChatMessage(chat)).toEqual(expectedAction);
});