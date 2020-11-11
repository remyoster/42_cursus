import { useContext } from 'react';
import { Store } from '../store';
import { navigate } from "@reach/router";

function Logout() {
  const { state, dispatch }  = useContext(Store);
  let dispatchObj = {
    type: 'LOGOUT'
  };
  if (state.login) {
    dispatch(dispatchObj);
  }
  navigate('/');
return(null);
}

export default Logout;
