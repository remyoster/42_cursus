import React from 'react';
import FormForName from '../../components/FormForName';
import { render, fireEvent } from '@testing-library/react';
import { requestConnect } from "../../actions/socket";

it('renders FormForName component with basic state', () => {
  const dispatch = jest.fn();
  const error = 'This name is already taken';
  const { rerender, container, getByText } = render(<FormForName dispatch={dispatch} />);
  fireEvent.click(getByText("Enter"));
  fireEvent.change(container.querySelector('input'), { target: { value: 'roster' } });
  fireEvent.click(getByText("Enter"));
  expect(dispatch.mock.calls.length).toBe(1);
  expect(dispatch).toHaveBeenCalledWith(requestConnect('roster'));
  rerender(<FormForName dispatch={dispatch} error={error} />);
  expect(getByText(error)).toBeInTheDocument();
});
