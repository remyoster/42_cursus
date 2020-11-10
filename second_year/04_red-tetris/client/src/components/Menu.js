import React, { useState, useEffect } from "react";
import {
    requestNewGame, requestJoinGame, requestListGame,
    requestBestGames
} from "../actions/socket";
import {
    Typography, Button, ListItem, Divider, Fab,
    CircularProgress, IconButton
} from "@material-ui/core";
import {
    Group, Person, ArrowBack, AddBox, Replay, ViewQuilt, Visibility, Timer,
    Stars, PeopleAlt
} from '@material-ui/icons';
import { withStyles } from '@material-ui/core/styles';
import Loader from './Loader';
import NestedMarksList from './NestedMarksList';

/*
** Display  menu choices : gameType menu then if multi gameChoice menu
*/

function Menu(props) {
    const { gameAvailable, dispatch, marks } = props;
    const [gameType, setGameType] = useState(false);

    /*
    ** If gametype is multi it updates the game's list every 5 seconds
    ** ig gameType is solo it starts a new game
    */

    useEffect(() => {
        if (!gameType) {
            dispatch(requestBestGames());
        }
        else if (gameType && gameType === 'solo')
            dispatch(requestNewGame(gameType));
    }, [gameType, dispatch])

    /*
    ** toggle the gameType changes. If it's multi it dispatch a request to
    ** update the game's list
    */

    function choseType(type) {
        if (type === 'multi')
            dispatch(requestListGame());
        setGameType(type);
    }

    function displayGameChoice() {
        if (!gameType) {
            return (<GameChoice choseType={choseType} marks={marks} />);
        }
        else if (gameType === 'multi')
            return (
                <MultiGameChoice gameAvailable={gameAvailable}
                    dispatch={dispatch} setGameType={setGameType}
                />
            );
        else
            return (<Loader />)
    }

    return (
        <div className='menu-container'>
            {displayGameChoice()}
        </div>
    );
}

/*
** Display and toggle the game choice between solo and multi
*/

export function GameChoice({ choseType, marks }) {
    return (
        <>
            <div className='game-type-container dark-backGround retro-border'>
                <Typography variant='h3' component='h3'>
                    Select your game type
                    </Typography>
                <div className='buttons-container'>
                    <Button variant="contained" color="primary"
                        onClick={() => choseType("solo")}
                        startIcon={<Person />}>
                        SOLO
                    </Button>
                    <Button variant="contained" color="primary"
                        onClick={() => choseType("multi")}
                        startIcon={<Group />}>
                        MULTIPLAYER
                    </Button>
                </div>
            </div>
            <div className='dark-backGround retro-border game-type-container'>
                <Typography variant='h4'>Best scores</Typography>
                <Divider style={{ backgroundColor: 'white', margin: '10px 0' }} />
                <div className="best-scores-container">
                    <NestedMarksList items={marks.solo} gameType="solo" />
                    <NestedMarksList items={marks.multi} gameType="multi" />
                </div>
            </div>
        </>
    );
}

/*
** Display and toggle the list of the game in multi and possibility to join or
** create one.
*/

