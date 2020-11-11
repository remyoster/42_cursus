const formidable = require('formidable');
const fs = require('fs-extra');
const uuidv1 = require('uuid/v1');
const db = require('../models/user.js');

exports.img = function (req, res)
{
	let error = null;
	var form = new formidable.IncomingForm();

	form.parse(req, async function (err, fields, files) {
		if (err)
		{
			//console.error(err);
			return res.send({error: 'Une erreur est survenue.'});
		}
		let id = parseInt(fields.id, 10);
		error = await checkImg(files.file, id);
		if (error || !await db.checkToken([id, fields.token]))
		{
			try {
				fs.unlink(files.file.path);
			} catch (e) {
				console.error(e);
			}
			return res.send({error: 'Une erreur est survenue.'});
		}
		let newname = uuidv1() + files.file.name;
		let newpath = `${__dirname}/../public/img/upload/${newname}`;
		fs.copy(files.file.path, newpath, async err => {
			if (err)
			{
				//console.error(err);
				try {
					fs.unlink(files.file.path);
				} catch (e) {
					console.error(e);
				}
				return res.send({error: 'Une erreur est survenue.'});
			}
			fs.unlink(files.file.path);
			let dbres = await db.insertImg([`/public/img/upload/${newname}`, id]);
			res.send({
				id_img: dbres,
				path: '/public/img/upload/' + newname,
				id_user: id,
				profil: 0});
		});
	});
}

async function checkImg(img, id)
{
	let error = null;

	if (!img.type.match(/image\/?(png)|(jpg)|(jpeg)/))
		error = 'L\'image ne respecte pas le bon format.';
	else if (img.name.length === 0)
		error = 'Le fichier ne possède pas de nom.';
	else if (img.size > 1000000)
		error = 'Le fichier est > 1mo.';
	else
	{
		let res = await db.getUserImg(id);
		if (res.length === 5)
			error = 'Vous avez déjà 5 images.';
	}
	return error;
}
