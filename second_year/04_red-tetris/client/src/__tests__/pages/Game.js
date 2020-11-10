import React from 'react';
import { render, customRender, fireEvent } from '../../test-utils';
import Game from '../../pages/Game';
import { HashRouter } from 'react-router-dom';
import { initialState as gameState } from '../../reducers/gameReducer';
import { initialState as boardState } from '../../reducers/boardReducer';

it('renders Game page', () => {
	customRender(
		<HashRouter>
			<Game />
		</HashRouter>
		, { initialState : {
    game: {...gameState, playerName: 'roster', players: [{name: 'roster'}]},
    board: {...boardState}
		}});
});
