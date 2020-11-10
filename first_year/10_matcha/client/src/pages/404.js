import React, { useState, useEffect } from 'react';
import Navbar from '../components/navbar';
import { navigate } from '@reach/router';

export default function NotFound() 
{
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
	if (count === 0)
		navigate('/');
	return (
		<>
		<Navbar />
		<p>Désolé cette page n'existe pas</p>
		<p>Vous serez redirigé dans {count}...</p>
		</>
	);
}
