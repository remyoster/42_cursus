<?php
class Weapon
{
  private $_arme_name;
  private $_id_arme;
  private $_charge;
  private $_portee_courte;
  private $_portee_moyenne;
  private $_portee_longue;
  private $_zone_effet_largeur;
  private $_zone_effet_longueur;
  static public $verbose;

	function __construct($kwargs)
	{
		foreach ($kwargs as $key => $value)
		{
			if ($key == "arme_name")
				$this->_arme_name = $value;
			else if ($key == "id_arme")
				$this->_id_arme = $value;
			else if ($key == "charge")
				$this->_charge = $value;
			else if ($key == "portee_courte")
				$this->_portee_courte = $value;
			else if ($key == "portee_moyenne")
				$this->portee_moyenne = $value;
			else if ($key == "portee_longue")
				$this->_portee_longue = $value;
			else if ($key == "zone_effet_largeur")
				$this->_zone_effet_largeur = $value;
			else if ($key == "zone_effet_longueur")
				$this->_zone_effet_longueur = $value;
		}

		$this->_values = array ('id_arme' => $this->_id_arme, 'arme_name' => $this->_arme_name, 'charge' => $this->_charge, 'portee_courte' => $this->_portee_courte, 'PP' => $this->portee_moyenne, 'portee_longue' => $this->_portee_longue, 'zone_effet_largeur' => $this->_zone_effet_largeur, 'zone_effet_longueur' => $this->_zone_effet_longueur);
		if (self::$verbose == true)
			echo "Weapon $this->_arme_name constructed !".PHP_EOL;
		return ;
	}
	function __toString()
	{
		return "('id_arme' => $this->_id_arme, 'arme_name' => $this->_arme_name, 'charge' => $this->_charge, 'portee_courte' => $this->_portee_courte, 'PP' => $this->portee_moyenne, 'portee_longue' => $this->_portee_longue, 'zone_effet_largeur' => $this->_zone_effet_largeur, 'zone_effet_longueur' => $this->_zone_effet_longueur)";
	}
	function __destruct()
	{
		if (self::$verbose == true)
			echo "Weapon $this->_arme_name destructed !".PHP_EOL;
		return ;
	}
}

?>
