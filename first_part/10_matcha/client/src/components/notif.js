import React, {useState, useEffect, useContext} from 'react';
import axios from 'axios';
import { getTime } from './chat';
import { socket } from '../store.js';
import { SearchStore } from '../search';
import { Store } from '../store';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faBell } from '@fortawesome/free-solid-svg-icons';

const action = 'UP_LASTCO';

export default function Notif() {
	const {state} = useContext(Store);
	const {search, dispatchSearch} = useContext(SearchStore);
	const [countNotif, setCountNotif] = useState(0);
	const [notif, setNotif] = useState(null);

	//GET NOTIF SOCKET EVENT AND UPDATE CLIENT STATE ON VISITS/LIKES/MATCHS
	//AND ADD ONE TO THE NOTIF COUNTER
	useEffect(() => {
		socket.on('notif', function(data) {
			if (data.type === 'visit')
				dispatchSearch({type: 'NEW_VISIT', payload: [...search.visits, {id_visitor: data.id_author, id_visited: state.id_session}]
				});
			else if (data.type === 'like')
				dispatchSearch({type: 'NEW_LIKE', payload: [...search.likes,
					{id_liked: state.id_session, id_author: data.id_author}]
				});
			else if (data.type === 'unlike')
			{
				let tmpMatchs = [...search.matchs];
				if (data.delete)
					tmpMatchs = tmpMatchs.filter(e => 
						(e.id_match !== data.delete));
				dispatchSearch({type: 'NEW_UNLIKE',
					likes: search.likes.filter(e =>
						(e.id_like !== data.id_like)), matchs: tmpMatchs
				});
			}
			else if (data.type === 'match')
			{
				let tmpLikes = data.bol === true ? [...search.likes,
					{id_like: data.id_like, id_liked: state.id_session,
						id_author: data.id_author}]
					: [...search.likes, {id_like: data.id_like,
						id_liked: data.id_author, id_author: state.id_session}];
				dispatchSearch({type: 'NEW_MATCH', likes: tmpLikes,
					matchs: [...search.matchs, {id_match: data.id_match,
						id_user1: state.id_session, id_user2: data.id_author}]
				});
			}
			else if (data.type === 'game')
			{
				dispatchSearch({type: 'NEW_GAME', visits: [...search.visits,
					{id_visit: data.id_visit, id_visitor: data.id_author,
						id_visited: state.id_session}], likes: [...search.likes,
							{id_like: data.id_like, id_liked: state.id_session,
								id_author: data.id_author}]
				});
			}
			setCountNotif((countNotif + 1));
		});
		return () => {
			socket.removeListener('notif');
		};
	}, [state, search, countNotif, dispatchSearch])

	useEffect(() => {
		async function fetchOldNotif()
		{
			try {
				let res = await axios.get(`/user/notif/${state.id_session}`);
				if (res.data && res.data.length > 0)
				{
					let lastco = new Date(search.lastco);
					let tmp = res.data.map(e => {e.date = new Date(e.date);
						return e});
					let i = 0;
					tmp.forEach(e => {
						if (lastco - e.date < 0)
							i++;
					});
					setNotif(tmp);
					setCountNotif(i);
					return ([res.data, i]);
				}
				else
					return (null);
			}
			catch (err) {
				//console.error(err);
				return (null);
			}
		}
		fetchOldNotif()
	}, [state.id_session, search.lastco])

	async function watchNotif() {
		let isDisplay = document.getElementById('notif-wrapper');
		if (isDisplay.style.display === 'block')
			isDisplay.style.display = 'none';
		else
		{
			isDisplay.style.display = 'block';
			dispatchSearch({type: action, payload: new Date()});
		}
		if (countNotif > 0)
			setCountNotif(0);
	}

	return (
		<div id='notif-bar' onClick={watchNotif}>
			<FontAwesomeIcon icon={faBell} className='header-icon' />
				{countNotif > 0 && <span className='notif-counter'>{countNotif}</span>}
				<ul id='notif-wrapper'>
						{notif ? notif.map((e, index) => (<li key={index} className='notif'>
							<img className='notifUserPic' src={e.img || '/public/img/avatar.png'} alt={`${e.id_author}-mainPic`} />
								{renderText(e.type, e.username)}
							<br />
								({getTime(e.date)})
							</li>)) : <li>Vous n'avez aucune notification</li>}
						</ul>
					</div>
	);
}

function renderText(type, name)
{
	if (type === 'visit')
		return (`${name} à visité votre profil.`);
	else if (type === 'like')
		return(`${name} vous à liké !`);
	else if (type === 'unlike')
		return(`${name} ne vous aime plus...`);
	else if (type === 'match')
		return(`Vous avez un nouveau match avec ${name} !!`);
	else if (type === 'game')
		return(`Votre profil a été suggéré et aimé par ${name} !`);
}
