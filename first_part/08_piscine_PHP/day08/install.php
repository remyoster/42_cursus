<?php
$db = mysqli_connect('127.0.0.1', 'root', 'roster');
$cmd = file_get_contents("database.sql");
$cmd = explode(";", $cmd);
foreach($cmd as $sql)
  mysqli_query($db, $sql);
mysqli_close($db);
header('Refresh: 0; URL=index.php');
?>
