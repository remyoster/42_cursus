const mysql = require('mysql');
const fs = require('fs');
const util = require('util');
const dbConfig = require('./database.js');
var connection = mysql.createConnection({
	host: dbConfig.host,
	user: dbConfig.user,
	password : dbConfig.password
});
var pool = mysql.createPool({
	host: dbConfig.host,
	user: dbConfig.user,
	password : dbConfig.password,
	database : dbConfig.database
});

if (process.argv[2] === 'drop')
	connection.query('DROP DATABASE matcha', function(err) {
		if (err)
			console.error(err);
		else
			console.log("\x1b[36m", 'Database Matcha deleted \u2718', "\x1b[0m");
		connection.end();
	});
else
{
	connection.connect();
	connection.query('CREATE DATABASE IF NOT EXISTS `matcha` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci', function (err, res) {
		if (err) 
			console.error(err);
		else
		{
			connection.end();
			installDb();
		}
	});

	function installDb() {
		pool.getConnection((err, connection) => {
			if (err)
			{
				if (err.code === 'PROTOCOL_CONNECTION_LOST')
					console.error('Database connection was closed.');
				if (err.code === 'ER_CON_COUNT_ERROR')
					console.error('Database has too many connections.');
				if (err.code === 'ECONNREFUSED')
					console.error('Database connection was refused.');

			}
			else
			{
				let bool = 1;
				console.log("\x1b[35m", 'Initializing queries...', "\x1b[0m");
				pool.query = util.promisify(pool.query);
				var dbQueries = fs.readFileSync('./config/matcha-db.sql', 'utf8');
				dbQueries = dbQueries.split(';');
				dbQueries.forEach((e, index) => {
					if (e !== '\n')
						pool.query(e, function(err) {
							if (err && err.code === 'ER_DUP_KEY')
								bool = 0;
							else if (err)
								bool = err.code;
						});
				});
				setTimeout(function() {
					if (bool === 1)
						console.log("\x1b[32m", 'Database matcha installed \u2713', "\x1b[0m");
					else if (bool === 0)
						console.log("\x1b[31m", 'Database matcha already exists \u274c', "\x1b[0m");
					else
						console.log("\x1b[31m", `An error occurs: ${bool} \u274c`, "\x1b[0m");

					pool.end()
				}, 3000);
			}
		});
	}
}
