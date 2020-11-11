<?PHP
function db_connect()
{
	include('config/database.php');
	try
	{
		$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD,
			array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));
	}
	catch (PDOException $e)
	{
		echo "Connection failed: ".$e->getMessage();
	}
	return ($db);
}

function delete_image($src)
{
	$db = db_connect();
	$req = $db->prepare('DELETE from image WHERE image.src LIKE :src');
	$req->bindValue(':src', $src, PDO::PARAM_STR);
	$req->execute();
}

function delete_like($img_id, $author_id)
{
	$db = db_connect();
	$req = $db->prepare("DELETE FROM img_like WHERE img_like.author_id LIKE :author_id AND img_like.image_id LIKE :image_id");
	$req->bindValue(':author_id', $author_id, PDO::PARAM_INT);
	$req->bindValue(':image_id', $img_id, PDO::PARAM_INT);
	$req->execute();
}

function insert_comment($image_id, $author_id, $text, $date)
{
	$db = db_connect();
	$req = $db->prepare('INSERT INTO comment (image_id, author_id, text, date) VALUES (:image_id, :author_id, :text, :date)');
	$req->execute(['image_id' => $image_id, 'author_id' => $author_id, 'text' => $text, 'date' => $date]);
}

function insert_image($src, $author_id, $date)
{
	$db = db_connect();
	$req = $db->prepare('INSERT INTO image (src, author_id, date) VALUES (:src, :author_id, :date)');
	$req->bindValue(':src', $src, PDO::PARAM_STR);
	$req->bindValue(':author_id', $author_id, PDO::PARAM_INT);
	$req->bindValue(':date', $date, PDO::PARAM_STR);
	$req->execute();
}

function insert_account($kwargs)
{
	$db = db_connect();
	$req = $db->prepare('INSERT INTO user (pseudo, email, password) VALUES (:pseudo, :email, :password)');
	$req->execute(array(
		'pseudo' => $kwargs['pseudo'],
		'email' => $kwargs['email'],
		'password' => $kwargs['password']));
}

function insert_like($img_id, $author_id)
{
	$db = db_connect();
	$req = $db->prepare("INSERT INTO img_like (author_id, image_id) VALUES (:author_id, :image_id)");
	$req->bindValue(':author_id', $author_id, PDO::PARAM_INT);
	$req->bindValue(':image_id', $img_id, PDO::PARAM_INT);
	$req->execute();
}

function change_like($img_id, $mod)
{
	$db = db_connect();
	$req = $db->prepare("SELECT nb_like FROM image WHERE image.id LIKE :img_id");
	$req->bindValue(':img_id', $img_id, PDO::PARAM_INT);
	$req->execute();
	$data = $req->fetch(PDO::FETCH_ASSOC);
	if ($data)
	{
		$nb = $data['nb_like'] + $mod;
		$req = $db->query("UPDATE image SET nb_like = $nb WHERE image.id = $img_id");
	}
}

function change_notification($id, $notif)
{
	$db = db_connect();
	$req = $db->prepare("UPDATE user SET notification = :notif WHERE user.id = :id");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->bindValue(':notif', $notif, PDO::PARAM_STR);
	$req->execute();
}

function change_password($id, $password)
{
	$db = db_connect();
	$req = $db->prepare("UPDATE user SET password = :password WHERE user.id = :id");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->bindValue(':password', $password, PDO::PARAM_STR);
	$req->execute();
}

function change_pseudo($id, $newpseudo)
{
	$db = db_connect();
	$req = $db->prepare("UPDATE user SET pseudo = :newpseudo WHERE user.id = :id");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->bindValue(':newpseudo', $newpseudo, PDO::PARAM_STR);
	$req->execute();
}

function change_email($id, $newemail)
{
	$db = db_connect();
	$req = $db->prepare("UPDATE user SET email = :newemail WHERE user.id = :id");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->bindValue(':newemail', $newemail, PDO::PARAM_STR);
	$req->execute();
}

function confirm_account($id)
{
	$db = db_connect();
	$req = $db->prepare("UPDATE user SET account = 'confirmed' WHERE user.id = :id");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->execute();
}

