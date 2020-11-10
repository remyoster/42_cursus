import React, { useContext } from 'react';
import Header from '../components/header';
import Sidebar from '../components/account/sidebar';
import NotFound from '../pages/404';
import { Store } from '../store';
import '../css/account.css';

export default function Account() 
{
	const { state } = useContext(Store);

	if (!state.login)
		return (<NotFound />);
	else
		return (
			<>
		<Header />
		<Sidebar state={state} />
</>
		);
}
