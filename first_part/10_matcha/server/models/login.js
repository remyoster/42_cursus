var pool = require('./database.js').pool;

exports.find_username = async function (data) {
	var query = 'SELECT * FROM `user` WHERE username=?';
	try {
		let res = await pool.query(query, data);
		return (res[0]);
	} catch (err) {
		//console.error(err);
		return (null);
	}
}

exports.find_usermail = async function (data) {
	var query = 'SELECT * FROM `user` WHERE mail=?';
	try {
		let res = await pool.query(query, data);
		return(res[0]);
	} catch (err) {
		//console.error(err);
		return (null);
	}
}

exports.check_token = async function(data) {
	var q = 'SELECT id_user FROM `user` WHERE token = ?';
	try {
		let res = await pool.query(q, data);
		if (res[0])
			return true;
		else
			return false;
	} catch (e) {
		//console.error(e);
		return false;
	}
}

exports.editpass = function (data) {
	const query = 'UPDATE user SET password = ? WHERE user.token = ?';
	pool.query(query, data, function (error, results) {
		if (error) {
			console.log(error);
			return(null);
		}
	});
	return(1);
}

exports.getMainImg = async function(data) {
	var q = 'SELECT path FROM `image` WHERE id_user = ? AND `profil` = 1';
	try {
		let res = await pool.query(q, data);
		return res[0];
	} catch (e) {
		console.error(e);
		return undefined;
	}
}

exports.fillGeoloc = async function(data) {
	var q = 'UPDATE user SET latitude = ?, longitude = ? WHERE id_user = ?';
	try {
		await pool.query(q, data);
	} catch (e) {
		//console.log(e);
	}
}
