import React, { useState } from "react";
import { requestConnect } from "../actions/socket";
import {
    Button, InputAdornment, TextField,
    Typography
} from "@material-ui/core";
import { makeStyles, withStyles } from '@material-ui/core/styles';
import ErrorIcon from '@material-ui/icons/Error';
import VideogameAssetIcon from '@material-ui/icons/VideogameAsset';

const useStyles = makeStyles({
    root: {
        padding: '6px 30px',
        margin: '20px 0 0 0',
    },
});

/*
** Display the form to connect to the site. It toggles a dispatch if name.length
** is valid. Then if there is no error the serv send a socket.
*/

function FormForName(props) {
    const { error, dispatch } = props;
    const classes = useStyles();
    const [name, setName] = useState("");

    function handleSubmit(e) {
        e.preventDefault();
        if (name.length)
            dispatch(requestConnect(name));
    }

    function handleChange(e) {
        setName(e.target.value);
    }

    return (
        <div className='formforname-container dark-backGround retro-border'>
            <Typography variant='h3' component='h1' className='margin-10'>
                Welcome on Red Tetris !
            </Typography>
            <Typography variant='h4' component='h3' className='margin-10'>
                Fill your playername :
            </Typography>
            <form noValidate onSubmit={handleSubmit} autoComplete="off">
                <PseudoTextField
                    type='text'
                    error={error ? true : false}
                    value={name}
                    onChange={handleChange}
                    variant="outlined"
                    label="Pseudo"
                    helperText={error}
                    InputProps={error ? {
                        endAdornment: (
                            <InputAdornment position="end">
                                <ErrorIcon />
                            </InputAdornment>
                        ),
                    } : {}}
                    autoFocus
                />
                <Button className={classes.root}
                    onClick={handleSubmit} variant='contained' color='primary'
                    startIcon={<VideogameAssetIcon />}>
                    Enter
          </Button>
            </form>
        </div>
    );
}

const PseudoTextField = withStyles((theme) => ({
    root: {
        '& .MuiInputBase-input': {
            color: 'white'
        },
        '& .MuiFormLabel-root': {
            color: 'grey'
        },
        '& .MuiFormLabel-root.Mui-focused': {
            color: theme.palette.primary.main
        },
        '& .MuiOutlinedInput-root': {
            '& fieldset': {
                borderColor: 'white',
            },
            '&:hover fieldset': {
                borderColor: theme.palette.primary.main,
            },
        },
        '& .MuiInputAdornment-root > .MuiSvgIcon-root': {
            fill: 'red'
        }
    },
}))(TextField);

export default FormForName;
