import React, { useEffect, useState, useContext } from 'react';
import axios from 'axios';
import Slider from '@material-ui/core/Slider';
import { SearchStore } from '../../search';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import { faCoffee, faHeart, faTimes,
	faCheck, faEye, faStar } from '@fortawesome/free-solid-svg-icons'
import '../../css/searchBar.css';

export default function SearchBar() {
	const { search, dispatchSearch } = useContext(SearchStore);
	const [interest, setInterest ] = useState([]);
	const [age, setAge] = useState([search.ageMin || 18, search.ageMax || 28]);
	const [popular, setPopular] = useState([search.popularMin || 0,
		search.popularMax || 10]);
	const [local, setLocal] = useState(search.localMax || 10);
	const [userSearch, setUserSearch] = useState(search.filter.search.val || '');
	const [error, setError] = useState(null);
	let sexpref = search.sexpref;

	//GET ALL TAGS FROM DATABASE AND FILTER WITH search TAGS
	useEffect(() => {
		const CancelToken = axios.CancelToken;
		const source = CancelToken.source();
		async function fetchTags() {
			try {
				let q = await axios.get('/interest', {cancelToken: source.token});
				if (q.data)
				{
					let tmp = search.tags.map(e => (e.id_interest));
					setInterest(q.data.filter(e => (!tmp.includes(e.id_interest))));
				}
			} catch (e) {
				if (axios.isCancel(e))
						source.cancel();
				else
				{
				//	console.error(e);
					setError('Une erreur est survenue.');
				}
			}
		}
		if (search.loaded)
			fetchTags();
		return () => {
			source.cancel();
		}
	}, [search.tags, search.loaded]);

	useEffect(() => {
		if (search.ageMin && search.ageMax)
			setAge([search.ageMin, search.ageMax]);
		if (search.popularMin && search.popularMax)
			setPopular([search.popularMin,
				search.popularMax]);
	}, [search.ageMin, search.ageMax, search.popularMin,
		search.popularMax])

	//TOGGLE SLIDERS
	function changeAge(e, newValue) {
		dispatchSearch({type: 'SEARCHAGE',
			ageMin: newValue[0], ageMax: newValue[1]});
	}
	function changeAgeVal(e, newValue) {
		setAge(newValue);
	}

	function changeLocal(e, newValue) {
		dispatchSearch({type: 'SEARCHLOCAL', localMax: newValue});
	}
	function changeLocalVal(e, newValue) {
		setLocal(newValue);
	}

	function changePopular(e, newValue) {
		dispatchSearch({type: 'SEARCHPOPULAR',
			popularMin: newValue[0], popularMax: newValue[1]});
	}
	function changePopularVal(e, newValue) {
		setPopular(newValue);
	}

	function changeSexpref(e) {
		dispatchSearch({type: 'SEARCHSEXPREF', sexpref: e.target.value});
	}

	//TOGGLE TAGS
	function addTags(e) {
		let tag = interest.find(f => (f.id_interest === e))
		let newTag = [...search.tags, tag];
		dispatchSearch({type: 'SEARCHTAGS', tags: newTag});
	}
	function deleteTags(e) {
		let tag = search.tags.find(f => (f.id_interest === e));
		if (tag) {
			let newTag = search.tags.filter(f =>
				(tag.id_interest !== f.id_interest));
			dispatchSearch({type: 'SEARCHTAGS', tags: newTag});
		}
	}

	//TOGGLE GALLERY VIEWS
	function toggleSugg() {
		if (search.cat !== 'sugg')
			dispatchSearch({type: 'SEARCHSHOW', cat: 'sugg'});
	}
	function toggleLikes() {
		if (search.cat !== 'likes')
			dispatchSearch({type: 'SEARCHSHOW', cat: 'likes'});
	}
	function toggleMatchs() {
		if (search.cat !== 'matchs')
			dispatchSearch({type: 'SEARCHSHOW', cat: 'matchs'});
	}
	function toggleVisits() {
		if (search.cat !== 'visits')
			dispatchSearch({type: 'SEARCHSHOW', cat: 'visits'});
	}

	// TOGGLE FILTER
	function toggleFilter(e) {
		let newFilter = {...search.filter};
		if (e.target.id === 'sex')
			search.filter.sex ? newFilter.sex = false : newFilter.sex = true;
		else if (e.target.id === "age")
			search.filter.age ? newFilter.age = false : newFilter.age = true;
		else if (e.target.id === "local")
			search.filter.local ? newFilter.local = false : newFilter.local = true;
		else if (e.target.id === "popular")
			search.filter.popular ? newFilter.popular = false : newFilter.popular = true;
		else if (e.target.id === "tags")
			search.filter.tags ? newFilter.tags = false : newFilter.tags = true;
		else if (e.target.id === "search")
		{
			search.filter.search.bool ? newFilter.search.bool = false : newFilter.search.bool = true;
			if (newFilter.search.bool && userSearch.length > 3)
				newFilter.search.val = userSearch;
		}
		dispatchSearch({type: 'SEARCHFILTER', filter: newFilter});
	}

	//TOGGLE USER SEARCH
	function toggleUserSearch(e) {
		setUserSearch(e.target.value);
		if (search.filter.search.bool === true
		&& (/^[a-zA-Z]+$/.test(e.target.value) || e.target.value === ""))
			dispatchSearch({type: 'SEARCHFILTER', filter: {...search.filter,
				search: {bool: true, val: e.target.value}
			}});
	}

	return(
		<div id="searchBar">
			<nav>
				<ul>
						{search.cat === 'sugg' ? <li className='currentSearch' onClick={toggleSugg}><FontAwesomeIcon icon={faCoffee} /></li> : <li onClick={toggleSugg} ><FontAwesomeIcon icon={faCoffee} /></li> }
						{search.cat === 'visits' ? <li className='currentSearch' onClick={toggleVisits}><FontAwesomeIcon icon={faEye} /></li> : <li onClick={toggleVisits}><FontAwesomeIcon icon={faEye} /></li> }
							{search.cat === 'likes' ? <li className='currentSearch' onClick={toggleLikes} ><FontAwesomeIcon icon={faHeart} /></li> : <li onClick={toggleLikes}><FontAwesomeIcon icon={faHeart} /></li> }
								{search.cat === 'matchs' ? <li className='currentSearch' onClick={toggleMatchs}><FontAwesomeIcon icon={faStar} /></li> : <li onClick={toggleMatchs}><FontAwesomeIcon icon={faStar} /></li> }
							</ul>
						</nav>
						<div>
							<h4>Les filtres de recherche:</h4>
							<div className="titleSlide">
								<input id="sex" type="checkbox" onChange={toggleFilter} checked={search.filter.sex ? true : false} />
								<label htmlFor="sex">Sexe</label>
							</div>
							<div className="sexpref">
								<select value={sexpref} onChange={changeSexpref} className="searchSex">
									<option value="bi">&#9892; (Bi)</option>
									<option value="female">&#9792; (F)</option>
									<option value="male">&#9794; (M)</option>
									<option value="other">&#9900; (Autre)</option>
								</select>
							</div>
							<div className="titleSlide">
								<input id="age" type="checkbox" onChange={toggleFilter}
								checked={search.filter.age ? true : false}/>
								<label htmlFor="age">Age</label>
							</div>
							<div className={search.filter.age ? "slideActiv" : "slide"}>
								<Slider
									min= {18}
									max = {80}
									step={1}
									value={age}
									onChange={changeAgeVal}
									onChangeCommitted={changeAge}
									valueLabelDisplay="on"
									aria-labelledby="range-slider"
									aria-label="test"
								/>
								</div>
								<div className="titleSlide">
									<input id="local" type="checkbox" onChange={toggleFilter}
									checked={search.filter.local ? true : false}/>
									<label htmlFor="local">Localisation</label>
								</div>
								<div className={search.filter.local ? "slideActiv" : "slide"}>
									<Slider
										min= {10}
										max = {1000}
										value={local}
										step={5}
										onChange={changeLocalVal}
										onChangeCommitted={changeLocal}
										valueLabelDisplay="on"
										aria-labelledby="range-slider"
									/>
									</div>
									<div className="titleSlide">
										<input id="popular" type="checkbox" onChange={toggleFilter}
										checked={search.filter.popular ? true : false}/>
										<label htmlFor="popular">Popularité</label>
									</div>
									<div className={search.filter.popular ? "slideActiv" : "slide"}>
										<Slider
											min= {0}
											max = {200}
											value={popular}
											step={1}
											onChange={changePopularVal}
											onChangeCommitted={changePopular}
											valueLabelDisplay="on"
											aria-labelledby="range-slider"
										/>
										</div>
										<div className="titleSlide">
											<input id="tags" type="checkbox"  onChange={toggleFilter}
											checked={search.filter.tags ? true : false}/>
											<label htmlFor="tags">Tags</label>
										</div>
										<div className="sexpref">
										<ul className="tagSearch">
												{search.tags && search.tags.map((e, index) => (
													<li key={index} onClick={() => deleteTags(e.id_interest)} className="listDel"> {e.name_interest} <FontAwesomeIcon icon={faTimes} /></li>
												))}
												</ul>
												<ul className="tagSearch">
														{interest && interest.map((e, index) => (<li key={index} onClick={() => addTags(e.id_interest)} className="listAdd">{e.name_interest} <FontAwesomeIcon icon={faCheck} /></li>))}
													</ul>
														{error && <p>{error}</p>}
												</div>
							<div className="titleSlide">
								<input id="search" type="checkbox" onChange={toggleFilter} checked={search.filter.search.bool ? true : false} />
								<label htmlFor="search">Recherche</label>
							</div>
							<input type='text' value={userSearch} onChange={toggleUserSearch} />
												</div>
											</div>
	)
}
