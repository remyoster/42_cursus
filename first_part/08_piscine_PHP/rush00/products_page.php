<?PHP
session_start();
include('connexion_sql.php');
include('ft_display_error.php');
if (isset($_GET['submit']) && $_GET['submit'] == "Commander")
{
	$id = mysqli_real_escape_string($db, $_GET['id']);
	$qty = intval(mysqli_real_escape_string($db, $_GET['qty']));
	if ($id !== 0 && $qty !== 0)
	{
		$_SESSION['basket'][] = array("id_item" => $id, "qty" => $qty);
		echo "Commande ajoutee au panier\n";
		header("Refresh: 0; URL=products_page.php");
	}
	else{
		ft_display_error(0);
	}
}
?>

<!DOCTYPE html>
<html>
<head>
	<title>Page de produits MultiFruix</title>
	<link rel="stylesheet" type="text/css" href="main.css">
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
</head>
<body>
	<header>
		<?php include('menu.php'); ?>
		<div>
			<h1>MultiFruix : Pour chaque fruit sa saison</h1>
			<h2>Tous les fruits et légumes dont vous avez besoin sont sur cette page</h2>			
		</div>
	</header>
	<div class="main-content">
		<nav id="products-nav">
			<ul>		  
				<li><a class="cat" href="products_page.php">Tous</a></li>  
				<?PHP

				$query = "SELECT DISTINCT type FROM item";
				$res = mysqli_query($db, $query);
				while ($row = mysqli_fetch_array($res))
				{
					$category = $row['type'];
					echo "<li><a class='cat' href='products_page.php?type=$category'>".$category."</a></li>";
				}

				?>
							</ul>
						</nav>
						<h3>Les produits du printemps</h3>
						<div class="products">

				<?PHP
				if (isset($_GET['type']) && $_GET['type'] != "")
				{
					$query = "SELECT * FROM item WHERE item.type = '".$_GET['type']."'";
					$res = mysqli_query($db, $query);
					while ($row = mysqli_fetch_array($res)) {
						$item_name = $row['item_name'];
						$category = $row['type'];
						$type = $row['type'];
						$description = $row['description'];
						$price = $row['price'];
						$img = $row['img'];
						$id = $row['id_item'];
						echo "
						<div>
							<img src=".$img.">
							<div class='infos-produit'>
								<h4>".$item_name."</h4>
								<p>".$description."</p>
								<p>".$price."(€) (au kg)</p>
							</div>
							<form action ='products_page.php' method='GET'>
			                    <input type='hidden' name='id' value='$id'>
			                    <div class='choose'>
			                    <label>Choisir la quantite :</label>
			                    <input type='number' min='1' name='qty' class='qty' placeholder='Kg' value=''>
			                    </div>
								<input type='submit' name='submit' value='Commander'>
			                </form>
						</div>";
					}
				} else {
					$query = "SELECT * FROM item";
					$res = mysqli_query($db, $query);
					while ($row = mysqli_fetch_array($res)) {
						$item_name = $row['item_name'];
						$description = $row['description'];
						$price = $row['price'];
						$img = $row['img'];
						$id = $row['id_item'];
						echo "
						<div>
							<img src=".$img.">
							<div class='infos-produit'>
								<h4>".$item_name."</h4>
								<p>".$description."</p>
								<p>".$price."(€) (au kg)</p>
							</div>
							<form action ='products_page.php' method='GET'>
								<input type='hidden' name='id' value='$id'>
								<div class='choose'>
								<label>Choisir la quantite :</label>
								<input type='number' min='1' name='qty' class='qty' placeholder='Kg' value=''>
								</div>
								<input type='submit' name='submit' class='buy' value='Commander'>
							</form>
							</div>";
					}
				}
				?>
		</div>
	</div>
</body>
</html>