function get_img_author_info($id)
{
	$db = db_connect();
	$req = $db->prepare("SELECT user.email, user.pseudo, user.notification FROM user INNER JOIN image ON user.id = image.author_id AND image.id = :id GROUP BY user.email");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->execute();
	$data = $req->fetch(PDO::FETCH_ASSOC);
	if ($data)
		return ($data);
	else
		return (false);
}

function get_img_author_pseudo()
{
	$db = db_connect();
	$req = $db->query("SELECT user.id, user.pseudo FROM user INNER JOIN image WHERE USER.id = image.author_id GROUP BY pseudo");
	$data = $req->fetchAll(PDO::FETCH_ASSOC);
	if ($data)
		return ($data);
	else
		return (false);
}

function get_user_pseudo($id)
{
	$db = db_connect();
	$req = $db->prepare("SELECT pseudo FROM user WHERE user.id LIKE :id");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->execute();
	$data = $req->fetch(PDO::FETCH_COLUMN);
	if ($data)
		return ($data);
	else
		return (false);
}

function get_comment_author_pseudo()
{
	$db = db_connect();
	$req = $db->query("SELECT user.id, user.pseudo FROM user INNER JOIN comment WHERE user.id = comment.author_id GROUP BY pseudo");
	$data = $req->fetchAll(PDO::FETCH_ASSOC);
	if ($data)
		return ($data);
	else
		return (false);
}

function get_comments($id)
{
	$db = db_connect();
	$req = $db->prepare("SELECT author_id, text, date FROM comment WHERE image_id LIKE :id");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->execute();
	$data = $req->fetchAll(PDO::FETCH_ASSOC);
	if ($data)
		return ($data);
	else
		return (false);
}

function get_image()
{
	$db = db_connect();
	$req = $db->query("SELECT * FROM image ORDER BY image.date DESC");
	$data = $req->fetchAll(PDO::FETCH_ASSOC);
	if ($data)
		return ($data);
	else
		return (false);
}

function get_like($img_id, $author_id)
{
	$db = db_connect();
	$req = $db->prepare("SELECT * FROM img_like WHERE image_id LIKE :img_id AND author_id like :author_id");
	$req->bindValue(':img_id', $img_id, PDO::PARAM_INT);
	$req->bindValue(':author_id', $author_id, PDO::PARAM_INT);
	$req->execute();
	$data = $req->fetch(PDO::FETCH_ASSOC);
	if ($data)
		return ($data);
	else
		return (false);
}

function get_image_with_id($id)
{
	$db = db_connect();
	$req = $db->prepare("SELECT src FROM image WHERE author_id = :id ORDER BY date DESC");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->execute();
	$data = $req->fetchAll(PDO::FETCH_COLUMN);
	if ($data)
		return ($data);
	else
		return (false);
}

function get_image_with_id_date($id, $date1, $date2)
{
	$db = db_connect();
	$req = $db->prepare("SELECT src FROM image WHERE author_id = :id AND date BETWEEN :date1 AND :date2 ORDER BY date DESC");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->bindValue(':date1', $date1, PDO::PARAM_STR);
	$req->bindValue(':date2', $date2, PDO::PARAM_STR);
	$req->execute();
	$data = $req->fetchAll(PDO::FETCH_COLUMN);
	if ($data)
		return ($data);
	else
		return (false);
}

function get_account_info_with_id($id)
{
	$db = db_connect();
	$req = $db->prepare("SELECT * FROM user WHERE id = :id");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->execute();
	$data = $req->fetch(PDO::FETCH_ASSOC);
	if ($data)
		return ($data);
	else
		return (false);
}

function check_image($id)
{
	$db = db_connect();
	$req = $db->prepare("SELECT id FROM image WHERE id LIKE :id");
	$req->bindValue(':id', $id, PDO::PARAM_INT);
	$req->execute();
	$data = $req->fetch(PDO::FETCH_ASSOC);
	if ($data)
		return (true);
	else
		return (false);
}

function check_email($email)
{
	$db = db_connect();
	$req = $db->prepare('SELECT email FROM user WHERE email LIKE :email');
	$req->bindValue(':email', $email, PDO::PARAM_STR);
	$req->execute();
	$data = $req->fetch(PDO::FETCH_ASSOC);
	if ($data)
		return (true);
	else
		return (false);
}

