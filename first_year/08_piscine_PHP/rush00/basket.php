<?PHP
session_start();
include('connexion_sql.php');
include('ft_display_error.php');
if($_SESSION['status'] == "visitor" && isset($_GET['submit']) && $_GET['submit'] == "Valider" && $_SESSION['basket'] != NULL)
	header("Refresh: 0; URL=login.php");
else if ($_SESSION['status'] !== "visitor")
{
	if (isset($_GET['submit']) && $_GET['submit'] == "Valider" && $_SESSION['basket'] != NULL)
	{
		$query = "INSERT INTO basket (id_basket, user_name, status, total_price) VALUES (NULL, '".$_SESSION['id']."', 'done', '".$_SESSION['total']."')";
		$res = mysqli_query($db, $query);
		$_SESSION['basket'] = array();
		$_SESSION['total'] = 0;
		header("Refresh 0; URL=basket.php");
	}
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
			<h1>Panier</h1>		
		</div>
	</header>
	<div class="main-content basket">

<?PHP
	if (!(empty($_SESSION['basket'])))
	{
		echo "<h3>Voici votre panier</h3>
			<table>
			<tr style='line-height: 40px;'>
			<td class='bold'>Quantite</td>
			<td class='bold'>Produit</td>
			<td class='bold'>Prix</td>
			<td class='bold'>Sous total</td>
			</tr>";
$total = 0;
foreach($_SESSION['basket'] as $key => $value)
{
	$query = "SELECT * FROM item WHERE id_item = ".$value['id_item']."";
	$res = mysqli_query($db, $query);
	$row = mysqli_fetch_array($res);
	if ($row)
	{
		$subtotal = $row['price'] * $value['qty'];
		echo "
							<tr>
								<td>".$value['qty']."</td>
								<td>".$row['item_name']."</td>
								<td>".$row['price']."</td>
								<td>".$subtotal."</td>
							</tr>";
		$total = $total + $subtotal;
		$_SESSION['total'] = $total;
	}
}
echo "<tr><td colspan='4' class='bold'>TOTAL = $total</td></tr>
	<tr><td colspan='4' align='right'><form method='GET' action='basket.php'> <input type='submit' name='submit' class='buy' value='Valider'></form></tr></table>";
	}
	else
		echo "<h3>Votre panier est vide :(</h3>";
?>
	</div>
</body>
</html>
