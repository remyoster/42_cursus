import React, { useContext, useEffect } from 'react'
import { Store } from './store';
import axios from 'axios';
export const SearchStore = React.createContext();

const initialState = {
	cat: '',
	mail: '',
	lastname: '',
	firstname: '',
	bio: '',
	gender: '',
	sexpref: '',
	ageMin: '',
	ageMax: '',
	defaultAge: '',
	birthdate: '',
	localMax: '',
	city: '',
	lat: '',
	lon: '',
	popularMin: '',
	popularMax: '',
	defaultPopular: '',
	defaultTags: [],
	tags: [],
	visits: [],
	likes: [],
	matchs: [],
	blocks: [],
	filter: {sex: true, age: false, local: false,
		popular: false, tags: false, search: {bool: false}},
	loaded: false,
	lastco: ''
};

function reducer(state, action) {
	switch (action.type) {
		case 'INIT':
			return (action.payload);
		case 'CHANGE_CIVIL':
			return({...state, lastname: action.lastname,
				firstname: action.firstname, gender: action.gender});
		case 'CHANGE_PUBLIC':
			return({...state, sexpref: action.sexpref, bio: action.bio,
				city: action.city, lat: action.lat, lon: action.lon});
		case 'CHANGE_TAGS':
			return ({...state, defaultTags: action.tags, tags: action.tags});
		case 'CHANGE_MAIL':
			return({...state, mail: action.mail});
		case 'SEARCHSHOW':
			return ({...state, cat: action.cat});
		case 'SEARCHAGE':
			return ({...state, ageMin: action.ageMin, ageMax: action.ageMax});
		case 'SEARCHLOCAL':
			return ({...state, localMax: action.localMax});
		case 'SEARCHPOPULAR':
			return ({...state, popularMin: action.popularMin, popularMax: action.popularMax});
		case 'SEARCHSEXPREF':
			return ({...state, sexpref: action.sexpref});
		case 'SEARCHTAGS':
			return ({...state, tags: action.tags});
		case 'SEARCHFILTER':
			return ({...state, filter: action.filter});
		case 'NEW_VISIT':
			return ({...state, visits: action.payload});
		case 'NEW_LIKE':
			return ({...state, likes: action.payload});
		case 'NEW_UNLIKE':
			return ({...state, likes: action.likes, matchs: action.matchs});
		case 'NEW_MATCH':
			return ({...state, likes: action.likes, matchs: action.matchs});
		case 'NEW_BLOCK':
			return ({...state, blocks: action.payload});
		case 'NEW_GAME':
			return ({...state, visits: action.visits, likes: action.likes});
		case 'UP_LASTCO':
			return ({...state, lastco: action.payload});
		default:
			return state;
	}
}

export function SearchProvider(props) {
	const [search, dispatchSearch] = React.useReducer(reducer, initialState);
	const value = { search, dispatchSearch };
	const { state } = useContext(Store);

	useEffect(() => {
		const CancelToken = axios.CancelToken;
		const source = CancelToken.source();
		async function fetchUserData() {
			try {
				let res = await axios.get(`/user/findWithId/${state.id_session}`,
					{cancelToken: source.token});
				let uInfo = res.data;
				res = await axios.get(`/user/interactions/${state.id_session}`,
					{cancelToken: source.token});
				let uInter = res.data;
				if (uInfo && uInter)
				{
					let agemin = uInfo.age - 5 < 18 ? 18 : uInfo.age - 5;
					let agemax = uInfo.age + 5 > 80 ? 80 : uInfo.age + 5;
					let popularMin = uInfo.popular - 15 < 0 ? 0 : uInfo.popular - 15;
					let popularMax = uInfo.popular + 15 > 195 ? 200 : uInfo.popular + 15;
					dispatchSearch({type: 'INIT', payload: {
						cat: 'sugg',
						mail: uInfo.mail,
						lastname: uInfo.lastname,
						firstname: uInfo.firstname,
						bio: uInfo.bio,
						gender: uInfo.gender,
						sexpref: uInfo.sexpref,
						ageMin: agemin,
						ageMax: agemax,
						defaultAge: uInfo.age,
						birthdate: uInfo.birthdate,
						localMax: 10,
						city: uInfo.city,
						lat: uInfo.latitude,
						lon: uInfo.longitude,
						popularMin: popularMin,
						popularMax: popularMax,
						defaultPopular: uInfo.popular,
						defaultTags: uInfo.tags,
						tags: uInfo.tags,
						visits: uInter.visits,
						likes: uInter.likes,
						matchs: uInter.matchs,
						blocks: uInter.blocks,
						filter: {sex: true, age: false, local: false,
							popular: false, tags: false, search: {bool: false}},
						loaded: true,
						lastco: uInfo.lastco
					}});
				}
			} catch (err) {
				if (axios.isCancel(err))
					source.cancel();
			}
		}
		if (state.login)
			fetchUserData();
		return () => {
			source.cancel();
		}
	}, [state.login, dispatchSearch, state.id_session]);

	return <SearchStore.Provider value={value}>
			{props.children}
	</SearchStore.Provider>
}
