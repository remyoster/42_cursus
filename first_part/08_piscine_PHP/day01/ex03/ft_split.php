<?PHP
function ft_split($arg)
{
	$i = 0;
	$arg = explode(" ", $arg);
	foreach($arg as $elem)
	{
		if ($elem != "")
		{
			$my_tab[$i] = $elem;
			$i++;
		}
	}
	if ($my_tab != NULL)
		sort($my_tab);
	return ($my_tab);
}
?>
