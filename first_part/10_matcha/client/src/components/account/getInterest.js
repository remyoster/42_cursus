import React, { useState, useEffect } from 'react';
import axios from 'axios';
import '../../css/account.css'

const action = 'CHANGE_TAGS';

export default function GetInterest(props) {
	const [interest, setInterest ] = useState([]);
	const [search, dispatchSearch] = props.search;
	const [error, setError] = useState(null);
	const [id, token] = props.id;
	const [newTag, setNewTag] = useState('');

	useEffect(() => {
		async function getInterest(id) {
			try {
				let allInt = await axios.get('/interest');
				if (allInt.data && search.defaultTags.length > 0)
				{
					setInterest(allInt.data
						.filter(e => (!search.defaultTags
							.find(f => (f.id_interest === e.id_interest)))));
				}
				else if (allInt.data)
					setInterest(allInt.data);
				else
					setError('Une erreur est survenue.');
			} catch (err) {
			//	console.error(err);
				setError('Une erreur est survenue.');
			}
		}
		getInterest(id);
	}, [id, search.defaultTags])

	async function changeInterest(e) {
		let id_interest = parseInt(e.target.value, 10);
		try {
			let res = await axios.post('/interest/add', {id : id,
				interest : id_interest,
				token: token
			});
			if (res.data)
			{
				let name = interest.find(e => (e.id_interest === id_interest));
				dispatchSearch({type: action,
					tags: [...search.defaultTags, name]});
			}
			else
				setError('Une erreur est survenue.');
		} catch (err) {
		//	console.error(err);
			setError('Une erreur est survenue.');
		}
	}

	async function removeInterest(e) {
		try {
			let res = await axios.post('/interest/delete', {id : id,
				interest : e.id_interest,
				token: token
			});
			if (res.data)
				dispatchSearch({type: action,
					tags: search.defaultTags.filter(f => (f !== e))
				});
			else
				setError('Une erreur est survenue.');
		} catch (err) {
			//console.error(err);
			setError('Une erreur est survenue.');
		}
	}

	async function addTag(e) {
		e.preventDefault();
		if (/^[a-z]+$/.test(newTag) && newTag.length < 50)
		{
		if (!interest.find(e => (e.name_interest === newTag))
			&& !search.defaultTags.find(e => (e.name_interest === newTag)))
		{
			try {
				let res = await axios.post('/interest/addNewTag', {
					newTag: newTag,
					id: id,
					token: token
				});
				if (res.data)
				{
					dispatchSearch({type: action,
						tags: [...search.defaultTags, {id_interest: res.data.id,
							name_interest: newTag.toLowerCase()}]
					});
					setNewTag('');
				}
				else
					setError('Une erreur est survenue.');
			} catch (err) {
			//	console.error(err);
				setError('Une erreur est survenue.');
			}
		}
		else
			setError('Ce tag existe déjà.');
		}
		else
			setError('Seuls les minuscules sont autorisées (50lettres max).');
	}

	function handleNewTag(e) {
		setNewTag(e.target.value);
	}

	return (
	<div className='profil'>
{error && <p>{error}</p>}
<div className="selectInterest">
	<div className="divInterest">
	<p className="paraInfo"> Sélectionne un tag ou crée le </p>
	<p className="paraInfo"> Clique sur 'OK' pour revenir au résumé de ton profil</p>
		<select value='' onChange={changeInterest}>
			<option> -- Sélectionne un # -- </option>
				{interest.map((e, index) => (
					<option value={e.id_interest} key={index}>{e.name_interest}</option>
				))}
				</select>
			</div>
			<div className="divInterest">
				<label>Ou créer ton propre TAG:</label>
				<input type="text" onChange={handleNewTag} value={newTag} />
				<button className="buttonsend" onClick={addTag}>
						Ajouter
				</button>
			</div>
		</div>
		<div className="selectInterest">
			<ul className="tags">
					{search.defaultTags.map((e, index) => (
						<li key={index} onClick={() => removeInterest(e)}>
								#{e.name_interest}
							</li>))}
						</ul>
					</div>
					<button className='buttonsend' onClick={() => props.show('')}>
							OK
					</button>
			</div>
	);
}
