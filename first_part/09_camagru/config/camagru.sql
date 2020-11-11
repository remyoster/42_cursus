SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";
CREATE DATABASE IF NOT EXISTS `camagru` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `camagru`;
CREATE TABLE IF NOT EXISTS `comment` (
  `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `image_id` int(10) UNSIGNED NOT NULL,
  `author_id` int(10) UNSIGNED NOT NULL,
  `text` text NOT NULL,
  `date` datetime NOT NULL,
  PRIMARY KEY (`id`),
  KEY `image_id` (`image_id`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=utf8;
CREATE TABLE IF NOT EXISTS `image` (
  `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `src` varchar(50) NOT NULL,
  `author_id` int(10) UNSIGNED NOT NULL,
  `date` datetime NOT NULL,
  `nb_like` int(11) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=utf8;
CREATE TABLE IF NOT EXISTS `img_like` (
  `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `author_id` int(10) UNSIGNED NOT NULL,
  `image_id` int(10) UNSIGNED NOT NULL,
  PRIMARY KEY (`id`),
  KEY `image_id` (`image_id`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=utf8;
CREATE TABLE IF NOT EXISTS `user` (
  `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `pseudo` varchar(20) NOT NULL,
  `email` varchar(320) NOT NULL,
  `password` varchar(512) NOT NULL,
  `account` enum('confirmed','not confirmed') NOT NULL DEFAULT 'not confirmed',
  `notification` enum('yes','no') NOT NULL DEFAULT 'yes',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=utf8;
ALTER TABLE `comment`
  ADD CONSTRAINT `comment_ibfk_1` FOREIGN KEY (`image_id`) REFERENCES `image` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `img_like`
  ADD CONSTRAINT `img_like_ibfk_1` FOREIGN KEY (`image_id`) REFERENCES `image` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;
