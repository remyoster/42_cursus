const notifDb = require('../models/interactions.js');

var socketUsers = [];
exports.socketController = function(io)
{
	io.on('connection', function(socket) {
		socket.on('login', function(data) {
			let i = socketUsers.findIndex(e => (e.id_user === data));
			i > -1 ? socketUsers[i].id_socket = socket.id
				: socketUsers.push({id_user: data, id_socket: socket.id});
		})
		socket.on('logout', function(data) {
			let i = socketUsers.findIndex(e => (e.id_user === data));
			if (i > -1)
			{
				notifDb.insertNewDate([new Date(), data]);
				socketUsers.splice(i, 1);
			}
		});
		socket.on('notif', async function(data) {
			if (data.type === 'visit' && typeof(data.id_visited) === `number`
				&& typeof(data.id_visitor) === `number`)
			{
				let id = await notifDb.insertNewVisit([data.id_visitor,
					data.id_visited]);
				socket.emit('visitInserted', id);
				if (id)
				{
					notifDb.insertNewNotif([data.type, data.id_visitor,
						data.id_visited]);
					let isOnline = socketUsers
						.find((e) => (e.id_user === data.id_visited));
					if (isOnline) 
						io.to(`${isOnline.id_socket}`).emit('notif',
							{type: 'visit', id_author: data.id_visitor});
				}
			}
			else if (data.type === 'like' 
				&& typeof(data.id_liked) === `number`
				&& typeof(data.id_author) === `number`)
			{
				let id = await notifDb.insertNewLike([data.id_liked,
					data.id_author]);
				socket.emit('likeInserted', id);
				if (id)
				{
					notifDb.insertNewNotif([data.type, data.id_author,
						data.id_liked]);
					let isOnline = socketUsers
						.find((e) => (e.id_user === data.id_liked));
					if (isOnline) 
						io.to(`${isOnline.id_socket}`).emit('notif',
							{type: 'like', id_author: data.id_author});
				}
			}
			else if (data.type === 'unlike' && typeof(data.id_like) === 'number'
				&& typeof(data.id_author) === 'number'
				&& typeof(data.id_liked) === 'number')
			{
				if (typeof(data.delete) === 'number')
					notifDb.deleteMatch(data.delete);
				notifDb.deleteLike(data.id_like);
				notifDb.insertNewNotif([data.type, data.id_author,
					data.id_liked]);
				let isOnline = socketUsers
					.find((e) => (e.id_user === data.id_liked));
				if (isOnline) 
					io.to(`${isOnline.id_socket}`).emit('notif',
						{type: 'unlike', id_like: data.id_like, 
							delete: data.delete});
			}
			else if (data.type === 'match' && typeof(data.id_author) === 'number'
				&& typeof(data.id_liked) === 'number')
			{
				let id_like = await notifDb.insertNewLike([data.id_liked,
					data.id_author]);
				let id_match = await notifDb.insertNewMatch([data.id_liked,
					data.id_author]);
				notifDb.insertNewNotif([data.type, data.id_author,
					data.id_liked]);
				notifDb.insertNewNotif([data.type, data.id_liked,
					data.id_author]);
				if (id_like && id_match)
				{
					let isOnline = socketUsers
						.find((e) => (e.id_user === data.id_liked));
					if (isOnline) 
						io.to(`${isOnline.id_socket}`).emit('notif', {
							type: 'match',
							id_like: id_like, id_match: id_match,
							id_author: data.id_author,
							bol: true,
						});
					socket.emit('notif', {type: 'match', id_like: id_like, 
						id_match: id_match, id_author: data.id_liked});
				}
			}
			else if (data.type === 'game' && typeof(data.id_author) === 'number'
				&& typeof(data.id_other) === 'number')
			{
				let id_visit = await notifDb.insertNewVisit([data.id_author,
					data.id_other]);
				let id_like = await notifDb.insertNewLike([data.id_other,
					data.id_author]);
				if (id_visit && id_like)
				{
					socket.emit('gameInserted', {id_visit: id_visit,
						id_like: id_like});
					notifDb.insertNewNotif([data.type, data.id_author,
						data.id_other]);
					let isOnline = socketUsers
						.find((e) => (e.id_user === data.id_other));
					if (isOnline) 
						io.to(`${isOnline.id_socket}`).emit('notif',
							{type: 'game', id_visit: id_visit, id_like: id_like,
								id_author: data.id_author});
				}

			}
		});
		socket.on('chat-message', async function(data) {
			if (typeof(data.id_author) === 'number'
				&& typeof(data.id_receiver) === 'number'
				&& typeof(data.mess) === 'string')
			{
				notifDb.insertNewMessage([data.id_author, data.id_receiver,
					data.mess]);
				let isOnline = socketUsers
					.find((e) => (e.id_user === data.id_receiver));
				if (isOnline)
					io.to(`${isOnline.id_socket}`).emit('mess',
						{id_author: data.id_author, mess: data.mess});
			}
		});
		socket.on('getSocketUsers', () => {
			socket.emit('getSocketUsers', socketUsers.map(e => (e.id_user)));
		});
		socket.on('disconnect', function() {
			let i = socketUsers.findIndex(e => (e.id_socket === socket.id));
			if (i > -1)
			{
				notifDb.insertNewDate([new Date(), socketUsers[i].id_user]);
				socketUsers.splice(i, 1);
			}
		});
	});
}
