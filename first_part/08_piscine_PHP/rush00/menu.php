<?PHP
	include('connexion_sql.php');
 	if ($_SESSION['status'] == "visitor") {
 	echo "<a id='logo' href='index.php'>
		<img src='img/logo_multifruix.png'>
		<span>Multifruix</span>
	</a>
	<nav>
		<ul class='menu-wrapper'>
		  <li id='menu1' class='sub-menu-parent'>
		    <a href='products_page.php'>Shop</a>
		  </li>
		  <li id='menu2' class='sub-menu-parent'>
		    <a href='basket.php'>Panier</a>
		  </li>
		  <li id='menu3' class='sub-menu-parent'>
		    <a href='login.php'>Connexion</a>
		  </li>	  
		  <li id='menu4' class='sub-menu-parent'>
		    <a href='create_account.php'>Creer un compte</a>
		  </li>			          
		</ul>
	</nav> ";
	} else if ($_SESSION['status'] == "admin"){
	echo "<a id='logo' href='index.php'>
		<img src='img/logo_multifruix.png'>
		<span>Multifruix</span>
	</a>
	<nav>
		<ul class='menu-wrapper'>
		  <li id='menu1' class='sub-menu-parent'>
		    <a href='products_page.php'>Shop</a>
		  </li>
		  <li id='menu2' class='sub-menu-parent'>
		    <a href='basket.php'>Panier</a>
		  </li>
		  <li id='menu3' class='sub-menu-parent'>
		    <a href='member_space.php'>Espace membre</a>
		  </li>
		  <li id='menu4' class='sub-menu-parent'>
		    <a href='logout.php'>Deconnection</a>
		  </li>	 
		  <li id='menu5' class='sub-menu-parent'>
		    <a href='admin_space.php'>Escape admin</a>
		  </li>	   		        
		</ul>
	</nav> ";
	}
	else {
	echo "<a id='logo' href='index.php'>
		<img src='img/logo_multifruix.png'>
		<span>Multifruix</span>
	</a>
	<nav>
		<ul class='menu-wrapper'>
		  <li id='menu1' class='sub-menu-parent'>
		    <a href='products_page.php'>Shop</a>
		  </li>
		  <li id='menu2' class='sub-menu-parent'>
		    <a href='basket.php'>Panier</a>
		  </li>
		  <li id='menu3' class='sub-menu-parent'>
		    <a href='member_space.php'>Espace membre</a>
		  </li>
		  <li id='menu4' class='sub-menu-parent'>
		    <a href='logout.php'>Deconnection</a>
		  </li>	       
		</ul>
	</nav> ";
	}
?>
