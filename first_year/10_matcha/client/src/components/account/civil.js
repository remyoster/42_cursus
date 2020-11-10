import React, { useState } from 'react';
import axios from 'axios';

const action = 'CHANGE_CIVIL';

export default function Civil(props) {
	const [id, token]  = props.id;
	const [search, dispatchSearch] = props.info;
	const lastname = useFormInput(search.lastname);
	const firstname = useFormInput(search.firstname);
	const gender = useFormInput(search.gender);
	const [error, setError] = useState(null);

	async function handleLastname(e) {
		let name = e.target.value;
		let res = await axios.post('registration/lastname', { value: name });
		if (res.data.error)
			setError(res.data.error+" -> Nom");
		else if (!res.data.error && error)
			setError(null);
	}

	async function handleFirstname(e) {
		let name = e.target.value;
		let res = await axios.post('registration/firstname', { value: name });
		if (res.data.error) {
			setError(res.data.error+" -> Prenom");
		}else if (!res.data.error && error)
			setError(null);
	}

	async function handleEditCivil(e) {
		e.preventDefault();
		if (!error)
		{
		try {
			let res = await axios.post('/user/editCivil', {
				lastname: lastname.value,
				firstname: firstname.value,
				gender: gender.value,
				id: id,
				token : token
			});
			if (res.data === 'ok')
			{
				dispatchSearch({type: action, lastname: lastname.value.toUpperCase(), firstname: firstname.value, gender: gender.value});
				props.show('');
			}
			else
				setError(res.data)
		} catch (err) {
		//	console.error(err);
			setError('Une erreur est survenue');
		}
		}
	}

	return (
		<>
<h2>- Tes informations personnelles -</h2>
<div className="profil">
		{error && <div className="error">{error}</div>}
		<form className="formInfo" onSubmit={handleEditCivil}>
			<div className="divForm">
				<label>Ton nom: </label>
				<input type='text' {...lastname} onBlur={handleLastname} />
			</div>
			<div className="divForm">
				<label>Ton prénom: </label>
				<input type='text' {...firstname} onBlur={handleFirstname} />
			</div>
			<div className="divForm">
				<label>Ta date de naissance:</label>
				<input type='text' value={search.birthdate} disabled />
			</div>
			<div className="divForm">
				<label>Tu es: </label>
				<select {...gender}>
					<option value="male">un homme</option>
					<option value="female">une femme</option>
					<option value="other">autre</option>
				</select>
			</div>
			<input className="send" type="submit" value="Modifier" />
		</form>
	</div>
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
