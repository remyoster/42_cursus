#!/usr/bin/php
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
	return ($my_tab);
}

if ($argc == 2)
{
	$tab = ft_split($argv[1]);
	$i = 0;
	while ($tab[$i])
	{
		if ($tab[$i + 1])
			echo $tab[$i]." ";
		else
			echo $tab[$i]."\n";
		$i++;
	}
}
?>