export function MultiGameChoice(props) {
    const { gameAvailable, dispatch, setGameType } = props;
    const [gameLoader, setGameLoader] = useState(false);

    useEffect(() => {
        let timeoutId = setTimeout(() => setGameLoader(false), 1000);
        return (() => {
            if (timeoutId)
                clearTimeout(timeoutId);
        })
    }, [gameAvailable])

    function joinGame(roomName) {
        dispatch(requestJoinGame(roomName));
    }

    function newGameMulti() {
        dispatch(requestNewGame('multi'));
    }

    function reloadGames() {
        setGameLoader(true);
        dispatch(requestListGame());
    }

    function displayReload() {
        if (gameLoader)
            return (
                <div style={{padding: '12px', display: 'inline-flex',
                    verticalAlign: 'middle', position: 'relative',
                    alignItems:'center', justifyContent:'center'}}>
                    <CircularProgress color="secondary" size={20} />
                </div>
            );
        return (
            <IconButton aria-label='reload' color='secondary'
                onClick={reloadGames}>
                <Replay />
            </IconButton>
        );
    }

    return (
        <div className='multi-choice-container'>
            <div style={{ width: '70%', marginRight: '20px' }}
                className='retro-border dark-backGround'>
                <Typography variant='h4' component='h4' align='center'>
                    Room choice
                </Typography>
                <Divider style={{ backgroundColor: 'white', alignSelf: 'normal' }} />
                {displayGameAvailable(gameAvailable, joinGame)}
                <Button style={{ margin: '10px' }} color="primary"
                    variant="contained"
                    onClick={newGameMulti}
                    startIcon={<AddBox />}>
                    New
                </Button>
                {displayReload()}
            </div>
            <div style={{ height: 'fit-content' }}
                className='retro-border dark-backGround'>
                {displayLegends()}
            </div>
            <CustomFab color="primary" variant="extended" aria-label="back"
                onClick={() => setGameType(false)} >
                <ArrowBack /> Back
            </CustomFab>
        </div>
    );
}

/*
** Display all available games with possibility to join them
*/

export function displayGameAvailable(gameAvailable, joinGame) {
    return (
        <div className='game-available-container'>
            {gameAvailable.length ? gameAvailable.map(game => (
                <CustomListItem key={game.name} button
                    onClick={() => joinGame(game.name)}>
                    <div style={{ alignItems: 'center' }} className='flex-container'>
                        <Typography fontWeight="bold" variant='h6' component='span'>
                            {game.name} [{game.nbPlayers}/5]
                    </Typography>
                        <PeopleAlt style={{ margin: '0 5px' }} />
                        <Typography variant='body1'>{game.leader}</Typography>
                    </div>
                    <div className='game-available-options'>
                        {gameOptionsToText(game.options)}
                    </div>
                </CustomListItem>
            )) : <Typography align='center' variant='h6' component='p'>
                    There are no room already created : go create one !
                    </Typography>
            }
        </div>
    )

}

/*
** Display in a div container each legend with a icon
*/

export function displayLegends() {
    return (
        <div className='options-legend-container'>
            <Typography variant='h4' component='h4'>Legends</Typography>
            <Divider style={{ backgroundColor: 'white', alignSelf: 'normal' }} />
            <div className='option-value'>
                <PeopleAlt /> = Leader
            </div>
            <div className='option-value'>
                <ViewQuilt /> = Ghost mode
            </div>
            <div className='option-value'>
                <Visibility /> = Full spectrum mode
            </div>
            <div className='option-value'>
                <Stars /> = Starting level
            </div>
            <div className='option-value'>
                <Timer /> = Gravity (time in ms)
            </div>
        </div>
    );
}

/*
** Transform the options object into a div container with each option with it
** value and a icon
*/

export function gameOptionsToText(options) {
    function optionsDispatcher(name, value) {
        if (name === 'ghostMode')
            return (<><ViewQuilt /> {(value ? 'On' : 'Off')}</>);
        else if (name === 'fullSpectrum')
            return (<><Visibility /> {(value ? 'On' : 'Off')}</>);
        else if (name === 'startingLevel')
            return (<><Stars /> {value}</>);
        else if (name === 'dropTimeRef')
            return (<><Timer /> {value}</>);
    }

    let optionsArray = Object.entries(options);
    return (
        optionsArray.map((e) =>
            <div key={e[0]} className='option-value'>
                {optionsDispatcher(e[0], e[1])}
            </div>
        )
    );
}

const CustomListItem = withStyles((theme) => ({
    root: {
        alignItems: 'unset',
        justifyContent: 'unset',
        flexDirection: 'column',
        '&:hover': {
            backgroundColor: 'rgba(213, 0, 0, 0.39)',
        }
    }
}))(ListItem);

const CustomFab = withStyles({
    root: {
        position: 'absolute',
        bottom: '20px',
        left: '20px',
    }
})(Fab);

export default Menu;
