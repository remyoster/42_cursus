export function requestListGame() {
  return { type: "REQUEST_LIST_GAME" };
}

export function requestConnect(name) {
  return ({ type: "REQUEST_CONNECT", payload: name });
}

export function requestNewGame(data) {
  return { type: "REQUEST_NEW_GAME", payload: data };
}

export function requestJoinGame(data) {
  return { type: "REQUEST_JOIN_GAME", payload: data };
}

export function requestChangeOption(data) {
  return ({ type: "REQUEST_CHANGE_OPTION", payload: data })
}

export function requestStartGame(data) {
  return { type: "REQUEST_START_GAME", payload: data };
}

export function requestLeaveRoom() {
  return { type: "REQUEST_LEAVE_ROOM" };
}

export function requestNewPiece(data) {
  return { type: "REQUEST_NEW_PIECE", payload: data };
}

export function updateSpectrum(data) {
  return { type: "UPDATE_SPECTRUM", payload: data };
}

export function addPenaltyLines(data) {
  return { type: "ADD_PENALTY_LINES", payload: data };
}

export function actionError(data) {
  return { type: "ERROR", payload: data };
}

export function removeError() {
  return { type: "REMOVE_ERROR" };
}

export function requestCheckReload(data) {
  return { type: "REQUEST_CHECK_RELOAD", payload: data };
}

export function requestDisconnect() {
  return { type: "REQUEST_DISCONNECT" }
}

export function requestGameOver(data) {
  return ({ type: "REQUEST_GAME_OVER", payload: data });
}

export function requestBackToOption() {
  return ({ type: "REQUEST_BACK_TO_OPTION" });
}

export function requestQuitGame() {
  return ({ type: "REQUEST_QUIT_GAME"});
}

export function requestChatMessage(data) {
  return ({ type: "REQUEST_CHAT_MESSAGE", payload: data });
}

export function requestBestGames() {
  return ({ type: "REQUEST_BEST_GAMES" });
}