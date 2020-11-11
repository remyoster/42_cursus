#!/usr/bin/php
<?php
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

function ft_srch_sign($s)
{
	$i = 0;
	while($s[$i])
	{
		if ($s[$i] == "+" || $s[$i] == "-" || $s[$i] == "*" || $s[$i] == "/" || $s[$i] == "%")
			return ($s[$i]);
		$i++;
	}
	return (0);
} 

if ($argc == 4)
{
	$op1 = ft_split($argv[1], " ");
	$op1 = implode($op1);
	$op1 = ft_split($op1, "\t");
	$op1 = implode($op1);
	$op1 = ft_split($op1, "\v");
	$op1 = implode($op1);
	$op2 = ft_split($argv[3], " ");
	$op2 = implode($op2);
	$op2 = ft_split($op2, "\t");
	$op2 = implode($op2);
	$op2 = ft_split($op2, "\v");
	$op2 = implode($op2);
	$sign = ft_srch_sign($argv[2]);
	if ($sign !== 0)
	{
		if ($sign == "+")
			$res = $op1 + $op2;
		else if ($sign == "-")
			$res = $op1 - $op2;
		else if ($sign == "*")
			$res = $op1 * $op2;
		else if ($sign == "/")
			$res = $op1 / $op2;
		else if ($sign == "%")
			$res = $op1 % $op2;
		else
			return(0);
		echo($res."\n");
	}
}
else
	echo "Incorrect Parameters\n";
?>
