var pool = require('./database.js').pool;

exports.checkToken = async function(data) {
	let q = 'SELECT 1 FROM user WHERE id_user = ? AND token= ?';
	try {
		let res = await pool.query(q, data);
		if (res[0])
			return (true);
		else
			return (false);
	} catch (err) {
		//console.error(err);
		return (false);
	}
}

exports.getNotifs = async function(data) {
	let q = 'SELECT notif.type, user.username, image.path AS img, notif.date FROM `notif` LEFT JOIN image ON notif.id_author = image.id_user AND image.profil = 1 LEFT JOIN user ON user.id_user = notif.id_author WHERE notif.id_receiver = ? ORDER BY notif.date DESC';
	try {
		let res = await pool.query(q, data);
		return (res);
	} catch (err) {
	//	console.error(err);
		return ([]);
	}
}
exports.getOthersChat = async function (data) {
	let ids = pool.escape(data);
	let q = 'SELECT user.id_user, user.username, image.path AS img FROM user LEFT JOIN image ON USER.id_user = image.id_user AND USER.id_user IN('+ids+') AND image.profil = 1 WHERE USER.id_user IN('+ids+')';
	try {
		let res = await pool.query(q);
		return (res);
	} catch (err) {
	//	console.error(err);
		return ([]);
	}
}
exports.getOlderChat = async function(data) {
	let q = "SELECT DISTINCT id_author, COUNT(DISTINCT date) AS count FROM `message` WHERE `id_receiver` = ? AND `date` > ?";
	try {
		let res = await pool.query(q, data);
		if (res[0].id_author)
			return (res);
		else 
			return([]);
	} catch (err) {
		console.error(err);
		return ([]);
	}
}

exports.getOthersBlocked = async function (data) {
	let ids = pool.escape(data);
	let q = 'SELECT user.id_user, user.username, user.city, image.path AS img FROM user INNER JOIN image ON USER.id_user = image.id_user AND USER.id_user IN('+ids+') AND image.profil = 1 AND USER.id_user IN('+ids+')';
	try {
		let res = await pool.query(q);
		return (res);
	} catch (err) {
	//	console.error(err);
		return(null);
	}
}

exports.getMessages = async function(data) {
	let id1 = pool.escape(data[0]);
	let id2 = pool.escape(data[1]);
	let q = 'SELECT * FROM message WHERE id_author = '+id1+' AND id_receiver = '+id2+' OR id_author = '+id2+' AND id_receiver = '+id1;
	try {
		let res = await pool.query(q);
		if (res[0])
			return res;
		else
			return (null);
	} catch (err) {
	//	console.error(err);
		return (null);
	}
}
exports.find_withid = async function (data) {
	var q = 'SELECT mail, lastname, firstname, gender, sexpref, bio, birthdate, city, latitude, longitude, status, lastco FROM `user` WHERE id_user = ?';
	try {
		let res = await pool.query(q, data);
		return(res[0]);
	} catch (err) {
		//console.error(err);
		return(null);
	}
}
exports.getUsersInfos = async function(data) {
	var q = 'SELECT id_user, username, lastname, firstname, gender, sexpref, bio,birthdate, city, latitude, longitude, status, lastco FROM `user` WHERE id_user != ?';
	try {
		let res = await pool.query(q, data);
		return (res);
	} catch (err) {
	//	console.error(err);
		return(null);
	}
}
exports.getUsersImgs = async function(data) {
	var q = 'SELECT id_user, path, profil FROM image WHERE id_user != ?';
	try {
		let res = await pool.query(q, data);
		return (res);
	} catch (err) {
	//	console.error(err);
		return (null);
	}
}
exports.getUsersInterests = async function(data) {
	var q = 'SELECT id_user, name_interest FROM interest_user INNER JOIN interest WHERE interest_user.id_interest = interest.id_interest AND id_user != ?'
	try {
		let res = await pool.query(q, data);
		return (res);
	} catch (err) {
	//	console.error(err);
		return (null);
	}
}
exports.countVisit = async function (data) {
	var q = 'SELECT COUNT(DISTINCT id_visitor) AS nbVisit FROM `visitor` WHERE id_visited = ?';
	try {
		let res = await pool.query(q, data);
		return (res[0].nbVisit);
	} catch (err) {
	//	console.error(err);
		return (0);
	}
}
exports.countLiked = async function (data) {
	var q = 'SELECT COUNT(DISTINCT id_author) AS nbLikes FROM `likes` WHERE id_liked = ?';
	try {
		let res = await pool.query(q, data);
		return (res[0].nbLikes);
	} catch (err) {
		//console.error(err);
		return (0);
	}
}
exports.countMatchs = async function (data) {
	let id = pool.escape(data);
	var q = 'SELECT COUNT(id_match) AS nbMatch FROM `match` WHERE id_user1 = '+id+' OR id_user2 = '+id;
	try {
		let res = await pool.query(q);
		return (res[0].nbMatch);
	} catch (err) {
	//	console.error(err);
		return (0);
	}
}
exports.getVisitors = async function (data) {
	let id = pool.escape(data);
	var q = 'SELECT * FROM `visitor` WHERE id_visitor = '+id+' OR id_visited = '+id;
	try {
		let res = await pool.query(q, data);
		return (res);
	} catch (err) {
		//console.error(err);
		return (null);
	}
}
exports.getLikes = async function (data) {
	let id = pool.escape(data);
	var q = 'SELECT * FROM likes WHERE id_liked = '+id+' OR id_author = '+id;
	try {
		let res = await pool.query(q, data);
		return (res);
	} catch (err) {
		//console.error(err);
		return (null);
	}
}

