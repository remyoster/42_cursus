<?PHP
function display_previous_imgs()
{
	$time = time();
	$date2 = date("Y-m-d H:i:s", $time);
	$date1 = date("Y-m-d H:i:s", $time - 3600);
	$data = get_image_with_id_date($_SESSION['id'], $date1, $date2);
	if ($data)
	{
		foreach($data as $key => $value)
			$data[$key] = "<img src='$value' class='previous_img'>";
	}
	return ($data);
}

function display_imgs($imgs)
{
	foreach ($imgs as $value)
		echo $value;
}

function montage()
{
	check_session_exists();
	$cadre_dir = "public/img/cadre";
	$imgs = [];
	$type = "<input type='radio' name='cadre'>";
	if (is_dir($cadre_dir))
	{
		if ($dh = opendir($cadre_dir))
		{
			while (($file = readdir($dh)) !== false)
			{
				if (preg_match("/\.png/", $file))
				{
					$value = substr($file, 0, -4);
					$imgs[] = "<div class='cadre'><input type='radio' class='cadre_button' name='cadre' value='$value' onclick='selectecadre(this.value)'><img class='cadre_img' src='$cadre_dir/"."$file' alt='$value' onclick='selecteimg(this.alt)'><br></div>";
				}
			}
			closedir($dh);
		}
	}
	if (isset($_POST['cadre']) && isset($_POST['image']) && isset($_POST['width'])
		&& isset($_POST['height']) && isset($_POST['id'])
		&& $_POST['id'] == $_SESSION['id'])
	{
		ctype_digit($_POST['width']) ? $width = $_POST['width'] : $width = 1000;
		ctype_digit($_POST['height']) ? $height = $_POST['height'] : $height = 1000;
		$date = date("Y-m-d H:i:s", time());
		$cadre = $_POST['cadre'];
		$img = $_POST['image'];
		$img = str_replace('data:image/png;base64,','', $img);
		$img = str_replace(' ','+', $img);
		$data = base64_decode($img);
		$im1 = imagecreatefromstring($data);
		$cadre = str_replace('data:image/png;base64,','', $cadre);
		$cadre = str_replace(' ','+', $cadre);
		$data = base64_decode($cadre);
		$im2 = imagecreatefromstring($data);
		imagecopy($im1, $im2, 0, 0, 0, 0, $width, $height);
		$file = "public/img/montage/".uniqid($_SESSION['id'], true).'.jpeg';
		if (imagejpeg($im1, $file))
		{
			insert_image($file, $_SESSION['id'], $date);
			echo $file;
		}
		exit();
	}
	if (isset($_POST['submit']) && $_POST['submit'] == "Envoyer")
	{
		if (isset($_FILES['img']))
		{
			if ($_FILES['img']['error'] == 0)
			{
				$extension_valid = ['jpg', 'jpeg', 'png'];
				$extension = strtolower(substr(strchr($_FILES['img']['type'], "/"), 1));
				$path = "public/img/upload/";
				$new_name = bin2hex(mcrypt_create_iv(32, MCRYPT_DEV_URANDOM));
				if ($_FILES['img']['size'] > 1000000 || $_FILES['img']['size'] == 0)
					$GLOBALS['error']['image_up'] = "size";
				if (!in_array($extension, $extension_valid))
					$GLOBALS['error']['image_up'] = "extension";
				if ($_FILES['img']['tmp_name'] == null
					|| $_FILES['img']['name'] == "")
					$GLOBALS['error']['image_up'] = "name";
				if(file_exists($path.$new_name.$extension))
					$GLOBALS['error']['image_up'] = "";
				$finfo = new finfo(FILEINFO_MIME_TYPE);
				$filename = $_FILES['img']['tmp_name'];
				$real_type = $finfo->file($filename);
				if ($real_type !== "image/png" && $real_type !== "image/jpeg"
					&& $real_type !== "image/jpg")
					$GLOBALS['error']['image_up'] = "extension";
				if (empty($GLOBALS['error']))
				{
					move_uploaded_file($_FILES['img']['tmp_name'], $path.$new_name.'.'.$extension);
					$up_img = "<img id='up_img' src='$path"."$new_name".".$extension"."'>";
				}
			}
			else if ($_FILES['img']['error'] == 1 || $_FILES['img']['error'] == 2)
				$GLOBALS['error']['image_up'] = "size";
		}
		else
			$GLOBALS['error']['image_up'] = "";
	}
	require('view/home_confirmed_view.php');
}
