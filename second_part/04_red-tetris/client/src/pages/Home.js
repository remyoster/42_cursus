import React from "react";
import { connect } from "react-redux";
import { Redirect } from "react-router-dom";
import { requestDisconnect } from "../actions/socket";
import Menu from "../components/Menu";
import FormForName from "../components/FormForName";
import Loader from "../components/Loader";
import Fab from "@material-ui/core/Fab";
import ExitToAppIcon from '@material-ui/icons/ExitToApp';

function Home(props) {
  const { room, playerName, gameAvailable, isLoading, error, dispatch,
    marks } = props;


  /*
  ** Display the forms in function of playerName and room
  */

  function displayForms(room, playerName) {
    if (!playerName)
      return (<FormForName error={error} dispatch={dispatch} />);
    if (!room)
      return (<Menu dispatch={dispatch} gameAvailable={gameAvailable}
        marks={marks} />);
  }

  /*
  ** Display the disconnect header button
  */

  function displayDisconnectHeader(playerName, dispatch) {
    if (playerName)
      return (
        <div className='disconnect-header'>
          <Fab
            color="primary"
            variant="extended"
            onClick={() => dispatch(requestDisconnect())}
          >
            {playerName} <ExitToAppIcon />
          </Fab>
        </div>
      );
  }

  if (isLoading)
    return (<Loader />);
  else if (room && playerName)//UTILE ? 
    return (<Redirect to={`${room}[${playerName}]`} />);
  else
    return (
      <div className="home-page">
        {displayDisconnectHeader(playerName, dispatch)}
        <div className="home-form-container">
          {displayForms(room, playerName)}
          {isLoading && <Loader />}
        </div>
      </div>
    );

}

const mapStatetoProps = (state) => {
  return {
    isLoading: state.game.isLoading,
    room: state.game.room,
    playerName: state.game.playerName,
    gameAvailable: state.game.gameAvailable,
    error: state.game.error,
    marks: state.game.marks,
  };
}

export default connect(mapStatetoProps)(Home);
