<?PHP
session_start();
include('connexion_sql.php');
include('ft_display_error.php');
include('ft_display_success.php');
if ($_SESSION['status'] == "admin")
{
	if (isset($_POST['submit_modif_user']) && $_POST['submit_modif_user'] == "Modifier")
	{
		$id = $_POST['id_user'];
		if (isset($_POST['lastname']) && $_POST['lastname'] != "")
			mysqli_query($db, "UPDATE user SET lastname ='".mysqli_real_escape_string($db, $_POST['lastname'])."' WHERE user . id_user = $id");
		if (isset($_POST['firstname']) && $_POST['firstname'] != "")
			mysqli_query($db, "UPDATE user SET firstname ='".mysqli_real_escape_string($db, $_POST['firstname'])."' WHERE user . id_user = $id");
		if (isset($_POST['email']) && $_POST['email'] != "")
			mysqli_query($db, "UPDATE user SET email ='".mysqli_real_escape_string($db, $_POST['email'])."' WHERE user . id_user = $id");
		if (isset($_POST['phone']) && $_POST['phone'] != "")
			mysqli_query($db, "UPDATE user SET phone ='".mysqli_real_escape_string($db, $_POST['phone'])."' WHERE user . id_user = $id");
		if (isset($_POST['address']) && $_POST['address'] != "")
			mysqli_query($db, "UPDATE user SET address ='".mysqli_real_escape_string($db, $_POST['address'])."' WHERE user . id_user = $id");
		if (isset($_POST['city']) && $_POST['city'] != "")
			mysqli_query($db, "UPDATE user SET city ='".mysqli_real_escape_string($db, $_POST['city'])."' WHERE user . id_user = $id");
		if (isset($_POST['country']) && $_POST['country'] != "")
			mysqli_query($db, "UPDATE user SET country ='".mysqli_real_escape_string($db, $_POST['country'])."' WHERE user . id_user = $id");
		if (isset($_POST['postal_code']) && $_POST['postal_code'] != "")
			mysqli_query($db, "UPDATE user SET postal_code ='".mysqli_real_escape_string($db, $_POST['postal_code'])."' WHERE user . id_user = $id");
		ft_display_success();
		$_POST = [];
	}
	if (isset($_POST['submit_del_user']) && $_POST['submit_del_user'] == "Supprimer")
	{
		if (isset($_POST['id_user_del']))
		{
			$id = $_POST['id_user_del'];
			mysqli_query($db, "DELETE FROM user WHERE user . id_user = $id");
			ft_display_success();
			$_POST = [];
		}
		else
			ft_display_error(0);
	}
	if (isset($_POST['submit_add_stock']) && $_POST['submit_add_stock'] == "Ajouter")
	{
		if (isset($_POST['item_name']) && isset($_POST['description']) && isset($_POST['item_stock']) && isset($_POST['price']))
		{
			$query = "INSERT INTO item (item_name, description, item_stock, price) VALUES ('".mysqli_real_escape_string($db, $_POST['item_name'])."', '".mysqli_real_escape_string($db, $_POST['description'])."', '".mysqli_real_escape_string($db, $_POST['item_stock'])."', '".mysqli_real_escape_string($db, $_POST['price'])."')";
			$res = mysqli_query($db, $query);
			$_POST['submit_add_stock'] === NULL;
			ft_display_success();
			$_POST = [];
		}
		else
			ft_display_error(0);
	}
	if (isset($_POST['submit_modif_stock']) && $_POST['submit_modif_stock'] == "Modifier")
	{
		$id = $_POST['id_item_modif'];
		if (isset($_POST['item_name']))
			mysqli_query($db, "UPDATE item SET item_name ='".mysqli_real_escape_string($db, $_POST['item_name'])."' WHERE item . id_item = $id");
		if (isset($_POST['description']))
			mysqli_query($db, "UPDATE item SET description ='".mysqli_real_escape_string($db, $_POST['description'])."' WHERE item . id_item = $id");
		if (isset($_POST['item_stock']))
			mysqli_query($db, "UPDATE item SET item_stock ='".mysqli_real_escape_string($db, $_POST['item_stock'])."' WHERE item . id_item = $id");
		if (isset($_POST['price']))
			mysqli_query($db, "UPDATE item SET price ='".mysqli_real_escape_string($db, $_POST['price'])."' WHERE item . id_item = $id");
		ft_display_success();
		$_POST = [];
	}
	if (isset($_POST['submit_del_stock']) && $_POST['submit_del_stock'] == "Supprimer")
	{
		if (isset($_POST['id_item_del']))
		{
			$id = $_POST['id_item_del'];
			mysqli_query($db, "DELETE FROM item WHERE item . id_item = $id");
			ft_display_success();
			$_POST = [];
		}
		else
			ft_display_error(0);
	}
	if (isset($_POST['submit_add_type']) && $_POST['submit_add_type'] == "Ajouter")
	{
		if (isset($_POST['id_type']) && isset($_POST['name']))
		{
			$query = "INSERT INTO type (it_type, name) VALUES (NULL, '".mysqli_real_escape_string($db, $_POST['name'])."')";
			$res = mysqli_query($db, $query);
			$_POST['submit_add_type'] === NULL;
			ft_display_success();
			$_POST = [];
		}
		else
			ft_display_error(0);
	}
	if (isset($_POST['submit_modif_type']) && $_POST['submit_modif_type'] == "Modifier")
	{
		$id = $_POST['id_type'];
		if (isset($_POST['name']))
		{
			mysqli_query($db, "UPDATE type SET name = '".mysqli_real_escape_string($db, $_POST['name'])."' WHERE type . it_type = $id");
			ft_display_success();
			$_POST = [];
		}
	}
	if (isset($_POST['submit_del_type']) && $_POST['submit_del_type'] == "Supprimer")
	{
		if (isset($_POST['id_type_del']))
		{
			$id = $_POST['id_type_del'];
			mysqli_query($db, "DELETE FROM type WHERE type . it_type = $id");
			$_POST = [];
			ft_display_success();
		}
		else
			ft_display_error(0);
	}
}
else
	return ft_display_error(4);
