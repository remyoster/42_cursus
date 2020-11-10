<?PHP
ob_start();
?>
	<nav>
		<ul>
			<li><a class="active" href="index.php">Accueil <i class="fas fa-camera-retro"></i></a></li>
			<li><a href="index.php?action=login">Se connecter <i class="fas fa-signature"></i></a></li>
			<li><a href="index.php?action=create_account">Creer un compte <i class="far fa-address-book"></i></a></li>
			<li><a href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
		</ul>
	</nav>
	<h1>Bienvenue sur mon Camagru</h1>
	<h2>Ici vous allez pouvoir réaliser des montages incroyables</h2>
<?PHP
$header = ob_get_clean();
ob_start();
?>
<div class='text_wrapper'>
	<p> Pour commencer votre experience connectez vous ou créez vous un compte.</p>
<img src="public/img/site/appareil_photo.png" alt="appareil_photo">
	<p> C'est ensuite sur cette même page que vous pourrez faire vos montages.</p>
	<p>En attendant vous pouvez aussi regarder la galerie ou vous trouverez les montages des membres.</p>
</div>
<div class="home_montage">
<img class='main_img' src='public/img/site/montage_admin.jpeg' alt="best_montage_ever">
</div>
<?PHP
$main_content = ob_get_clean();
require('template.php');
?>
