<?php 
session_start();
include ("ft_display_error.php");
include('connexion_sql.php');
if (isset($_SESSION['id']) && $_SESSION['status'] == "visitor")
{
	if(isset($_POST['submit']))
	{
		if ($_POST['submit'] == "OK")
		{
			if(isset($_POST['email']) && isset($_POST['passwd']))
			{
				$email = mysqli_real_escape_string($db, $_POST['email']);
				$query = "SELECT * FROM user WHERE email LIKE '$email'";
				$res = mysqli_query($db, $query);
				$data = mysqli_fetch_array($res);
				if ($data)
				{
					$passwd = hash("whirlpool", $_POST['passwd']);
					$query = "SELECT * FROM user WHERE passwd LIKE '$passwd'";
					$res = mysqli_query($db, $query);
					$data = mysqli_fetch_array($res);
					if ($data)
					{
						$data = mysqli_fetch_array(mysqli_query($db, "SELECT * FROM user WHERE email LIKE '$email'"));
						$_SESSION['id'] = $data['id_user'];
						if ($data['group_user'] == "admin")
						{
							$_SESSION['status'] = "admin";
							header("Refresh: 0; URL=admin_space.php");
						}
						else
							$_SESSION['status'] = "regular";
						mysqli_close($db);
						if (!(empty($_SESSION['basket'])))
							header("Refresh: 0; URL=basket.php");
						else
							header("Refresh: 0; URL=index.php");
					}
					else
						ft_display_error(1);
				}
				else
					ft_display_error(2);
			}
			else
				ft_display_error(3);
		}
	}
}
else
	echo "Vous etes deja connecte\n";
?>

<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" type="text/css" href="main.css">
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<title>Page de Login</title>
</head>
<body>
	<header>
		<?php include('menu.php'); ?>
		<div>
			<h1>Connecter vous pour commander chez MultiFruix</h1>		
		</div>
	</header>
	<div class="main-content">
		<form action="login.php" method="POST">
			<legend>Se connecter :</legend>
			<br/>
			<label>Email: <input type="email" name="email" value=""></label>
			<br/>            
			<label>Mot de passe:  <input type="password" name="passwd" value=""></label>
			<input type="submit" name="submit" value="OK">
		</form> 
	</div>    
</body>
</html>
