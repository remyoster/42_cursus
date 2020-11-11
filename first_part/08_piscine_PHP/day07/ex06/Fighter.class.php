<?PHP
abstract class Fighter
{
	function __construct($kwargs)
	{
		$this->name = $kwargs;
	}
	abstract function fight($target);
}
?>
