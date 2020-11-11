# Hypertube

## Description
>Last project in his series, hypertube project invite you to discover extremely powerful tools : MVC frameworks. You will learn to manipulate an MVC, in the language of your choice, to realize a streaming web site of downloaded videos from BitTorrent protocol.

## Objectives
* Frameworks
* Instant time Web
* Streaming
* BitTorrent

## Skills
* Web
* DB & Data
* Security

## Usage
The stack : NodeJs(express) in the back with SQL, and React with custom CSS on the front.
You will have to install your own SQL server, and NodeJs.
Then go to server/config folder and change database.js and mail.js with your credentials.
Once it's done you can return back to /server folder and run `npm install && npm run database && npm run seed` to install and seed the database. The client is pre-builted
so you just need to run : `npm start` to start dating.

## Screenshots

_Login_</br>
<img src="https://github.com/remyoster/42_cursus/blob/main/first_year/11_hypertube/.ressources/login.png" width="100%" /></br>

_Home_</br>
<img src="https://github.com/remyoster/42_cursus/blob/main/first_year/11_hypertube/.ressources/home.png" width="100%" /></br>
<img src="https://github.com/remyoster/42_cursus/blob/main/first_year/11_hypertube/.ressources/home2.png" width="100%" /></br>

_Profil_</br>
<img src="https://github.com/remyoster/42_cursus/blob/main/first_year/11_hypertube/.ressources/profil.png" width="100%" />

_Streaming_</br>
<img src="https://github.com/remyoster/42_cursus/blob/main/first_year/11_hypertube/.ressources/42_movie.png" width="100%" />
<img src="https://github.com/remyoster/42_cursus/blob/main/first_year/11_hypertube/.ressources/42_movie2.png" width="100%" />
<img src="https://github.com/remyoster/42_cursus/blob/main/first_year/11_hypertube/.ressources/42_movie3.png" width="100%" />

## Features
* English and french languages available (and synopsys translate on the fly)
* Multi-part connection (42, github, insta, local)
* Profil pic upload on drag and drop
* Scrapping from YTS and Popcorn
* Watched movie history
* Comments
* Account management
* Multi resolution (streaming)
* Mobile friendly
* Bypass cloudflare

## Contributors
@madufour (Marie Dufourq) 
@jmoussu (Jim Moussu)
@bboutoil (Benjamin Boutoille)

## Disclaimers
This project is NOT destinated to be USED. The torrent sources are
illegals. You will need to put your own keys (see .env) to make it work.
