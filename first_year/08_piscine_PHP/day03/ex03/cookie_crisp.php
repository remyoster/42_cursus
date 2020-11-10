<?PHP
if($_GET['action'] == "set")
	setcookie($_GET['name'], $_GET['value'], time() + 7200);
else if ($_GET['action'] == "get")
{
	foreach($_COOKIE as $key => $value)
	{
		if ($key == $_GET['name'])
			echo "$value\n";
	}
}
else if ($_GET['action'] == "del")
	setcookie($_GET['name'], $_GET['value'], time() - 1);
?>
