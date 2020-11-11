import React, { useContext, useState, useEffect } from 'react';
import { Link, navigate } from '@reach/router';
import axios from 'axios';
import NotFound from './404';
import Header from '../components/header';
import { Store } from '../store';
import '../css/form.css';

export default function Login() {
	const { state, dispatch }  = useContext(Store);

	const identity = useFormInput('');
	const password = useFormInput('');
	let [error, setError] = useState(null);
	let [geoloc, setGeoloc] = useState({latitude: 0, longitude: 0});

	useEffect(() => {
		function maPosition(pos) {
			let lat = pos.coords.latitude;
			let lon = pos.coords.longitude;
			setGeoloc({latitude: lat, longitude: lon});
		}
		async function forcePosition() {
			try {
				let res = await axios.get(`http://api.ipstack.com/check?access_key=${process.env.REACT_APP_IPSTACKKEY}`);
				let lat = res.data.latitude;
				let lon = res.data.longitude;
				setGeoloc({latitude: lat, longitude: lon});
			} catch (e) {
				//console.error(e);
				setError("Une erreur est survenue.");
			}
		}
		var watchId = navigator.geolocation.watchPosition(maPosition,
			function(error) {
				if (error.code === error.PERMISSION_DENIED)
					forcePosition();
			});
		return () => {
			navigator.geolocation.clearWatch(watchId);
		};
	}, [])

	async function handleLogin(e) {
		e.preventDefault();
		try {
			let result = await axios.post('/login',
				{
					identity: identity.value,
					password: password.value,
					lat: geoloc.latitude,
					lon: geoloc.longitude
				});
			let data = result.data;
			if (data.id_user)
			{
				dispatch({
					type: 'LOGIN',
					id: data.id_user,
					username: data.username,
					token: data.token,
					img: data.img

				});
				navigate('/');
			}
			else
				setError(data);
		} catch(err) {
			//console.error(err);
			setError("Une erreur est survenue.");
		}
	}

	if (!state.login)
		return (
			<React.Fragment>
				<Header />
				<div className="containLogin">
						{error && <div>{error}</div>}
						<form className="formInfo" onSubmit={handleLogin}>
							<div className="divForm">
								<label>Pseudo ou mail: </label>
								<input type='text' {...identity} />
							</div>
							<div className="divForm">
								<label>Mot de passe: </label>
								<input type='password' {...password}/>
							</div>
							<Link className="sendForget" to='/connexion/oublie'>Mot de passe oublie</Link>
							<input className="send" type="submit" value="Se connecter" />
						</form>
					</div>
				</React.Fragment>
		);
	else
		return (<NotFound />);
}

export function Forgotpass() {
	let [error, setError] = useState(null);
	const identity = useFormInput('');

	async function handleForgot(e) {
		e.preventDefault();
		try {
			let result = await axios.post('/forgotpass', {
				identity: identity.value
			});
			if (result.data === "send")
				navigate('/');
			else
				setError(result.data);
		} catch (e) {
			//console.error(e);
			setError("Une erreur est survenue.");
		}
	}

	return (
		<>
		<Header />
			{error && <div>{error}</div>}
			<div className="containLogin">
			<form className="formInfo" onSubmit={handleForgot}>
				<div>
					<label>Pseudo ou mail: </label>
					<input type='text' {...identity} />
				</div>
				<input className="send" type="submit" value="Envoyer" />
			</form>
			</div>
	</>
	);
}

function useFormInput(init) {
	const [value, setValue] = useState(init);

	function handleChange(e) {
		setValue(e.target.value);
	}
	return {
		value,
		onChange: handleChange
	};
}
