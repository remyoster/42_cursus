import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import Modal from '@material-ui/core/Modal';

const useStyles = makeStyles({
  modal: {
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'center',
	},
	body: {
		color: 'white',
		width: 200,
		textAlign: 'center'
	}
});

export default function TransitionModal({ data }) {
	const classes = useStyles();
	const body = (
		<div className={classes.body}>
			<h2>{data}</h2>
		</div>
		);

  return (
      <Modal
        className={classes.modal}
        open={true}
				disableBackdropClick
      >
				{body}
      </Modal>
  );
}
