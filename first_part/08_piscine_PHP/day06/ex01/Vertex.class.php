<?PHP
require_once '../ex00/Color.class.php';
Class Vertex
{
	private $_x = 0.0;
	private $_y = 0.0;
	private $_z = 0.0;
	private $_w = 1.0;
	private $_color = 0;
	public static $verbose = False;

	public function getX()
	{
		return $this->_x;
	}
	public function setX($x)
	{
		$this->_x = $x;
	}
	public function getY()
	{
		return $this->_y;
	}
	public function setY($y)
	{
		$this->_y = $y;
	}
	public function getZ()
	{
		return $this->_z;
	}
	public function setZ($z)
	{
		$this->_z = $z;
	}
	public function getW()
	{
		return $this->_w;
	}
	public function setW($w)
	{
		$this->_w = $w;
	}
	public function getColor()
	{
		return $this->_color;
	}
	public function setColor($color)
	{
		$this->_color = $color;
	}
	function __construct(array $kwargs)
	{
		foreach ($kwargs as $key => $value)
		{
			if ($key == 'x')
				$this->_x = floatval($value);
			else if ($key == 'y')
				$this->_y = floatval($value);
			else if ($key == 'z')
				$this->_z = floatval($value);
			else if ($key == 'w')
				$this->_w = floatval($value);
			else if ($key == 'color')
				$this->_color = $value;
		}
		if (!(array_key_exists('color', $kwargs)))
			$this->_color = new Color (array('rgb' => 0xffffff));
		if (!(array_key_exists('w', $kwargs)))
			$this->_w = self::getW();
		if (self::$verbose === TRUE)
			print("Vertex( x: ".number_format($this->_x, 2, '.', ' ').", y: ".number_format($this->_y, 2, '.', ' ').", z: ".number_format($this->_z, 2, '.', ' ').", w: ".number_format($this->_w, 2, '.', ' ').", ".$this->_color." ) constructed".PHP_EOL);
		return ;
	}

	function __destruct()
	{
		if (self::$verbose === true)
			print("Vertex( x: ".number_format($this->_x, 2, '.', ' ').", y: ".number_format($this->_y, 2, '.', ' ').", z: ".number_format($this->_z, 2, '.', ' ').", w: ".number_format($this->_w, 2, '.', ' ').", ".$this->_color." ) destructed".PHP_EOL);
		return ;
	}

	function __toString()
	{
		if (self::$verbose === true)
			return ("Vertex( x: ".number_format($this->_x, 2, '.', ' ').", y: ".number_format($this->_y, 2, '.', ' ').", z: ".number_format($this->_z, 2, '.', ' ').", w: ".number_format($this->_w, 2, '.', ' ').", ".$this->_color." )");
		else
			return ("Vertex( x: ".number_format($this->_x, 2, '.', ' ').", y: ".number_format($this->_y, 2, '.', ' ').", z: ".number_format($this->_z, 2, '.', ' ').", w: ".number_format($this->_w, 2, '.', ' ')." )");
	}

	public static function doc()
	{
		return file_get_contents("Vertex.doc.txt");
	}
}
