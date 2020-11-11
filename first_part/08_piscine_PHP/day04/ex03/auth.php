<?PHP
function auth($login, $passwd)
{
	$user = unserialize(file_get_contents("../htdocs/private/passwd"));
	foreach($user as $key => $value)
	{
		if ($value['login'] == $login && $value['passwd'] == hash("whirlpool", $passwd))
			return TRUE;
	}
	return FALSE;
}
?>
