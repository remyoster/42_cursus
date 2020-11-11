<?PHP
$title = "Mot de passe oublié";
$GLOBALS['script'] = "<script src='public/js/forgot_password.js'></script>";
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
<h2>Mot de passe oublié</h2>
<?PHP
$header = ob_get_clean();
ob_start();
if (!isset($data))
{
?>
<form action="index.php?action=forgot_password" method="POST">
	<fieldset>
		<legend>Identification</legend>
		<label>Pseudo ou email: <input type="text" name="pseudo_email" oninput="enabled_submit()"></label>
		<br />
		<input type="hidden" name="token" value="<?=$_SESSION['token']?>">
		<input type="submit" name="submit" value="Envoyer" disabled="true">
	</fieldset>
</form>
<?PHP
}
else
{
?>
<div class='text_wrapper'>
	<p>Un email vient de vous être envoyé.</p>
	<p>Vous allez être redirigé vers la page d'acceuil.</p>
</div>
<?PHP
}
$main_content = ob_get_clean();
require('template.php');
?>
