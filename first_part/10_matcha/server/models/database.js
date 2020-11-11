const mysql = require('mysql');
const util = require('util');
var db_config = require('../config/database.js');
var pool = mysql.createPool({
	host : db_config.host,
	user : db_config.user,
	password : db_config.password,
	database : db_config.database,
	acquireTimeout: 120000,
	connectionLimit: 100,
	connectTimeout : 100000
});

pool.getConnection((err, connection) => {
	if (err) {
		if (err.code === 'PROTOCOL_CONNECTION_LOST') {
			console.error('Database connection was closed.')
		}
		if (err.code === 'ER_CON_COUNT_ERROR') {
			console.error('Database has too many connections.')
		}
		if (err.code === 'ECONNREFUSED') {
			console.error('Database connection was refused.')
		}
	}
	if (connection)
		connection.release()
	return;
})

pool.query = util.promisify(pool.query);
exports.pool = pool;
