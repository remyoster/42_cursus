import React from 'react'
import { render } from '@testing-library/react'
import { Provider } from 'react-redux'
import { createStore, combineReducers } from 'redux';
import { boardReducer } from './reducers/boardReducer';
import { gameReducer } from './reducers/gameReducer';
import { chatReducer } from './reducers/chatReducer';

/*
** Tricks to inject state from redux into component when testing
*/

const reducer = combineReducers({
  game: gameReducer,
  board: boardReducer,
  chat: chatReducer
});

function customRender(
  ui,
  {
    initialState,
    store = createStore(reducer, initialState),
    ...renderOptions
  } = {}
) {
  function Wrapper({ children }) {
    return <Provider store={store}>{children}</Provider>
  }
  return render(ui, { wrapper: Wrapper, ...renderOptions })
}

export * from '@testing-library/react'
export { customRender }
