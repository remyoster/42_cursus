-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le :  Dim 31 mars 2019 à 12:55
-- Version du serveur :  5.6.43
-- Version de PHP :  5.6.40

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `rush00`
--
CREATE DATABASE IF NOT EXISTS `rush00` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `rush00`;

-- --------------------------------------------------------

--
-- Structure de la table `basket`
--

CREATE TABLE `basket` (
  `id_basket` int(11) NOT NULL,
  `user_name` varchar(30) NOT NULL,
  `item_name` text NOT NULL,
  `date` datetime NOT NULL,
  `status` enum('done','in progress','','') NOT NULL,
  `total_price` decimal(6,2) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `basket`
--

INSERT INTO `basket` (`id_basket`, `user_name`, `item_name`, `date`, `status`, `total_price`) VALUES
(1, 'test', 'Tomates', '2019-03-08 05:21:40', 'done', '2.56');

-- --------------------------------------------------------

--
-- Structure de la table `item`
--

CREATE TABLE `item` (
  `id_item` int(11) NOT NULL,
  `item_name` varchar(60) NOT NULL,
  `type` varchar(30) NOT NULL,
  `description` text NOT NULL,
  `item_stock` mediumint(8) UNSIGNED NOT NULL,
  `price` decimal(4,2) UNSIGNED NOT NULL,
  `img` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `item`
--

INSERT INTO `item` (`id_item`, `item_name`, `type`, `description`, `item_stock`, `price`, `img`) VALUES
(2, 'Peche', 'Fruit', 'Peches origine France\r\nMorbi luctus elit in venenatis tincidunt. Aenean cursus lorem ut enim finibus viverra. Suspendisse lorem massa, volutpat vel lobortis sed, mattis et tortor.', 400, '3.00', 'img/peche.jpg'),
(3, 'Cocombre', 'Legume', 'Cocombre origine France\r\nMorbi luctus elit in venenatis tincidunt. Aenean cursus lorem ut enim finibus viverra. Suspendisse lorem massa, volutpat vel lobortis sed, mattis et tortor.', 123, '2.50', 'img/cocombre.jpg'),
(4, 'Poivron', 'Legume', 'Poivron\r\nMorbi luctus elit in venenatis tincidunt. Aenean cursus lorem ut enim finibus viverra. Suspendisse lorem massa, volutpat vel lobortis sed, mattis et tortor.', 800, '3.56', 'img/poivron.jpg'),
(9, 'Salade', 'Legume', 'Salades origine France\r\nMorbi luctus elit in venenatis tincidunt. Aenean cursus lorem ut enim finibus viverra. Suspendisse lorem massa, volutpat vel lobortis sed, mattis et tortor.', 400, '3.00', 'img/salade.jpg'),
(10, 'Fraise', 'Fruit', 'Fraises origine France\r\nMorbi luctus elit in venenatis tincidunt. Aenean cursus lorem ut enim finibus viverra. Suspendisse lorem massa, volutpat vel lobortis sed, mattis et tortor.', 400, '3.00', 'img/fraise.jpg');

-- --------------------------------------------------------

--
-- Structure de la table `user`
--

CREATE TABLE `user` (
  `id_user` int(11) NOT NULL,
  `lastname` varchar(30) NOT NULL,
  `firstname` varchar(30) NOT NULL,
  `email` varchar(320) CHARACTER SET ascii NOT NULL,
  `phone` int(10) UNSIGNED ZEROFILL NOT NULL,
  `address` varchar(300) CHARACTER SET ascii NOT NULL,
  `city` varchar(60) NOT NULL,
  `country` varchar(60) NOT NULL,
  `postal_code` mediumint(8) UNSIGNED NOT NULL,
  `passwd` varchar(512) NOT NULL,
  `group_user` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `user`
--

INSERT INTO `user` (`id_user`, `lastname`, `firstname`, `email`, `phone`, `address`, `city`, `country`, `postal_code`, `passwd`, `group_user`) VALUES
(37, 'root', 'root', 'root@root.com', 0678360842, 'root', 'root', 'root', 75010, '06948d93cd1e0855ea37e75ad516a250d2d0772890b073808d831c438509190162c0d890b17001361820cffc30d50f010c387e9df943065aa8f4e92e63ff060c', 'admin');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `basket`
--
ALTER TABLE `basket`
  ADD PRIMARY KEY (`id_basket`);

--
-- Index pour la table `item`
--
ALTER TABLE `item`
  ADD PRIMARY KEY (`id_item`);

--
-- Index pour la table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id_user`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `basket`
--
ALTER TABLE `basket`
  MODIFY `id_basket` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pour la table `item`
--
ALTER TABLE `item`
  MODIFY `id_item` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT pour la table `user`
--
ALTER TABLE `user`
  MODIFY `id_user` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=39;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
