import React from 'react';
import { render, fireEvent } from '../../test-utils';
import { requestStartGame } from '../../actions/socket';
import StartButton from '../../components/StartButton';

it('render StartButton component', () => {
	const dispatch = jest.fn();
	const setSnackState = jest.fn();
	const data = {
		room: 'testroom',
		dispatch,
		setSnackState
	};
	const { getByText } = render(<StartButton {...data} />);
	expect(getByText('START')).toBeInTheDocument();
	fireEvent.click(getByText('START'));
	expect(dispatch.mock.calls.length).toBe(1);
	expect(dispatch).toHaveBeenCalledWith(requestStartGame(data.room));
});