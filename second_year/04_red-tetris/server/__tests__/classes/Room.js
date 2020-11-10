const Room = require("../../classes/Room");

describe("Room class", () => {
    it('constructor', () => {
        const rooms = [
            "JurassicPark",
            "StarWars",
            "Taxi",
            "Titanic",
            "TheFifthElement",
        ];
        const regex = new RegExp('^' + rooms.join('|') + '_[a-zA-Z0-9]{5}$');
        let randomRoom = new Room();
        let nameRoom = new Room('testRoom');
        expect(nameRoom.name).toEqual("testRoom");
        expect(randomRoom.name).toEqual(
            expect.stringMatching(regex));
    })
});