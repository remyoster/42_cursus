<?PHP
function ft_strcmp($s1, $s2)
{
	$c1 = count($s1);
	$c2 = count($s2);
	if ($c1 == $c2)
	{
		$i = 0;
		while ($s2[$i])
		{
			if ($s1[$i] != $s2[$i])
				return (0);
			$i++;
		}
	}
	return (1);
}
function	ft_sort($tab)
{
	$tmp = $tab;
	sort($tmp);
	print_r($tmp);
	$i = 0;
	$len = count($tab);
	while ($i < $len)
	{
		if (ft_strcmp($tmp[$i], $tab[$i]) == 0)
			return (0);
		$i++;
	}
	return (1);
}
function	ft_rsort($tab)
{
	$tmp = $tab;
	rsort($tmp);
	print_r($tmp);
	$i = 0;
	$len = count($tab);
	while ($i < $len)
	{
		if (ft_strcmp($tmp[$i], $tab[$i]) == 0)
			return (0);
		$i++;
	}
	return (1);
}
function ft_is_sort($tab)
{
	if ($tab == 0)
		return (1);
	if ((ft_sort($tab) == 1) || (ft_rsort($tab) == 1))
		return (1);
	else
		return (0);
}
?>
