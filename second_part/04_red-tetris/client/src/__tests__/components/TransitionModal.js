import React from 'react';
import { render } from '@testing-library/react';
import TransitionModal from '../../components/TransitionModal';

it('should render a transition modal', () => {
	const { getByText } = render(<TransitionModal data='test' />);
  expect(getByText('test')).toBeInTheDocument();
});