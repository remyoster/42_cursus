import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import { Modal, Button, Typography } from '@material-ui/core';
import {
    requestStartGame, requestBackToOption, requestLeaveRoom
} from "../actions/socket";
import ReplayIcon from '@material-ui/icons/Replay';
import ArrowBack from '@material-ui/icons/ArrowBack';
import ExitToAppIcon from '@material-ui/icons/ExitToApp';

const useStyles = makeStyles({
    modal: {
        display: 'flex',
        alignItems: 'center',
        justifyContent: 'center',
    },
    body: {
        color: 'white',
        textAlign: 'center',
        backgroundColor: 'black',
        padding: '30px'
    },
    button: {
        margin: '10px'
    }
});

/*
** Display the gameOver modal at the end of the game. Then toggles restart game,
** display winner (if multi) and go back to options
*/

export default function TransitionModalGameOver(props) {
    const classes = useStyles();
    const { score, result, isLeader, gameType, nbPlayers, room,
        dispatch } = props;

    function restartSameGame() {
        dispatch(requestStartGame(room));
    }
    function backToOptions() {
        dispatch(requestBackToOption());
    }
    function leaveRoom() {
        dispatch(requestLeaveRoom());
    }
    function displayMultiWinner(gameType, result) {
        if (gameType === 'multi' && result)
            return (
                <div className='winner-scoring'>
                    <Typography component='p'>
                        Winner : {result.winner}
                    </Typography>
                    <Typography component='p'>
                        Points : {result.points} / Level : {result.level} / Line : {result.line}
                    </Typography>
                </div>
            );
    }

    function displayEndActions(gameType, isLeader, result) {
        if (gameType === 'solo' || (isLeader && result))
            return (
                <>
                    {(gameType === 'solo' || nbPlayers > 1) &&
                        <Button className={classes.button}
                            onClick={restartSameGame}
                            variant="contained" color="primary"
                            startIcon={<ReplayIcon />}>
                            Restart
                    </Button>}
                    <Button
                        onClick={backToOptions}
                        variant="contained" color="primary"
                        startIcon={<ArrowBack />}>
                        Back to options
                    </Button>
                </>
            );
        else if (!result) {
            return (
                <Typography component='p'>
                    Wait for the end of game
                </Typography>
            );
        }
        else
            return (
                <Typography component='p'>
                    Wait the leader's choice
                </Typography>
            );
    }

    return (
        <Modal
            className={classes.modal}
            open={true}
            disableBackdropClick
        >
            <div className={classes.body}>
                <Typography variant='h2' component='h2'>Game Over</Typography>
                <div className='personnal-scoring'>
                    <Typography variant='body1' component='p'>
                        Points: {score.points}
                    </Typography>
                    <Typography variant='body1' component='p'>
                        Level : {score.level}
                    </Typography>
                    <Typography variant='body1' component='p'>
                        Lines : {score.line}
                    </Typography>
                </div>
                {displayMultiWinner(gameType, result)}
                <div className='end-actions-container flex-container'>
                    {displayEndActions(gameType, isLeader, result)}
                    <Button className={classes.button}
                        onClick={leaveRoom} variant='contained' color='primary'
                        startIcon={<ExitToAppIcon />}>
                        Quit
          </Button>
                </div>
            </div>
        </Modal>
    );
}
