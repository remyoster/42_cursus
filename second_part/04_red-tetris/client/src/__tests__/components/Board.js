import React from 'react';
import { render, customRender, fireEvent } from '../../test-utils';
import Board, { gravityDispatcher } from '../../components/Board';
import { createBoard } from '../../utils/board';
import { initialState as gameState } from '../../reducers/gameReducer';
import { initialState as boardState } from '../../reducers/boardReducer';

it('renders Board component with basic state', () => {
  const board = createBoard(10, 20);
  const { container } = customRender(<Board />, { initialState : {
    game: {...gameState},
    board: {...boardState, board}
  }});
});

it('gravityDispatcher function', () => {
  expect(gravityDispatcher(1000, 0)).toBe(1000);
  expect(gravityDispatcher(48, 40)).toBe(1);
});