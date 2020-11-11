import React, { useState, useEffect, useContext } from 'react';
import axios from 'axios';
import Header from '../components/header';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import { faCheckCircle } from '@fortawesome/free-solid-svg-icons'
import { navigate } from '@reach/router';
import { Store } from '../store';
import NotFound from './404';
import '../css/form.css';

export default function Registration () {
	const gender = useFormInput('male');
	const birthdate = useFormInput('');
	const lastname = useFormInput('');
	const firstname = useFormInput('');
	const username = useFormInput('');
	const email = useFormInput('');
	const password = useFormInput('');
	const cfpassword = useFormInput('');
	const [success, setSuccess] = useState(null);
	const { state }  = useContext(Store);

	async function handleSubmit(e) {
		e.preventDefault();
		try {
			const res = await fetch('/registration',
				{
					method: 'POST',
					headers: {
						'Accept': 'application/json',
						'Content-Type': 'application/json'
					},
					body: JSON.stringify({
						gender: gender.value,
						birthdate: birthdate.value,
						lastname: lastname.value,
						firstname: firstname.value,
						username: username.value,
						email: email.value,
						password: password.value,
						cfpassword: cfpassword.value
					})
				});
			const data = await res.json();
			if (Object.keys(data).length === 0)
				setSuccess(true);
		} catch (error) {
			//console.error(error);
		}
	}

	if (state.login)
		return (<NotFound />);
	else if (success)
		return (
			<>
<Header />
<div className="containLogin">
<p>Merci pour votre inscription. Il ne vous reste plus qu'à valider votre compte via le lien que nous vous avons envoyé sur votre adresse mail.</p>
</div>
			</>
		);
	else
		return (
			<>
				<Header />
				<form className="formInfo" onSubmit={handleSubmit} style={{boxShadow:'0px 0px 5px 5px #8EC83C'}}>
					<Gender val={gender} />
					<Birthdate val={birthdate} />
					<Lastname val={lastname} />
					<Firstname val={firstname} />
					<Username val={username} />
					<Email val={email} />
					<Password val={password} />
					<Cfpassword val={cfpassword} pwd={password.value} />
					<input className="send" type="submit" value="Créer un compte" />
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
				const res = await axios.post(`registration/${name}`,
					{value: value});
				if (res.data.error)
					setError(res.data.error);
				else
					setError('OK');
			} catch (error) {
				//console.error(error);
			}
		}
		elem.addEventListener("blur", check_value);
		return () => {
			elem.removeEventListener("blur", check_value);
		};
	})
	return (error);
}

function Gender(props)
{
	return (
		<div className="divForm">
		<label>Tu es: </label>
			<select {...props.val} required>
				<option value="male">Un homme</option>
				<option value="female">Une femme</option>
				<option value="other">Autre</option>
			</select>
		</div>
	);
}

function Birthdate(props)
{
	const error = useCheckServForVal(props.val.value, 'date');
	const date = new Date();
	const year = date.getFullYear();
	var month = date.getMonth();
	month = month.toString().padStart(2, '0');
	var day = date.getDate();
	day = day.toString().padStart(2, '0');

	return (
		<div className="divForm">
		<label>
				Date de naissance:{error === 'OK'
						&& <FontAwesomeIcon icon={faCheckCircle} color='green'/>}
							{(error && error !== 'OK')
									&& <span className='error'>{error}</span>}
									</label>
									<input
										type='date'
										name='date'
										max={`${year - 18}-${month}-${day}`}
										min={`${year - 80}-${month}-${day}`}
										{...props.val}
										required />
								</div>
	);
}

function Lastname(props)
{
	const error = useCheckServForVal(props.val.value, 'lastname');

	return (
		<div className="divForm">
		<label>
				Nom:{error === 'OK' && <FontAwesomeIcon icon={faCheckCircle} color='green'/>}
					{(error && error !== 'OK') && <span className='error'>{error}</span>}
					</label>
					<input
						type='text'
						name='lastname'
						placeholder='MAT'
						{...props.val}
						required/>
				</div>
	);
}

function Firstname(props)
{
	const error = useCheckServForVal(props.val.value, 'firstname');

	return (
		<div className="divForm">
		<label>
				Prénom:{error === 'OK' && <FontAwesomeIcon icon={faCheckCircle}
					color='green'/>}
					{(error && error !== 'OK') && <span className='error'>{error}</span>}
					</label>
					<input
						type='text'
						name='firstname'
						placeholder='Cha'
						{...props.val}
						required />
				</div>
	);
}

function Username(props)
{
	const error = useCheckServForVal(props.val.value, 'username');

	return (
		<div className="divForm">
		<label>
				Pseudo:{error === 'OK' && <FontAwesomeIcon icon={faCheckCircle}
					color='green'/>}
					{(error && error !== 'OK') && <span className='error'>{error}</span>}
					</label>
					<input
						type='text'
						name='username'
						placeholder='Matchera'
						{...props.val}
						required />
				</div>
	);
}

function Email(props)
{
	const error = useCheckServForVal(props.val.value, 'email');

	return (
		<div className="divForm">
		<label>
				Email:{error === 'OK' && <FontAwesomeIcon icon={faCheckCircle}
					color='green'/>}
					{(error && error !== 'OK') && <span className='error'>{error}</span>}
					</label>
					<input
						type='email'
						name='email'
						placeholder='matcha@matcha.com'
						{...props.val}
						required />
				</div>
	);
}

function Password(props)
{
	const error = useCheckServForVal(props.val.value, 'password');

	return (
		<div className="divForm">
		<label>
				Mot de passe:{error === 'OK'
						&& <FontAwesomeIcon icon={faCheckCircle} color='green'/>}
							{(error && error !== 'OK') && <span className='error'>{error}</span>}
							</label>
							<input
								type='password'
								name='password'
								placeholder='matcha'
								{...props.val}
								required />
						</div>
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
				const res = await axios.post('registration/cfpassword',
					{
						cfpassword: cfpassword.value,
						password: password
					});
				if (res.data.error)
					setError(res.data.error);
				else
					setError('OK');
			} catch(error) {
				//console.error(error);
			}
		}
		elem.addEventListener("blur", check_cfpassword);
		return () => {
			elem.removeEventListener("blur", check_cfpassword);
		};
	})

	return (
		<div className="divForm">
		<label>
				Confirmation:{error === 'OK' && <FontAwesomeIcon icon={faCheckCircle}
					color='green'/>}
					{(error && error !== 'OK') && <span className='error'>{error}</span>}
					</label>
					<input
						type='password'
						name='cfpassword'
						placeholder='matcha'
						{...cfpassword}
						required />
				</div>
	);
}

export function Validate(props)
{
	const [data, setData] = useState(false);
	const [count, setCount] = useState(7);

	useEffect(() => {
		function tick() {
			setCount(count - 1);
		}
		var intervalID = setInterval(tick, 1000);
		return function cleanup() {
			clearInterval(intervalID);
		}
	})

	async function validate() {
		const response = await axios.get(`/registration/activate/${props.token}`)
		if (response.data !== 'OK')
			setData(response.data);
	}
	if (!data)
		validate();
	if (count === 0)
		navigate('/connexion');

	return (
		<>
				<Header />
				<div className="containLogin">
					{data && <p>{data}</p>}
					<p>Vous serez redirigé dans {count}...</p>
				</div>
			</>
	);
};
