<?PHP
$GLOBALS['script'] = "<script src='public/js/home_view.js'></script>";
ob_start();
?>
	<nav>
		<ul>
			<li><a class="active" href="index.php">Montage <i class="fas fa-camera-retro"></i></a></li>
			<li><a href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
			<li><a href="index.php?action=logout">Deconnexion <i class="fas fa-power-off"></i></a></li>
		</ul>
	</nav>
	<h1>Camagru</h1>
	<h2>Ici vous allez pouvoir réaliser des montages incroyables</h2>
<?PHP
$header = ob_get_clean();
ob_start();
?>
<div class='text_wrapper'>
	<p>Votre compte n'est pas encore validé, allez voir votre boîte mail(si vous n'avez rien reçu cliquez <a href="index.php?action=resent_email">ici</a>).</p>
<img src="public/img/site/appareil_photo.png" alt="appareil_photo">
	<p>En attendant vous pouvez regarder la galerie pour découvrir les montages des membres.</p>
</div>
<div class="home_montage">
<img class='main_img' src='public/img/site/montage_admin2.jpeg' alt="best_montage_ever">
</div>
<?PHP
$main_content = ob_get_clean();
require('template.php');
?>
