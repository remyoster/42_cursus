import React, { useEffect, useMemo, useRef, useState } from "react";
import { connect } from "react-redux";
import { Redirect } from "react-router-dom";
import { Button, Divider } from "@material-ui/core";
import { checkHashUrl } from "../utils/hashUrl";
import Loader from '../components/Loader';
import Board from "../components/Board";
import OptionsForm from "../components/OptionsForm";
import DataSlideSnackbar from '../components/DataSlideSnackbar';
import ChatRoom from "../components/ChatRoom";
import GameHeader from '../components/GameHeader';
import StartButton from '../components/StartButton';

function Game(props) {
  const { gameType, playerName, players, room, board, isLoading,
    dispatch } = props;
  const [snackState, setSnackState] = useState({ open: false });
  const nbPlayers = useRef(players.length);
  const isLeader = useMemo(() =>
    findLeader(playerName, players, gameType), [gameType, playerName, players]);

  /*
  ** Toggle the snackbar if players change
  */

  useEffect(() => {
    if (players.length && nbPlayers.current 
        && players.length !== nbPlayers.current) {
      if (players.length > nbPlayers.current)
        setSnackState({ open: true, data: "A new player join the room" });
      else
        setSnackState({ open: true, data: "A player quit the room" });
      nbPlayers.current = players.length;
    }
    else if (players.length && !nbPlayers.current)
      nbPlayers.current = players.length;
  }, [players])

  /*
  ** Display the ready button 
  */

  function displayReady() {
    if ((gameType === 'solo' || nbPlayers.current > 1) && isLeader)
      return (
        <StartButton room={room} gameType={gameType} dispatch={dispatch} 
          setSnackState={setSnackState}/>
      );
    const waitingText = !isLeader ? 'Please wait before the game start'
      : ' You must wait at least one more player to start the game';
    return (
      <Button variant='contained' color='primary' style={{ color: 'white' }}
        disabled>
        {waitingText}
      </Button>
    );
  }

  function displaySnackBar() {
    return (<DataSlideSnackbar data={snackState.data}
      open={typeof (snackState) === 'boolean' ? snackState : snackState.open}
      setOpen={setSnackState} />);
  }

  if (isLoading)
    return (<Loader />);
  else if ((room && !checkHashUrl(room, playerName)) || !room)
    return (<Redirect to="/" hashType="noslash" />);
  else if (board) {
    return (
      <>
        <Board isLeader={isLeader} nbPlayers={nbPlayers.current} />
        {displaySnackBar()}
      </>
    );
  }
  else
    return (
      <div className='game-page'>

        <GameHeader room={room} players={players} dispatch={dispatch}
          gameType={gameType} />

        <div className='flex-container-center'>

          <div className='left-gamePage-container retro-border dark-backGround'>
            <OptionsForm leader={isLeader} />
            <Divider style={{ backgroundColor: 'white', margin: '10px 0' }} />
            <div className='ready-container'>
              {displayReady()}
            </div>
          </div>

          {gameType === 'multi' &&
            <div className='right-gamePage-container retro-border dark-backGround'>
              <ChatRoom />
            </div>}
        </div>
        {displaySnackBar()}
      </div>
    );
}

/*
** Find the leader if the players array if gameType is not solo. Then return
** boolean if the actual player is the leader
*/
export function findLeader(playerName, players, gameType) {
  if (playerName && players.length && gameType)
    return (gameType === 'solo' ? true
      : playerName === players.find((e) => e.leader).name)
}

const mapStatetoProps = (state) => {
  return {
    room: state.game.room,
    playerName: state.game.playerName,
    isLoading: state.game.isLoading,
    players: state.game.players,
    gameType: state.game.type,
    board: state.board.board,
  };
}

export default connect(mapStatetoProps)(Game);
