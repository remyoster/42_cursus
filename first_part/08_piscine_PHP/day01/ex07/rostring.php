#!/usr/bin/php
<?PHP
function ft_split($arg)
{
	$array_var = explode(" ", $arg);
	$c = 0;
	foreach ($array_var as $key)
	{
		if ($key != "")
		{
			$array_end[$c] = $key;
			$c++;
		}
	}
	return ($array_end);
}

if ($argc > 1)
{
	$tab = ft_split($argv[1]);
	if (ord($tab[0]) == 0)
	{
		echo $argv[1]."\n";
		return (0);
	}
	$c = count($tab);
	$i = 1;
	while ($i < $c)
	{
		echo($tab[$i]." ");
		$i++;
	}
	echo($tab[0]."\n");
}
?>
