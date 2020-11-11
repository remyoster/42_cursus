var pool = require('./database.js').pool;

exports.getInterest = async function () {
	var q = "SELECT * FROM `interest`";
	try {
		let res = await pool.query(q);
		return(res);
	} catch (e) {
		//console.error(e);
		return (null);
	}
}

exports.getIdInterest = async function () {
	var q = "SELECT id_interest FROM `interest`";
	try {
		let res = await pool.query(q);
		return(res);
	} catch (e) {
		//console.error(e);
		return null;
	}
}

exports.userInterest = async function (data) {
	var q = "SELECT interest_user.id_interest_user, interest.id_interest, interest.name_interest FROM interest INNER JOIN interest_user WHERE interest.id_interest = interest_user.id_interest AND interest_user.id_user = ?";
	try {
		let res = await pool.query(q, data);
		return(res);
	} catch (e) {
		//console.log(e);
		return null;
	}
}

exports.addUserInterest = async function(data) {
	var q = "INSERT INTO `interest_user`(`id_user`, `id_interest`) VALUES (?, ?)";
	try {
		let res = await pool.query(q, data);
		return (true);
	} catch (err) {
		//console.error(err);
		return(null);
	}
}

exports.deleteUserInterest = function (data) {
	var q = "DELETE FROM `interest_user` WHERE id_user = ? AND id_interest = ?";
	try {
		let res = pool.query(q, data)
		return (true);
	} catch (err) {
		//console.error(err);
		return (false);
	}
}

exports.checkTag = async function(data) {
	let q = 'SELECT * FROM interest WHERE name_interest = ?';
	try {
		let res = await pool.query(q, data);
		if (res[0])
			return (false);
		else
			return (true);
	} catch (err) {
		//console.error(err);
		return (false);
	}
}
exports.insertNewTag = async function (data) {
	var q = "INSERT INTO `interest`(`name_interest`) VALUES (?)";
	try {
		let res = await pool.query(q, data);
		return (res.insertId);
	} catch (err) {
		//console.error(err);
		return (null);
	}
}

exports.insertUserInterest = async function (data) {
	try {
		var q = "INSERT INTO `interest_user`(`id_user`, `id_interest`) VALUES (?, ?)";
		let res = await pool.query(q, data);
		return (res.insertId);
	} catch (err) {
		//console.error(err);
		return null;
	}
}
