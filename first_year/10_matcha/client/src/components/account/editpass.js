import React, { useState, useEffect } from 'react';
import axios from 'axios';
import { navigate } from "@reach/router";
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import { faCheckCircle } from '@fortawesome/free-solid-svg-icons'

export default function Editpass(props) {
	const password = useFormInput('');
	const cfpassword = useFormInput('');
	const [error, setError] = useState(null);

	async function handleEditPass(e) {
		e.preventDefault();
		try {
			let result = await axios.post('/editpass', {
				password: password.value,
				token: props.token
			});
			if (result.data === "ok" && !props.login)
				navigate('/connexion');
			if (result.data === "ok" && props.login)
				props.show('');
			else
				setError('Le changement de mot de passe n\'est pas effectif');
		} catch (err) {
			setError('Une erreur est survenue.');
		}
	}

	return (
		<>
{error && <div>{error}</div>}
<form className="formInfo" onSubmit={handleEditPass}>
	<Password val={password} className="divForm"/>
	<Cfpassword val={cfpassword} pwd={password.value} className="divForm" />
	<input className="send" type="submit" value="Valider" />
</form>
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

function useCheckServForVal(value, name)
{
	const [error, setError] = useState('');

	useEffect(() => {
		var elem = document.getElementsByTagName('input')[name];
		async function check_value (e) {
			try {
				const res = await axios.post(`/registration/${name}`,
					{value: value});
				if (res.data.error)
					setError(res.data.error);
				else
					setError('OK');
			} catch (err) {
				//console.error(err);
				setError('Une erreur est survenue.');
			}
		}
		elem.addEventListener("blur", check_value);
		return () => {
			elem.removeEventListener("blur", check_value);
		};
	})
	return (error);
}

function Password(props)
{
	const error = useCheckServForVal(props.val.value, 'password');

	return (
		<>
		<div className="divForm">
			<label>
					Mot de passe:{error === 'OK'
							&& <FontAwesomeIcon icon={faCheckCircle} color='green'/>}
							</label>
							<input
								type='password'
								name='password'
								placeholder='matcha'
								{...props.val}
								required />
						</div>
								{(error && error !== 'OK') && <span className='error'>{error}</span>}
						</>
	);
}

function Cfpassword(props)
{
	let cfpassword = props.val;
	let password = props.pwd;
	const [error, setError] = useState('');

	useEffect(() => {
		var elem = document.getElementsByTagName('input')['cfpassword'];
		async function check_cfpassword (e) {
			try {
				const res = await axios.post('/registration/cfpassword',
					{
						cfpassword: cfpassword.value,
						password: password
					});
				if (res.data.error)
					setError(res.data.error);
				else
					setError('OK');
			} catch (err) {
			//	console.error(err);
				setError('Une erreur est survenue.');
			}
		}
		elem.addEventListener("blur", check_cfpassword);
		return () => {
			elem.removeEventListener("blur", check_cfpassword);
		};
	})

	return (
		<>
		<div className="divForm">
			<label>
					Confirmation:{error === 'OK' && <FontAwesomeIcon icon={faCheckCircle}
						color='green'/>}
					</label>
					<input
						type='password'
						name='cfpassword'
						placeholder='matcha'
						{...cfpassword}
						required />
				</div>
						{(error && error !== 'OK') && <span className='error'>{error}</span>}
		</>
	);
}
