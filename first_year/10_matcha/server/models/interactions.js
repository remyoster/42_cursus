var pool = require('./database.js').pool;

exports.insertNewMessage = function(data) {
	let q = "INSERT INTO message (id_author, id_receiver, content) VALUES (?, ?, ?)";
	try {
		pool.query(q, data);
	} catch (err) {
		//console.error(err);
		return (null);
	}
}

exports.insertNewVisit = async function(data) {
  let q1 = "SELECT * from visitor WHERE id_visitor = ? AND id_visited = ?";
  try {
    let res = await pool.query(q1, data);
    if (!res[0])
    {
      let q2 = "INSERT INTO visitor (id_visitor, id_visited) VALUES (?, ?)";
      res = await pool.query(q2, data);
      return (res.insertId);
    }
    else
      return null;
  } catch (e) {
    //console.error(e);
	  return null
  }
}

exports.insertNewLike = async function (data) {
  var q1 = "SELECT * from likes WHERE id_liked = ? AND id_author = ?";
  try {
    let res = await pool.query(q1, data);
    if (!res[0])
    {
      let q2 = "INSERT INTO likes (id_liked, id_author) VALUES (?, ?)";
      res = await pool.query(q2, data);
      return (res.insertId);
    }
    else
      return null;
  } catch (e) {
    //console.error(e);
	  return null
  }
}

exports.insertNewMatch = async function (data) {
	try {
      let q = 'INSERT INTO `match` (id_user1, id_user2) VALUES (?, ?)';
      let res = await pool.query(q, data);
      return (res.insertId);
    }
	catch (err) {
		//console.error(err);
		return null;
	}
}

exports.deleteLike = function (data) {
	let q = 'DELETE FROM likes WHERE id_like = ?';
	pool.query(q, data, err => {
		if (err)
			console.error(err);
	});
}

exports.deleteMatch = function (data) {
	let q = 'DELETE FROM `match` WHERE id_match = ?';
	pool.query(q, data, err => {
		if (err)
			console.error(err);
	});
}

exports.insertNewNotif = function (data) {
  let q = "INSERT INTO notif (type, id_author, id_receiver) VALUES (?, ?, ?)";
  pool.query(q, data, function(err, res) {
    if (err)
      console.error(err);
  })
}

exports.insertNewDate = function(data) {
	let q = 'UPDATE user SET lastco = ? WHERE id_user = ?'
	pool.query(q, data, function(err, res) {
		if (err)
			console.error(err);
	});
}
