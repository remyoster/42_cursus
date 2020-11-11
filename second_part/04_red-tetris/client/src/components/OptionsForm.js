import React, { useState, useEffect, useRef } from 'react';
import { connect } from 'react-redux';
import {
	Typography, Slider, FormGroup, FormControlLabel, Switch, Divider, FormControl,
	Select, InputLabel
} from '@material-ui/core';
import { requestChangeOption } from '../actions/socket';
import { withStyles } from '@material-ui/core/styles';
import DataSlideSnackbar from './DataSlideSnackbar';


/*
** OptionsForm component display the list of all available options. It use
** different form to display a option (see functions below). Each options passed
** in the optionsDispatcher and is returned in his own div container.
** Whenever options change, it pop-up a snackbar if the user is not the leader.
** It use redux to make changes in state.
*/

function OptionsForm(props) {
	const { options, dispatch, room, leader, gameType } = props;
	const refOptions = useRef(options);
	const [openSnack, setOpenSnack] = useState(false);

	/*
	** Toggle the snackbar whenever options change
	*/

	useEffect(() => {
		if (options !== refOptions.current && gameType === 'multi' && !leader) {
			refOptions.current = options;
			setOpenSnack(true);
		}
	}, [options, gameType, leader])

	/*
	** Create and array of entries and values from options then map the array
	*/

	function displayOptions() {
		let optionsArray = Object.entries(options);
		return (
			optionsArray.map((e, idx) =>
				<div key={'option-' + idx} className='option-container'>
					{optionsDispatcher(e[0], e[1], dispatch, room, leader, gameType)}
				</div>
			)
		);
	}

	/*
	** Simple if/else dispatcher to render options
	*/

	function optionsDispatcher(option, value) {
		if (option === 'ghostMode')
			return (<CustomSwitcher option={option} value={value} room={room}
				leader={leader} dispatch={dispatch} />);
		else if (option === 'colorMode')
			return (<ColorSelect option={option} value={value} room={room}
				leader={leader} dispatch={dispatch} />);
		else if (option === 'startingLevel')
			return (<StartingLevelSlider value={value} dispatch={dispatch}
				room={room} leader={leader} />);
		else if (option === 'dropTimeRef')
			return (<DropTimeRefSlider value={value} dispatch={dispatch}
				room={room} leader={leader} />);
		else if (option === 'fullSpectrum' && gameType === 'multi')
			return (<CustomSwitcher option={option} value={value} room={room}
				leader={leader} dispatch={dispatch} />);
	}

	return (
		<div className='game-options-container'>
			<Typography variant='h4' component='h4'>Options </Typography>
			<Divider style={{ backgroundColor: 'white', alignSelf: 'normal' }} />
			{gameType === 'multi' &&
				<Typography variant='body1'>
					Only the leader can change them before the game starts
				</Typography>}
			{displayOptions()}
			<DataSlideSnackbar data="The leader changed game options"
				open={openSnack} setOpen={setOpenSnack} />
		</div>
	)
}

/*
** Toggle on/off value of ghost mode. If the user is leader it dispatch the new
** value. Else the switcher is disabled
*/
export function CustomSwitcher({ option, value, room, leader, dispatch }) {
	function toggleChange() {
		dispatch(requestChangeOption({ option, value: !value, room }));
	}
	return (
		<FormGroup row>
			<CustomFormControlLabel
				control={
					<Switch
						checked={value}
						disabled={!leader}
						name={option + '_switch'}
						onChange={toggleChange} />
				}
				label={option}
				labelPlacement="start"
			/>
		</FormGroup>
	);
}

export function ColorSelect({ option, value, dispatch, room, leader }) {

	function toggleChange(event) {
		dispatch(requestChangeOption({ option, value: event.target.value, room }));
	}

	return (
		<CustomFormControl variant='outlined' disabled={!leader}>
			<InputLabel id="color-select-label">Color</InputLabel>
			<Select
				native
				labelId="color-select-label"
				id="color-select"
				value={value}
				onChange={toggleChange}
				label="Color"
			>
				<option value="normal">Normal</option>
				<option value="random">Random</option>
				<option value="red">Red</option>
			</Select>
		</CustomFormControl>
	);
}

/*
**  Toggle starting level value. If the user is leader it dispatch the new
** value. Else the slider is disabled.
*/

