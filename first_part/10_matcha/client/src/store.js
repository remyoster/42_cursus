import React from 'react'
//import axios from 'axios';
import io from 'socket.io-client';

//export const socket = io('e1r11p17.42.fr:3001');//A CHANGER EN PROD
export const socket = io('localhost:3001');//A CHANGER EN PROD
export const Store = React.createContext();

function createState()
{
	try {
		let initialState = localStorage.getItem('store');
		if (!initialState)
			return (undefined);
		else
			return (JSON.parse(initialState));
	} catch (e) {
		//console.error(e);
		return (undefined);
	}
}

function reducer(state, action)
{
	switch (action.type)
	{
		case 'LOGIN':
			let loginState = { ...state, login: true, id_session: action.id,
				username: action.username, token: action.token, img: action.img };
			localStorage.setItem('store', JSON.stringify(loginState));
			socket.emit('login', action.id);
			return (loginState);
		case 'LOGOUT':
			localStorage.removeItem('store');
			socket.emit('logout', state.id_session);
			return ({ ...state, login: false, id_session: '', username: '',
				token: '', img: '/public/img/avatar.png'});
		case 'CHANGE_AVATAR':
			let avatarState = {...state, img: action.payload };
			localStorage.setItem('store', JSON.stringify(avatarState));
			return (avatarState);
		case 'PROFIL':
			let tmp = {...state, profil: action.profil};
			localStorage.setItem('store', JSON.stringify(tmp));
			return (tmp);
		default:
			return (state);
	}
}

export function StoreProvider(props)
{
	let initialState = createState();
	if (!initialState)
		initialState = {
			login: false,
			username: '',
			id_session: null,
			token: '',
			profil: false,
			img: '/public/img/avatar.png'
		};
	else
		socket.emit('login', initialState.id_session);
	const [state, dispatch] = React.useReducer(reducer, initialState);
	const value = { state, dispatch };

	return (<Store.Provider value={value}>
			{props.children}
	</Store.Provider>
	);
}
