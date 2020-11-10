#!/usr/bin/php
<?PHP
while (1)
{
	print("Entrez un nombre: ");
	$nb = fgets(STDIN);
	if (ord($nb) == 0)
	{
		echo "\n";
		exit();
	}
	else
	{
		$nb = explode ("\n", $nb);
		$nb = implode($nb);
		if (is_numeric($nb) == 1 && strstr($nb, ".") === FALSE)
		{
			$len = strlen($nb);
			if ($nb[$len - 1] % 2 == "0")
				echo "Le chiffre $nb est Pair\n";
			else
				echo "Le chiffre $nb est Impair\n";
		}
		else
			echo "'$nb' n'est pas un chiffre\n";
	}
}
?>
