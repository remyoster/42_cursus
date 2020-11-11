import React from 'react';
import { customRender, render, fireEvent } from '../../test-utils';
import Menu, {
  GameChoice, MultiGameChoice, displayGameAvailable,
  displayLegends, gameOptionsToText
} from '../../components/Menu';
import { requestNewGame, requestJoinGame } from '../../actions/socket';

it('renders Menu component with basic state', () => {
  const dispatch = jest.fn();
  const marks={solo:[], multi:[]};
  const { container } = render(<Menu playerName='roster' gameAvailable={[]} 
    dispatch={dispatch} marks={marks}/>);
});

it('renders GameChoice component', () => {
  const choseType = jest.fn();
  const marks = {
    solo: [
      {
        pseudo: 'roster',
        score: {
          points: 42, line: 42, level: 42
        },
        options: {}
      }],
      multi: []
  }
  const { getByText, getAllByText } = render(<GameChoice choseType={choseType} marks={marks} />)
  expect(getByText('MULTIPLAYER')).toBeInTheDocument();
  expect(getAllByText('SOLO')).toHaveLength(2);
  fireEvent.click(getAllByText("SOLO")[0]);
  expect(choseType).toHaveBeenCalledWith("solo");
  fireEvent.click(getByText("MULTIPLAYER"));
  expect(choseType.mock.calls.length).toBe(2);
  expect(choseType).toHaveBeenCalledWith("multi");
});

it('renders MultiGameChoice component', () => {
  const gameAvailable = [{
    name: 'testgame',
    nbPlayers: 3,
    leader: 'roster',
    options: {}
  }];
  const dispatch = jest.fn();
  const setGameType = jest.fn();
  const playerName = 'roster';
  const { getByText } = render(<MultiGameChoice gameAvailable={gameAvailable}
    dispatch={dispatch} setGameType={setGameType} playerName={playerName} />);
  fireEvent.click(getByText('New'));
  expect(dispatch.mock.calls.length).toBe(1);
  expect(dispatch).toHaveBeenCalledWith(requestNewGame('multi'));
  fireEvent.click(getByText('Back'));
  expect(setGameType.mock.calls.length).toBe(1);
  expect(setGameType).toHaveBeenCalledWith(false);
  fireEvent.click(getByText("testgame [3/5]"));
  expect(dispatch.mock.calls.length).toBe(2);
  expect(dispatch).toHaveBeenCalledWith(requestJoinGame('testgame'));
});

it('displayGameAvailable function', () => {
  let gameAvailable = [];
  const joinGame = jest.fn();
  const { rerender, getByText } = render(displayGameAvailable(gameAvailable, joinGame));
  expect(getByText("There are no room already created : go create one !")).toBeInTheDocument();
  gameAvailable = [{
    name: 'testgame',
    nbPlayers: 3,
    leader: 'roster',
    options: {}
  }];
  rerender(displayGameAvailable(gameAvailable, joinGame));
  fireEvent.click(getByText("testgame [3/5]"));
  expect(joinGame.mock.calls.length).toBe(1);
  expect(joinGame).toHaveBeenCalledWith('testgame');
});

it('displayLegends function', () => {
  const { container } = render(displayLegends());
  expect(container.querySelectorAll("div.option-value")).toHaveLength(5);
});

it('gameOptionsToText function', () => {
  const options = {
    ghostMode: true,
    fullSpectrum: false,
    startingLevel: 42,
    dropTimeRef: 1000
  };
  const { container } = render(gameOptionsToText(options));
  expect(container.querySelectorAll("div.option-value")).toHaveLength(4);
});