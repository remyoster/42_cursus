<?PHP
class Battleship// implements IShip
{
	private $_name;
	private $_id_vaisseau;
	private $_longueur;
	private $_largeur;
	private $_PP;
	private $_coque;
	private $_bouclier;
	private $_manoeuvrabilite;
	private $_id_arme;
	private $_vitesse;
	private $_values;
	private $_race;
	static public $verbose;
	function __construct($kwargs)
	{
		foreach ($kwargs as $key => $value)
		{
			if ($key == "name")
				$this->_name = $value;
			else if ($key == "id_vaisseau")
				$this->_id_vaisseau = $value;
			else if ($key == "longueur")
				$this->_longueur = $value;
			else if ($key == "largeur")
				$this->_largeur = $value;
			else if ($key == "PP")
				$this->_PP = $value;
			else if ($key == "coque")
				$this->_coque = $value;
			else if ($key == "bouclier")
				$this->_bouclier = $value;
			else if ($key == "manoeuvrabilite")
				$this->_manoeuvrabilite = $value;
			else if ($key == "id_arme")
				$this->_id_arme = $value;
			else if ($key == "vitesse")
				$this->_vitesse = $value;
				else if ($key == "race")
					$this->_race = $value;
		}

		$this->_values = array ('id_vaisseau' => $this->_id_vaisseau, 'id_name' => $this->_name, 'longueur' => $this->_longueur, 'largeur' => $this->_largeur, 'PP' => $this->_PP, 'coque' => $this->_coque, 'bouclier' => $this->_bouclier, 'manoeuvrabilite' => $this->_manoeuvrabilite, 'id_arme' => $this->_id_arme, 'vitesse' => $this->_vitesse);
		if (self::$verbose == true)
			echo "Battleship $this->_name constructed !".PHP_EOL;
		return ;
	}
	function __toString()
	{
		return "('id_vaisseau' => $this->_id_vaisseau, 'id_name' => $this->_name, 'longueur' => $this->_longueur, 'largeur' => $this->_largeur, 'PP' => $this->_PP, 'coque' => $this->_coque, 'bouclier' => $this->_bouclier, 'manoeuvrabilite' => $this->_manoeuvrabilite, 'id_arme' => $this->_id_arme, 'vitesse' => $this->_vitesse)";
	}
	function __destruct()
	{
		if (self::$verbose == true)
			echo "Battleship $this->_name destructed !".PHP_EOL;
		return ;
	}
}
?>
