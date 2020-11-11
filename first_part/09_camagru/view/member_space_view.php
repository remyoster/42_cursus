<?PHP
$title = "Espace membre";
$GLOBALS['script'] = "<script src='public/js/member_space.js'></script>";
ob_start();
?>
<nav>
	<ul>
		<li><a href="index.php">Montage <i class="fas fa-camera-retro"></i></a></li>
		<li><a class="active" href="index.php?action=member_space">Espace membre <i class="far fa-address-card"></i></a></li>
		<li><a href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
		<li><a href="index.php?action=logout">Deconnexion <i class="fas fa-power-off"></i></a></li>
	</ul>
</nav>
<h1>Espace membre</h1>
<?PHP
$header = ob_get_clean();
ob_start();
?>
<form action="index.php?action=member_space" method="POST">
	<fieldset>
		<legend>Informations du compte</legend>
		<label>Pseudo:<br><input type="text" name="pseudo" onkeyup="check_hint_pseudo(this.value)" value="<?= htmlspecialchars($pseudo) ?>"></label>
		<span id="check_pseudo"></span><br />
		<label>email:<br><input type="email" name="email" onkeyup="check_hint_email(this.value)" value="<?= htmlspecialchars($email) ?>"></label>
		<span id="check_email"></span><br />
		<label>Notifications: Oui <input type="radio" name="notif" value="yes" <?= $notification == "yes" ? "checked" : ""; ?> onclick="this.form.submit_account.disabled = false"> Non <input type="radio" name="notif" value="no" <?= $notification == "no" ? "checked" : ""; ?> onclick="this.form.submit_account.disabled = false"></label><br />
		<input type="hidden" name="token" value="<?=$_SESSION['token']?>">
		<input type="submit" name="submit_account" value="Modifier" disabled="true">
	</fieldset>
</form>
<form action="index.php?action=member_space" method="POST">
	<fieldset>
		<legend>Modification du mot de passe</legend>
		<label>Nouveau mot de passe:<br><input type="password" name="password" onkeyup="check_hint_password(this.value)"></label>
		<span id="check_password"></span><br />
		<label>Confirmation:<br><input type="password" name="cfpassword" onkeyup="check_hint_cfpassword(this.value)"></label>
		<span id="check_cfpassword"></span><br />
		<input type="hidden" name="token" value="<?=$_SESSION['token']?>">
		<input type="submit" name="submit_password" value="Valider" disabled="true">
	</fieldset>
</form>

<form action="index.php?action=member_space" method="POST">
	<fieldset>
		<legend>Suppression de ses images</legend>
			<div id='form_wrapper'>
			<?php display_user_imgs() ?>
			</div>
			<br>
			<input type="hidden" name="token" value="<?=$_SESSION['token']?>">
			<input type="submit" name="submit_delete" id="delete" value="Supprimer">
			<button type="button" id="select" onclick="select_all()">Tout cocher</button>
	</fieldset>
</form>
<?PHP
$main_content = ob_get_clean();
require('template.php');
?>
