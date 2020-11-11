## Available Scripts for correcting

- To do the correction you can launch :
`npm run install-server && npm start`.

- To rebuild (to be sure that build is correct) and start :
`npm run install-client && npm run install-server && npm start`

- To launch the test :
`npm run install-all && npm test`
OR (is dependencies allready installed)
npm test

### `npm run install-server`

Install server's dependencies

### `npm run install-client`

Install client's dependencies and build the app

### `npm run install-all`
Install client and server dependencies

### `npm start`

Run the server

### `npm test`

Run test in concurrently mode (need install-all before)