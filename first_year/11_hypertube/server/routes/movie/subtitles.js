const fs = require('fs');
const srt2vtt = require('srt2vtt');
const request = require('request');
const zlib = require('zlib');
const axios = require('axios');
const Sub = require('./model.js').Sub;

//ASKING DATABASE FOR EXISTING SUBTITLES (based on imdb)
//IF EXISTING, SEND THEM, ELSE ASKING OPENSUBTITLES.org 
//AND DOWNLOAD/CONVERT THEM ON SERV 
async function searchSub(req, res) {
	var { imdb } = req.query;
	var newSub;
	var sendres = 0;
	if (/^tt/.test(imdb))
		imdb = imdb.slice(2);
	try {
		let dbRes = await Sub.findOne({ movie_imdb: imdb}).exec();
		if (dbRes && dbRes.files && dbRes.files.length > 0)
			return res.send(dbRes.files);
		else if (dbRes)
			newSub = dbRes;
		else
			newSub = new Sub({
				movie_imdb: imdb,
				files: []
			});
	} catch (err) {
		if (process.env.MODE === 'DEV')
			console.error(err);
		return res.send([]);
	}

	function gogoRes(err, sub) {
		try {
			if (err)
			{
				if (sub === 'fr' && freSub[1])
					return dlUnzipConvert(freSub[1].SubDownloadLink,
						imdb, 'fr', gogoRes)
				else if (sub === 'eng' && engSub[1])
					return dlUnzipConvert(engSub[1].SubDownloadLink,
						imdb, 'eng', gogoRes)
			}
			sendres -= 1;
			if (typeof(sub) === 'object')
				newSub.files.push(sub);
			if (sendres <= 0)
			{
				newSub.save();
				return res.send(newSub.files);
			}
		} catch (err) {
			return res.send(newSub.files);
		}
	}

	let [freSub, engSub] = await searchSubFiles(imdb);
	if (freSub.length > 0)
	{
		sendres += 1;
		dlUnzipConvert(freSub[0].SubDownloadLink, imdb, 'fr', gogoRes)
	}
	if (engSub.length > 0)
	{
		sendres += 1;
		dlUnzipConvert(engSub[0].SubDownloadLink, imdb, 'eng', gogoRes)
	}
}

async function searchSubFiles(imdb) {
	freLang = axios.get(`https://rest.opensubtitles.org/search/imdbid-${imdb}/sublanguageid-fre`, {headers : {'X-User-Agent': 'TemporaryUserAgent'}});
	engLang = axios.get(`https://rest.opensubtitles.org/search/imdbid-${imdb}/sublanguageid-eng`, {headers : {'X-User-Agent': 'TemporaryUserAgent'}});
	try {
		let [fre, eng] = await Promise.all([freLang, engLang]);
		return ([fre.data, eng.data])
	} catch (err) {
		if (process.env.MODE === 'DEV')
			console.error(err);
		return ([]);
	}
}

function dlUnzipConvert(url, imdb, lang, gogoRes) {
	try {
		request({ url: url, encoding: null }, (error, response, data) => {
			if (error)
				return gogoRes(true, lang);
			zlib.unzip(data, (error, buffer) => {
				if (error)
					return gogoRes(true, lang);
				if (buffer.length < 40000)
					return gogoRes(true, lang);
				srt2vtt(buffer, (err, vttData) => {
					if (err)
						return gogoRes(true, lang);
					var path = `/files/subtitles/${imdb}_${lang}.vtt`;
					fs.writeFileSync('.'+path, vttData);
					return gogoRes(false, {path: path, lang: lang});
				});
			});
		});
	} catch (err) {
		if (process.env.MODE === 'DEV')
			console.error(err);
		return gogoRes(true, lang);
	}
}
module.exports.searchSub = searchSub;