export function StartingLevelSlider({ value, dispatch, room, leader }) {
	const [sliderVal, setSliderVal] = useState(value);

	useEffect(() => {
		setSliderVal(value)
	}, [value])

	const marks = [
		{
			value: 0,
			label: 'Easy',
		},
		{
			value: 5,
			label: 'Normal',
		},
		{
			value: 10,
			label: 'Hard',
		},
		{
			value: 15,
			label: 'Really hard',
		},
		{
			value: 20,
			label: 'Professionnal',
		},
	];

	function toggleValue(e, val) {
		setSliderVal(val);
	}

	function toggleChange(e, val) {
		dispatch(requestChangeOption({ option: 'startingLevel', value: val, room }));
	}

	return (
		<div style={{ width: '100%', color: 'white' }}>
			<Typography gutterBottom>
				Starting Level : {sliderVal}
			</Typography>
			<CustomSlider
				data-testid="startingLevelSlider"
				value={sliderVal}
				disabled={!leader}
				getAriaValueText={(value) => value}
				aria-labelledby="discrete-slider-custom"
				valueLabelDisplay="auto"
				step={1}
				marks={marks}
				min={0}
				max={20}
				onChange={toggleValue}
				onChangeCommitted={toggleChange}
			/>
		</div>
	);
}

/*
**  Toggle droptimeRef value. If the user is leader it dispatch the new
** value. Else the slider is disabled.
*/

export function DropTimeRefSlider({ value, dispatch, room, leader }) {
	const [sliderVal, setSliderVal] = useState(value);

	useEffect(() => {
		setSliderVal(value)
	}, [value])

	const marks = [
		{
			value: 400,
			label: 'BlackHole',
		},
		{
			value: 600,
			label: 'Hard',
		},
		{
			value: 800,
			label: 'Higher',
		},
		{
			value: 1000,
			label: 'Normal',
		},
		{
			value: 1200,
			label: 'Lower',
		},
		{
			value: 1400,
			label: 'Easy',
		},
		{
			value: 1600,
			label: 'Moon',
		},
	];

	function toggleValue(e, val) {
		setSliderVal(val);
	}

	function toggleChange(e, val) {
		dispatch(requestChangeOption({ option: 'dropTimeRef', value: val, room }));
	}

	return (
		<div style={{ width: '100%', color: 'white' }}>
			<Typography gutterBottom>
				Gravity (time in ms) : {sliderVal}
			</Typography>
			<CustomSlider
				value={sliderVal}
				disabled={!leader}
				data-testid="dropTimeRefSlider"
				getAriaValueText={(value) => value}
				aria-labelledby="discrete-slider-custom"
				valueLabelDisplay="auto"
				step={200}
				marks={marks}
				min={400}
				max={1600}
				onChange={toggleValue}
				onChangeCommitted={toggleChange}
			/>
		</div>
	);
}

const CustomSlider = withStyles({
	markLabel: {
		color: 'rgba(255,255,255,0.6)',
	},
	markLabelActive: {
		color: 'white'
	}
})(Slider);

const CustomFormControlLabel = withStyles({
	root: {
		'& .MuiFormControlLabel-label.Mui-disabled': {
			color: 'rgba(255,255,255,0.6)',
		},
	}
})(FormControlLabel);

const CustomFormControl = withStyles((theme) => ({
	root: {
		'& .MuiOutlinedInput-notchedOutline': {
			borderColor: 'white'
		},
		'& .MuiFormLabel-root': {
			color: 'white'
		},
		'& .MuiFormLabel-root.Mui-focused': {
			color: theme.palette.primary.main
		},
		'& .MuiOutlinedInput-root': {
			color: theme.palette.secondary.main,
			'&:hover fieldset': {
				borderColor: theme.palette.primary.main,
			},
		},
		'& .MuiOutlinedInput-root.Mui-disabled': {
			color: 'grey',
			'&:hover fieldset': {
				borderColor: 'grey',
			},
		},
		'& .MuiOutlinedInput-root.Mui-focused': {
			color: theme.palette.secondary.main
		},
		'& .MuiSvgIcon-root': {
			fill: 'white'
		},
		'& .MuiSelect-select.Mui-disabled': {
			color: 'grey'
		}
	},
}))(FormControl);

const mapStateToProps = (state) => {
	return ({
		options: state.game.options,
		room: state.game.room,
		gameType: state.game.type,
	});
}

export default connect(mapStateToProps)(OptionsForm);
