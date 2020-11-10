const db = require('../models/registration.js');
const port = require('../server.js').port;
const bcrypt = require('bcrypt');
const nodemailer = require('nodemailer');
const transporter = nodemailer.createTransport({
	sendmail: true,
	newline: 'unix',
	path: '/usr/sbin/sendmail'
});
const uuidv1 = require('uuid/v1');

function check_gender(str)
{
	let error = null;

	if (str !== 'male' && str !== 'female' && str !== 'other')
		error = '* Le genre est inconnu';
	return ({value : str, error});
}

function check_birthdate(str)
{
	let error = null;

	const date = new Date();
	const year = date.getFullYear();
	const month = date.getMonth() + 1;
	const day = date.getDate();
	const strTmp = str;

	if (str.length === 0)
		error =  '* Le champ est vide.';
	else
	{
		str = str.split('-').map(x => parseInt(x, 10));
		if (str[0] < year - 100 || str[0] > year - 18 || str[1] < 1
			|| str[1] > 12 || str[2] < 1 || str[2] > 31)
			error = "* La date n'est pas valide. "
			+ "Vous devez avoir entre 18 et 100 ans";
	}
	return ({value : strTmp, error});
}

async function check_email(str)
{
	let error = null;

	if (str.length === 0)
		error =  '* Le champ est vide.';
	else if (str.length > 250)
		error =  '* Le nombre de caractères est supérieur à 250.';
	else if (!/^[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]{2,}\.[a-z]{2,4}$/.test(str))
		error = "* L'adresse mail est invalide.";
	else
	{
		if (await db.search_user_email(str))
			error = "* Cette adresse mail est déjà utilisée.";
	}
	return ({value : str, error});
}

async function check_username(str)
{
	let error = null;

	if (str.length === 0)
		error =  '* Le champ est vide.';
	else if (str.length > 50)
		error =  '* Le nombre de caractères est supérieur à 50.';
	else if (str.match(/\W/))
		error =  '* Les caractères spéciaux sont interdits.';
	else
	{
		if (await db.search_user_username(str))
			error = "* Ce pseudo est déjà utilisé.";
	}
	return ({value : str, error});
}

function check_lastname(str)
{
	let error = null;

	if (str.length === 0)
		error = '* Le champ est vide.';
	else if (str.length > 50)
		error = '* Le nombre de caractères est supérieur à 50.';
	else if (!(str.match(/^[a-zA-Z ]+$/)))
		error = '* Seuls les caractéres alphabétiques et les espaces sont autorisés';
	else if (str.match(/(^\s|\s$|\s[\s]+)/))
		error = '* Les espaces en début et fin de ligne ne sont pas autorisés, ainsi que les espaces multiples.';
	return ({value : str.toUpperCase(), error});
}

function check_firstname(str)
{
	let error = null;

	if (str.length === 0)
		error = '* Le champ est vide.';
	else if (str.length > 50)
		error = '* Le nombre de caractères est supérieur à 50.';
	else if (!(str.match(/^[a-zA-Z-]+$/)))
		error = '* Seuls les caractéres alphabétiques et les "-" sont autorisés.'
	else if (str.match(/(^-|-$|-[-]+)/))
		error = '* Les "-" en début et fin de ligne ne sont pas autorisés, ainsi que les "-" multiples.';
	return ({value : str.toLowerCase().charAt(0).toUpperCase()
		+ str.slice(1), error});
}

function check_password(str)
{
	let error = null;

	if (str.length === 0)
		error = '* Le champ est vide.';
	else if (str.length > 30)
		error = '* Le nombre de caractères est supérieur à 30.';
	else if (str.length < 6)
		error = '* Le nombre de caractères est inférieur à 6.';
	else if (!(str.match(/(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*\W).{6,}$/)))
		error = '* Le mot de passe doit contenir au moins une minuscule, '
			+ 'une majuscule, un chiffre et un caractère spécial.';
	return ({value : str, error});
}

function check_cfpassword(cfpwd, pwd)
{
	let error = null;

	if (cfpwd.length === 0)
		error = '* Le champ est vide.';
	else if (cfpwd !== pwd)
		error = '* Les mots de passe ne correspondent pas.';
	return ({value : cfpwd, error});
}

exports.check_data = async function(req, res)
{
	var data = {};
	data.gender = await check_gender(req.body.gender);
	data.birthdate = await check_birthdate(req.body.birthdate);
	data.email = await check_email(req.body.email);
	data.username = await check_username(req.body.username);
	data.lastname = await check_lastname(req.body.lastname);
	data.firstname = await check_firstname(req.body.firstname);
	data.password = await check_password(req.body.password);
	data.cfpassword = await check_cfpassword(req.body.cfpassword,
		req.body.password);
	for (var elem in data)
	{
		if (data[elem].error)
			return (res.send(data));
		else
			data[elem] = data[elem].value;
	}
	const token = uuidv1();
	bcrypt.hash(data.password, 10, function(err, hash) {
		var args = [data.email, data.username, data.lastname, data.firstname,
			hash, data.gender, data.birthdate, token];
		db.insert_new_user(args, function(err, results) {
			if (err == null)
			{
				sendmail(data.email, data.firstname, token);
				return (res.send({}));
			}
			else
				return (res.status(200).send('null'));
		});
	});
}

function sendmail(email, firstname, token)
{
	if (email)
	{
		transporter.sendMail({
			from: '"Matcha" matcha@matcha.com',
			to: email,
			subject: 'Validation de compte',
			text: `Bonjour ${firstname},\n`
			+ "Merci d'avoir créé un compte chez nous.\n"
			+ "Pour trouver l'amour active d'abord ton compte en cliquant ici:\n"
			+ `http://localhost:${port}/activate/${token}`
		}, (err, info) => {
			if (err)
				console.error(err, info);
		});
	}
}

async function activate_account(token)
{
	try {
		const res = await db.search_token(token);
		if (res && res.status !== 'confirmed')
		{
			db.update_account_status(['confirmed', res.id_user]);
			return (true);
		}
		else
			return (false);
	} catch (err) {
		console.error(err);
		return (false);
	}
}

exports.check_lastname = check_lastname;
exports.check_gender = check_gender;
exports.check_birthdate = check_birthdate;
exports.check_firstname = check_firstname;
exports.check_email = check_email;
exports.check_username = check_username;
exports.check_password = check_password;
exports.check_cfpassword = check_cfpassword;
exports.activate_account = activate_account;
