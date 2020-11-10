<?PHP
$title = "Réinitialisation de mot de passe";
$GLOBALS['script'] = "<script src='public/js/reset_password.js'></script>";
ob_start();
?>
<nav>
	<ul>
		<li><a href="index.php">Accueil <i class="fas fa-camera-retro"></i></a></li>
		<li><a href="index.php?action=login">Se connecter <i class="fas fa-signature"></i></a></li>
		<li><a href="index.php?action=create_account">Creer un compte <i class="far fa-address-book"></i></a></li>
		<li><a href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
	</ul>
</nav>
<h1>Camagru</h1>
<h2>Réinitialisation de mot passe</h2>
<?PHP
$header = ob_get_clean();
ob_start();
if (isset($password) && empty($GLOBALS['error']))
{
?>
<div class='text_wrapper'>
	<p>Votre mot de passe à bien été modifié.</p>
	<p>Vous allez être redirigé vers la page de login.</p>
</div>
<?PHP
}
else
{
?>
	<form action="index.php?action=reset_password&email=<?=$data['email']?>&id=<?=$data['id']?>" method="POST">
	<fieldset>
		<legend>Entrez votre nouveau mot de passe</legend>
		<label>Mot de passe:<br><input type="password" name="password" onkeyup="check_hint_password(this.value)"></label>
		<span id="check_password"></span><br />
		<label>Confirmation:<br><input type="password" name="cfpassword" onkeyup="check_hint_cfpassword(this.value)"></label>
		<span id="check_cfpassword"></span><br />
		<input type="hidden" name="token" value="<?=$_SESSION['token']?>">
		<input type="submit" name="submit" value="Valider" disabled="true">
	</fieldset>
</form>
<?PHP
}
$main_content = ob_get_clean();
require('template.php');
?>
