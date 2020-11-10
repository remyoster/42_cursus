function enabled_submit()
{
	if (document.getElementsByClassName('far fa-check-circle').length == 2)
		document.getElementsByTagName('input')['submit'].disabled=false;
}

function check_hint_password(str)
{
	if (str.length == 0)
	{
		document.getElementById("check_password").innerHTML = "";
		return ;
	}
	else
	{
		var xmlhttp = new XMLHttpRequest();
		str = encodeURIComponent(str);
		xmlhttp.onreadystatechange = function() {
			if (this.readyState == 4 && this.status == 200) {
				if (this.responseText == "OK")
					document.getElementById("check_password").innerHTML = '<i class="far fa-check-circle"></i>';
				else
					document.getElementById("check_password").innerHTML = '<br><i class="far fa-times-circle"> Le mot de passe doit contenir au moins 6 caractères dont une majuscule et un caractère spécial</i>';

			}
		};
		xmlhttp.open("GET", "index.php?action=create_account&password=" + str, true);
		xmlhttp.send();
	}
	enabled_submit();
}

function check_hint_cfpassword(str)
{
	if (str.length == 0 || document.getElementsByTagName('input')['password'].value == "")
	{
		document.getElementById("check_cfpassword").innerHTML = "";
		return ;
	}
	else
	{
		if (document.getElementsByTagName('input')['password'].value == document.getElementsByTagName('input')['cfpassword'].value)
			document.getElementById("check_cfpassword").innerHTML = '<i class="far fa-check-circle"></i>';
		else
			document.getElementById("check_cfpassword").innerHTML = '<br><i class="far fa-times-circle"> Le mot de passe ne correspond pas</i>';

	}
	enabled_submit();
}

window.onload = function()
{
	setTimeout(function()
			{
				var i = 0;
				while (document.getElementsByClassName("error")[i])
				{
					document.getElementsByClassName("error")[i].style.display = "none";
					i++;
				}
			}, 6000);
}