?>

<!DOCTYPE html>
<html>
<head>
	<title>Page administrateur MultiFruix</title>
	<link rel="stylesheet" type="text/css" href="main.css">
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
</head>
<body>
	<header>
		<?php include('menu.php'); ?>
		<div>
		<h1>Modifier la base de données</h1>
	</header>
	<div class="main-content admin-space">
<h3>Utilisateurs</h3>
<table>
	<th>
		<td class="bold">Lastname</td>
		<td class="bold">Firstname</td>
		<td class="bold">email</td>
		<td class="bold">phone</td>
		<td class="bold">address</td>
		<td class="bold">city</td>
		<td class="bold">country</td>
		<td class="bold">postal_code</td>
	</th>
<?PHP
$query = "SELECT id_user, lastname, firstname, email, phone, address, city, country, postal_code FROM user";
$res = mysqli_query($db, $query);
while ($data = mysqli_fetch_array($res))
{ 
	echo "<tr>";
	echo "<td>".$data['id_user']."</td>";
	echo "<td>".$data['lastname']."</td>";
	echo "<td>".$data['firstname']."</td>";
	echo "<td>".$data['email']."</td>";
	echo "<td>".$data['phone']."</td>";
	echo "<td>".$data['address']."</td>";
	echo "<td>".$data['city']."</td>";
	echo "<td>".$data['country']."</td>";
	echo "<td>".$data['postal_code']."</td>";
	echo "</tr>";
}
?>
</table>
<form action="admin_space.php" method="POST">
	<span class="bold">Modifier un utilisateur :</span>
	<tr>
		<td><input type"number" name="id_user" placeholder="id_user" value=""></td>
		<td><input type="text" name="lastname" placeholder="NOM" value=""></td>
		<td><input type="text" name="firstname" placeholder="Prenom" value=""></td>
		<td><input type="email" name="email" placeholder="email" value=""></td>
		<td><input type="tel" name="phone" placeholder="N de tel" value=""></td>
		<td><input type="text" name="address" placeholder="Addresse" value=""></td>
		<td><input type="number" name="postal_code" placeholder="Code postal" value=""></td>
		<td><input type="text" name="city" placeholder="VILLE" value=""></td>
		<td><input type="text" name="country" placeholder="PAYS" value=""></td>
		<input type="submit" name="submit_modif_user" value="Modifier">
		<br />
		<span class="bold">Supprimer un utilisateur :</span>
		<td><input type="number" name="id_user_del" placeholder="id_user" value=""></td>
		<input type="submit" name="submit_del_user" value="Supprimer">
	</tr>
</form>
<h3>Stock</h3>
<table>
	<th>
		<td class="bold">Nom du produit</td>
		<td class="bold">Categories du produit</td>
		<td class="bold">Description</td>
		<td class="bold">Stock (en kg)</td>
		<td class="bold">Prix(au kg)</td>
		<td class="bold">Image produit</td>
	</th>
	<?PHP
	$query = "SELECT * FROM item";
	$res = mysqli_query($db, $query);
	while ($data = mysqli_fetch_array($res))
	{ 
		echo "<tr>";
		echo "<td>".$data['id_item']."</td>";
		echo "<td>".$data['item_name']."</td>";
		echo "<td>".$data['type']."</td>";
		echo "<td>".$data['description']."</td>";
		echo "<td>".$data['item_stock']."</td>";
		echo "<td>".$data['price']."</td>";
		echo "<td>".$data['img']."</td>";
		echo "</tr>";
	}
?>
</table>
<form action="admin_space.php" method="POST">
	<tr>
		<span class="bold">Modifier le stock :</span>
		<td><input type"number" name="id_item_modif" placeholder="id_item" value=""></td>
		<td><input type="text" name="item_name" placeholder="Nom du produit" value=""></td>
		<td><input type="text" name="description" placeholder="Description" value=""></td>
		<td><input type="number" name="item_stock" placeholder="Stock(en kg)" value=""></td>
		<td><input type="text" name="price" placeholder="Prix(au kg)" value=""></td>
		<input type="submit" name="submit_add_stock" value="Ajouter">
		<input type="submit" name="submit_modif_stock" value="Modifier">
		<br />
		<span class="bold">Supprimer le stock :</span>
		<td><input type="number" name="id_item_del" placeholder="id_item" value=""></td>
		<input type="submit" name="submit_del_stock" value="Supprimer">
	</tr>
</form>
<h3>Order</h3>
<table>
	<th>
		<td class="bold">User</td>
		<td class="bold">Nom du produit</td>
		<td class="bold">Date</td>
		<td class="bold">Prix(au kg)</td>
		<td class="bold">Etat de la commande</td>
	</th>
	<?PHP
	$query = "SELECT * FROM basket";
	$res = mysqli_query($db, $query);
	while ($data = mysqli_fetch_array($res))
	{ 
		echo "<tr>";
		echo "<td>".$data['id_basket']."</td>";
		echo "<td>".$data['user_name']."</td>";
		echo "<td>".$data['item_name']."</td>";
		echo "<td>".$data['date']."</td>";
		echo "<td>".$data['total_price']."</td>";
		echo "<td>".$data['status']."</td>";
		echo "</tr>";
	}
	?>
</table>
</body>
</html>
