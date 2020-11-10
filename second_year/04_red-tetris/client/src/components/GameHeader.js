import React from "react";
import { Button, Typography, Divider } from "@material-ui/core";
import { requestLeaveRoom } from "../actions/socket";
import PeopleAltIcon from '@material-ui/icons/PeopleAlt';
import ArrowBack from '@material-ui/icons/ArrowBack';

/*
** Header component of the game page. Displays the room name and players (if
** multi)
*/

export default function GameHeader({ room, players, dispatch, gameType }) {

  function handleBackToHome() {
    dispatch(requestLeaveRoom());
  }

  return (
    <div className='flex-container'>
      <div className='dark-backGround retro-border room-container'>
        <Typography variant='h4' component='h4'>Room</Typography>
        <Divider style={{ backgroundColor: 'white', alignSelf: 'normal' }} />
        <Typography variant='h5' component='h5' style={{ margin: '5px 0' }}>
          {room}
        </Typography>
        <Button
          variant="contained"
          color="primary"
          onClick={handleBackToHome}
          size="small"
          startIcon={<ArrowBack />}
        >
          Leave room
      </Button>
      </div>
      { gameType === 'multi' && displayPlayers(players)}
    </div>
  );
}

/*
** Display all the players of the room and add an icon on the leader
*/

export function displayPlayers(players) {
    return (
      <div className=' dark-backGround retro-border room-container'>
        <Typography variant='h4' component='h4'>Players</Typography>
        <Divider style={{ backgroundColor: 'white', alignSelf: 'normal' }} />
        <ul className='players-list'>
          {players.map(e => {
            if (e.leader)
              return (
                <li key={e.name} className='flex-container'>
                  <PeopleAltIcon />
                  <Typography variant='body1' component='span'>
                    {e.name}
                  </Typography>
                </li>
              );
            return (
              <li key={e.name}>
                <Typography variant='body1' component='p'>
                  {e.name}
                </Typography>
              </li>
            );
          })}
        </ul>
      </div>
    );
}