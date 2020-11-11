<?php 
session_start();
include ("ft_display_error.php");
$_SESSION['status'] = "visitor";
$_SESSION['id'] = 0;
$_SESSION['basket'] = array();
header("Refresh: 0; URL=index.php");
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
