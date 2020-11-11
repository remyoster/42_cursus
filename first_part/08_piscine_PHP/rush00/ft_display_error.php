<?PHP
function ft_display_error($error)
{
	if ($error == 1)
		echo "Mot de passe incorrect\n";
	else if ($error == 2)
		echo "Adresse mail incorrect\n";
	else if ($error == 3)
		echo "Veuillez remplir le champs\n";
	else if ($error == 4)
		echo "Vous n'avez pas acces a cette page, veuillez vous identifier\n";
	else if ($error == 5)
		echo "Adresse mail deja utilisee\n";
	else
		echo "Une erreur est survenue, veuillez reessayer\n";
}
?>
