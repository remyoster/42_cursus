#!/usr/bin/php
<?PHP
function ft_split($arg, $split)
{
	$array_var = explode($split, $arg);
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

if ($argc >= 2)
{
	$len = strlen($argv[1]);
	$i = 0;
	$c = 0;
	while($i < $len)
	{
		if (ord($argv[1][$i]) == 32 || ord($argv[1][$i]) == 9 || ord($argv[1][$i]) == 11)
			$c++;
		$i++;
	}
	if ($c == $len)
		return (0);
	$res = ft_split($argv[1],"\t");
	$res = implode($res);
	$res = ft_split($res," ");
	$i = 0;
	while($res[$i + 1] != NULL)
	{
		if ($res[$i] != "")
			echo "$res[$i] ";
		$i++;
	}
	echo "$res[$i]\n";
}
?>
