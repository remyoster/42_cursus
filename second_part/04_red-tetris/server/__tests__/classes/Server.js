const Server = require("../../classes/Server");

describe("server in classe server", () => {
    let server = new Server();
    it("test new server", () => {
        expect(server).toBeDefined();
    });
    it("function close", () => {
        expect(server.close()).toEqual("close");
    });
});