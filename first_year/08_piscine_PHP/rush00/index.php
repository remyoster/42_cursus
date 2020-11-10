<?PHP
	include('connexion_sql.php');
	include('ft_display_error.php');
	session_start();
	if (!(isset($_SESSION['status'])))
	{
	 	$_SESSION['status'] = "visitor";
		$_SESSION['basket'] = array();
	}
?>
<!DOCTYPE html>
<html>
<head>
	<title>Welcome to MultiFruix</title>
</head>
<link rel="stylesheet" type="text/css" href="main.css">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
<body>
	<header>
		<?php include('menu.php'); ?>
		<div>
			<h1>MultiFruix: Pour chaque fruit sa saison</h1>
			<h2>Retrouver des fruits et legumes cutivés pas loin de chez vous</h2>			
		</div>
	</header>
	<div class="main-content">
		<h3>Les nouveaux fruits et legumes de la saison sont arrivé !</h3>
		<div class="news">
			<h3>-10% sur la selection printemps</h3>
			<img src="img/vegetables.png">
			<a class='buy' href='products_page.php'>Voir les produits du moment</a></div>
		</div>
	</div>
</body>
</html>
