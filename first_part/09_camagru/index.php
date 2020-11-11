<?PHP
session_start();
if (!file_exists("config/OK"))
	require_once('config/setup.php');
if (!isset($_SESSION['status']) || !isset($_SESSION['id']) || !isset($_SESSION['token']))
{
	$_SESSION['status'] = "visitor";
	$_SESSION['id'] = -1;
	$_SESSION['token'] = bin2hex(mcrypt_create_iv(32, MCRYPT_DEV_URANDOM));
}
require_once('model/model.php');
$controller_dir = "controller";
if (is_dir($controller_dir))
{
	if ($dh = opendir($controller_dir))
	{
		while (($file = readdir($dh)) !== false)
		{
			if ($file != "." && $file != ".." && !preg_match("/swp/", $file))
				require_once("controller/".$file);
		}
		closedir($dh);
	}
}
$GLOBALS['error'] = [];
$GLOBALS['script'] = "";
date_default_timezone_set("Europe/Paris");
try 
{
	if (isset($_GET['action']))
	{
		if ($_GET['action'] == 'create_account')
		{
			if (isset($_SESSION['status']) && $_SESSION['status'] == "visitor")
				create_account();
			else
				throw new Exception("Vous êtes déjà connecté sur un compte existant");
		}
		else if ($_GET['action'] == 'logout')
		{
			$_SESSION['status'] = "visitor";
			$_SESSION['id'] = -1;
			$_SESSION['pseudo'] = "";
			header("Refresh: 0; URL=index.php");
		}	
		else if ($_GET['action'] == 'login')
		{
			if (isset($_SESSION['status']) && $_SESSION['status'] == "visitor")
				login();
			else
				throw new Exception("Vous êtes déjà connecté");
		}
		else if ($_GET['action'] == 'activate')
		{
			if (isset($_GET['email']) && !empty($_GET['email'])
				&& isset($_GET['id']) && !empty($_GET['id']))
				activate_account();
			else
				throw new Exception("Le lien que vous utilisez n'est pas valable");
		}
		else if ($_GET['action'] == 'resent_email')
		{
			if (isset($_SESSION['status']) && $_SESSION['status'] == "not confirmed"
				&& isset($_SESSION['id']) && !empty($_SESSION['id'])
				&& isset($_SESSION['pseudo']) && !empty($_SESSION['pseudo']))
				resent_email();
			else
				throw new Exception();
		}
		else if ($_GET['action'] == 'forgot_password')
		{
			if (isset($_SESSION['status']) && $_SESSION['status'] == "visitor")
				forgot_password();
			else
				throw new Exception();
		}
		else if ($_GET['action'] == 'reset_password')
		{
			if (isset($_SESSION['status']) && $_SESSION['status'] == "visitor"
				&& isset($_GET['action']) && $_GET['action'] == "reset_password"
				&& isset($_GET['email']) && !empty($_GET['email'])
				&& isset($_GET['id']) && ctype_digit($_GET['id']))
				reset_password();
			else
				throw new Exception();
		}
		else if ($_GET['action'] == 'member_space')
		{
			if (isset($_SESSION['status']) && $_SESSION['status'] == "confirmed"
				&& isset($_SESSION['id']))
				member_space();
			else
				throw new Exception("Vous n'avez pas accès à cette page");
		}
		else if ($_GET['action'] == 'montage')
		{
			if (isset($_SESSION['status']) && $_SESSION['status'] == "confirmed"
				&& isset($_SESSION['id']))
				montage();
			else
				throw new Exception();
		}
		else if ($_GET['action'] == "gallery")
			gallery();
		else
			throw new Exception("Cette page n'existe pas");
	}
	else
		home();
}
catch(Exception $e) 
{
	require('view/error_view.php');
	header('Refresh: 7; URL=index.php');
}
?>
