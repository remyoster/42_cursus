<?PHP
/*Control display on index.php in function of the status of the visitor.*/
function home()
{
	check_session_exists();
	if (!(isset($_SESSION['status'])))
		$_SESSION['status'] = "visitor";
	$title = 'Camagru';
	if (isset($_SESSION['status']) && $_SESSION['status'] == "visitor")
		require('view/home_visitor_view.php');
	else if (isset($_SESSION['status']) && $_SESSION['status'] == "not confirmed")
		require('view/home_not_confirmed_view.php');
	else if (isset($_SESSION['status']) && $_SESSION['status'] == "confirmed")
		montage();
	else
		throw new Exception();
}
?>
