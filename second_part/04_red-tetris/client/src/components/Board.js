import React, { useEffect, useState, useRef } from "react";
import { Typography, Button, List, ListItem, ListItemText, Divider } from "@material-ui/core";
import { connect } from "react-redux";
import {
  offsetPiece, toggleRotationOffset, toggleHardDrop, toggleSimpleOffset,
  toggleGhost
} from "../utils/tetrimino";
import {
  isBoardFillable, fillBoard, checkAndPopCompleteLine
} from "../utils/board";
import {
  displayCounterModal, displayGameOverModal, displayBoard,
  displaySpectrums, displayNextTetri
} from '../utils/display';
import {
  displayScoreLevel, displayScoreLine, displayScorePoints,
} from "../utils/scoring";
import {
  requestNewPiece, updateSpectrum,
  addPenaltyLines, requestGameOver, requestLeaveRoom
} from "../actions/socket";
import {
  moveTetri, lockBoard, unlockBoard, updateBoard, updateScore, updateStartCounter,
  updateGhost
} from "../actions/board";
import ChatRoom from './ChatRoom';
import * as keyboardIcon from '../img/keyboard';
import PauseIcon from '@material-ui/icons/Pause';
import PlayArrowIcon from '@material-ui/icons/PlayArrow';
import ExitToAppIcon from '@material-ui/icons/ExitToApp';

/*
** Board component is the playable game. It creates the board (obj of coordinates)
** display it, get tetrimino from the serv via socket and display them on
** the previous grid and on the board. Then it's tetris with SRS,
** wall-kicks, hard-drop, counter clockwise rotation.
** dropTime is the gravity moment, t0 the time where the gravity moment is
** applied, lock a boolean to lock the tetri, downMove is a counter of soft and
** hard drop (for score) and lastKey is the lastKey press if lock is on.
** StartCounter toggle the pre-start moment
*/

