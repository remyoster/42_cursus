#!/usr/bin/php
<?php
function	al_chr($a, $i)
{
	if ($a[$i] >= 'a' && $a[$i] <= 'z')
		return (1);
	return (0);
}

function	nu_chr($a, $i)
{
	if ($a[$i] >= '0' && $a[$i] <= '9')
		return (1);
	return (0);
}

function	ft_sort($a, $b)
{
	$a = strtolower($a);
	$b = strtolower($b);
	$size = (strlen($a) > strlen($b)) ? strlen($b) : strlen($a);
	$i = 0;
	while ($i < $size && $a[$i] == $b[$i])
		$i++;
	if ($i == $size)
		return (strlen($a) > strlen($b) ? 1 : -1);
	if (al_chr($a, $i) && al_chr($b, $i))
		return ($a[$i] > $b[$i] ? 1 : -1);
	if (al_chr($b, $i))
		return (1);
	if (al_chr($a, $i))
		return (-1);
	if (nu_chr($a, $i) && nu_chr($b, $i))
		return ($a[$i] > $b[$i] ? 1 : -1);
	if (nu_chr($b, $i))
		return (1);
	if (nu_chr($a, $i))
		return (-1);
	return ($a[$i] > $b[$i] ? 1 : -1);
}

if ($argc >= 2)
{
	$i = 1;
	$result = NULL;
	while ($i < $argc)
	{
		$tab = explode(" ", $argv[$i]);
		if ($tab != 0)
		{
			foreach($tab as $word)
			{
				if ($word != NULL)
					$result[] = $word;
			}
		}
		$i++;
	}
	if ($result != 0)
	{
		usort($result, "ft_sort");
		foreach($result as $str)
			echo "$str\n";
	}
}
?>
