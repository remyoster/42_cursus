import React from 'react';
import TransitionModal from '../components/TransitionModal';
import Loader from '../components/Loader';
import TransitionModalGameOver from '../components/TransitionModalGameOver';

/*
** display a transitionModal with startCounter
*/

export function displayCounterModal(startCounter) {
  if (startCounter) {
    return (<TransitionModal data={startCounter} />);
  }
}

/*
** Display a transitionModal with game over and score of the player
*/

export function displayGameOverModal(data) {
  return (<TransitionModalGameOver {...data} />);
}

/*
** Display the board by transforming the board object into an array of
** Paper (if cell is occuped) or simple div if cell is empty
*/

export function displayBoard(board) {
  const boardArray = Object.keys(board);
  return (boardArray.map((e) => {
    if (board[e].occuped)
      return (
        <div
          key={e}
          className="tetri-cell"
          style={{
            backgroundColor: board[e].color,
            borderColor: board[e].color
          }}
        />
      );
    else if (board[e].ghost)
      return (
        <div
          key={e}
          className="tetri-cell"
          style={{
            backgroundColor: board[e].color, opacity: 0.33,
            borderColor: board[e].color
          }}
        />
      );
    else
      return (<div key={e}></div>);
  }));
}

/*
** Display spectrum with the player's board
*/

export function displayGridSpectrum(board, full = false) {
  const boardArray = Object.keys(board);
  if (full)
    return (boardArray.map((cell) => {
      if (board[cell].occuped)
        return (
          <div
            key={`${cell}-spectrum`}
            className="tetri-cell"
            style={{ backgroundColor: board[cell].color,
              borderColor: board[cell].color }}
          />
        );
      return (<div key={`${cell}-spectrum`} />);
    }));
  const yMin = searchFirstOccupedLine(board);
  const regex = new RegExp(`,${yMin}$`);
  return (boardArray.map((cell) => {
    if (regex.test(cell))
      return (
        <div
          key={`${cell}-spectrum`}
          className='tetri-cell'
          style={{ backgroundColor: 'firebrick', borderColor: 'firebrick' }}
        />
      );
    return (<div key={`${cell}-spectrum`} />);
  }))
}

/*
** Search the first cell occuped in the board and return the y coordinate
*/

export function searchFirstOccupedLine(board) {
  let y = 19;
  let x = 0;
  while (y >= 0) {
    x = 0;
    while (x < 10) {
      if (board[`${x},${y}`].occuped)
        break;
      x++;
    }
    if (x === 10)
      return (y + 1);
    y--;
  }
  return (null);
}

/*
** Display each spectrum in a multiplayer game
*/

export function displaySpectrums(spectrums, full = false) {
  if (spectrums[0])
    return (
      <div className='spectrums-container'>
        {spectrums.map((spectrum, idx) => (
          <div key={`${spectrum}-${idx}`} className='spectrum-board'>
            <div className="spectrum-name retro-border">
              {spectrum.playerName}
              </div>
            <div className="spectrum-grid retro-border">
              {displayGridSpectrum(spectrum.spectrum, full)}
            </div>
          </div>
        ))}
      </div>
    );
}

/*
 ** Display the next playable tetri by parsing nextTetri and filling
 ** a 4*6 grid with some div(if the point is empty) or paper cell (if the point
 ** corresponding)
 */

export function displayNextTetri(nextTetri) {
  if (nextTetri) {
    let coord_idx;
    return (
      Array.from({ length: 8 }, (v, k) => {
        return { x: k % 4, y: parseInt(k / 4) }
      }).map(e => {
        coord_idx = nextTetri.shape.find(tet => tet.x === e.x && tet.y === e.y);
        if (coord_idx)
          return (
            <div
              className='tetri-cell'
              key={`nextTetri-cell-${e.x},${e.y}`}
              style={{ backgroundColor: nextTetri.color,
                borderColor: nextTetri.color }}
            />
          );
        return (<div key={`nextTetri-cell-${e.x},${e.y}`} />);
      }));
  }
}

export function displayLoader(isLoading) {
  if (isLoading)
    return (<Loader />);
}
