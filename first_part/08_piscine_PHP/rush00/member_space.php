<?PHP
session_start();
include('connexion_sql.php');
include('ft_display_error.php');
if (isset($_SESSION['id']) && $_SESSION['id'] != "")
{
	if (isset($_POST['submit_info']) && $_POST['submit_info'] == "Oui")
	{
		$query = "SELECT * FROM user WHERE id_user LIKE ".$_SESSION['id']."";
		$res = mysqli_query($db, $query);
		$data = mysqli_fetch_array($res);
		if (isset($data))
		{
			if ($_POST['phone'] !== $data['phone'])
				mysqli_query($db, "UPDATE user SET phone = '".$_POST['phone']."' WHERE user . id_user = ".$_SESSION['id']."");
			if ($_POST['address'] !== $data['address'])
				mysqli_query($db, "UPDATE user SET address = '".$_POST['address']."' WHERE user . id_user = ".$_SESSION['id']."");
			if ($_POST['postal_code'] !== $data['postal_code'])
				mysqli_query($db, "UPDATE user SET postal_code = '".$_POST['postal_code']."' WHERE user . id_user = ".$_SESSION['id']."");
			if ($_POST['city'] !== $data['city'])
				mysqli_query($db, "UPDATE user SET city = '".$_POST['city']."' WHERE user . id_user = ".$_SESSION['id']."");
			if ($_POST['country'] !== $data['country'])
				mysqli_query($db, "UPDATE user SET country = '".$_POST['country']."' WHERE user . id_user = ".$_SESSION['id']."");
			echo '<div class="change">'."Modification faites avec succes\n".'</div>';
		}
	}
	if (isset($_POST['submit_pwd']) && $_POST['submit_pwd'] == "OK")
	{
		if(isset($_POST['newpwd']) && isset($_POST['cfnewpwd']))
		{
			if ($_POST['newpwd'] === $_POST['cfnewpwd'])
			{
				$newpwd = hash("whirlpool", mysqli_real_escape_string($db, $_POST['newpwd']));
				$query = "UPDATE user SET passwd = '$newpwd' WHERE user . id_user = ".$_SESSION['id']."";
				$res = mysqli_query($db, $query);
				echo '<div class="change">'."Modification faites avec succes\n".'</div>';
			}
			else
				ft_display_error(1);
		}
		else
			ft_display_error(1);
	}
	if(isset($_POST['submit_delete']) && $_POST['submit_delete'] == "OK")
	{
		if(isset($_POST['pwd']) && isset($_POST['cfpwd']))
		{
			if ($_POST['pwd'] === $_POST['cfpwd'])
			{
				$pwd = hash("whirlpool", mysqli_real_escape_string($db, $_POST['pwd']));
				$query = "SELECT * FROM user WHERE passwd LIKE '$pwd'";
				$res = mysqli_query($db, $query);
				$data = mysqli_fetch_array($res);
				if ($data)
				{
					$query = "DELETE FROM user WHERE id_user = ".$_SESSION['id']."";
					$res = mysqli_query($db, $query);
					$_SESSION['email'] = "";
					mysqli_close($db);
					header("Refresh: 0; URL=index.php");
				}
				else
					ft_display_error(1);
			}
			else
				ft_display_error(1);
		}
		else
			ft_display_error(3);
	}
}
else{
	echo "
	<!DOCTYPE html>
	<html>
	<head>
		<title>Espace membre MultiFruix</title>
		<link rel='stylesheet' type='text/css' href='main.css'>
		<meta http-equiv='Content-Type' content='text/html; charset=UTF-8' />
		<link href='https://fonts.googleapis.com/css?family=Montserrat' rel='stylesheet'>
	</head>
	<body>
		<header>
		";
	include('menu.php');
	echo "
			<div>
				<h1>Votre espace membre</h1>		
			</div>
		</header>
		<div class='main-content member-space'>
		</body>
	</html>";
	return ft_display_error(4);
}
?>



<!DOCTYPE html>
<html>
<head>
	<title>Espace membre MultiFruix</title>
	<link rel="stylesheet" type="text/css" href="main.css">
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
</head>
<body>
	<header>
		<?php include('menu.php'); ?>
		<div>
			<h1>Votre espace membre</h1>		
		</div>
	</header>
	<div class="main-content member-space">
		<h3>Recapitulatif</h3>
<?PHP
if (isset($_SESSION['id']) && $_SESSION['id'] != "")
{
	$query = "SELECT * FROM user WHERE id_user LIKE ".$_SESSION['id']."";
	$res = mysqli_query($db, $query);
	$data = mysqli_fetch_array($res);
}
else
	return ft_display_error(4);
?>
		<form action="member_space.php" method="POST">
			<label>Email: <?= $data['email']; ?>"</label>
			<br/>
			<label>Prénom: <?= $data['firstname']; ?></label>
			<br/>
			<label>Nom: <?= $data['lastname']; ?></label> 
		   <br/>
			<label>Phone: <input type="tel" name="phone" value="<?= $data['phone']; ?>"></label>
			<br/>
			<label>Adresse: <input type="text" name="address" value="<?= $data['address']; ?>"></label>
			<br/>
			<label>Code postal: <input type="number" name="postal_code" value="<?= $data['postal_code']; ?>"></label>
			<br/>
			<label>Ville: <input type="text" name="city" value="<?= $data['city']; ?>"></label>
			<br/>
			<label>Pays: <input type="text" name="country" value="<?= $data['country']; ?>"></label>
			<br/>
			<label>Voulez vous modifier ces informations ?</label>
			<br/>
			<input type="submit" name="submit_info" value="Oui">
		</form>
		<h3>Mes commandes</h3>
<?PHP
if (isset($_SESSION['id']) && $_SESSION['id'] != "")
{
	$id = $_SESSION['id'];
	$query = "SELECT * FROM basket WHERE user_name = $id";
	$res = mysqli_query($db, $query);
	while ($data = mysqli_fetch_array($res))
	{
		echo "<table><tr>";
		echo 	'<td>'.$data['id_basket'].'</td>';
		echo '<td>'.$data['item_name'].'</td>';
		echo '<td>'.$data['date'].'</td>';
		echo '<td>'.$data['total_price'].'</td>';
echo "</tr></table>";
	}
}
?>
		<h3>Modifiez votre mot de passe</h3>
		<form action="member_space.php" method="POST">
			<label>Nouveau mot de passe:  <input type="password" name="newpwd" value="<?php if (isset($_SESSION["newpwd"])) { print($_SESSION["newpwd"]); } ?>"></label>
			<br/>
			<label>Confirmation:  <input type="password" name="cfnewpwd" value="<?php if (isset($_SESSION["cfnewpwd"])) { print($_SESSION["cfnewpwd"]); } ?>"></label>
			<br/>
			<input type="submit" name="submit_pwd" value="OK">
		</form>
		<h3>Supprimer son compte</h3>
		<form action="member_space.php" method="POST">
			<label>Mot de passe:  <input type="password" name="pwd" value="<?php if (isset($_SESSION["pwd"])) { print($_SESSION["pwd"]); } ?>"></label>
			<br/>
			<label>Confirmation:  <input type="password" name="cfpwd" value="<?php if (isset($_SESSION["cfpwd"])) { print($_SESSION["cfpwd"]); } ?>"></label>
			<br/>
			<input type="submit" name="submit_delete" value="OK">
		</form>
	</body>
</html>
