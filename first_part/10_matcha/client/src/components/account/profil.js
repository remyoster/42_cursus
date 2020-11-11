import React,{ useEffect, useContext } from 'react';
import Image from './image';
import { Store } from '../../store';
import '../../css/form.css';
import '../../css/account.css';

const action = 'PROFIL';
export default function Profil(props)
{
	const { state, dispatch } = useContext(Store);
	const profil = props.info;

	useEffect(() => {
		if (!state.profil && profil.bio && profil.city
			&& state.img !== '/public/img/avatar.png'
			&& state.img !== "" && profil.tags.length > 0)
			dispatch({type: action, profil: true});
		else if (state.profil)
		{
			if (!profil.bio || !profil.city
				|| state.img === '/public/img/avatar.png' || state.img === ''
				|| profil.tags.length === 0)
				dispatch({type: action, profil: false});
		}
	}, [state, profil, dispatch])
	return (
		<>
<h2>- Résumé de ton profil -</h2>
<div className='profil'>
{!state.profil && <p className="paraInfo">Remplis tes infos publiques et ajoute au moins une photo pour pouvoir JOUER</p>}
	<div>
		<h3>{profil.firstname} {profil.lastname}, {profil.defaultAge} ans</h3>
		<p>Ma courte description :<br /> {profil.bio}</p>
	</div>
	<div>
		<h3>Quelques informations personnelles: </h3>
		<p>Tu es : {setGenderText(profil.gender)}</p>
		<p>Tu recherches : {setSexprefText(profil.sexpref)}</p>
		<p>Tu viens de : {profil.city}</p>
	</div>
	<div>
		<h3>Tes centres d'intérêts : </h3>
		<ul className='tags'>
				{profil.defaultTags.map((e, index) => (
					<li key={index}>#{e.name_interest}</li>
				))}
				</ul>
			</div>
			<div>Ton score de popularité : {profil.defaultPopular}</div>
		</div>
		<Image />
</>
	);
}

//RENDER ANOTHER STRING BASED ON INPUT
function setGenderText(str) {
	if (str === 'female')
		return ('une femme');
	else if (str === 'male')
		return ('un homme');
	else if (str === 'other')
		return ('une personne non définie, autre');
}
function setSexprefText(str) {
	if (str === 'female')
		return ('une femme');
	else if (str === 'male')
		return ('un homme');
	else if (str === 'bi')
		return ('un homme ou une femme');
	else if (str === 'other')
		return ('une personne non définie, autre');
}
