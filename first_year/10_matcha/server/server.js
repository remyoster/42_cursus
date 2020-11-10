//MAIN MODULES
const express = require('express');
const bodyParser = require('body-parser');
const helmet = require('helmet');
const compression = require('compression');
const path = require('path');
const port = 3001;
exports.port = port;

//CONTROLLERS
const registration = require('./controller/registration.js');
const login = require('./controller/login.js');
const user = require('./controller/user.js');
const interest = require('./controller/interest.js');
const upload = require('./controller/upload.js');
const socketController = require('./controller/socket.js').socketController;

const app = express();
const server = require('http').Server(app);

//PROXY TO REDIRECT REQUEST FROM FRONT
app.set('trust proxy', 1);

//SOCKET
const io = require('socket.io')(server, {
pingTimeout: 60000});
socketController(io);

//MIDDLEWARES
app.use(helmet());
app.use(compression());
app.use(bodyParser.urlencoded({extended: false}));
app.use(bodyParser.json());
app.use('/public', express.static(__dirname + '/public'));

app.use(express.static(path.join(__dirname + '/build')));
app.use(async function (req, res, next) {
	let reg = /registration|login|upload|forgotpass|editpass/;
	if (req.method === 'POST' && !reg.test(req.path))
	{
		let pass = await user.checkToken(req.body.id, req.body.token);
		if (pass)
			next();
		else
			res.status(200).send('null');
	}
	else
		next();
});

//PROD
app.get('/', function (req, res) {
	res.sendFile(path.join(__dirname, 'build', 'index.html'));
});
app.get('/activate/:token', function (req, res) {
	res.sendFile(path.join(__dirname, 'build', 'index.html'));
});
app.get('/inscription', function (req, res) {
	res.sendFile(path.join(__dirname, 'build', 'index.html'));
});
app.get('/connexion', function (req, res) {
	res.sendFile(path.join(__dirname, 'build', 'index.html'));
});
app.get('/jouer', function (req, res) {
	res.sendFile(path.join(__dirname, 'build', 'index.html'));
});
app.get('/profil', function (req, res) {
	res.sendFile(path.join(__dirname, 'build', 'index.html'));
});
app.get('/activate/:token', function (req, res) {
	res.sendFile(path.join(__dirname, 'build', 'index.html'));
});


//LOGIN
app.post('/login', login.check_data);
app.post('/forgotpass', login.forgotpass);
app.post('/editpass', login.editpass);


//REGISTRATION
app.get('/registration/activate/:token', async (req, res) => {
	if (req.params.token
		&& await registration.activate_account(req.params.token))
		res.status(200).send("Votre compte est activé")
	else
		res.status(200).send("Le lien n'est plus valide");
});
app.post('/registration', registration.check_data);
app.post('/registration/:check', async (req, res) => {
	try {
		if (req.params.check == 'date')
			res.send(registration.check_birthdate(req.body.value));
		else if (req.params.check == 'lastname')
			res.send(registration.check_lastname(req.body.value));
		else if (req.params.check == 'firstname')
			res.send(registration.check_firstname(req.body.value));
		else if (req.params.check == 'username')
			res.send(await registration.check_username(req.body.value));
		else if (req.params.check == 'email')
			res.send(await registration.check_email(req.body.value));
		else if (req.params.check == 'password')
			res.send(registration.check_password(req.body.value));
		else if (req.params.check == 'cfpassword')
			res.send(registration.check_cfpassword(req.body.password,
				req.body.cfpassword));
		else
			res.send({});
	} catch (err) {
		console.error(err);
		res.send({});
	}
});

//user
app.get('/user/findWithId/:id', user.find_withid);
app.get('/user/message/:ids', user.getMessages);
app.get('/user/notif/:id', user.getNotifs);
app.get('/user/chat/:id/:date', user.getOlderChat);
app.post('/user/others/fake', user.fakeUser);
app.post('/user/others/block', user.blockUser);
app.post('/user/others/deblock', user.deblockUser);

//MATCH
app.get('/user/others/:id', user.getOthersInfo);
app.get('/user/interactions/:id', user.getInteractions);
app.get('/user/others/chat/:ids', user.getOthersChat);
app.get('/user/others/blocked/:ids', user.getOthersBlocked);

//PROFIL ACCOUNT
app.get('/user/img/:id', user.getUserImg);
app.post('/user/img/delete', user.deleteUserImg);
app.post('/user/img/profil/switch', user.switchProfilImg);
app.post('/user/editInfo', user.editInfo);
app.post('/user/editCivil', user.editCivil);
app.post('/user/editMail', user.editMail);

// INTEREST
app.get('/interest', interest.getInterest);
app.get('/interest/:id', interest.userInterest);
app.post('/interest/addNewTag', interest.addNewTag);
app.post('/interest/add', interest.addUserInterest);
app.post('/interest/delete', interest.deleteUserInterest);

//UPLOAD
app.post('/upload/img/:id', upload.img);

//A UTILISER EN PRODUCTION
app.use(function(req, res, next) {
	res.sendFile(path.join(__dirname, 'build', 'index.html'));
});

server.listen(port, function () {
	console.log('\x1b[1m', `Server is ready on port ${port}`, '\x1b[0m')
})
