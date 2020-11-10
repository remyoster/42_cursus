<?PHP
function login()
{
	check_session_exists();
	if (isset($_POST['submit']) && $_POST['submit'] == "Valider")
	{
		if (check_token())
		{
			if (isset($_POST['pseudo_email']) && $_POST['pseudo_email'] != ""
				&& isset($_POST['password']) && $_POST['password'] != "")
			{
				$pseudo_email = $_POST['pseudo_email'];
				$password = hash("whirlpool", $_POST['password']);
				if(!check_pseudo_email($pseudo_email))
					$GLOBALS['error']['pseudo_email'] = $pseudo_email;
				else
					if(!check_password($password, $pseudo_email))
						$GLOBALS['error']['password'] = $password;
				if (empty($GLOBALS['error']))
				{
					$data = check_account($pseudo_email);
					$_SESSION['status'] = $data['account'];
					$_SESSION['id'] = $data['id'];
					$_SESSION['pseudo'] = $data['pseudo'];
					header('Refresh: 0; URL=index.php');
					exit();
				}
			}
			else
				$GLOBALS['error']['empty_field'] = "";
		}
		else
			$GLOBALS['error']['main'] = "";

	}
	require('view/login_view.php');
}
?>
