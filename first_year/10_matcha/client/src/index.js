import React from 'react';
import ReactDOM from 'react-dom';
import { StoreProvider } from './store';
import { SearchProvider } from './search';
import { Router } from '@reach/router';
import Login, { Forgotpass } from './pages/login';
import Home from './pages/home';
import Game from './pages/game';
import Logout from './components/logout';
import Account from './pages/account';
import NotFound from './pages/404';
import './css/main.css';
import Registration, { Validate } from './pages/registration';
import Editpass from './components/account/editpass';

ReactDOM.render(
	<StoreProvider>
		<SearchProvider>
			<Router>
				<Home path='/' />
				<Game path='/jouer' />
				<Login path='/connexion' />
				<Logout path='/deconnexion' />
				<Registration path='/inscription' />
				<Validate path='/activate/:token' />
				<Forgotpass path='/connexion/oublie' />
				<Editpass path='/motdepasse/:token' />
				<Account path='/profil' />
				<NotFound default />
			</Router>
		</SearchProvider>
		</StoreProvider>,
	document.getElementById('root'));
