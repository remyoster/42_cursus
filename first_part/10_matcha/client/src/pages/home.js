import React, { useEffect, useContext, useState } from 'react';
import Header from '../components/header';
import { Store } from '../store';
import { Link } from "@reach/router";
import Gallery from '../components/match/gallery';
import axios from 'axios';
import '../css/match.css';
import '../css/home.css';

export default function Home(props) {
	const { state }  = useContext(Store);
	const [others, setOthers] = useState([]);
	const [error, setError] = useState(null);
	const [loading, setLoading] = useState(true);

	useEffect(() => {
		const CancelToken = axios.CancelToken;
		const source = CancelToken.source();
		let intervalID;
		async function fetchOthersData() {
			try {
				let res = await axios.get(`/user/others/${state.id_session}`,
					{cancelToken: source.token});
			if (res.data)
			{
				setOthers(res.data);
				setLoading(false);
			}
			} catch (err) {
				if (axios.isCancel(err))
						source.cancel();
				else
					setError('Une erreur est survenue.');
			}
		}
		if (state.login)
		{
			fetchOthersData();
			intervalID = setInterval(fetchOthersData, 30000);
		}
		return () => {
			source.cancel();
			if (intervalID)
				clearInterval(intervalID);
		}
	}, [state.login, state.id_session]);

	if (state.login)
		return (
			<>
<Header />
	{error && <p>{error}</p>}
	<Gallery others={others} state={state} loading={loading} />
	</>
		);
	else
		return (
			<>
	<Header />
	<section className="homeLogout">
	{error && <p>{error}</p>}
		<div>
			<p>Trouve ta moitié - MATCHA -</p>
		</div>
	</section>
	<div className="home">-- Rejoins la communauté, Inscris toi --</div>
	<Link to='/inscription'><div id="heart" ></div></Link>
			</>
		);
}
