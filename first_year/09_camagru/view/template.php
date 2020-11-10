<!DOCTYPE HTML>
<html>
	<head>
		<title><?= $title ?></title>
		<link rel="stylesheet" href="public/css/main.css">
		<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.8.1/css/all.css" integrity="sha384-50oBUHEmvpQ+1lW4y57PTFmhCaXp0ML5d60M1M7uH2+nqUivzIebhndOJK28anvf" crossorigin="anonymous">
		<meta charset="utf-8">
		<?= $GLOBALS['script'] ?>
	</head>

	<body>
		<header>
		<?= $header ?>
		</header>

		<div class ="main-content">
		<?= $main_content ?>
		<?= display_error($GLOBALS['error']) ?>
		</div>

		<footer>
			<p>© roster 2019</p>
			<a href="https://fr.freepik.com/photos-vecteurs-libre/fond">Fond vecteur créé par starline - fr.freepik.com</a>
		</footer>
	</body>
</html>
