<?PHP
$title = "Camagru";
$GLOBALS['script'] = "<script src='public/js/webcam.js'></script>";
ob_start();
?>
	<nav>
		<ul>
			<li><a class="active" href="index.php">Montage <i class="fas fa-camera-retro"></i></a></li>
			<li><a href="index.php?action=member_space">Espace membre <i class="far fa-address-card"></i></a></li>
			<li><a href="index.php?action=gallery">Galerie <i class="far fa-images"></i></a></li>
			<li><a href="index.php?action=logout">Deconnexion <i class="fas fa-power-off"></i></a></li>
		</ul>
	</nav>
	<h1>Camagru</h1>
	<h2>A vous de monter ! </h2>
<?PHP
$header = ob_get_clean();
ob_start();
?>
<div id='montage'>
<div id='montage_content'>
	<div id="cadre_wrapper"><?php display_imgs($imgs)?></div>
	<div id="montage_wrapper">
		<video id="video" autoplay></video>
		<?php if(isset($up_img)) {echo $up_img;} ?>
	</div>
	<button id="shoot" disabled="true">Séléctionnez un cadre pour prendre une photo !"</button>
	<canvas id="canvas"></canvas>
	<canvas id="img_tmp"></canvas>
	<canvas id="cadre_tmp"></canvas>
	<button id="save" style="display:none;" onclick="save_picture(<?=$_SESSION['id']?>)">Enregistrer</button>
</div>
<section>
	<a href='index.php?action=member_space'><h3>Photos prises</h3></a>
	<?php if ($data = display_previous_imgs()){ foreach($data as $value) echo $value;} ?>
</section>
</div>
<div class='text_wrapper'>
<p><b>- Agrandir/retrecir :</b> placez votre souris dessus et utilisez votre molette.</p>
<p><b>- Déplacer :</b> cliquez sur le cadre en place puis utilisez les flèches de votre clavier.</p>
</div>
<?PHP
$main_content = ob_get_clean();
require('template.php');
?>
