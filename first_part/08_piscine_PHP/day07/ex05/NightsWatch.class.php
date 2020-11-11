<?PHP
class NightsWatch implements IFighter
{
	private $_fighters;

	function __construct()
	{
		$this->_fighters = [];
	}
	function recruit($foo)
	{
		if ($foo instanceof IFighter)
			$this->_fighters[] = $foo->fight();
	}
	function fight()
	{
		if ($this->_fighters != NULL)
		{
			foreach($this->_fighters as $value)
				echo $value;
		}
	}
}
?>
