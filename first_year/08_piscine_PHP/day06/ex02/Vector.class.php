<?PHP
require_once('../ex01/Vertex.class.php');
Class Vector
{
	private $_x = 0.0;
	private $_y = 0.0;
	private $_z = 0.0;
	private $_w = 0.0;
	static $verbose = False;

	function getX()
	{
		return $this->_x;
	}
	function getY()
	{
		return $this->_y;
	}
	function getZ()
	{
		return $this->_z;
	}
	function getW()
	{
		return $this->_w;
	}
	function __construct(array $kwargs)
	{
		if (!(array_key_exists('orig', $kwargs)))
		{
			$orig = new Vertex( array( 'x' => $this->_x, 'y' => $this->_y, 'z' => $this->_z, 'w' => $this->_w ) );
			$this->_x = $kwargs['dest']->getX() - $orig->getX();
			$this->_y = $kwargs['dest']->getY() - $orig->getY();
			$this->_z = $kwargs['dest']->getZ() - $orig->getZ();
		}
		else
		{
			$this->_x = $kwargs['dest']->getX() - $kwargs['orig']->getX();
			$this->_y = $kwargs['dest']->getY() - $kwargs['orig']->getY();
			$this->_z = $kwargs['dest']->getZ() - $kwargs['orig']->getZ();
		}
		if (self::$verbose === TRUE)
			printf("Vector( x: %.2f, y: %.2f, z: %.2f, w: %.2f ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
		return ['x' => $this->_x, 'y' => $this->_y, 'z' => $this->_z, 'w' => $this->_w];
	}

	function magnitude()
	{
		$norme = sqrt(pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2)); 
		return $norme;
	}
	function normalize()
	{
	}
	function add(Vector $rhs)
	{
	}
	function sub(Vector $rhs)
	{
	}
	function opposite()
	{
	}
	function scalarProduct($k)
	{
	}
	function dotProduct(Vector $rhs)
	{
	}
	function cos(Vector $rhs)
	{
		floatval(cos(0));
	}
	function crossProduct(Vector $rhs)
	{
	}
	function __toString()
	{
		return "Vector( x: ".number_format($this->_x, 2, '.', ' ').", y: ".number_format($this->_y, 2, '.', ' ').", z: ".number_format($this->_z, 2, '.', ' ').", w: ".number_format($this->_w, 2, '.', ' ')." )";
	}
	public static function doc()
	{
		return file_get_contents("Vertex.doc.txt");
	}
	function __destruct()
	{
		if (self::$verbose === true)
			printf("Vector( x: %.2f, y: %.2f, z: %.2f, w: %.2f ) destructed\n", $x, $y, $z, $w);
		return ;
	}
}
?>
