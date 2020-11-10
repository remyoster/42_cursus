import React, { useState, useContext }from 'react';
import { SearchStore } from '../../search';
import Profil from './profil';
import Civil from './civil';
import Info from './info';
import Account from './account';
import UserBlocks from './userBlocks';
import '../../css/sidebar.css';


export default function Sidebar(props) {
	const id = [props.state.id_session, props.state.token];
	const { search, dispatchSearch } = useContext(SearchStore);
	const [show, setShow] = useState('');

	function toggleView(view) {
		setShow(view);
	}

	return (
		<div className="sidebar">
			<div className="sideContainer">
				<ul>
					<li onClick={() => toggleView('')} className={show === "" ? "currentInfo" : ''}>
							Résumé
				</li>
				<li onClick={() => toggleView('civil')} className={show === 'civil' ? "currentInfo" : ''}>Infos civiles</li>
				<li onClick={() => toggleView('info')} className={show === 'info' ? "currentInfo" : ''}>
						Infos publiques
					</li>
					<li onClick={() => toggleView('account')} className={show === 'account' ? "currentInfo" : ''}>
							Informations de connexion
						</li>
						<li onClick={() => toggleView('block')} className={show === 'block' ? "currentInfo" : ''}>
								Utilisateurs bloqués
							</li>
				</ul>
			</div>
			<div className="container">
				{show === "" && <Profil info={search} />}
				{show === "civil" && <Civil id={id} info={[search, dispatchSearch]} show={setShow} />}
				{show === "info" && <Info id={id} info={[search, dispatchSearch]} show={setShow} />}
				{show === "account" && <Account state={props.state} info={[search, dispatchSearch]} show={setShow} />}
				{show === "block" && <UserBlocks id={id} info={[search, dispatchSearch]} show={setShow} />}
			</div>
	</div>
	);
}
