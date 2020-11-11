<?PHP
session_start();
if (isset($_SESSION['loggued_on_user']))
{
	if ($_SESSION['loggued_on_user'] != "")
		echo $_SESSION['loggued_on_user']."\n";
	else
		echo "ERROR\n";
}
else
	echo "ERROR\n";
?>
