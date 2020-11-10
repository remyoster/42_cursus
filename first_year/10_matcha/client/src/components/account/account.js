import React, { useState } from 'react';
import axios from 'axios';
import Editpass from './editpass';

const action = 'CHANGE_MAIL';

export default function Account(props) {
	const [search, dispatchSearch] = props.info;
	const [mail, setMail] = useState(search.mail);
	const [error, setError] = useState('');

	async function editMail(e) {
		e.preventDefault();
		try {
			let res = await axios.post('registration/email', {
				value: mail});
			if (res.data.error)
				setError(res.data.error);
			else
			{
				res = await axios.post('user/editMail', {
					mail: mail,
					id: props.state.id_session,
					token: props.state.token
				});
				if (res.data === 'ok')
				{
					dispatchSearch({type: action, mail: mail});
					props.show('');
				}
				else
					setError(res.data);
			}
		} catch (err) {
			//console.error(err);
			setError('Une erreur est survenue.');
		}
	}

	function changeMail(e) {
		setMail(e.target.value);
	}

	return (
		<>
<h2>- Modifie tes informations de connexion -</h2>
	{error && <div className="error">{error}</div>}
	<div className='profil'>
		<form className="formInfo" onSubmit={editMail}>
			<div className="divForm">
				<label>Ton mail: </label>
				<input type="text" value={mail} onChange={changeMail} />
			</div>
			<input type="submit" className="send" value="Modifier l'email"/>
		</form>
		<Editpass token={props.state.token} show={props.show} login={props.state.login}/>
	</div>
	</>
	);
}
