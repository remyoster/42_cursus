<?PHP
function display_user_imgs()
{
	if ($imgs = get_image_with_id($_SESSION['id']))
		foreach ($imgs as $key => $value)
			echo "<div class='checkbox_wrap'><input type='checkbox' class='checkbox' name='$key' value='$value'><img src='$value' class='user_img' onclick='check_img($key)'></div>";
}

function member_space()
{
	check_session_exists();
	$data = get_account_info_with_id($_SESSION['id']);
	$pseudo = $data['pseudo'];
	$email = $data['email'];
	$password = $data['password'];
	$notification = $data['notification'];
	if (isset($_POST['submit_account']) && $_POST['submit_account'] == "Modifier")
	{
		if (check_token())
		{
			if (isset($_POST['pseudo']) && $_POST['pseudo'] !== $pseudo && !empty($_POST['pseudo']))
			{
				$newpseudo = $_POST['pseudo'];
				if (preg_match('/\W/', $newpseudo) || strlen($newpseudo) > 20)
					$GLOBALS['error']['wrong_pseudo'] = "";
				else
				{
					if (!check_pseudo($newpseudo))
					{
						change_pseudo($_SESSION['id'], $newpseudo);
						$pseudo = $newpseudo;
					}
					else
						$GLOBALS['error']['pseudo'] = $newpseudo;
				}
			}
			if (isset($_POST['email']) && !empty($_POST['email']) && $_POST['email'] !== $email)
			{
				$newemail = $_POST['email'];
				if (!preg_match('/^[a-z0-9._-]+@[a-z0-9._-]{2,}\.[a-z]{2,4}$/', $newemail))
					$GLOBALS['error']['wrong_email'] = "";
				else
				{
					if (!check_email($newemail))
					{
						change_email($_SESSION['id'], $newemail);
						$email = $newemail;
						$GLOBALS['error']['success_modif'] = "";
					}
					else
						$GLOBALS['error']['email'] = $newemail;
				}
			}
			if (isset($_POST['notif']) && ($_POST['notif'] == "yes" || $_POST['notif'] == "no") && $_POST['notif'] !== $notification)
			{
				change_notification($_SESSION['id'], $_POST['notif']);
				$notification = $_POST['notif'];
				$GLOBALS['error']['success_modif'] = "";
			}
		}
		else
			$GLOBALS['error']['token'] = "";
	}
	else if (isset($_POST['submit_password']) && $_POST['submit_password'] == "Valider")
	{
		if (isset($_POST['password']) && !empty($_POST['password'])
			&& isset($_POST['cfpassword']) && !empty($_POST['password']))
		{
			if (check_token())
			{
				$newpassword = $_POST['password'];
				if ($newpassword === $_POST['cfpassword'])
				{
					if (preg_match('/(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*\W).{6,}$/', $newpassword))
					{
						$newpassword = hash("whirlpool", $newpassword);
						if ($newpassword !== $password)
						{
							change_password($_SESSION['id'], $newpassword);
							$GLOBALS['error']['success_modif'] = "";
						}
						else
							$GLOBALS['error']['same_password'] = "";
					}
					else
						$GLOBALS['error']['wrong_password'] = "";
				}
				else
					$GLOBALS['error']['cfpassword'] = "";
			}
			else
				$GLOBALS['error']['token'] = "";
		}
	}
	if (isset($_GET['pseudo']) && $_GET['pseudo'] != "")
	{	
		$newpseudo = $_GET['pseudo'];
		if ($newpseudo !== $pseudo)
		{
			if (!preg_match('/\W/', $newpseudo) && strlen($newpseudo) < 20)
			{
				if (check_pseudo($newpseudo))
					echo "KO_EXIST";
				else
					echo "OK";
			}
			else
				echo "KO";
		}
		else
			echo "SAME";
		exit;
	}
	if (isset($_GET['email']) && $_GET['email'] != "")
	{

		$newemail = $_GET['email'];
		if ($newemail !== $email)
		{
			if (preg_match('/^[a-z0-9._-]+@[a-z0-9._-]{2,}\.[a-z]{2,4}$/', $newemail))
			{
				if (check_email($newemail))
					echo "KO_EXIST";
				else
					echo "OK";
			}
			else
				echo "KO";
		}
		else
			echo "SAME";
		exit;
	}
	else if (isset($_GET['password']) && $_GET['password'] != "")
	{
		$newpassword = hash("whirlpool", $_GET['password']);
		if ($newpassword !== $password)
		{
			if (preg_match('/(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*\W).{6,}$/', $_GET['password']))
				echo "OK";
			else
				echo "KO";
		}
		else
			echo "SAME";
		exit();
	}
	if (isset($_POST['submit_delete']) && $_POST['submit_delete'] == "Supprimer")
	{
		if (check_token())
		{
			foreach($_POST as $key => $value)
				if (is_numeric($key))
					if (file_exists($value))
					{
						delete_image($value);
						unlink($value);
					}
		}
		else
			$GLOBALS['error']['token'] = "";
	}
	require('view/member_space_view.php');
}
