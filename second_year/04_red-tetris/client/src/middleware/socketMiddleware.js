import {
  EVENT_CLIENT_LISTENER,
  EVENT_CLIENT_EMIT,
} from "../constant/eventConstant";
import io from "socket.io-client";
let socket = null;

export const wsMiddleware = (store) => {
  return (next) => (action) => {
    if (socket) {
      if (action.type && EVENT_CLIENT_EMIT.indexOf(action.type) !== -1) {
        socket.emit(action.type, action.payload);
      }
    }
    return next(action);
  };
}

/*
** Socket setup, it connects with serv and if there was a ID/name it sends it
** when the connection is established (to deal with reload and deconnection)
*/

export const startWs = (store) => {
  if (!socket) {
    socket = io('http://localhost:3001/game');//PROD local et DEV 
    //socket = io("https://red-tetris-game.herokuapp.com/game");//PROD heroku
    socket.on('connect', () => {
      let state = store.getState();
      socket.emit("REQUEST_CHECK_RELOAD", state.game.id);
    });
    EVENT_CLIENT_LISTENER.forEach((event) => {
      socket.on(event, (payload) => {
        return store.dispatch({ type: event, payload });
      });
    });
  }
};
