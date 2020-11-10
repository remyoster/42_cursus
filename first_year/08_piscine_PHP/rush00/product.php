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
	<div class="main-content product-page">
		<div class="product">
			<?PHP
			
				$query = "SELECT * FROM item";
				$res = mysqli_query($db, $query);
				$row = mysqli_fetch_array($res); 
				$item_name = $row['item_name'];
				$description = $row['description'];
				$price = $row['price'];
				$img = $row['img'];
				$id = $row['id_item'];
				echo "
					<img src=".$img.">
					<div class='infos-product'>
					<h4>".$item_name."</h4>
					<p>".$description."</p>
					<p>Prix : ".$price." (au kg)</p>
					<form action ='products_page.php' method='POST'>
						<input type='hidden' name='id' value='$id'>
						<label>Choisir la quantite :</label>
						<input type='number' name='qty' placeholder='Kg' value=''>
						<input class='buy' type='button' name='submit' value='Commander'>
					</form>";
			?>			
		</div>
	</div>
</body>
</html>