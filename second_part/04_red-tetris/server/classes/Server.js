const Socket = require("./Socket");
const express = require("express");
const http = require("http");
const path = require('path');
const PORT = process.env.PORT || 80;

class Server {
    constructor() {
        this.app = express();
        this.server = http.Server(this.app);
        this.socket = new Socket(this.server).listenToEvents();
    }
    listen() {
        this.app.use(express.static(path.join(__dirname + '/../../client/build')));
        this.app.use(function (req, res, next) {
            res.sendFile(path.join(__dirname, '/../../client/build', 'index.html'));
        });

        this.server.listen(PORT, function () {
            console.log("Red tetris app listening on port " + PORT + "!");
        });
    }
    close() {
        this.server.close();
        return "close";
    }
}

module.exports = Server;