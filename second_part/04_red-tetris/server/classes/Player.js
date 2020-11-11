class Player {
  constructor(socketId, name, leader=false) {
    this.socketId = socketId;
    this.name = name;
    this.counterPieces = 2;
    this.spectrum = this.createBoard(10, 20);
    this.leader = leader;
    this.isOver = false;
  }

  getIndexNextTetri() {
    let index = this.counterPieces;
    this.counterPieces += 1;
    return index;
  }

  updateSpectrum(newSpectrum) {
    this.spectrum = newSpectrum;
    return this.spectrum;
  }

  createBoard(width, height) {
    width = parseInt(width) || 1;
    height = parseInt(height) || 1;
    return (Array.from({
      length: width * height
    }, (v, k) => k)
      .reduce((o, key) => ({
        ...o, [`${key % width},${parseInt(key / width)}`]: {
          occuped: false,
          color: null
        }
      }), {}));
  }

  resetcounterPieces(count) {
    this.counterPieces = count;
  }

  setNewLeader() {
    this.leader = true;
  }

  setIsOver(isOver) {
    this.isOver = isOver;
  }

  resetSpectrum() {
    this.spectrum = this.createBoard(10, 20);
  }

}
module.exports = Player;
