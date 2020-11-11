const Room = require("./Room");
const Player = require("./Player");
const Piece = require("./Piece");

class Game {
  constructor(data = {}) {
    this.room = data.room ? new Room(data.room) : new Room();
    this.type = data.type;
    this.isStart = false;
    this.players = [];
    this.options = data.options ? data.options : {
      ghostMode: true,
      fullSpectrum: false,
      colorMode: 'normal',
      startingLevel: 0,
      dropTimeRef: 1000,
    };
    this.isOver = false;
    this.tetrigen = new Piece();
    this.pieces = [];
  }

  setPieces() {
    let pieces = [];
    let countTetri = 100;
    let tetri;
    for (let i = 0; i < countTetri; i++) {
      tetri = this.tetrigen.getRandomShape(this.options.colorMode);
      pieces.push(tetri);
    }
    return (pieces);
  }

  setIsStart() {
    this.pieces = this.setPieces();
    this.isStart = true;
    this.players.forEach(e => e.resetcounterPieces(2));
    let first = this.pieces[0];
    let next = this.pieces[1];
    return { first, next };
  }

  changeOption(name, value) {
    if (this.options[name] !== undefined)
      this.options[name] = value;
    return (this.options);
  }

  addPlayer(player) {
    let leader = this.players.length ? false : true;
    let newPlayer = new Player(player.socketId, player.name, leader);
    return this.players.push(newPlayer);
  }

  removePlayer(index) {
    let leader = this.players[index].leader ? true : false;
    this.players.splice(index, 1);
    if (leader && this.players.length)
      this.players[0].setNewLeader();
    return (this.players);
  }

  resetGame() {
    this.pieces = this.setPieces();
    this.isStart = false;
  }

  setGameOver() {
    this.isOver = true;
    this.isStart = false;
  }

  restartGame() {
    this.players.forEach(e => {
      e.setIsOver(false);
      e.resetSpectrum();
    });
    this.isOver = false;
  }
  
  setNewPieces() {
    let pieces_bis = this.setPieces();
    this.pieces = this.pieces.concat(pieces_bis);
  }

  /*
  ** Boolean function to check if the game is joinable
  */

  isJoinable() {
    return (this.players.length < 5 && !this.isStart)
  }

  /*
  ** Boolean function to check if the leader can start the game 
  */

  isStartable() {
    return (this.type === 'solo'
      || (this.type === 'multi' && this.players.length > 1));
  }

  /*
  ** Return the lead player
  */

  getLeader() {
    return (this.players.find(e => e.leader));
  }
}

module.exports = Game;
