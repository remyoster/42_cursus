import React, { useContext } from 'react';
import { Store } from '../store';
import { Link } from "@reach/router";
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import { faPowerOff, faBars } from '@fortawesome/free-solid-svg-icons'

export default function Navbar() {
	const { state }  = useContext(Store);

	function displayBurger() {
		var x = document.getElementById("topnav");
		if (x.className === "") {
			x.className = "responsive";
		} else {
			x.className = "";
		}
	}


	if (state.login)
		return (
			<nav id='topnav'>
					<NavLink to='' className='icon' onClick={displayBurger}>
						<FontAwesomeIcon icon={faBars} />
					</NavLink>
				<NavLink to='/'>Match</NavLink>{' '}
				<NavLink to='/jouer'>Jouer</NavLink>{' '}
				<NavLink to='/profil'>
					<img src={state.img} alt='avatar' className='avatar' />
						{state.username}
					</NavLink>{' '}
					<NavLink to='/deconnexion'><FontAwesomeIcon icon={faPowerOff} />
						<span className='infobulle'>Deconnexion</span>
					</NavLink>
				</nav>
		);
	else
		return (
			<nav id='topnav'>
					<NavLink to='' className='icon' onClick={displayBurger}>
						<FontAwesomeIcon icon={faBars} />
					</NavLink>
				<NavLink to='/'>Match</NavLink>{' '}
				<NavLink to='/connexion'>Connexion</NavLink>{' '}
				<NavLink to='/inscription'>S'inscrire</NavLink>{' '}
			</nav>
		);
}

function NavLink(props) {
	return (
		<Link
			{...props} getProps={({ isCurrent }) => {
				return {
					style: {
						color: isCurrent ? "#374140" : "#f8f9f4"
					}
				};
			}}
		/>
	);
}
