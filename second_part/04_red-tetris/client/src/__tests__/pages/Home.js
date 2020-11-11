import React from 'react';
import { render, customRender, fireEvent } from '../../test-utils';
import Home from '../../pages/Home';
import { initialState as gameState } from '../../reducers/gameReducer';
import { initialState as boardState } from '../../reducers/boardReducer';

it('renders Home page', () => {
	customRender(<Home />);
});
