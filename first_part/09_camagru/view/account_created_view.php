<?PHP
$title = "Validation de compte";
ob_start();
?>
<nav>
	<ul>
		<li><a href="index.php">Montage <i class="fas fa-camera-retro"></i></a></li>
		<li><a href="index.php?action=logout">Deconnexion <i class="fas fa-power-off"></i></a></li>
		<li><a href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
	</ul>
</nav>
<h1>Camagru</h1>
<h2>Validation de compte</h2>
<?PHP
$header = ob_get_clean();
ob_start();
?>
<div class='text_wrapper'>
<p>Votre compte à bien été créé. Un lien vous sera envoyé sur votre addresse mail afin de l'activer.</p>
<p>Vous aurez ensuite accés à la totalité du site.<p>
</div>
<?PHP
$main_content = ob_get_clean();
require('template.php');
?>
