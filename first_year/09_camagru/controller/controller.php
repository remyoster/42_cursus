<?PHP
function create_account()
{
	check_session_exists();
	if (isset($_POST['submit']) && $_POST['submit'] == "Valider")
	{
		if (isset($_POST['pseudo']) && $_POST['pseudo'] != ""
			&& isset($_POST['email']) && $_POST['email'] != ""
			&& isset($_POST['password']) && $_POST['password'] != ""
			&& isset($_POST['cfpassword']) && $_POST['cfpassword'] != "")
		{
			if (check_token())
			{
				$email = $_POST['email'];
				$pseudo = $_POST['pseudo'];
				$password = $_POST['password'];
				if (!preg_match('/^[a-z0-9._-]+@[a-z0-9._-]{2,}\.[a-z]{2,4}$/', $email))
					$GLOBALS['error']['wrong_email'] = "";
				else
					if (check_email($email))
						$GLOBALS['error']['email'] = $email;
				if (preg_match('/\W/', $pseudo) || strlen($pseudo) > 20)
					$GLOBALS['error']['wrong_pseudo'] = "";
				else
					if (check_pseudo($pseudo))
						$GLOBALS['error']['pseudo'] = $pseudo;
				if (!preg_match('/(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*\W).{6,}$/', $password))
					$GLOBALS['error']['wrong_password'] = "";
				else
					if ($_POST['password'] !== $_POST['cfpassword'])
						$GLOBALS['error']['cfpassword'] = "";
				if (empty($GLOBALS['error']))
				{
					$password = hash("whirlpool", $password);
					$account_info = array(
						'pseudo' => $pseudo,
						'email' => $email,
						'password' => $password);
					insert_account($account_info);
					$data = check_account($email);
					$_SESSION['status'] = $data['account'];
					$_SESSION['id'] = $data['id'];
					$_SESSION['pseudo'] = $pseudo;
					send_verification_email($email, $pseudo, $data['id']);
					require('view/account_created_view.php');
					header('Refresh: 10; URL=index.php');
					exit;
				}
			}
			else
				$GLOBALS['error']['main'] = "";
		}
		else
			$GLOBALS['error']['empty_field'] = "";
	}
	if (isset($_GET['pseudo']) && $_GET['pseudo'] != "")
	{
		$pseudo = $_GET['pseudo'];
		if (!preg_match('/\W/', $pseudo) && strlen($pseudo) < 20)
		{
			if (check_pseudo($pseudo))
				echo "KO_EXIST";
			else
				echo "OK";
		}
		else
			echo "KO";
		exit;
	}
	if (isset($_GET['email']) && $_GET['email'] != "")
	{

		$email = $_GET['email'];
		if (preg_match('/^[a-z0-9._-]+@[a-z0-9._-]{2,}\.[a-z]{2,4}$/', $email))
		{
			if (check_email($email))
				echo "KO_EXIST";
			else
				echo "OK";
		}
		else 
			echo "KO";
		exit;
	}
	if (isset($_GET['password']) && $_GET['password'] != "")
	{
		if (preg_match('/(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*\W).{6,}$/', $_GET['password']))
			echo "OK";
		else
			echo "KO";
		exit;
	}
	require('view/create_account_view.php');
}

function resent_email()
{
	check_session_exists();
	if (ctype_digit($_SESSION['id']))
	{
		if($data = get_account_info_with_id($_SESSION['id']))
		{
			if ($data['pseudo'] == $_SESSION['pseudo'])
			{
				send_verification_email($data['email'], $data['pseudo'], $data['id']);
				$GLOBALS['error']['email_sent'] = "";
				home();
				header('Refresh: 5; URL=index.php');
			}
			else
				throw new Exception();
		}
		else
			throw new Exception();
	}
	else
		throw new Exception();
}

function activate_account()
{
	check_session_exists();
	if (($data = check_account($_GET['email'])) && ctype_digit($_GET['id']))
	{
		if ($data['id'] == $_GET['id'] && $data['account'] == "not confirmed")
		{
			confirm_account($_GET['id']);
			$_SESSION['status'] = "confirmed";
			$_SESSION['id'] = $data['id'];
			$_SESSION['pseudo'] = $data['pseudo'];
			require('view/account_confirmed_view.php');
			header('Refresh: 7; URL=index.php');
		}
		else
			throw new Exception();
	}
	else
		throw new Exception();
}

function send_verification_email($email, $pseudo, $id)
{
	$path = $_SERVER['SCRIPT_NAME'];
	$port = $_SERVER['HTTP_HOST'];
	$to = $email;
	$subject = "Vérification de votre compte";
	$message = "Bonjour $pseudo,\r\nMerci d'avoir créé un compte chez nous.\r\nVeuillez cliquer sur le lien ci dessous pour l'activer:\r\nhttp://".$port.$path."?action=activate&email=$email&id=$id";
	mail($to, $subject, $message);
}

