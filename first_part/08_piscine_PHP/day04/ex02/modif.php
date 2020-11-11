<?PHP
function	error()
{
	echo "ERROR\n";
}

if($_POST['submit'] == "OK")
{
	if($_POST['login'] != NULL && $_POST['oldpw'] != NULL
		&& $_POST['newpw'] != NULL && $_POST['oldpw'] !== $_POST['newpw'])
	{
		$user = unserialize(file_get_contents("../htdocs/private/passwd"));
		foreach($user as $key => $account)
		{
			if ($account['login'] == $_POST['login'])
			{
				if ($account['passwd'] == hash("whirlpool", $_POST['oldpw']))
				{
					$user[$key]['passwd'] = hash("whirlpool", $_POST['newpw']);
					file_put_contents("../htdocs/private/passwd", serialize($user));
					echo "OK\n";
					return ;
				}
				else
					return error();
			}
		}
		return error();
	}
	else
		return error();
}
else
	return error();
?>
