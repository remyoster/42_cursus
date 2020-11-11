<?php 
session_start();
include('connexion_sql.php');
include('ft_display_error.php');
if (isset($_POST['submit']))
{
	if ($_POST['submit'] == "OK")
	{
		if(isset($_POST['firstname']) && isset($_POST['lastname']) && isset($_POST['email']) && isset($_POST['phone']) && isset($_POST['address']) && isset($_POST['postal_code']) && isset($_POST['city']) && isset($_POST['country']) && isset($_POST['passwd']))
		{
			$email = mysqli_real_escape_string($db, $_POST['email']);
			if (!(mysqli_fetch_array(mysqli_query($db, "SELECT * FROM user WHERE email LIKE '$email'"))))
			{
				$query = "INSERT INTO user (id_user, lastname, firstname, email, phone, address, city, country, postal_code, passwd, group_user) VALUES (NULL, '".mysqli_real_escape_string($db, $_POST['lastname'])."', '".mysqli_real_escape_string($db, $_POST['firstname'])."', '".mysqli_real_escape_string($db, $_POST['email'])."', '".mysqli_real_escape_string($db, $_POST['phone'])."', '".mysqli_real_escape_string($db, $_POST['address'])."', '".mysqli_real_escape_string($db, $_POST['city'])."', '".mysqli_real_escape_string($db, $_POST['country'])."', '".mysqli_real_escape_string($db, $_POST['postal_code'])."', '".hash("whirlpool", mysqli_real_escape_string($db, $_POST['passwd']))."', 'regular')";
				$res = mysqli_query($db, $query);
				$data = mysqli_fetch_array(mysqli_query($db, "SELECT * FROM user WHERE email LIKE '$email'"));
				$_SESSION['id'] = $data['id_user'];
				$_SESSION['status'] = "regular";
				if (!(empty($_SESSION['basket'])))
					header("Refresh: 0; URL=basket.php");
				else
					header("Refresh: 0; URL=index.php");
				mysqli_close($db);
			}
			else
				ft_display_error(5);
		}
		else
			ft_display_error();
	}
}
?>

<!DOCTYPE html>
<html><head>
	<title>Create your account</title>
	<link rel="stylesheet" type="text/css" href="main.css">
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
</head>
<body>
	<header>
		<?php include('menu.php'); ?>
		<div>
		<h1>Creation de compte</h1> 
	</header>
	<div class="main-content">
		<form action="create_account.php" method="POST">
			<legend>Creer un compte</legend>
			<label>Prénom: <input type="text" name="firstname" required pattern="[A-Za-z]+" value="<?php if (isset($_SESSION["firstname"])) { print($_SESSION["firstname"]); } ?>"></label>
			<br/>
			<label>Nom: <input type="text" name="lastname" required pattern="[A-Za-z]+" value="<?php if (isset($_SESSION["lastname"])) { print($_SESSION["lastname"]); } ?>"></label>
			<br/>
			<label>Email: <input type="email" name="email" value="<?php if (isset($_SESSION["email"])) { print($_SESSION["email"]); } ?>"></label>
			<br/>            
			<label>Phone: <input type="tel" name="phone" value="<?php if (isset($_SESSION["phone"])) { print($_SESSION["phone"]); } ?>"></label>
			<br/>
			<label>Adresse: <input type="text" name="address" value="<?php if (isset($_SESSION["address"])) { print($_SESSION["address"]); } ?>"></label>
			<br/>
			<label>Code postal: <input type="number" name="postal_code" value="<?php if (isset($_SESSION["postal_code"])) { print($_SESSION["postal_code"]); } ?>"></label>
			<br/>
			<label>Ville: <input type="text" name="city" value="<?php if (isset($_SESSION["city"])) { print($_SESSION["city"]); } ?>"></label>
			<br/>
			<label>Pays: <input type="text" name="country" value="<?php if (isset($_SESSION["country"])) { print($_SESSION["country"]); } ?>"></label>
			<br/>  
			<label>Mot de passe:  <input type="password" name="passwd" value="<?php if (isset($_SESSION["passwd"])) { print($_SESSION["passwd"]); } ?>"></label>
			<input type="submit" name="submit" value="OK">
		</form> 
	</div>    
</body>
</html>
