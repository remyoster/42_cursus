import React from 'react';
import { render } from '@testing-library/react';
import GameHeader from '../../components/GameHeader';

it('renders GameHeader component with basic state', () => {
  const room = 'test';
  const players = [{name: 'roster'}, {name: 'madufour'}];
  const dispatch = jest.fn();
  const { container } = render(
    <GameHeader room={room} players={players} dispatch={dispatch} gameType='solo' />
      );
});
