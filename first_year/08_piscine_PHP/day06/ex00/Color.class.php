<?PHP
Class Color
{
	public $red = 0;
	public $green = 0;
	public $blue = 0;
	public static $verbose = FALSE;

	function __construct(array $kwargs)
	{
		foreach ($kwargs as $key => $value)
		{
			if ($key == "red")
				$this->red = intval($value);
			else if ($key == "green")
				$this->green = intval($value);
			else if ($key == "blue")
				$this->blue = intval($value);
			else if ($key == "rgb")
			{
				$this->red = (intval($value) >> 16) & 255;
				$this->green = (intval($value) >> 8) & 255;
				$this->blue = intval($value) & 255;
			}
		}
		$this->red = $this->red < 0 ? 0 : $this->red;
		$this->red = $this->red > 255 ? 255 : $this->red;
		$this->blue = $this->blue < 0 ? 0 : $this->blue;
		$this->blue = $this->blue > 255 ? 255 : $this->blue;
		$this->green = $this->green < 0 ? 0 : $this->green;
		$this->green = $this->green > 255 ? 255 : $this->green;
		if (self::$verbose == TRUE)
			echo "Color( red: $this->red, green: $this->green, blue: $this->blue ) constructed.".PHP_EOL;
		return ;
	}

	function __destruct()
	{
		if (self::$verbose == true)
			echo "Color( red: $this->red, green: $this->green, blue: $this->blue ) destructed.".PHP_EOL;
		return ;
	}

	function __toString()
	{
		return 'Color( red: '.$this->red.', green: ' .$this->green.', blue: '.$this->blue.' )';
	}

	static function doc() 
	{
		$str = file_get_contents("Color.class.txt");
		return $str;
	}

	function add(Color $tmp)
	{
		$red = $tmp->red + $this->red;
		$blue = $tmp->blue + $this->blue;
		$green = $tmp->green + $this->green;
		return new Color(["red" => $red, "blue" => $blue, "green" => $green]);
	}

	function sub(Color $tmp) 
	{
		$red = $this->red - $tmp->red;
		$blue = $this->blue - $tmp->blue;
		$green = $this->green - $tmp->green;
		return new Color(["red" => $red, "blue" => $blue, "green" => $green]);
	}

	function mult($f)
	{
		$red = $this->red * $f;
		$blue = $this->blue * $f;
		$green = $this->green * $f;
		return new Color(["red" => $red, "blue" => $blue, "green" => $green]);
	}
}
?>