function Board(props) {
  const { tetri, nextTetri, board, room, playerName, isLeader, gameType, locked,
    spectrums, options, ghostShape, dispatch, isOver, result, score,
    startCounter, nbPlayers } = props;
  const [paused, setPaused] = useState({ text: "PAUSE", state: false });
  const dropTime = useRef(options.dropTimeRef);
  const t0 = useRef(Date.now());
  const lock = useRef(false);
  const downMove = useRef({ soft: 0, hard: 0 });
  const lastKey = useRef(null);

  /*
  ** Start the game with the startCounter interval by unlocking it
  */

  useEffect(() => {
    let intervalId = null;
    if (startCounter > 0) {
      intervalId = setInterval(() => {
        dispatch(updateStartCounter())
      }, 1000);
    }
    if (startCounter === 0) {
      dispatch(unlockBoard());
    }
    return (() => {
      if (intervalId)
        clearInterval(intervalId);
    });
  }, [startCounter, dispatch]);

  /*
  ** Unlock the tetrimino whenever it changes (avoid weird behavior when
  ** moving a piece manually + gravity move)
  */

  useEffect(() => {
    if (!locked)
      lock.current = false;
  }, [locked, dispatch, board, tetri]);

  /*
  ** Center the tetri when it pops on the board and reset downMove counter.
  ** If there is no space to place it, the game is over !
  */

  useEffect(() => {
    if (tetri && !tetri.init && !locked) {
      let coords_x = tetri.shape.map((e) => e.x);
      let xMax = Math.max(...coords_x) === 1 ? 1 : 0;
      let newShape = offsetPiece(tetri.shape, { x: 3 + xMax, y: 0 });
      if (isBoardFillable(board, null, newShape)) {
        let tmpBoard = fillBoard(board, null, newShape, tetri.color);
        lock.current = true;
        lastKey.current = null;
        downMove.current = { soft: 0, hard: 0 };
        dispatch(moveTetri({
          tetri: { ...tetri, shape: newShape, init: true },
          board: tmpBoard,
        }));
      } else {
        dispatch(requestGameOver(score));
      }
    }
  }, [tetri, locked, board, dispatch, score]);

  /*
  ** Toggle the gravity during the  It move the piece from 1y down at the
  ** dropTime timeout and actualize the moment it does it (t0).
  ** If it can't move the piece it locks the  It reset the dropTime at
  ** the frame rate of the current level.
  */

  useEffect(() => {
    function gravity() {
      if (tetri && tetri.init && !locked && !lock.current) {
        let newShape = offsetPiece(tetri.shape, { x: 0, y: 1 });
        if (isBoardFillable(board, tetri.shape, newShape)) {
          lock.current = true;
          let tmpBoard = fillBoard(board, tetri.shape, newShape, tetri.color);
          dispatch(moveTetri({
            tetri: { ...tetri, shape: newShape },
            board: tmpBoard,
          }));
          t0.current = Date.now();
        }
        else {
          dispatch(lockBoard());
          lock.current = true;
        }
        dropTime.current = gravityDispatcher(options.dropTimeRef, score.level);
      }
    }
    let intervalId = setTimeout(gravity, dropTime.current);
    return () => {
      clearTimeout(intervalId);
    };
  }, [score.level, paused, tetri, locked, board, options.dropTimeRef, dispatch]);

  /*
  ** Key event function. If the key move the tetri, the lock ref is set to true
  ** to avoid weird behavior when waiting for component rerender. If a key is
  ** pressed during the gravity moment, the lastKey ref is set to fire the event
  ** when gravity is done.
  ** Also if the board change, it calculates the time spended since the previous
  ** gravity moment (=dropTime) and actualize it.
  ** Key codes (ubuntu qwerty americain US):
  ** 38 = up arrow / 39 = right arrow / 37 = left arrow / 40 = down arrow
  ** 90 = z / 32 = space bar
  */

  useEffect(() => {
    function listenKey(e) {
      if (e.target === document.body && tetri && tetri.init && !locked
        && !lock.current) {
        let action;
        let key = e.keyCode;
        //console.log(key);
        if (key === 38 || key === 90) {
          action = toggleRotationOffset(key, tetri, board);
        }
        else if (key === 32) {
          action = toggleHardDrop(tetri, board);
          downMove.current.hard = action.dropedLines || 0;
        }
        else {
          action = toggleSimpleOffset(key, tetri, board);
          downMove.current.soft += action && key === 40 ? 1 : 0;
        }
        if (!action && key === 40) {
          action = { type: "LOCK" };
        }
        if (action) {
          dispatch(action);
          dropTime.current -= Date.now() - t0.current;
          lock.current = action.type ? true : false;
        }
      }
      else if (lock.current)
        lastKey.current = e.keyCode;
    }
    document.body.addEventListener("keyup", listenKey);
    return () => {
      document.body.removeEventListener("keyup", listenKey);
    };
  }, [tetri, locked, board, dispatch]);


  /*
  ** Update ghost based on tetri's moves
  */

  useEffect(() => {
    if (options.ghostMode && tetri && tetri.init) {
      let action = toggleGhost(ghostShape, tetri, board);
      let diffs = action.ghostShape.filter(e =>
        ((ghostShape || []).findIndex(f =>
          (f.x === e.x && f.y === e.y)) > -1) ? false : true);
      if (diffs.length)
        dispatch(updateGhost(action));
    }
  }, [tetri, board, ghostShape, options.ghostMode, dispatch])

  /*
   ** Fire the keyboard event if lastKey is set (cf listenKey function) and
   ** reset it to null
   */

  useEffect(() => {
    if (lastKey.current && tetri.init && !locked) {
      document.body.dispatchEvent(
        new KeyboardEvent("keyup", { keyCode: lastKey.current })
      );
      lastKey.current = null;
    }
  }, [tetri, locked]);

  /*
   ** Toggle the complete line effect. Whenever a tetri can't move anymore the
   ** game will be locked and this event is fired. It toggle the board with
   ** the checkAndPopCompleteLine function and actualize the score and level if
   ** needed. Then it requests a new piece and update spectrums if multi
   */

  useEffect(() => {
    if (locked && lock.current) {
      let { tmpBoard, fullLine } = checkAndPopCompleteLine(board, tetri);
      if (tmpBoard) {
        dispatch(updateBoard({ board: tmpBoard }));
        let penaltyLines = fullLine - 1;
        if (gameType === 'multi' && penaltyLines > 0)
          dispatch(addPenaltyLines({ room, penaltyLines }));
      }
      else {
        dispatch(requestNewPiece({ room, playerName }));
        if (gameType === 'multi')
          dispatch(updateSpectrum({ room, board, playerName }));
      }
      dispatch(updateScore(fullLine, downMove.current));
    }
  }, [playerName, room, gameType, locked, board, dispatch, tetri]);

  /*
  ** To stop the game when you're the last player : you win !
  */

  useEffect(() => {
    if (gameType === 'multi' && isOver && !locked) {
      dispatch(requestGameOver(score));
    }
  }, [isOver, locked, dispatch, score, gameType])

  /*
   ** Put the in "pause" by setting lock ref to true. Or unpause the game
   ** by setting lock ref to false and reseting lastKey ref
   */

  function pauseGame() {
    if (paused.state) {
      lock.current = false;
      lastKey.current = null;
      setPaused({ text: "PAUSE", state: false });
    } else {
      lock.current = true;
      setPaused({ text: "RESUME", state: true });
    }
  }

  function quitGame() {
    dispatch(requestLeaveRoom());
  }

  return (
    <div className="game-container">

      <div className="flex-column-container left-game-container">

        <div className="dark-backGround retro-border">
          <Typography align='center' variant="h5" component='h5'>
            Controls :
          </Typography>
          <Divider style={{ backgroundColor: 'white', alignSelf: 'normal' }} />
          <List>
            <ListItem>
              <img src={keyboardIcon.cursorUp} className='keyboard-icon' alt='up key' />
              <ListItemText primary='clockwise rotation' />
            </ListItem>
            <ListItem><img src={keyboardIcon.z} className='keyboard-icon' alt='z key' />
              <ListItemText primary='counter clockwise rotation' />
            </ListItem>
            <ListItem>
              <img src={keyboardIcon.cursorLeft} className='keyboard-icon' alt='left key' />
              <img src={keyboardIcon.cursorRight} className='keyboard-icon' alt='right key' />
              <img src={keyboardIcon.cursorDown} className='keyboard-icon' alt='down key' />
              <ListItemText primary='move' />
            </ListItem>
            <ListItem>
              <img src={keyboardIcon.spacebar} className='keyboard-icon-large' alt='spacebar' />
              <ListItemText primary='fall towards the pile' />
            </ListItem>
          </List>
        </div>

        <div className='buttons-container'>
          {gameType === 'solo' && <><Button onClick={pauseGame} variant="contained" color="primary"
            startIcon={paused.state ? <PlayArrowIcon /> : <PauseIcon />}>
            {paused.text}
          </Button></>}
          <Button onClick={quitGame} variant='contained' color='primary'
            startIcon={<ExitToAppIcon />}>
            Quit
          </Button>
        </div>

        {gameType === 'multi' && displaySpectrums(spectrums, options.fullSpectrum)}

      </div>

      <div className="board center-game-container">

        <div className="flex-container upper-board-container retro-border">

          <div className="line-counter-container">
            <Typography variant="h5">Line</Typography>
            <Typography variant="h5">{displayScoreLine(score.line)}</Typography>
          </div>

          <div className="next-tetri-container flex-container">
            <div className="align-self-center">
              <Typography variant="h5">NEXT</Typography>
            </div>
            <div className='center-container'>
              <div className="tetrimino-container">
                {displayNextTetri(nextTetri)}
              </div>
            </div>
          </div>

        </div>

        <div className="board-container retro-border">
          {displayBoard(board)}
        </div>

      </div>

      <div className='right-game-container'>

        <div className="score-container retro-border">
          <Typography variant="h5">Score</Typography>
          <Typography variant="h5">{displayScorePoints(score.points)}</Typography>
        </div>

        <div className="score-container retro-border">
          <Typography variant="h5">Level</Typography>
          <Typography variant="h5">{displayScoreLevel(score.level)}</Typography>
        </div>

      </div>
      {gameType === 'multi' &&
        <div className='retro-border dark-backGround board-chatroom'>
          <ChatRoom />
        </div>}
      {displayCounterModal(startCounter)}
      {isOver && displayGameOverModal({score, result, isLeader, gameType,
        dispatch, nbPlayers, room
      })}
    </div >
  );
}

/*
 ** Return the current dropTime of the level. Based on NES release it applies a
 ** cross product on the frame rate table (frames) and our dropTimeRef (1s)
 */

export function gravityDispatcher(dropTimeRef, level) {
  const frames = [
    48, 43, 38, 33, 28, 23, 18, 13, 8, 6, 5, 5, 5, 4, 4, 4, 3, 3,
    3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  ];
  return (((frames[level] || 1) * dropTimeRef) / frames[0]);
}

const mapStatetoProps = (state) => {
  return {
    board: state.board.board,
    tetri: state.board.tetri,
    ghostShape: state.board.ghostShape,
    nextTetri: state.board.nextTetri,
    spectrums: state.board.spectrums,
    locked: state.board.locked,
    score: state.board.score,
    startCounter: state.board.startCounter,
    options: state.game.options,
    room: state.game.room,
    playerName: state.game.playerName,
    gameType: state.game.type,
    isOver: state.board.isOver,
    result: state.board.result,
  };
}

export default connect(mapStatetoProps)(Board);
