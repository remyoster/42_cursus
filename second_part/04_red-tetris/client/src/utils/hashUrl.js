export function checkHashUrl(room, playerName) {
    if (window.location.hash) {
        let urlSplit = window.location.hash.split('[');
        let roomUrl = urlSplit[0].substring(1);
        let name = urlSplit[1].substring(0, urlSplit[1].length - 1);
        if (room !== roomUrl || playerName !== name) {
            return (false);
        }
    }
    return (true);
}