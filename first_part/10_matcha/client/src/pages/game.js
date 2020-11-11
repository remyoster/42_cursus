import React, { useEffect, useContext, useState } from 'react';
import Header from '../components/header';
import { Store, socket } from '../store';
import { SearchStore } from '../search';
import NotFound from './404';
import Map from '../components/map';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import { faChevronCircleRight, faHeart,
	faChevronCircleLeft } from '@fortawesome/free-solid-svg-icons';
import axios from 'axios';
import '../css/match.css';
import '../css/game.css';

const action = 'NEW_GAME';

export default function Game() {
	const { state }  = useContext(Store);
	const { search, dispatchSearch } = useContext(SearchStore);
	const [others, setOthers] = useState([]);
	const [targother, setTargother] = useState([]);
	const [i, setI] = useState(0);
	const [error, setError] = useState(null);
	const [filters, setFilters] = useState({age: true, loc : true,
		pop: true, tags: true})
	const [loading, setLoading] = useState(true);
	const [fetchDb, setFetchDb] = useState(null);

	useEffect(() => {
		const CancelToken = axios.CancelToken;
		const source = CancelToken.source();
		async function fetchOthersData() {
			try {
				let res = await axios.get(`/user/others/${state.id_session}`,
					{cancelToken:source.token});
				if (res.data)
					setFetchDb(res.data);
				else
					setError('Une erreur est survenue.');
			} catch (err) {
				if (axios.isCancel(err))
					source.cancel();
				else
					setError('Une erreur est survenue.');
			}
		}
		if (state.login && search.loaded)
			fetchOthersData();
		return () => {
			source.cancel();
		}
	}, [state.login, state.id_session, search.loaded]);

	useEffect(() => {
		if (fetchDb)
		{
			let Uwids = getUnWantedIds(search, state.id_session)
			let tmp = fetchDb.filter(e => (
				!Uwids.includes(e.id_user)));
			setLoading(false);
			setOthers(tmp);
		}
	}, [search, state.id_session, fetchDb])


	useEffect(() => {
		if (others.length > 0)
			setTargother(filterOthers(search, others, filters));
	}, [search, others, filters])

	function toggleLike(other) {
		socket.emit('notif', {type: "game", id_other: other.id_user,
			id_author: state.id_session});
		socket.on('gameInserted', (data) => {
			dispatchSearch({type: action, visits: [...search.visits,
				{id_visit: data.id_visit, id_visitor: state.id_session,
					id_visited: other.id_other}],
				likes: [...search.likes, {id_like: data.id_like,
					id_liked: other.id_user, id_author: state.id_session}],
			});
			setI(0);
		});
	}

	function toggleFilter(e) {
		if (e.target.name === 'age')
			setFilters({...filters, age: e.target.checked});
		else if (e.target.name === 'loc')
			setFilters({...filters, loc: e.target.checked});
		else if (e.target.name === 'pop')
			setFilters({...filters, pop: e.target.checked});
		else if (e.target.name === 'tags')
			setFilters({...filters, tags: e.target.checked});
		setI(0);
	}

	if (!state.login)
		return (<NotFound />);
	else if (!state.profil)
		return(<>
		<Header />
		<div className='containLogin'>
			<p>Vous devez compléter votre profil pour accéder aux suggestions.</p> 
			<p>Ajoutez y une photo de profil, une description, quelques centres d'intérêts et votre ville.</p>
			<p>Nous nous chargerons du reste ;)</p>
		</div>
</>
);
	else
		return(
			<>
<Header />
<h2 className='gameTitle'>-- La tisane parfaite --</h2>
	{error && <p>{error}</p>}
	<div style={{display:'flex' ,flexDirection:'column'}}>
			{loading && <img className='loader' src='/public/img/ajax-loader.gif' alt='loader' />}
		</div>
		<ul className='filter-wrapper'>
			<li className='filter'>Avec ou sans filtres :</li>
			<li className='filter'>
				<label>Age
				<input type='checkbox' name='age' checked={filters.age} onChange={toggleFilter}/>
			</label>
		</li>
		<li className='filter'>
			<label>Localisation
			<input type='checkbox' name='loc' checked={filters.loc} onChange={toggleFilter}/>
		</label>
	</li>
	<li className='filter'>
		<label>Score de popularité
		<input type='checkbox' name='pop' checked={filters.pop} onChange={toggleFilter}/>
	</label>
</li>
<li className='filter'>
	<label>Tags en commun
	<input type='checkbox' name='tags' checked={filters.tags} onChange={toggleFilter}/>
</label>
		</li>
	</ul>
		{!targother[i] && <p>Vous n'avez aucune suggestion...Essayez de désactiver les filtres</p>}
			{targother[i] &&
					<div className='suggMatch'>
						<h3>{targother[i].username}, {targother[i].age} ans</h3>
						<h4>{targother[i].score.toFixed(2)} % compatible</h4>
						<div className='switchWrapper'>
								{i === 0 && <FontAwesomeIcon className='switchIconDis' icon={faChevronCircleLeft} />}
									{i > 0 && <FontAwesomeIcon className='switchIcon' icon={faChevronCircleLeft} onClick={() => setI(i - 1)} />}
									<img src={getMainPic(targother[i])} alt={'profilpic' + targother[i].id_user} />
										{i < (targother.length - 1) && <FontAwesomeIcon className='switchIcon' icon={faChevronCircleRight} onClick={() => setI(i + 1)} />}
											{i === (targother.length - 1) && <FontAwesomeIcon className='switchIconDis' icon={faChevronCircleRight} />}
										</div>
										<FontAwesomeIcon className='love-button' icon={faHeart} onClick={() => toggleLike(targother[i])} />
										<div className='suggInfo'>
											<div>
												<h3>{targother[i].firstname} {targother[i].lastname}, {targother[i].age} ans</h3>
												<p>Ma courte description :<br /> {targother[i].bio}</p>
											</div>
											<div>
												<h3>Quelques informations personnelles: </h3>
												<p>Je suis : {setGenderText(targother[i].gender)}</p>
												<p>Je recherche : {setSexprefText(targother[i].sexpref)}</p>
												<p>De : {targother[i].city}</p>
											</div>
											<div>
												<h3>Mes centres d'intérêts: </h3>
												<ul className='tags'>
														{targother[i].interest && targother[i].interest.map((e, index) => (<li key={index}>{e}</li>))}
													</ul>
												</div>
											</div>
										</div>
			}
										<div className="map">
											<Map others={targother} coord={[search.lat, search.lon]} index={i}/>
										</div>
								</>
		);
}

