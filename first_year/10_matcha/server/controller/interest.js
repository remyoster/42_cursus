const db = require('../models/interest.js');

exports.getInterest = async function (req, res) {
	let result = await db.getInterest();
	if (result)
		res.send(result);
	else
		res.status(200).send('null');
}

exports.userInterest = async function (req, res) {
	let id = req.params.id;
	if (typeof(id) === 'number')
	{
		let result = await db.userInterest(req.params.id);
		if (result)
			res.send(result);
		else
			res.status(200).send('null');
	}
	else
		res.status(200).send('null');
}

exports.addUserInterest = async function (req, res) {
	let id = req.body.id;
	let interest = req.body.interest;
	if (typeof(interest) === 'number' && typeof(id) === 'number'
		&& await db.addUserInterest([id, interest]))
		res.send('OK');
	else
		res.status(200).send('null');
}

exports.deleteUserInterest = async function(req, res) {
	let id = req.body.id;
	let interest = req.body.interest;
	if (typeof(interest) === 'number' && typeof(id) === 'number'
		&& await db.deleteUserInterest([id, interest]))
		res.send('OK');
	else
		res.status(200).send('null');
}

exports.addNewTag = async function(req, res) {
	let newTag = req.body.newTag;
	let id = req.body.id;
	if (typeof(id) === 'number' && typeof(newTag) === 'string'
		&& newTag.length < 50 && /^[a-z]+$/.test(newTag))
	{
		if (await db.checkTag(newTag))
		{
		let result = await db.insertNewTag(newTag);
		if (result && await db.insertUserInterest([id, result]))
			res.send({id: result});
		else
			res.status(200).send('null');
		}
	else
		res.status(200).send('null');
	}
	else
		res.status(200).send('null');
}
