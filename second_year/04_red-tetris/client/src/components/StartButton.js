import React from 'react';
import Button from '@material-ui/core/Button';
import GamesIcon from '@material-ui/icons/Games';
import { requestStartGame } from "../actions/socket";

/*
** Start button of the game page. Trigger a start of the game when pressed.
*/

export default function StartButton({ room, dispatch, setSnackState }) {

  function handleStartGame() {
    setSnackState(false);
    dispatch(requestStartGame(room));
  }

  return (
    <Button
      style={{ width: '30%' }}
      variant="contained"
      color="primary"
      startIcon={<GamesIcon />}
      onClick={handleStartGame}
    >
      START
    </Button>
  );
}
