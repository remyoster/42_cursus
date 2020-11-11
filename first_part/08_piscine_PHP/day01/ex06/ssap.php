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
	$i = 0;
	foreach ($argv as $key)
	{
		if ($key != $argv[0])
		{
			$tmp = ft_split($key);
			if ($tmp != 0)
			{
				foreach ($tmp as $k)
				{
					$str[$i] = $k;
					$i++;
				}
			}
		}
	}
	if ($str != 0)
	{
		sort($str);
		foreach ($str as $val)
			echo($val."\n");
	}
}
?>
