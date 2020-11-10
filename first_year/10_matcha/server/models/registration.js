var pool = require('./database.js').pool;

exports.search_user_email = async function (data)
{
	var query = 'SELECT mail FROM user WHERE user.mail = ?';
	try {
		const res = await pool.query(query, data);
		return (res[0]);
	} catch (err) {
	//	console.error(err);
		return (null);
	}
}

exports.search_user_username = async function (data)
{
	var query = 'SELECT username FROM user WHERE user.username = ?';
	try {
		const res = await pool.query(query, data);
		return (res[0]);
	} catch (err) {
	//	console.error(err);
		return (null);
	}
}

exports.search_token = async function (data)
{
	var query = 'SELECT id_user, firstname, status FROM user WHERE user.token = ?';
	try {
		const res = await pool.query(query, data);
		return (res[0]);
	} catch (err) {
	//	console.error(err);
		return (null);
	}
}

exports.insert_new_user = function (data, callback)
{
	var query = 'INSERT INTO user (mail, username, lastname, firstname, password, gender, birthdate, token) '
		+ 'VALUES (?, ?, ?, ?, ?, ?, ?, ?)';
	pool.query(query, data, function (error, results, fields) {
		if (error)
		{
			console.error(error)
			return (callback(true, 0));
		}
		return (callback(null, results.insertId));
	});
}

exports.update_account_status = function (data)
{
	const query = 'UPDATE user SET status = ? WHERE user.id_user = ?';
	pool.query(query, data, function (error, results) {
		if (error)
			console.error(error);
	});
}
