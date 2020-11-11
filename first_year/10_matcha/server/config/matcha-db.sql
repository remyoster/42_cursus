CREATE TABLE IF NOT EXISTS `block` (
  `id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT,
  `id_author` int(11) UNSIGNED NOT NULL,
  `id_blocked` int(11) UNSIGNED NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id_author` (`id_author`),
  KEY `id_blocked` (`id_blocked`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `image` (
  `id_img` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `path` varchar(255) NOT NULL,
  `id_user` int(11) UNSIGNED NOT NULL,
  `profil` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id_img`),
  KEY `id_user` (`id_user`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `interest` (
  `id_interest` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `name_interest` varchar(50) NOT NULL,
  PRIMARY KEY (`id_interest`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;


CREATE TABLE IF NOT EXISTS `interest_user` (
  `id_interest_user` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `id_user` int(11) UNSIGNED NOT NULL,
  `id_interest` int(11) UNSIGNED NOT NULL,
  PRIMARY KEY (`id_interest_user`),
  KEY `id_interest` (`id_interest`),
  KEY `interest_user_ibfk_2` (`id_user`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `likes` (
  `id_like` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `id_liked` int(11) UNSIGNED NOT NULL,
  `id_author` int(11) UNSIGNED NOT NULL,
  PRIMARY KEY (`id_like`),
  KEY `id_author` (`id_author`),
  KEY `id_liked` (`id_liked`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `match` (
  `id_match` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `id_user1` int(11) UNSIGNED NOT NULL,
  `id_user2` int(11) UNSIGNED NOT NULL,
  `date_match` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id_match`),
  KEY `id_user1` (`id_user1`),
  KEY `id_user2` (`id_user2`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `message` (
  `id_message` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT,
  `id_author` int(11) UNSIGNED NOT NULL,
  `id_receiver` int(11) UNSIGNED NOT NULL,
  `date` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `content` text NOT NULL,
  PRIMARY KEY (`id_message`),
  KEY `message_ibfk_1` (`id_author`),
  KEY `message_ibfk_2` (`id_receiver`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `notif` (
  `id_notif` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT,
  `type` enum('visit','like','unlike','match','game') NOT NULL,
  `id_author` int(11) UNSIGNED NOT NULL,
  `id_receiver` int(11) UNSIGNED NOT NULL,
  `date` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id_notif`),
  KEY `id_author` (`id_author`),
  KEY `id_receiver` (`id_receiver`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `user` (
  `id_user` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `mail` varchar(200) NOT NULL,
  `username` varchar(120) NOT NULL,
  `lastname` varchar(120) NOT NULL,
  `firstname` varchar(120) NOT NULL,
  `password` varchar(300) NOT NULL,
  `gender` enum('female','male','other') NOT NULL,
  `sexpref` enum('female','male','bi','other') NOT NULL DEFAULT 'bi',
  `bio` text DEFAULT '',
  `birthdate` date NOT NULL,
  `city` varchar(50) NOT NULL DEFAULT "Paris",
  `latitude` double NOT NULL,
  `longitude` double NOT NULL,
  `token` varchar(300) DEFAULT NULL,
  `status` enum('confirmed','register','fake') NOT NULL DEFAULT 'register',
  `lastco` datetime NOT NULL,
  PRIMARY KEY (`id_user`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `visitor` (
  `id_visit` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `id_visitor` int(10) UNSIGNED NOT NULL,
  `id_visited` int(10) UNSIGNED NOT NULL,
  PRIMARY KEY (`id_visit`),
  KEY `id_visited` (`id_visited`),
  KEY `id_visitor` (`id_visitor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `interest` (`id_interest`, `name_interest`) VALUES
(1, 'voyage'),
(2, 'musique'),
(3, 'film'),
(4, 'série'),
(5, 'sport'),
(6, 'gaming'),
(7, '42'),
(8, 'born2code'),
(9, 'roster et madufour'),
(10, 'roster'),
(11, 'madufour');

ALTER TABLE `block`
  ADD CONSTRAINT `block_ibfk_1` FOREIGN KEY (`id_author`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `block_ibfk_2` FOREIGN KEY (`id_blocked`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `image`
  ADD CONSTRAINT `image_ibfk_1` FOREIGN KEY (`id_user`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `interest_user`
  ADD CONSTRAINT `interest_user_ibfk_1` FOREIGN KEY (`id_interest`) REFERENCES `interest` (`id_interest`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `interest_user_ibfk_2` FOREIGN KEY (`id_user`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `likes`
  ADD CONSTRAINT `likes_ibfk_1` FOREIGN KEY (`id_author`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `likes_ibfk_2` FOREIGN KEY (`id_liked`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `match`
  ADD CONSTRAINT `match_ibfk_1` FOREIGN KEY (`id_user1`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `match_ibfk_2` FOREIGN KEY (`id_user2`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `message`
  ADD CONSTRAINT `message_ibfk_1` FOREIGN KEY (`id_author`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `message_ibfk_2` FOREIGN KEY (`id_receiver`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `notif`
  ADD CONSTRAINT `notif_ibfk_1` FOREIGN KEY (`id_author`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `notif_ibfk_2` FOREIGN KEY (`id_receiver`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `visitor`
  ADD CONSTRAINT `visitor_ibfk_1` FOREIGN KEY (`id_visited`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `visitor_ibfk_2` FOREIGN KEY (`id_visitor`) REFERENCES `user` (`id_user`);
