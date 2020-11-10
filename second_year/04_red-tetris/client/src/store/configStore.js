import { createStore, applyMiddleware, combineReducers } from 'redux';
import { persistStore, persistReducer } from 'redux-persist';
import storage from 'redux-persist/lib/storage';
import { gameReducer } from '../reducers/gameReducer';
import { boardReducer } from '../reducers/boardReducer';
import { chatReducer } from '../reducers/chatReducer';
import { startWs, wsMiddleware } from '../middleware/socketMiddleware';

const authPersistConfig = {
  key: "redTetris-auth",
  storage: storage,
  whitelist: ['id', 'playerName']
}

const reducer = combineReducers({
  game: persistReducer(authPersistConfig, gameReducer),
  board: boardReducer,
  chat: chatReducer,
});

const store = createStore(
  reducer,
  applyMiddleware(wsMiddleware),
);
const persistor = persistStore(store);
startWs(store);

export { persistor, store };
