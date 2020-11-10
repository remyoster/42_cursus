<?PHP
$title = "Galerie";
$GLOBALS['script'] = "<script src='public/js/gallery.js'></script>";
ob_start();
if ($_SESSION['status'] == "visitor")
{
?>
<nav>
	<ul>
		<li><a href="index.php">Accueil <i class="fas fa-camera-retro"></i></a></li>
		<li><a href="index.php?action=login">Se connecter <i class="fas fa-signature"></i></a></li>
		<li><a href="index.php?action=create_account">Creer un compte <i class="far fa-address-book"></i></a></li>
		<li><a class="active" href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
</nav>
<h1>Camagru</h1>
<h2>Galerie</h2>
<?PHP
}
else if($_SESSION['status'] == "not confirmed")
{
?>
<nav>
	<ul>
		<li><a href="index.php">Montage <i class="fas fa-camera-retro"></i></a></li>
		<li><a class="active" href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
		<li><a href="index.php?action=logout">Deconnexion <i class="fas fa-power-off"></i></a></li>
	</ul>
</nav>
<h1>Camagru</h1>
<h2>Galerie</h2>
<?PHP
}
else if($_SESSION['status'] == "confirmed")
{
?>
<nav>
	<ul>
		<li><a href="index.php">Montage <i class="fas fa-camera-retro"></i></a></li>
		<li><a href="index.php?action=member_space">Espace membre <i class="far fa-address-card"></i></a></li>
		<li><a class="active" href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
		<li><a href="index.php?action=logout">Deconnexion <i class="fas fa-power-off"></i></a></li>
	</ul>
</nav>
<h1>Camagru</h1>
<h2>Galerie</h2>
<?PHP
}
$header = ob_get_clean();
ob_start();
?>
<div id="gallery_wrap">
<?php if (isset($imgs) && !empty($imgs)) display_all_imgs($imgs); else echo "<p>Pour le moment aucune image n'a été enregistrée. Soyez le premier ;)" ?>
</div>
<div class="pagination">
<?php display_pagination($nb_pages) ?>
</div>
<?PHP
$main_content = ob_get_clean();
require('template.php');
?>
