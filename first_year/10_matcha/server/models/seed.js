var pool = require('./database.js').pool;

exports.seedUser = async function(data, callback) {
  var quest = 'INSERT INTO user (mail, username, lastname, firstname, password, gender, sexpref, bio, birthdate, city, latitude, longitude, token, status, lastco) '+
  'VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)';
  try {
    let res = await pool.query(quest, data);
    return (res.insertId);
  } catch (e) {
    console.error(e);
  return (null);
  }
}

exports.seedImg = function(data) {
  var quest = 'INSERT INTO image (path, id_user, profil) VALUES (?,?,?), (?,?,?)';
  try {
    pool.query(quest, data);
  } catch (e) {
    //console.log(e);
  }
}

exports.seedInterestUser = function(id, data) {
	let tmp = data.map(e => (`(${id}, ${e})`)).join(',');
	let query = 'INSERT INTO interest_user (id_user, id_interest) VALUES'+tmp;
  try {
    pool.query(query, data);
  } catch (e) {
    //console.log(e);
  }
}

exports.stopSeed = function () {
  try {
    pool.end();
  } catch (e) {
    //console.error(e);
  }
}
