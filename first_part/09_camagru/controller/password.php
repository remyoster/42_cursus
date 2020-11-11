<?PHP
/*Send a email to reset the password*/
function forgot_password()
{
	check_session_exists();
	if (isset($_POST['submit']) && $_POST['submit'] == "Envoyer")
	{
		if (check_token())
		{
			if (isset($_POST['pseudo_email']) && $_POST['pseudo_email'] != "")
			{
				$pseudo_email = $_POST['pseudo_email'];
				$pseudo_email = str_replace(array("\n", "\r", PHP_EOL), '', $pseudo_email);
				if(!check_pseudo_email($pseudo_email))
					$GLOBALS['error']['pseudo_email'] = $pseudo_email;
				if (empty($GLOBALS['error']))
				{
					$data = check_account($pseudo_email);
					send_forgot_password_email($data['email'], $data['pseudo'], $data['id']);
					header('Refresh: 7; URL=index.php');
				}
			}
			else
				$GLOBALS['error']['empty_field'] = "";
		}
		else
			$GLOBALS['error']['main'] = "";
	}
	require('view/forgot_password_view.php');
}

/*Once the reset_email had been clicked, this function update the new password*/
function reset_password()
{
	check_session_exists();
	$data = get_account_info_with_id($_GET['id']);
	if ($data['email'] == $_GET['email'])
	{
		if (isset($_POST['submit']) && $_POST['submit'] == "Valider")
		{
			if (check_token())
			{
				if (isset($_POST['password']) && !empty($_POST['password'])
					&& isset($_POST['cfpassword']) && !empty($_POST['cfpassword']))
				{
					$password = $_POST['password'];
					if (!preg_match('/(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*\W).{6,}$/', $password))
						$GLOBALS['error']['wrong_password'] = "";
					else
						if ($_POST['password'] !== $_POST['cfpassword'])
							$GLOBALS['error']['cfpassword'] = "";
					if (empty($GLOBALS['error']))
					{
						$password = hash("whirlpool", $password);
						change_password($_GET['id'], $password);
						header("Refresh: 7; URL=index.php?action=login");
					}
				}
				else
					$GLOBALS['error']['empty_field'] = "";
			}
			else
				$GLOBALS['error']['main'] = "";
		}
		require('view/reset_password_view.php');
	}
	else
		throw new Exception();
}

function send_forgot_password_email($email, $pseudo, $id)
{
	$path = $_SERVER['SCRIPT_NAME'];
	$port = $_SERVER['HTTP_HOST'];
	$to = $email;
	$subject = "Réinitialisation de mot de passe";
	$message = "Bonjour $pseudo,\r\nUne demande de réinitialisation de mot de passe vient d'être éffectuée sur votre compte.\r\nPour ce faire, veuillez cliquer sur le lien ci dessous :\r\nhttp://".$port.$path."?action=reset_password&email=$email&id=$id";
	mail($to, $subject, $message);
}
?>
