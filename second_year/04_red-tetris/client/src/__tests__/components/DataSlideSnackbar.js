import React from 'react';
import { render, fireEvent } from '@testing-library/react';
import DataSlideSnackbar from '../../components/DataSlideSnackbar';

it('renders the DataSlideSnackbar component', () => {
	const data = 'A new player enter the room';
	const direction = 'down';
	const severity = 'error';
	let open = false;
	const setOpen = jest.fn();
	const { rerender, getByText, queryByText, getByTitle } = render(<DataSlideSnackbar open={open} />);
	expect(queryByText(data)).toBeNull();
	rerender(<DataSlideSnackbar open={true} direction={direction} 
		severity={severity} setOpen={setOpen} data={data} />);
	expect(getByText(data)).toBeInTheDocument();
	fireEvent.click(getByTitle("Close"));
	expect(setOpen.mock.calls.length).toBe(1);
	expect(setOpen).toHaveBeenCalledWith(false);
})