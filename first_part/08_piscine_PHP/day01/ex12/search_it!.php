#!/usr/bin/php
<?PHP
if ($argc >= 3)
{
	if ($argv[1] != NULL)
	{
		$needle = $argv[1];
		$res = NULL;
		foreach ($argv as $elem)
		{
			$elem = explode(":", $elem);
			if (count($elem) == 2)
			{
				if ($needle == $elem[0])
					$res = $elem[1];
			}
		}
		if ($res != NULL)
			echo "$res\n";
	}
}			
?>
