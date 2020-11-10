const Getter = require('../utils/Getter');

class Room {
  constructor(roomName = null) {
    this.name = roomName ? roomName : this.getRandomName();
  }

  getRandomName() {
    const names = [
      "JurassicPark",
      "StarWars",
      "Taxi",
      "Titanic",
      "TheFifthElement",
    ];
    let randomRoom = names[Math.floor(Math.random() * names.length)];
    return (Getter.randomId(randomRoom));
  }
}
module.exports = Room;