function check_pseudo($pseudo)
{
	$db = db_connect();
	$req = $db->prepare('SELECT pseudo FROM user WHERE pseudo LIKE :pseudo');
	$req->bindValue(':pseudo', $pseudo, PDO::PARAM_STR);
	$req->execute();
	$data = $req->fetch(PDO::FETCH_ASSOC);
	if ($data)
		return (true);
	else
		return (false);
}

function check_pseudo_email($str)
{
	$db = db_connect();
	$req = $db->prepare('SELECT pseudo, email FROM user WHERE pseudo LIKE :str OR email LIKE :str');
	$req->bindValue(':str', $str, PDO::PARAM_STR);
	$req->execute();
	$data = $req->fetch(PDO::FETCH_ASSOC);
	if ($data)
		return (true);
	else
		return (false);
}

function check_account($str)
{
	$db = db_connect();
	$req = $db->prepare('SELECT * FROM user WHERE pseudo LIKE :str OR email LIKE :str');
	$req->bindValue(':str', $str, PDO::PARAM_STR);
	$req->execute();
	$data = $req->fetch(PDO::FETCH_ASSOC);
	return ($data);
}

function check_password($password, $pseudo_email)
{
	$db = db_connect();
	$req = $db->prepare('SELECT password FROM user WHERE (pseudo LIKE :str OR email LIKE :str) AND password LIKE :password');
	$req->bindValue(':password', $password, PDO::PARAM_STR);
	$req->bindValue(':str', $pseudo_email, PDO::PARAM_STR);
	$req->execute();
	$data = $req->fetch(PDO::FETCH_ASSOC);
	if ($data)
		return (true);
	else
		return (false);
}

function display_error($message)
{
	if (isset($message) && !empty($message))
	{	
		foreach($message as $key => $value)
		{
			if ($key == "pseudo")
				echo "<div class='error'>Le pseudo '$value' n'est pas disponible</div>";
			else if ($key == "wrong_pseudo")
				echo "<div class='error'>Le pseudo ne respecte pas le format</div>";
			else if ($key == "email")
				echo "<div class='error'>L'adresse '$value' est déjà utilisée</div>";
			else if ($key == "wrong_email")
				echo "<div class='error'>L'adresse mail ne respecte pas le format</div>";
			else if ($key == "pseudo_email")
				echo "<div class='error'>Le pseudo ou l'adresse mail '$value' est incorrect</div>";
			else if ($key == "password")
				echo "<div class='error'>Mot de passe incorrect</div>";
			else if ($key == "wrong_password")
				echo "<div class='error'>Le mot de passe ne respecte pas le format</div>";
			else if ($key == "cfpassword")
				echo "<div class='error'>Les mots de passe ne correspondent pas</div>";
			else if ($key == "same_password")
				echo "<div class='error'>Le mot de passe est identique au précédent</div>";
			else if ($key == "empty_field")
				echo "<div class='error'>Veuillez remplir les champs</div>";
			else if ($key == "success_modif")
				echo "<div class='success'>Modifications prises en compte</div>";
			else if ($key == "email_sent")
				echo "<div class='success'>Un email vous a été envoyé</div>";
			else if ($key == "password_changed")
				echo "<div class='success'>Votre mot de passe a bien été modifié</div>";
			else if ($key == "image_save")
				echo "<div class='success'>Votre image a bien été sauvegardé</div>";
			else if ($key == "image_up" && $value == "")
				echo "<div class='error'>Une erreur est survenue</div>";
			else if ($key == "image_up" && $value == "size")
				echo "<div class='error'>Le fichier est trop gros (max 1mo)</div>";
			else if ($key == "image_up" && $value == "extension")
				echo "<div class='error'>Le fichier n'est pas au bon format (jpg/jpeg/png)</div>";
			else if ($key == "image_up" && $value == "name")
				echo "<div class='error'>Le nom du fichier est inccorect</div>";
			else if ($key == "main")
				echo "<div class='error'>Une erreur est survenue</div>";
			else if ($key == "token")
				echo "<div class='error'>Une erreur est survenue</div>";
		}
	}
}
?>
