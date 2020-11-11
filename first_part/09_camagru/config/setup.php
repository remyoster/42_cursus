<?PHP
require_once('config/database.php');
try
{
	$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD,
		array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));
	$db_sql = file_get_contents('config/camagru.sql');
	$cmd = explode(";", $db_sql);
	foreach($cmd as $query)
		if (!empty($query) && $query !== "\n" && $query !== PHP_EOL)
			$db->query($query);
	touch("config/OK");
	header('Refresh: 0; URL=index.php');
}
catch (PDOException $e)
{
	//echo "Connection failed: ".$e->getMessage();
	touch("config/OK");
	header('Refresh: 0; URL=index.php');
}
?>
