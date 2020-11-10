<?PHP
$title = "Login";
$GLOBALS['script'] = "<script src='public/js/login.js'></script>";
ob_start();
?>
<nav>
	<ul>
		<li><a href="index.php">Accueil <i class="fas fa-camera-retro"></i></a></li>
		<li><a class="active" href="index.php?action=login">Se connecter <i class="fas fa-signature"></i></a></li>
		<li><a href="index.php?action=create_account">Creer un compte <i class="far fa-address-book"></i></a></li>
		<li><a href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
	</ul>
</nav>
<h1>Camagru</h1>
<h2>Connexion</h2>
<?PHP
$header = ob_get_clean();
ob_start();
?>
<form action="index.php?action=login" method="POST">
	<fieldset>
		<legend>Identification</legend>
		<label>Pseudo ou email:<br /><input type="text" name="pseudo_email"></label>
		<br />
		<label>Mot de passe:<br /><input type="password" name="password" oninput="enabled_submit()"></label>
		<br />
		<a href="index.php?action=forgot_password">Mot de passe oublié ?</a>
		<br />
		<input type="hidden" name="token" value="<?=$_SESSION['token']?>">
		<input type="submit" name="submit" value="Valider" disabled="true">
	</fieldset>
</form>
<div class="home_montage">
<img class='main_img' src='public/img/site/montage_admin3.jpeg' alt="best_montage_ever">
</div>
<?PHP
$main_content = ob_get_clean();
require('template.php');
?>
