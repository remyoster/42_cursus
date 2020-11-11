<?PHP
$title = "Validation";
ob_start();
?>
	<nav>
		<ul>
			<li><a href="index.php">Montage <i class="fas fa-camera-retro"></i></a></li>
			<li><a href="index.php?action=member_space">Espace membre <i class="far fa-address-card"></i></a></li>
			<li><a href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
			<li><a href="index.php?action=logout">Deconnexion <i class="fas fa-power-off"></i></a></li>
		</ul>
	</nav>
	<h1>Camagru</h1>
	<h2>Compte validé</h2>
<?PHP
$header = ob_get_clean();
ob_start();
?>
<div class='text_wrapper'>
	<p>Bienvenue <?= htmlspecialchars($_SESSION['pseudo']) ?></p>
	<p>Votre compte est maintenant validé, vous allez être redirigé dans quelques instants.</p>
</div>
<?PHP
$main_content = ob_get_clean();
require('template.php');
?>
