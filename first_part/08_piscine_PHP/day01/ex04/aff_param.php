#!/usr/bin/php
<?php
foreach ($argv as $key)
{
  if ($key != $argv[0])
    echo($key."\n");
}
?>
