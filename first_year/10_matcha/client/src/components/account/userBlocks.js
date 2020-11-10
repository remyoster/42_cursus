import React, { useState, useEffect } from 'react';
import axios from 'axios';

export default function UserBlocks(props) {
	const [id, token] = props.id;
	const [search, dispatchSearch] = props.info;
	const [others, setOthers] = useState([]);
	const [error, setError] = useState(null);

	useEffect(() => {
		async function fetchOthersData(ids) {
			let res = await axios.get(`/user/others/blocked/${ids}`);
			if (res.data)
				setOthers(res.data);
			else
				setError('Une erreur est survenue.');
		}
		if (search.blocks.length > 0)
		{
			let ids = search.blocks.filter(e => (e.id_blocked !== id))
				.map(e => (e.id_blocked)).join(',');
			if (ids !== '')
				fetchOthersData(ids);
		}
		else
			setOthers([]);
	}, [search.blocks, id]);

	async function deblock(e) {
		try {
			let res = await axios.post('/user/others/deblock', {
				id_blocked: e,
				id_author: id,
				id: id,
				token: token
			});
			if (res.data === 'OK')
				dispatchSearch({type: 'NEW_BLOCK',
					payload: search.blocks.filter(f => (f.id_blocked !== e))
				});
			else
				setError('Une erreur est survenue.');
		} catch (err) {
			setError('Une erreur est survenue.');
		}
	}

	return (
		<div className='blocked'>
		<h2>- Les utilisateurs que tu bloques -</h2>
			{error && <p>{error}</p>}
			<ul className='blocked-wrap'>
					{others && others.map((e, index) => (
						<li className='blockedUser' key={index}>
							<img src={e.img} alt={'profilpic' + e.id_user} />
							<br/>
								{e.username}
							<br/>
								{e.city}
							<br/>
							<button className="deblock" onClick={() => deblock(e.id_user)}>
									Débloquer l'utilisateur
							</button>
						</li>
					))}
					</ul>
				</div>
	)
}
