<?PHP
function check_session_exists()
{
	if (!(isset($_SESSION)))
	{
		header('Location: index.php');
		exit();
	}
}
function check_token()
{
	if (isset($_SESSION['token']) && isset($_POST['token'])
		&& !empty($_SESSION['token']) && !empty($_POST['token'])) 
	{
		if ($_SESSION['token'] == $_POST['token'])
			return (true);
		else
			return(false);
	}
	else
		return(false);
}
