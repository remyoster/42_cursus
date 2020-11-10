<?PHP
$title = "Création de compte";
$GLOBALS['script'] = "<script src='public/js/create_account.js'></script>";
ob_start();
?>
<nav>
	<ul>
		<li><a href="index.php">Accueil <i class="fas fa-camera-retro"></i></a></li>
		<li><a href="index.php?action=login">Se connecter <i class="fas fa-signature"></i></a></li>
		<li><a class="active" href="index.php?action=create_account">Creer un compte <i class="far fa-address-book"></i></a></li>
		<li><a href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
	</ul>
</nav>
<h1>Camagru</h1>
<h2>Création de compte</h2>
<?PHP
$header = ob_get_clean();
ob_start();
?>
<form action="index.php?action=create_account" method="POST">
	<fieldset>
		<legend>Informations du compte</legend>
		<label>Pseudo:<br /><input type="text"  name="pseudo" onkeyup="check_hint_pseudo(this.value)"></label>
		<span id="check_pseudo"></span><br />
		<label>email:<br /><input type="email" name="email" onkeyup="check_hint_email(this.value)"></label>
		<span id="check_email"></span><br />
		<label>Mot de passe:<br /><input type="password" name="password" onkeyup="check_hint_password(this.value)"></label>
		<span id="check_password"></span><br />
		<label>Confirmation:<br /><input type="password" name="cfpassword" onkeyup="check_hint_cfpassword(this.value)"></label>
		<span id="check_cfpassword"></span><br />
		<input type="hidden" name="token" value="<?=$_SESSION['token']?>">
		<input type="submit" name="submit" value="Valider" disabled="true">
	</fieldset>
</form>
<?PHP
$main_content = ob_get_clean();
require('template.php');
?>
