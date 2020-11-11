#!/usr/bin/php
<?PHP

if ($argc >= 2)
{
	$fd = fopen("$argv[1]", "r");
	while ($line = fgets($fd))
	{
		$line = preg_replace_callback('/<a.*?title=\"([^\"]*)\".*?>([^<]*?)<.*?\/a>/',
			function ($matches) {
				return $matches[0].strtoupper($matches[1]);
			},
			$line
		);
		echo $line;
	}
	fclose($fd);
}
?>
