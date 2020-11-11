<?PHP
class Tyrion extends Lannister 
{
	function __construct()
	{
		parent::__construct();
		echo "My name is Tyrion".PHP_EOL;
	}
	public function getSize()
	{
		return "Short";
	}
}
?>
