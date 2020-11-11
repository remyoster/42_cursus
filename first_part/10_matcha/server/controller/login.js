const db = require('../models/login.js');
const port = require('../server.js').port;
const bcrypt = require('bcrypt');
const nodemailer = require('nodemailer');
const transporter = nodemailer.createTransport({
	sendmail: true,
	newline: 'unix',
	path: '/usr/sbin/sendmail'
});

async function check_withuser(data)
{
	let user = await db.find_username(data.identity);
	if (!user)
		return (null);
	else
		return (user);
}

async function check_withmail(data)
{
	let user = await db.find_usermail(data.identity);
	if (!user)
		return (null);
	else
		return (user);
}

exports.check_data = async function(req, res) {
	var data = {};
	let error = null;
	let result = null;
	let user = null;
	let regex_mail = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$/;
	data.identity = req.body.identity;
	data.password = req.body.password;
	data.lat = req.body.lat;
	data.lon = req.body.lon;
	if (!regex_mail.test(data.identity))
		user = await check_withuser(data);
	else
		user = await check_withmail(data);
	if (user)
	{
		const match = await bcrypt.compare(data.password, user.password);
		if (match)
		{
			if (user.status === "confirmed")
			{
				result = user;
				let img = await db.getMainImg(user.id_user);
				if (img)
					user.img = img.path;
				else
					user.img = '/public/img/avatar.png';
				if (user.lat !== data.lat || user.lon !== data.lon) {
					await db.fillGeoloc([data.lat, data.lon, user.id_user]);
				}
			}
			else
				result = "Allez sur votre boite mail afin de valider votre compte";
		}
		else
			result = "wrong password";
	}
	else
		result = "IDENTIFIANT INCONNU";
	res.send(result);
}

exports.forgotpass = async function(req, res) {
	var data = {};
	let regex_mail = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$/;
	let user = null;
	let result = null;

	data.identity = req.body.identity;
	if (!regex_mail.test(data.identity))
		user = await check_withuser(data);
	else
		user = await check_withmail(data);
	if (user)
	{
		sendmailForgot(user.mail, user.username, user.token);
		result = "send";
	}
	else
		result = "Utilisateur introuvable";
	res.send(result);
}

function sendmailForgot(email, username, token) {
	transporter.sendMail({
		from: '"Matcha" matcha@matcha.com',
		to: email,
		subject: 'Réinitialisation mot de passe',
		text: `Bonjour ${username},\n`
		+ "Clique ici pour créer ton nouveau mot de passe:\n"
		+ `http://localhost:${port}/motdepasse/${token}`
	}, (err, info) => {
		if (err)
			console.error(err);
	});
}

exports.editpass = async function(req, res) {
	let token = req.body.token;
	if (await db.check_token(token)) {
		let hash = bcrypt.hashSync(req.body.password, 10);
		var data = [hash, token];
		let result = await db.editpass(data);
		if (result)
			res.send('ok');
		else
			res.send('');
	}
	else
		res.send('');
}
