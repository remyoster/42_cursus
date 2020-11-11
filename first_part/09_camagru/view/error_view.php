<?PHP
$title = "Error";
ob_start();
?>
	<nav>
		<ul>
			<li><a href="index.php">Accueil <i class="fas fa-camera-retro"></i></a></li>
			<li><a href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
		</ul>
	</nav>
	<h1>Camagru</h1>
	<h2>Error page</h2>
<?PHP
$header = ob_get_clean();
ob_start();
?>
<div class='text_wrapper'>
<p>Une erreur est survenue !</p>
<p><?= htmlspecialchars($e->getMessage()); ?></p>
<p>Pas de panique vous allez être redirigé dans quelques instants.</p>
</div>
<?PHP
$main_content = ob_get_clean();
require('template.php');
?>