/** MATCH  **/
exports.getMatchs = async function (data) {
	let id = pool.escape(data);
	var q = 'SELECT * FROM `match` WHERE id_user1 = '+id+' OR id_user2 = '+id;
	try {
		let res = await pool.query(q, data);
		return (res);
	} catch (err) {
		//console.error(err);
		return (null);
	}
}
exports.getBlocks = async function (data) {
	let id = pool.escape(data);
	var q = 'SELECT * FROM `block` WHERE id_author = '+ id+' OR id_blocked = '+id;
	try {
		let res = await pool.query(q, id);
		return (res);
	} catch (err) {
	//	console.error(err);
		return (null);
	}
}
exports.insertImg = async function(data) {
	const query = 'INSERT INTO image (path, id_user) VALUES (?, ?)';
	try {
	const res = await pool.query(query, data);
	return (res.insertId);
	} catch (err) {
	//	console.error(err);
		return (null);
	}
}

exports.getUserImg = async function (data) {
	const query = 'SELECT * FROM `image` WHERE id_user = ?';
	try {
		let res = await pool.query(query, data);
		return (res);
	} catch (err) {
	//	console.error(err);
		return (null);
	}
}

exports.setProfilImg = async function(data) {
	const q1 = 'UPDATE `image` SET `profil` = 0 WHERE `image`.`id_user` = ? AND `image`.`profil` = 1;'
	const q2 = 'UPDATE `image` SET `profil` = 1 WHERE `image`.`id_user` = ? AND `image`.`id_img` = ?;'
	try {
		await pool.query(q1, data)
		await pool.query(q2, data)
		return true;
	} catch (err) {
	//	console.error(err)
		return false;
	}
}

exports.deleteImg = function(data) {
	const query = 'DELETE FROM image WHERE image.id_img = ?';
	pool.query(query, data, (err, res) => {
		if (err)
			console.error(err);
	});
}

exports.insertInfo = async function(data) {
	var q = "UPDATE `user` SET `sexpref` = ?, `bio` = ?, `city` = ?, `latitude` = ?, `longitude` = ? WHERE id_user = ?";
	try {
		let res = await pool.query(q, data);
		return (true);
	} catch (err) {
	//	console.error(err);
		return (false);
	}
}

exports.insertCivil = async function (data) {
	var q = "UPDATE `user` SET `lastname` = ?, `firstname` = ?, `gender` = ? WHERE id_user = ?";
	try {
		let res = await pool.query(q, data);
		return (res);
	} catch (err) {
	//	console.error(err);
		return (null)
	}
}

exports.updateMail = async function (data) {
	var q = "UPDATE `user` SET `mail` = ? WHERE id_user = ?";
	try {
		await pool.query(q, data);
	} catch (err) {
	//	console.error(err);
	}
}

exports.getTags = async function (data) {
	var q = "SELECT interest.id_interest, interest.name_interest FROM interest INNER JOIN interest_user WHERE interest.id_interest = interest_user.id_interest AND interest_user.id_user = ?";
	try {
		let res = await pool.query(q, data);
		return(res);
	} catch (err) {
	//	console.error(err);
		return ([]);
	}
}

exports.reportFake = async function (data) {
	var q = "UPDATE `user` SET `status` = 'fake' WHERE id_user = ?";
	try {
		pool.query(q, data);
		let quest = "SELECT firstname, mail, token FROM `user` WHERE id_user = ?"
		let res = await pool.query(quest, data);
		return(res[0]);
	} catch (e) {
	//	console.error(e);
		return null;
	}
}

exports.blockUser = async function(data) {
	var q = "INSERT INTO `block`(`id_author`, `id_blocked`) VALUES (?, ?)";
	try {
		let res = await pool.query(q, data);
		return (res.insertId);
	} catch (err) {
		//console.error(err);
		return null;
	}
}

exports.deblockUser = async function(data) {
	let q = "DELETE FROM `block` WHERE id_author = ? AND id_blocked = ?";
	try {
		let res = await pool.query(q, data);
		return (true);
	} catch (err) {
	//	console.error(err);
		return (false);
	}
}
