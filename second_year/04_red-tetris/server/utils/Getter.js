class Getter {
    static listGameAvailable(games) {
        return (
            games.filter(e => e.type === "multi" && e.isJoinable())
                .map(e => ({
                    name: e.room.name,
                    options: e.options,
                    leader: e.getLeader().name,
                    nbPlayers: e.players.length
                }))
        );
    }

    static findGameWithRoomName(games, roomName) {
        return (games.find(e => e.room.name === roomName));
    }

    static findGameWithPlayerName(games, playerName) {
        let findGame = null;
        let indexPlayer = -1;
        games.forEach(e => {
            let index = e.players.findIndex(item => item.name === playerName);
            if (index !== -1) {
                findGame = e;
                indexPlayer = index;
            }
        });
        return { findGame, indexPlayer };
    }

    static findGameWithSocketId(games, socketId) {
        return (games.find(e => e.players.find(f => f.socketId === socketId)));
    }

    static playerIdxWithName(game, playerName) {
        if (game && game.players)
            return game.players.findIndex(
                (e) => e.name === playerName
            );
    }

    static playerWhithSocketId(game, socketId) {
        if (game && game.players)
            return (game.players.find(e => e.socketId === socketId));
    }

    static playerIdxWhithSocketId(game, socketId) {
        if (game && game.players)
            return (game.players.findIndex((e) => e.socketId === socketId));
        return (-1);
    }

    static randomId(name, length=5) {
        let random = "";
        let characters =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        for (let i = 0; i < length; i++) {
            random += characters.charAt(Math.floor(Math.random() * characters.length));
        }
        return name + "_" + random;
    }
}

module.exports = Getter;
