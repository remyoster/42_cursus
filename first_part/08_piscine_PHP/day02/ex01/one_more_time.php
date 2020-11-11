#!/usr/bin/php
<?PHP
function	ft_error()
{
	echo "Wrong Format\n";
	return (0);
}

function	ft_parse_day($s_day)
{
	$day = array("lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche");
	$s_day = lcfirst($s_day);
	if (array_search($s_day, $day) == 0)
		return (0);
	else
		return (1);
}

function	ft_parse_mounth($s_mounth)
{
	$mounth = array("janvier", "février", "mars", "avril", "mai", "juin", "juillet", "août", "septembre", "octobre", "novembre", "décembre");
	$s_mounth = lcfirst($s_mounth);
	if (array_search($s_mounth, $mounth) == 0)
		return (0);
	$i = 1;
	foreach ($mounth as $elem)
	{
		if ($s_mounth == $elem)
			return ($i);
		$i++;
	}
}

function	ft_parse_sec($s_sec)
{
	$s_sec = explode(":", $s_sec);
	foreach($s_sec as $elem)
	{
		if (strlen($elem) !== 2)
			return (0);
	}
	if (preg_match("/^[0-2]/", "$s_sec[0]") == 0 || preg_match("/[0-4]$/", "$s_sec[0]") == 0 || preg_match("/^[0-5]/", "$s_sec[1]") == 0 || preg_match("/[0-9]$/", "$s_sec[1]") == 0 || preg_match("/^[0-5]/", "$s_sec[2]") == 0 || preg_match("/[0-9]$/", "$s_sec[2]") == 0)
		return (0);
	else
		return (1);
}
	
if ($argc >= 2)
{
	$tab = explode(" ", $argv[1]);
	if (count($tab)!== 5 || ft_parse_day($tab[0]) == 0 || ft_parse_sec($tab[4]) == 0 || strlen($tab[1]) !== 2 || preg_match("/^[0-3]/", "$tab[1]") == 0 || preg_match("/[0-9]$/", "$tab[1]") == 0 || preg_match("/^[0-9]{4}/", "$tab[3]") == 0 || preg_match("/^[0-9]{4}$/", "$tab[3]") == 0)
		return ft_error();
	$s_m = ft_parse_mounth($tab[2]);
	if ($s_m == 0)
		return ft_error();
	$s_sec = explode(":", $tab[4]);
	date_default_timezone_set('UTC');
	$res = mktime(intval($s_sec[0]), intval($s_sec[1]), intval($s_sec[2]), intval($s_m), intval($tab[1]), intval($tab[3]), 1);
	echo $res."\n";
}
?>
