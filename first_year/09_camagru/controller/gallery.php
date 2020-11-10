<?PHP

function display_comments($id)
{
	$pseudos = get_comment_author_pseudo();
	if ($data = get_comments($id))
	{
		foreach ($data as $comment)
		{
			foreach($comment as $key => $value)
			{
				if ($key == "author_id")
					$author = search_author_id($value, $pseudos);
				else if ($key == "text")
					$content = $value;
				else if ($key == "date")
					$date = $value;
			}
			$p = "<p><b>$author</b> - $date<br/>".htmlspecialchars($content)."</p>";
			!isset($all_p) ? $all_p = $p : $all_p = $all_p.$p;
		}
		return($all_p);
	}
	else
		return ("");
}

function display_pagination($nb_pages)
{
	if (isset($_GET['page']) && ctype_digit($_GET['page']) && $_GET['page'] > 0)
		$i = $_GET['page'];
	else
		$i = 1;
	$nb_pages <= 5 ? $j = 1 : $j = $i - 2;
	$j < 1 ? $j = 1 : $j;
	$nb_pages > 5 ? ($j + 4 > $nb_pages ? $k = $nb_pages : $k = $j + 4) : $k = $nb_pages;

	echo "<a href='index.php?action=gallery&page=".($i - 5 > 0 ? $i - 5 : 1)."'>&laquo</a>";
	echo "<a href='index.php?action=gallery&page=".($i - 1 < 1 ? 1 : $i - 1)."'>&lt</a>";
	while ($j <= $k)
	{
		if ($j == $i)
			echo "<a href='index.php?action=gallery&page=$j' class='active'>$j</a>";
		else
			echo "<a href='index.php?action=gallery&page=$j'>$j</a>";
		$j++;
	}
	echo "<a href='index.php?action=gallery&page=".($i + 1 <= $nb_pages ? $i + 1 : $nb_pages)."'>&gt</a>";
	echo "<a href='index.php?action=gallery&page=".($i + 5 <= $nb_pages ? $i + 5 : $nb_pages)."'>&raquo</a>";
	echo "<a href='' class='total'>$i/$nb_pages</a>";
}

function search_author_id($id, $pseudos)
{
	if (isset($pseudos) && !empty($pseudos))
	{
		foreach($pseudos as $pseudo)
			if ($pseudo['id'] == $id)
				return $pseudo['pseudo'];
		return "Inconnu";
	}
	else
		return "Inconnu";
}

function display_all_imgs($imgs)
{
	if (isset($_GET['page']) && ctype_digit($_GET['page']) && $_GET['page'] > 0)
		$i = $_GET['page'];
	else
		$i = 1;
	$i_start = ($i - 1) * 5;
	$i_end = $i * 5;
	$pseudos = get_img_author_pseudo();
	while(!empty($imgs[$i_start]) && $i_start < $i_end)
	{
		if (get_like($imgs[$i_start]['id'], $_SESSION['id']))
			$icon = '<i class="fas fa-thumbs-up"></i>';
		else
			$icon = '<i class="far fa-thumbs-up"></i>';
		$form = "<form action='index.php?action=gallery' method='POST'>
			<input type='hidden' name='img_id' value=".$imgs[$i_start]['id'].">
			<input type='hidden' name='page_id' value='$i'>
			<input type='hidden' name='token' value='".$_SESSION['token']."'>
			<textarea class='comment_area' name='comment'></textarea><br />
			<input type='button' class='submit_comment' name='submit' value='Commenter' onclick='deal_comment(this.form)'>
			</form>";
$share_fb = '<iframe src="https://www.facebook.com/plugins/share_button.php?href=http%3A%2F%2Flocalhost%3A8100%2FDocuments%2Fmy_git_lab%2Fcamagru%2Findex.php%3Faction%3Dgallery&layout=button&size=large&width=89&height=28&appId" width="89" height="28" style="border:none;overflow:hidden" scrolling="no" frameborder="0" allowTransparency="true" allow="encrypted-media"></iframe>';

echo "<div class='gallery_img_wrapper'><figure><img class='gallery_img' src='".$imgs[$i_start]['src']."' alt='img".$imgs[$i_start]['date']."'><figcaption>De: <span id='auteur_name'>".search_author_id($imgs[$i_start]['author_id'], $pseudos)."</span> (".substr($imgs[$i_start]['date'], 0, 10).")<br /><span class ='like' id='nb_like".$imgs[$i_start]['id']."'>".$imgs[$i_start]['nb_like']."</span> <button class='like_button' name='like_button' id='".$imgs[$i_start]['id']."'onclick='deal_like(this.id)'>$icon</button> $share_fb </figcaption></figure><div class='comment'>".display_comments($imgs[$i_start]['id'])."$form</div></div>";
$i_start++;
	}
}

function send_notification_email($email, $pseudo, $comment_author)
{
	if (isset($_GET['page']) && ctype_digit($_GET['page']))
		$page = $_GET['page'];
	else
		$page = 1;
	$path = $_SERVER['SCRIPT_NAME'];
	$port = $_SERVER['HTTP_HOST'];
	$to = $email;
	$subject = "Notification de commentaire";
	$message = "Bonjour $pseudo,\r\nVotre image vient d'être commentée par '$comment_author'. Cliquez sur ce lien pour voir le commentaire:\r\nhttp://".$port.$path."?action=gallery&page=$page";
	mail($to, $subject, $message);
}

function gallery()
{
	if ($imgs = get_image())
	{ 
		$nb_imgs = count($imgs);
		$nb_pages = round($nb_imgs / 5);
		$nb_pages == 0 ? $nb_pages = 1 : $nb_pages;
	}
	else
		$nb_pages = 1;
	if (isset($_GET['like']) && ctype_digit($_GET['like']))
	{
		if (isset($_SESSION['id']) && $_SESSION['id'] > -1
			&& $_SESSION['status'] == "confirmed")
		{
			if ($data = get_like($_GET['like'], $_SESSION['id']))
			{
				delete_like($_GET['like'], $_SESSION['id']);
				change_like($_GET['like'], -1);
				echo "OK DISLIKE";
			}
			else
			{
				insert_like($_GET['like'], $_SESSION['id']);
				change_like($_GET['like'], 1);
				echo "OK LIKE";
			}
		}
		else
			echo "KO";
		exit();
	}
	if (isset($_POST['comment']) && isset($_POST['img_id']) && ctype_digit($_POST['img_id']))
	{
		if (!empty($_POST['comment']))
		{
			if (isset($_SESSION['id']) && $_SESSION['id'] > -1
				&& $_SESSION['status'] == "confirmed" && check_token())
			{
				if (check_image($_POST['img_id']))
				{
					if (strlen($_POST['comment']) < 161)
					{
						if (!preg_match("/<.*>/", $_POST['comment']))
						{
							$date = date("Y-m-d H:i:s", time());
							insert_comment($_POST['img_id'], $_SESSION['id'], $_POST['comment'], $date);
							$comment_author = get_user_pseudo($_SESSION['id']);
							$img_author = get_img_author_info($_POST['img_id']);
							if ($img_author['notification'] == "yes")
								send_notification_email($img_author['email'], $img_author['pseudo'], $comment_author); 
							echo "<b>$comment_author</b> - $date<br />".htmlspecialchars($_POST['comment'])."";
						}
						else
							echo "KO XSS";
					}
					else
						echo "TOO LONG";
				}
				else
					echo "KO EMPTY";
			}
			else
				echo "KO";
		}
		else
			echo "KO EMPTY";
		exit();
	}
	require('view/gallery_view.php');
}
