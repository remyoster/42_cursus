<?php
include('connexion_sql.php');
require_once('Battleship.class.php');
require_once('Weapon.class.php');
Battleship::$verbose = true;
Weapon::$verbose = true;
$query = "SELECT * FROM vaisseaux WHERE id_vaisseau = '1'";
$res = mysqli_query($db, $query);
$data = mysqli_fetch_assoc($res);
$honorableduty = new Battleship ($data);
$query = "SELECT * FROM armes WHERE id_arme = '1'";
$res = mysqli_query($db, $query);
$dataw = mysqli_fetch_assoc($res);
$lightcanon = new Weapon($dataw);
?>
<html>
<head>
	<link rel="stylesheet" href="css/style.css" />
</head>
<body>
<table>
<?PHP
$i = 0;
$j = 0;
while ($i < 50)
{
	$j = 0;
	echo "<tr>";
	while ($j < 50)
	{
		echo "<td>.</td>";
		$j++;
	}
	echo "</tr>";
	$i++;
}
?>
</table>
</body>
</html>
