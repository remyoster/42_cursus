import React, { useState, useEffect, useContext } from 'react';
import Map from '../map';
import axios from 'axios';
import { socket } from '../../store';
import { SearchStore } from '../../search';
import SearchBar from './searchBar';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faEye, faCircle,
	faHeart, faExclamationTriangle, faAngleDoubleDown} from '@fortawesome/free-solid-svg-icons';

export default function Gallery(props) {
	const { search, dispatchSearch } = useContext(SearchStore);
	const state = props.state;
	const [other, setOther] = useState({});
	const [targother, setTargother] = useState([]);
	const [visited, setVisited] = useState(false);
	const [liked, setLiked] = useState(false);
	const [sortSearch, setSortSearch] = useState('');
	const [ascSort, setAscSort] = useState(true);
	const [i, setI] = useState(0);
	const [tmpTargother, setTmpTargother] = useState([]);
	const [error, setError] = useState(null);
	const [online, setOnline] = useState([]);

	//DISPLAY MODAL WHEN CLICKING ON A PROFIL
	useEffect(() => {
		function displayModal(e) {
			let modal = document.getElementById('modal');
			if (e.target === modal)
				modal.style.display = 'none';
		}
		window.addEventListener('click', displayModal);
		return () => {
			window.removeEventListener('click', displayModal);
		}
	})

	//LOAD AND FILTER PROFILS
	useEffect(() => {
		let searchOthers = [];
		let id = state.id_session;
		if (search.cat === "visits")
			searchOthers = getVisits(search.visits, props.others,
				id, visited);
		else if (search.cat === "likes")
			searchOthers = getLikes(search.likes, props.others,
				id, liked);
		else if (search.cat === "matchs")
			searchOthers = getMatches(search.matchs, props.others, id);
		else
		{
			let listVisits = getVisits(search.visits, props.others,
				id, true).map(e => (e.id_user));
			searchOthers = props.others.filter(e => (
				!listVisits.includes(e.id_user)));
		}
		searchOthers = filterBlocks(search.blocks, searchOthers);
		let profils = filterProfils(search, searchOthers);
		if (sortSearch !== '')
			profils = changeTri(profils, sortSearch, search, ascSort);
		setTargother(profils);
		setI(0);
	}, [props.others, search, visited, liked, state.id_session,
		sortSearch, ascSort])

	//MAKE A LIMITED COPY BASED ON I OF TARGOTHER TO DISPLAY
	useEffect(() => {
		if (targother.length > 10)
			setTmpTargother(targother.slice(0, ((i + 1) * 10)));
		else
			setTmpTargother(targother);
	}, [targother, i])

	//KNOWING WHO IS ONLINE
	useEffect(() => {
		function whoIsOnline() {
			socket.emit('getSocketUsers');
			socket.on('getSocketUsers', function(data) {
				setOnline(data);
			});
		}
		let intervalID = setInterval(whoIsOnline, 5000);
		return () => {
			socket.removeListener('getSocketUsers');
			clearInterval(intervalID);
		};
	}, [])

	/*
	 * DISPLAY THE PROFIL WHEN CLICKED ON PIC
	 * ADD TO VISITED AND SEND NOTIF IF NEVER DID BEFORE
	 */
	function watchProfil(e) {
		setOther(e);
		document.getElementById('modal').style.display = 'block';
		if (!search.visits.find(e => (e.id_visited === e.id_user)))
		{
			socket.emit('notif', {type: "visit", id_visited: e.id_user,
				id_visitor: state.id_session});
			socket.on('visitInserted', data => {
				dispatchSearch({type: 'NEW_VISIT',
					payload: [...search.visits, {id_visit: data,
						id_visited: e.id_user, id_visitor: state.id_session}]
				});
			});
		}
	}

	function closeProfil() {
		document.getElementById('modal').style.display = 'none';
	}

	function toggleLike() {
		//CHECK IF WE ALREADY LIKED THE OTHER
		let i = search.likes.findIndex(e => (e.id_liked === other.id_user
			&& e.id_author === state.id_session));
		if (i === -1)//IF WE DON'T LIKE IT
		{
			//CHECK IF IT ALREADY LIKED US
			let j = search.likes.findIndex(e => (e.id_author === other.id_user));
			if (j === -1)//IF HE DOESN'T LIKE US
			{
				socket.emit('notif', {type: "like", id_liked: other.id_user,
					id_author: state.id_session});
				socket.on('likeInserted', data => {
					dispatchSearch({type: 'NEW_LIKE',
						payload: [...search.likes, {id_like: data,
							id_liked: other.id_user, id_author: state.id_session}],
					});
				});
			}
			else
				socket.emit('notif', {type: "match", id_liked: other.id_user,
					id_author: state.id_session});
		}
		else
		{
			let like = search.likes[i];
			let k = search.matchs.findIndex(e => (e.id_user1 === like.id_liked
				|| e.id_user2 === like.id_liked));
			let tmpLikes = search.likes
				.filter(e => (e.id_liked !== like.id_liked));
			let tmpMatchs = [...search.matchs];
			if (k > -1)//THERE IS A MATCH
			{
				tmpMatchs = search.matchs
					.filter(e => (e.id_user1 !== like.id_liked
						&& e.id_user2 !== like.id_liked));
				socket.emit('notif', {type: "unlike", id_like: like.id_like,
					id_author: like.id_author, id_liked: like.id_liked,
					delete: search.matchs[k].id_match});
			}
			else //THERE WAS NO MATCH
				socket.emit('notif', {type: "unlike", id_like: like.id_like,
					id_author: like.id_author, id_liked: like.id_liked});
			dispatchSearch({type: 'NEW_UNLIKE', likes: tmpLikes,
				matchs: tmpMatchs})
		}
	}

	/** TOGGLE VISIT ET LIKE BOOLEAN**/
	function toggleVisits() {
		if (visited)
			setVisited(false);
		else
			setVisited(true);
	}
	function toggleLikes() {
		if (liked)
			setLiked(false);
		else
			setLiked(true);
	}

	/*** SORT RESULTS ***/
	function changeSortSearch(e) {
		let tmp = parseInt(e.target.value);
		let tab = [...targother];
		if (targother) {
			if (tmp === 1) {
				tab = changeTri(tab, 'age', search, ascSort);
				setSortSearch('age');
			} else if (tmp === 2) {
				tab = changeTri(tab, 'localisation', search, ascSort);
				setSortSearch('localisation');
			} else if (tmp === 3) {
				tab = changeTri(tab, 'popular', search, ascSort);
				setSortSearch('popular');
			} else if (tmp === 4) {
				tab = changeTri(tab, 'tags', search, ascSort);
				setSortSearch('tags');
			}
			setTargother(tab);
		}
	}
	function changeAscSort (e) {
		let bool = parseInt(e.target.value);
		if (bool === 1 && ascSort === false)
			setAscSort(true);
		else if (bool === 0 && ascSort === true)
			setAscSort(false);
	}

	/*** REPORT ***/
	function report() {
		if (document.getElementById('report').style.display === "block")
			document.getElementById('report').style.display = "none";
		else
			document.getElementById('report').style.display = "block";
	}

	function fakeAccount() {
		let id = other.id_user;
		try {
			axios.post('/user/others/fake', {id_other: id, id: state.id_session,
				token: state.token });
			document.getElementById('modal').style.display = 'none';
			let tmp = [...targother];
			let i = tmp.findIndex(e => (e.id_user === id));
			if (i > -1)
			{
				tmp[i].status = 'fake';
				setTargother(tmp);
			}
		} catch (e) {
			//console.error(e);
			setError('Une erreur est survenue.');
		}
		report();
	}

	async function blockAccount() {
		let id_blocked = other.id_user;
		try {
			let result = await axios.post('/user/others/block', {
				id: state.id_session,
				id_blocked: id_blocked,
				token: state.token
			});
			if (result.data) {
				dispatchSearch({type: 'NEW_BLOCK', payload: [...search.blocks,
					{id: result.data.result, id_author: state.id_session,
						id_blocked: id_blocked}]
				});
				document.getElementById('modal').style.display = 'none';
			}
		} catch (e) {
			//console.error(e);
			setError('Une erreur est survenue.');
		}
		report();
	}

	return(
		<>
<div className='mainContain'>
		{error && <p>{error}</p>}
		<SearchBar />
		<div id="gallery">
			<div className="sortsearch">
				<select defaultValue={'default'} onChange={changeSortSearch}>
					<option disabled value="default">Trier par :</option>
					<option value='1'>Âge</option>
					<option value='2'>Localisation</option>
					<option value='3'>Popularité</option>
					<option value='4'>Tags commun</option>
				</select>
				<select defaultValue="1" onChange={changeAscSort}>
					<option value="1">&and;</option>
					<option value="0">&or;</option>
				</select>
			</div>
				{props.loading && <img className='loader' src='/public/img/ajax-loader.gif' alt='loader' />}
					{(search.cat === 'visits') && visited && <div className="lineToggle">
						<h3>Tu as regardé leur profil /</h3><button onClick={toggleVisits} className="toggleEd">Ils ont regardé ton profil</button>
						</div>}
							{(search.cat === 'visits') && !visited && <div className="lineToggle">
								<button onClick={toggleVisits} className="toggleEd"> Tu as regardé leur profil /</button><h3> Ils ont regardé ton profil</h3>
							</div>
							}
								{(search.cat === 'likes') && liked && <div className="lineToggle">
									<h3>Tu as liké leur profil /</h3><button onClick={toggleLikes} className="toggleEd">Ils ont liké ton profil</button>
									</div>}
										{(search.cat === 'likes') && !liked &&
												<div className="lineToggle">
													<button onClick={toggleLikes} className="toggleEd">Tu as liké leur profil /</button><h3> Ils ont liké ton profil </h3>
													</div>}
													<ul className="listOthers">
															{tmpTargother && tmpTargother.map((e, index) => (<li className='others' key={index} value={e.id_user} onClick={() => watchProfil(e)}>
																<img src={getMainPic(e)} alt={'profilpic' + e.id_user} />
																<div className='othersInfos'> <FontAwesomeIcon icon={faCircle} style={{color: online.includes(e.id_user) ? 'green' : 'grey'}} /> {e.username}<br/>{e.age} ans, {e.city}</div></li>))}
															</ul>
																{(i + 1) * 10 < targother.length && <FontAwesomeIcon className='getDown' icon={faAngleDoubleDown} onClick={() => setI(i + 1)} />}
																<div id='modal' className='modal'>
																	<div className='modal-content'>
																		<span className="close" onClick={closeProfil}>&times;</span>
																		<div className='profilOther'>
																			<div className='profil-img'>
																				<div className='imgP'>
																					<h3>{other.username} {online.includes(other.id_user) ? 'En ligne' : `Dernière connexion le : ${troncDate(other.lastco)}`} </h3>
																						{other.imgs && other.imgs.map((e, index) => (<img src={e.path} alt={'profilpic' + index} key={index}/>))}
																					</div>
																					<div>
																							{ search.visits && search.visits.find(e => (e.id_visitor === other.id_user)) && <p><FontAwesomeIcon icon={faEye} className="interactionIcon" /> {other.username} t'a déjà visité</p>}
																								{search.likes.find(e => (e.id_author === other.id_user)) && <p><FontAwesomeIcon icon={faHeart} className="interactionIcon"/>{other.username} t'a déjà liké</p>}
																								<p>Son score: {other.popular}</p>
																							</div>
																							<div>
																								<h3>Mes centres d'intérêts: </h3>
																								<ul className='tags'>
																										{other.interest && other.interest.map((e, index) => (<li key={index}>{e}</li>))}
																									</ul>
																								</div>
																							</div>

																							<div className='profil-info'>
																								<div>
																									<h3>{other.firstname} {other.lastname}, {other.age} ans</h3>
																									<p>Ma courte description :<br /> {other.bio}</p>
																										{other.status === "confirmed" ? <p>Statut: confirmé</p> : <p>Statut: reporté comme faux profil</p>}
																									</div>
																									<div>
																										<h3>Quelques informations personnelles: </h3>
																											{other.gender === "female" && <p>Je suis : une femme </p>}
																												{other.gender === "male" && <p>Je suis : un homme </p>}
																													{other.gender === "other" && <p>Je suis : autre </p>}
																														{other.sexpref === "female" && <p>Je recherche: une femme </p>}
																															{other.sexpref === "male" && <p>Je recherche: un homme</p>}
																																{other.sexpref === "bi" && <p>Je recherche: un homme ou une femme </p>}
																																	{other.sexpref === "other" && <p>Je recherche: autre </p>}
																																	<p>Je viens de : {other.city}</p>
																																</div>
																																	{(other.imgs && other.imgs.length > 0 && state.img !== "/public/img/avatar.png") &&
																																			<div className="likeDiv">
																																				<h3><span style={{color: "red"}}>Like</span> OU <span style={{color: "green"}}>Unlike</span></h3><FontAwesomeIcon icon={faHeart} onClick={toggleLike} className='likeButton' style={{color: search.likes.find(e => (e.id_liked === other.id_user)) ? 'red' : 'green'}}/>
																																				</div>}
																																				<div className="likeDiv">
																																					<h3>Un problème avec {other.username}</h3><FontAwesomeIcon onClick={report} className='reportIcon' icon={faExclamationTriangle} />
																																					<div id="report">
																																						<ul>
																																								{other.status !== 'fake' && <li value={other.id_user} onClick={fakeAccount}>Reporter comme faux compte</li>}
																																								<li value={other.id_user} onClick={blockAccount}>Bloquer ce compte</li>
																																							</ul>
																																						</div>
																																					</div>

																																				</div>
																																			</div>

																																		</div>
																																	</div>
																																</div>
																															</div>
																															<div className='map'>
																																<Map others={tmpTargother} coord={[search.lat, search.lon]} />
																															</div>
																													</>
	)
}

function getMainPic(e) {
	let res = e.imgs.filter(f => (f.profil === 1));
	let path = '/public/img/avatar.png';
	if (res[0])
		path = res[0].path;
	return (path);
}
//CALCUL DISTANCE
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

/** FUNCTION TRIAGE **/

//SORT MY VISITS BY I VISITED (true/default) OR THEY VISITED ME (false)
function getVisits(visits, others, id, bool)
{
	if (bool)
		return (others.filter(e => (visits.filter(f => (f.id_visitor === id))
			.map(f => (f.id_visited)).includes(e.id_user))));
	else
		return (others.filter(e => (visits.filter(f => (f.id_visited === id))
			.map(f => (f.id_visitor)).includes(e.id_user))));
}

//SORT MY LIKES BY I LIKED (true/default) OR THEY LIKED ME (false)
function getLikes(likes, others, id, bool)
{
	if (bool)
		return (others.filter(e => (likes.filter(f => (f.id_author === id))
			.map(f => (f.id_liked)).includes(e.id_user))));
	else
		return (others.filter(e => (likes.filter(f => (f.id_liked === id))
			.map(f => (f.id_author)).includes(e.id_user))));
}

function getMatches(search, others, id) {
	let matches = [];
	let listFinal = [];
	for (var mat = 0; mat < search.length; mat++) {
		if (search[mat].id_user1 === id)
			matches.push(search[mat].id_user2);
		else
			matches.push(search[mat].id_user1);
	}
	listFinal = others.filter((h) => {
		return(matches.includes(h.id_user));
	});
	return (listFinal);
}

function filterBlocks(block, others) {
	if (block.length > 0) {
		others = others.filter(elem => (
			!block.map(el => (el.id_blocked)).includes(elem.id_user)));
		others = others.filter(elem => (
			!block.map(e => (e.id_author)).includes(elem.id_user)));
	}
	return (others);
}

/* FILTER BY SEX AND SEXPREF
 * THEN BY AGE
 * THEN BY DISTANCE
 * THEN BY POPULAR SCORE
 * THEN BY TAGS
 */
function filterProfils(search, searchOthers)
{
	let profils = searchOthers;
	if (search.filter.sex)
	{
		profils = searchOthers.filter(e => {
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
		});
	}
	if (search.filter.age)
		profils = profils.filter(e => (e.age >= search.ageMin && e.age <= search.ageMax))
	if (search.filter.local)
		profils = profils.filter(e => (distanceKm(e.latitude, e.longitude,
			search.lat, search.lon) <= search.localMax))
	if (search.filter.popular)
		profils = profils.filter(e => (e.popular >= search.popularMin && e.popular <= search.popularMax))
	if (search.filter.tags)
		profils = profils.filter(e => (search.tags.map(e => (e.name_interest)).every(f => (e.interest.includes(f)))))
	if (search.filter.search && search.filter.search.bool === true
		&& search.filter.search.val)
	{
		if (/^[a-zA-Z]+$/.test(search.filter.search.val))
		{
			let regexp = new RegExp(search.filter.search.val, 'i');
			profils = profils.filter(e => (e.username.match(regexp)
				|| e.firstname.match(regexp)))
		}
	}
	return (profils);
}

function changeTri(tab, crit, search, sens) {
	if (crit === 'age') {
		if (sens === true)
			tab.sort((a, b) => (a.age > b.age) ? 1 : -1);
		else
			tab.sort((a, b) => (a.age < b.age) ? 1 : -1);
	} else if (crit === 'localisation') {
		if (sens === true)
			tab.sort((a, b) => (distanceKm(a.latitude, a.longitude,
				search.lat, search.lon) > distanceKm(b.latitude, b.longitude, search.lat, search.lon)) ? 1 : -1);
		else
			tab.sort((a, b) => (distanceKm(a.latitude, a.longitude,
				search.lat, search.lon) < distanceKm(b.latitude, b.longitude, search.lat, search.lon)) ? 1 : -1);
	} else if (crit === 'popular') {
		if (sens === true)
			tab.sort((a, b) => (a.popular > b.popular) ? 1 : -1);
		else
			tab.sort((a, b) => (a.popular < b.popular) ? 1 : -1);
	} else if (crit === 'tags') {
		let tmpSearch = [...search.defaultTags];
		tmpSearch = tmpSearch.map(e => (e.name_interest));
		if (sens === true)
			tab.sort((a, b) => (countCommonTag(a.interest, tmpSearch) < countCommonTag(b.interest, tmpSearch)) ? 1 : -1);
		else
			tab.sort((a, b) => (countCommonTag(a.interest, tmpSearch) > countCommonTag(b.interest, tmpSearch)) ? 1 : -1);
	}
	return (tab);
}

function countCommonTag(tab1, tab2) {
	let count = 0;
	for (var i = 0; i < tab1.length; i++) {
		if (tab2.includes(tab1[i]))
			count += 1;
	}
	return (count);
}

function troncDate(date) {
	if (date)
	{
		date = new Date(date);
		date = `${date.getDate()}/${date.getMonth() + 1} à ${date.getHours()}h${date.getMinutes()}`;
	}
	return (date);
}
