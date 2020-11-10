#!/usr/bin/php
<?PHP
if ($argc >= 2)
{
	$i = 0;
	while ($line = fgets(STDIN))
	{
		$tab[$i] = str_getcsv($line, ";");
		$i++;
	}
	if ($argv[1] == "moyenne")
	{
		$moyenne = 0;
		$nb_note = 0;
		$i = 0;
		foreach($tab as $sub_tab)
		{
			if ($sub_tab[1] != NULL && $i != 0 && $sub_total[0] != "moulinette")
			{
				$moyenne = $moyenne + intval($sub_tab[1]);
				$nb_note++;
			}
			if ($sub_tab[3] != NULL && $i != 0 && $sub_total[2] != "moulinette")
			{
				$moyenne = $moyenne + intval($sub_tab[3]);
				$nb_note++;
			}
			$i++;
		}
		$moyenne = $moyenne / $nb_note;
		echo $moyenne;
	}
}
?>