//FILTER USERS BY SEXPREF+GENDER AND STATUS ON 'confirmed' AND ON IF MAIN PIC
function filterOthers(search, others, filters) 
{
	others = others.filter(e => {
		if (search.sexpref === 'bi')
			return (e.gender === 'male' || e.gender === 'female')
		else
			return (e.gender === search.sexpref)
	}).filter(f => {
		if (search.gender === 'male')
			return (f.sexpref === 'bi' || f.sexpref === 'male');
		else if (search.gender === 'female')
			return (f.sexpref === 'bi' || f.sexpref === 'female');
		else
			return (f.sexpref === 'other');
	}).filter(e => (e.status === 'confirmed'))
		.filter(e => e.imgs.find(f => f.profil));
	others = others.map(e => {
		e.score = AlgoMatch(search, e, filters);
		return (e);
	});
	others = others.filter(e => (e.score > 50));
	return (others.sort((a, b) => (a.score < b.score ? 1 : -1)));
}

/**** ALGO ****/
function AlgoMatch(search, other, filters) {
	let score = 0;
	let diff = 0;
	if (filters.age)
	{
		diff = abs(search.defaultAge - other.age);
		if (diff <= 10)
			score += 20 - diff;
	}
	else
		score += 20;
	if (filters.loc)
	{
		diff = distanceKm(search.lat, search.lon, other.latitude,
			other.longitude);
		if (diff <= 50)
			score += 50 - diff;
	}
	else
		score += 50;
	if (filters.pop)
	{
		let diff = abs(search.defaultPopular - other.popular);
		if (diff <= 10)
			score += 10 - diff;
	}
	else
		score += 10;
	if (filters.tags)
	{
		let nbTags = search.defaultTags.length;
		if (nbTags > 0)
		{
			let c = countCommonTag(search.defaultTags.map((e) => 
				(e.name_interest)), other.interest);
			score += c * (10 / nbTags);
		}
		else
			score += 10;
	}
	else
		score += 10;
	score += (other.imgs.length - 1) * 2.5;
	return (score);
}

function getMainPic(e) {
	let res = e.imgs.filter(f => (f.profil === 1));
	let path = '/public/img/avatar.png';
	if (res[0])
		path = res[0].path;
	return (path);
}
/*** CALCUL DISTANCE ***/
function degreesToRadians(degrees) {
	return degrees * Math.PI / 180;
}

function distanceKm(lat1, lon1, lat2, lon2) {
	var earthRadiusKm = 6371;

	var dLat = degreesToRadians(lat2-lat1);
	var dLon = degreesToRadians(lon2-lon1);

	lat1 = degreesToRadians(lat1);
	lat2 = degreesToRadians(lat2);

	var a = Math.sin(dLat/2) * Math.sin(dLat/2) +
		Math.sin(dLon/2) * Math.sin(dLon/2) * Math.cos(lat1) * Math.cos(lat2);
	var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));
	return earthRadiusKm * c;
}

function abs(a) {
	return (a > 0 ? a : -a);
}

function countCommonTag(tab1, tab2) {
	let count = 0;
	for (var i = 0; i < tab1.length; i++) {
		if (tab2.includes(tab1[i]))
			count += 1;
	}
	return (count);
}

//FILTER PROFILS WITH OUR LIKES, BLOCKS, AND MATCHS. RETURN ALL UNWANTED IDS
function getUnWantedIds(search, id)
{
	let Uwids = [];
	search.visits.forEach(e => {
		if (e.id_visitor !== id && !Uwids.includes(e.id_visitor))
			Uwids.push(e.id_visitor);
		if (e.id_visited !== id && !Uwids.includes(e.id_visited))
			Uwids.push(e.id_visited);
	});
	search.likes.forEach(e => {
		if (e.id_liked !== id && !Uwids.includes(e.id_liked))
			Uwids.push(e.id_liked);
		if (e.id_author !== id && !Uwids.includes(e.id_author))
			Uwids.push(e.id_author);
	});
	search.blocks.forEach(e => {
		if (e.id_blocked !== id && !Uwids.includes(e.id_blocked))
			Uwids.push(e.id_blocked);
		if (e.id_author !== id && !Uwids.includes(e.id_author))
			Uwids.push(e.id_author);
	});
	search.matchs.forEach(e => {
		if (e.id_user1 !== id && !Uwids.includes(e.id_user1))
			Uwids.push(e.id_user1);
		if (e.id_user2 !== id && !Uwids.includes(e.id_user2))
			Uwids.push(e.id_user2);
	});
	return (Uwids);
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
