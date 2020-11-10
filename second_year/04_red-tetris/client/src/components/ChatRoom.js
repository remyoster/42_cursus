import React, { useState } from 'react';
import { connect } from "react-redux";
import { TextField, Typography, Divider } from '@material-ui/core';
import { requestChatMessage } from '../actions/socket';
import { withStyles } from '@material-ui/core/styles';
import moment from 'moment';

/*
** Display and deal the chat when there is a multi game
*/

function ChatRoom(props) {
	const { messages, dispatch, playerName, room } = props;
	const [chat, setChat] = useState('');

	function handleChange(e) {
		setChat(e.target.value);
	}

	/*
	** Prevent default enter key in textarea to directly send the message
	*/

	function listenKey(e) {
		if (e.key === 'Enter' && !e.shiftKey) {
			e.preventDefault();
			if (chat.length) {
				dispatch(requestChatMessage({ chat, room, playerName }));
				setChat('');
			}
		}
	}

	return (
		<div className='chatroom-container'>
			<Typography variant='h4' component='h4'>Chat</Typography>
			<Divider style={{ backgroundColor: 'white', alignSelf: 'normal' }} />
			<div className='chatroom-messages-container'>
				{displayMessages(messages, playerName)}
			</div>
			<div className='chat-input'>
				<ChatTextField
					id="standard-multiline-flexible"
					label="Chat"
					multiline
					variant='outlined'
					value={chat}
					onChange={handleChange}
					onKeyDown={listenKey}
				/>
			</div>
		</div>
	)
}

/*
** Display a div container with className right-chat or left-chat if the player
** is the sender and apply a different style on it. It displays the playername,
** the content of the message and the date of sending
*/

export function displayMessages(messages, playerName) {
	return (messages.map((e, idx) =>
		<div
			className={e.playerName === playerName ? 'right-chat' : 'left-chat'}
			key={'chat-' + idx}
		>
			{e.playerName !== playerName &&
				<Typography variant='subtitle1' component='p'>
						<span className='boldText'>{e.playerName}</span>
				</Typography>
			}
			<span className='chat-content'>
				<Typography variant='body1' component='span'>
					{e.chat}
				</Typography>
			</span>
			<Typography variant='caption' component='p'>
				{moment(e.date).format('HH:mm')}
			</Typography>
		</div>
	));
}

const ChatTextField = withStyles((theme) => ({
	root: {
		width: '100%',
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
	},
}))(TextField);

const mapStateToProps = (state) => {
	return ({
		messages: state.chat.messages,
		playerName: state.game.playerName,
		room: state.game.room
	});
};

export default connect(mapStateToProps)(ChatRoom);