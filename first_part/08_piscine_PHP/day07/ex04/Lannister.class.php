<?PHP
class Lannister 
{
	public $name = "Cersei";
	function sleepWith($foo)
	{
		if ($this->name == "Jaime")
		{
			if ($foo->name == "Tyrion")
				echo "Not even if I'm drunk !".PHP_EOL;
			else if ($foo->name == "Cersei")
				echo "With pleasure, but only in a tower in Winterfell, then.".PHP_EOL;
			else
				echo "Let's do this.".PHP_EOL;
		}
		else 
		{
			if ($foo->name != "Jaime" && $foo->name != "Cersei")
				echo "Let's do this.".PHP_EOL;
			else
				echo "Not even if I'm drunk !".PHP_EOL;
		}
		return ;
	}
}
?>
