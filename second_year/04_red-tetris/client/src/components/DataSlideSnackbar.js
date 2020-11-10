import React from 'react';
import { Slide, Snackbar } from '@material-ui/core';
import MuiAlert from '@material-ui/lab/Alert';

/*
** Display a snackbar with a slide transition.
** - data : innerText of the snackbar
** - direction : animation direction (up,down,left,right)
** - severity : color of the snack (see material ui)
** - open, setOpen : boolean + function to modify it
*/

function DataSlideSnackbar({ data, direction, severity, open, setOpen }) {

	/*
	** Close the snackbar
	*/

	function closeSnack(e, reason) {
		if (reason === 'clickaway') {
			return;
		}
		setOpen(false);
	}

/*
** Create a slide animation from the bottom (avoid findDomNode error)
*/
	function SlideTransition(props){
		return (<Slide {...props} direction={direction ? direction : "up"} />);
	}

	return (
			<Snackbar TransitionComponent={SlideTransition} open={open}
				autoHideDuration={3000} onClose={closeSnack}>
				<MuiAlert elevation={6} variant="filled"
					onClose={closeSnack} severity={severity ? severity : "info"}>
						{data}
					</MuiAlert>
			</Snackbar>
	);
}

export default DataSlideSnackbar;
