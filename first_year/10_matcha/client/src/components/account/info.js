import React, { useState } from 'react';
import axios from 'axios';
import GetInterest from './getInterest';

const action = 'CHANGE_PUBLIC';

export default function Info(props) {
	const [id, token] = props.id;
	const [search, dispatchSearch] = props.info;
	const sexpref = useFormInput(search.sexpref);
	const bio = useFormInput(search.bio);
	const [city, setCity] = useState(search.city);
	const [sugg, setSugg] = useState('');
	const [error, setError] = useState(null);
	const [loading, setLoading] = useState(false);
	const [coord, setCoord] = useState([0,0]);


	async function handleEditProfil(e) {
		e.preventDefault();
		let lat;
		let lon;
		if (coord[0] !== 0 && coord[1] !== 0)
			[lat, lon] = coord;
		else
			[lat, lon] = await getLoc(city);
		let res = await axios.post('/user/editInfo', {
			sexpref: sexpref.value,
			bio: bio.value,
			id: id,
			token: token,
			lat: lat,
			lon: lon,
			city: city
		});
		if (res.data === "ok")
		{
			dispatchSearch({type: action, sexpref: sexpref.value,
				bio: bio.value, city: city, lat: lat, lon: lon});
			props.show('');
		}
		else
			setError(res.data);
	}
	
	async function changeCity(e) {
		setCity(e.target.value);
		try {
			let cities = await axios.get('https://geo.api.gouv.fr/communes?nom='+e.target.value);
			setSugg(cities.data);
		} catch (e) {
			//console.error(e);
			setError("Une erreur est survenue lors du chargement des villes");
		}
		document.getElementsByClassName('suggCity')[0].style.display = 'block';
	}

	function changeCitySugg(e) {
		setCity(e.target.id);
		document.getElementsByClassName('suggCity')[0].style.display = 'none';
	}

	function changeGeoloc(e) {
		e.preventDefault();
		setLoading(true);
		let  options = {
			enableHighAccuracy: true,
			timeout: 5000,
			maximumAge: 0
		};
		async function success(pos) {
			let crd = pos.coords;
			let res = await getCity(crd.latitude, crd.longitude);
			setCity(res);
			setCoord([crd.latitude, crd.longitude])
			setLoading(false);
		}
		navigator.geolocation.getCurrentPosition(success, (err) => {
				setError('Veuillez autoriser le navigateur à vous localiser');
			setLoading(false);
		}, options);
	}

	return (
		<>
<h2>- Tes informations pour matcher -</h2>
	{error && <div className="error">{error}</div>}
	<div className='profil'>
		<form className="formInfo" onSubmit={handleEditProfil}>
		<p className="paraInfo"> Remplis ta recherche, écris ta bio enfin clique pour être géolocalisé OU remplis ta ville </p>
			<div className="divForm">
				<label>Tu recherches: </label>
				<select {...sexpref} >
					<option value="bi">Une femme ou un homme</option>
					<option value="male">Un homme</option>
					<option value="female">Une femme</option>
					<option value="other">autre</option>
				</select>
			</div>
			<div className="divForm">
				<label>Ta courte description: </label>
				<textarea type='text' {...bio} maxLength="160"></textarea>
			</div>
				<button id="locCity" onClick={changeGeoloc}>
						Geolocalise moi
					</button> {loading && 'Loading...'}
			<div className="divForm city">
				<label>Ta ville: </label>
				<input className="city"type="text" value={city} onChange={changeCity}/>
				<ul className="suggCity">
						{sugg && sugg.map((e, index) => (
							<li key={index} id={e.nom} onClick={changeCitySugg}>{e.nom}</li>
						))}
						</ul>
					</div>
					<input className="send" type="submit" value="Enregistrer" />
				</form>
			</div>
					<GetInterest id={props.id} search={[search, dispatchSearch]} show={props.show} />
	</>
	);
}

function useFormInput(initialValue)
{
	const [value, setValue] = useState(initialValue);

	function handleChange(e) {
		setValue(e.target.value);
	}
	return {
		value,
		onChange: handleChange
	};
}

//GET CITY'S LATITUDE AND LONGITUDE
async function getLoc(city)
{
	try {
		let res = await axios.get(`https://nominatim.openstreetmap.org/search?q=${city}&format=json&addressdetails=1`);
		if (res.data[0] && res.data[0].address.country === 'France')
			return([res.data[0].lat, res.data[0].lon]);
		else
			return([0, 0]);
	} catch (err) {
		//console.error(err);
		return ([0, 0]);
	}
}

//GET CITY NAME WITH A LATITUDE AND LONGITUDE
async function getCity(lat, lon) {
	try {
		let res = await axios.get(`https://nominatim.openstreetmap.org/reverse?format=json&lat=${lat}&lon=${lon}&addressdetails=1`);
		return (res.data.address.city);
	} catch (err) {
		//console.error(err);
		return ('');
	}
}
