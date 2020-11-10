<?PHP
function	error()
{
	echo "ERROR\n";
}
function	add_user($user)
{
	$user[] = array("login" => $_POST['login'], "passwd" => hash("whirlpool", $_POST['passwd']));
	file_put_contents("../htdocs/private/passwd", serialize($user));
	echo "OK\n";
}

if($_POST['submit'] == "OK")
{
	if($_POST['login'] != NULL && $_POST['passwd'] != NULL)
	{
		if (!(file_exists("../htdocs/private/passwd")))
		{
			if(!(file_exists("../htdocs")))
				mkdir("../htdocs");
			if(!(file_exists("../htdocs/private")))
				mkdir("../htdocs/private");
			$user = array(array("login" => $_POST['login'], "passwd" => hash("whirlpool", $_POST['passwd'])));
			file_put_contents("../htdocs/private/passwd", serialize($user));
			 echo "OK\n";
		}
		else
		{
			$user = unserialize(file_get_contents("../htdocs/private/passwd"));
			foreach($user as $account)
			{
				if ($account['login'] == $_POST['login'])
					return error();
			}
			add_user($user);
		}
	}
	else
		return error();
}
else
	return error();
?>
