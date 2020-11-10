import React from 'react';
import { render, fireEvent } from '@testing-library/react';
import TransitionModalGameOver from '../../components/TransitionModalGameOver';
import {
    requestStartGame, requestBackToOption
} from "../../actions/socket";

it('should render a transition modal', () => {
	const dispatch = jest.fn();
	let data = { score : {points:42, line: 2, level: 0}, result: {
		winner: 'roster',
		points: '745',
		level: 2,
		line: 48,
	},
	isLeader: true,
	dispatch,
	gameType: 'multi',
	nbPlayers: 2,
	room: 'testroom'

};
const { getByText, rerender } = render(<TransitionModalGameOver {...data} />);
  expect(getByText(/roster/)).toBeInTheDocument();
  expect(getByText(/745/)).toBeInTheDocument();
	expect(getByText(/48/)).toBeInTheDocument();
	fireEvent.click(getByText("Restart"));
	expect(dispatch.mock.calls.length).toBe(1);
	expect(dispatch).toHaveBeenCalledWith(requestStartGame('testroom'));
	fireEvent.click(getByText("Back to options"));
	expect(dispatch.mock.calls.length).toBe(2);
	expect(dispatch).toHaveBeenCalledWith(requestBackToOption());
	data.result = null;
	rerender(<TransitionModalGameOver {...data} />);
	expect(getByText("Wait for the end of game")).toBeInTheDocument();
});