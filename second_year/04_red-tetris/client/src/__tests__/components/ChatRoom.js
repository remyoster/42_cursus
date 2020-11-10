import React from 'react';
import { customRender,  render } from '../../test-utils';
import ChatRoom, { displayMessages } from '../../components/ChatRoom';
import { initialState as gameState } from '../../reducers/gameReducer';
import { initialState as chatState } from '../../reducers/chatReducer';

it('renders chatRoom component', () => {
	const playerName = 'roster';
	const room = 'test';
	const { container } = customRender(<ChatRoom />, { initialState : {
		game : {...gameState, playerName, room},
		chat: chatState
	}});
})

it('displayMessages function', () => {
	const messages = [
		{playerName: 'roster', chat: 'Coucou'},
		{playerName: 'madufour', chat:'Hello'}
	];
	const playerName = 'roster';
	const { container, getByText } = render(displayMessages(messages, playerName));
	expect(container.querySelectorAll("div.right-chat")).toHaveLength(1);
	expect(container.querySelectorAll("div.left-chat")).toHaveLength(1);
	expect(getByText('Coucou')).toBeInTheDocument();
	expect(getByText('Hello')).toBeInTheDocument();
})