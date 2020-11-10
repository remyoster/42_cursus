import React from 'react';
import { render } from '@testing-library/react';
import Loader from '../../components/Loader';

it('should render the Loader component', () => {
	const { container } = render(<Loader />);
  expect(container.querySelector("div.loader-component")).toBeInTheDocument();
});