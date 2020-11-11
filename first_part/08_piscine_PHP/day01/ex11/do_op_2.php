#!/usr/bin/php
<?PHP 
function ft_split($str, $arg)
{
	$i = 0;
	$arg = explode($arg, $str);
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

function ft_error($bol)
{
	if ($bol == 1)
		echo "Syntax Error\n";
	else
		echo "Incorrect Parameters\n";
	return (0);
}

if ($argc == 2)
{
	$str = ft_split($argv[1], " ");
	$str = implode($str);
	$i = 0;
	$nb_op = 0;
	$nb_error = 0;
	$len = strlen($str);
	while($i < $len)
	{
		if (ord($str[$i]) >= 48 && ord($str[$i]) <= 57)
			$i++;
		else if ($str[$i] == "+" || $str[$i] == "-" || $str[$i] == "*" || $str[$i] == "/" || $str[$i] == "%")
		{
			if ($str[$i] == '+' || $str[$i] == '-')
			{
				if ($i == 0 && ord($str[$i + 1]) >= 48 && ord($str[$i + 1]) <= 57)
				{
					if ($str[$i] == "-")
					{
						$sign1 = $str[$i];
						$str[$i] = "p";
					}
					else
						$nb_error++;
					$i++;
				}
				else if ($i > 0 && (ord($str[$i + 1]) >= 48 && ord($str[$i + 1]) <= 57))
				{
					$nb_op++;
					$op = $str[$i];
					$i++;
				}
				else if ($i > 0 && $str[$i + 1] == "-" && (ord($str[$i + 2]) >= 48 && ord($str[$i + 2]) <= 57))
				{
					$nb_op++;
					$op = $str[$i];
					$sign2 = $str[$i + 1];
					$str[$i + 1] = "p";
					$i = $i + 2;
				}
				else
				{
					$i++;
					$nb_error++;
				}
			}
			else
			{
				$nb_op++;
				$op = $str[$i];
				if ($str[$i + 1] == '+' || $str[$i + 1] == '-')
				{
					if (ord($str[$i + 2]) >= 48 && ord($str[$i + 2]) <= 57)
						$i++;
					else
						$nb_error++;
				}
				$i++;
			}
		}
		else
		{
			$i++;
			$nb_error++;
		}
	}
	if ($nb_op == 1 && $nb_error == 0)
	{
		$nbs = ft_split($str, $op);
		if ($sign1 == "+" || $sign1 == "-")
		{
			$i = 0;
			while($nbs[0][$i])
			{
				if ($nbs[0][$i] == "p")
					$nbs[0][$i] = $sign1;
				$i++;
			}
		}
		if ($sign2 == "+" || $sign2 == "-")
		{
			$i = 0;
			while($nbs[1][$i])
			{
				if ($nbs[1][$i] == "p")
					$nbs[1][$i] = $sign2;
				$i++;
			}
		}
		if ($op == "+")
			$res = $nbs[0] + $nbs[1];
		else if ($op == "-")
			$res = $nbs[0] - $nbs[1];
		else if ($op == "*")
			$res = $nbs[0] * $nbs[1];
		else if($op == "/" && $nbs[1] != 0)
			$res = $nbs[0] / $nbs[1];
		else if ($op == "%")
			$res = $nbs[0] % $nbs[1];
		else
		{
			ft_error(0);
			return (0);
		}
		echo $res."\n";
	}
	else
		ft_error(1);
}
else
	ft_error(0);
?>
