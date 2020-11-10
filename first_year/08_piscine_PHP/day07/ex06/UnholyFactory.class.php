<?PHP
class UnholyFactory
{
	public $fighters;
	function __construct()
	{
		$this->fighters = [];
	}
	function absorb($foo)
	{
		if ($foo instanceof Fighter)
		{
			if (!(in_array($foo->name, $this->fighters)))
			{
				$this->fighters[] = $foo->name;
				echo "(Factory absorbed a fighter of type $foo->name)".PHP_EOL;
			}
			else
				echo "(Factory already absorbed a fighter of type $foo->name)".PHP_EOL;
		}
		else
			echo "(Factory can't absorb this, it's not a fighter)".PHP_EOL;
	}
	function fabricate($foo)
	{
		if (!(in_array($foo, $this->fighters)))
			echo "(Factory hasn't absorbed any fighter of type $foo)".PHP_EOL;
		else
		{
			echo "(Factory fabricates a fighter of type $foo)".PHP_EOL;
			if ($foo == "foot soldier")
				return (new Footsoldier);
			if($foo == "archer")
				return (new Archer);
			if($foo == "assassin")
				return (new Assassin);
		}
	}
}
?>
