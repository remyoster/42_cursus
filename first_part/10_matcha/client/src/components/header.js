import React, { useContext } from 'react';
import { Store } from '../store';
import Navbar from './navbar';
import Notif from './notif';
import Chat from './chat';
import '../css/header.css';

export default function Header() {
	const { state }  = useContext(Store);
	if (state.login)
		return (
		<header>
		<Navbar />
		<Notif />
		<Chat />
		</header>
	);
	else
		return (
		<header>
		<Navbar />
		</header>
	);
}
