function enabled_submit()
{
	var field1 = document.getElementsByTagName('fieldset')[0];
	var field2 = document.getElementsByTagName('fieldset')[1];
	if (field1.getElementsByClassName('far fa-check-circle').length >= 1)
		field1.getElementsByTagName('input')['submit_account'].disabled=false;
	else
		field1.getElementsByTagName('input')['submit_account'].disabled=true;
	if (field2.getElementsByClassName('far fa-check-circle').length == 2)
		field2.getElementsByTagName('input')['submit_password'].disabled=false;
	else
		field2.getElementsByTagName('input')['submit_password'].disabled=true;
}

function check_hint_pseudo(str)
{
	if (str.length == 0)
	{
		document.getElementById("check_pseudo").innerHTML = "";
		return ;
	}
	else
	{
		var xmlhttp = new XMLHttpRequest();
		str = encodeURIComponent(str);
		xmlhttp.onreadystatechange = function() {
			if (this.readyState == 4 && this.status == 200) {
				if (this.responseText == "OK")
					document.getElementById("check_pseudo").innerHTML = '<i class="far fa-check-circle"></i>';
				else if (this.responseText == "KO_EXIST")
					document.getElementById("check_pseudo").innerHTML = '<br><i class="far fa-times-circle"> Ce pseudo n\'est pas disponible</i>';
				else if (this.responseText == "KO")
					document.getElementById("check_pseudo").innerHTML = '<br><i class="far fa-times-circle"> Le pseudo ne peut pas contenir de caractères spéciaux, ni faire plus de 20 caractères</i>';
				else if (this.responseText == "SAME")
					document.getElementById("check_pseudo").innerHTML = "";
				enabled_submit();
			}
		};
		xmlhttp.open("GET", "index.php?action=member_space&pseudo=" + str, true);
		xmlhttp.send();
	}
}

function check_hint_email(str)
{
	if (str.length == 0)
	{
		document.getElementById("check_email").innerHTML = "";
		return ;
	}
	else
	{
		var xmlhttp = new XMLHttpRequest();
		str = encodeURIComponent(str);
		xmlhttp.onreadystatechange = function() {
			if (this.readyState == 4 && this.status == 200) {
				if (this.responseText == "OK")
					document.getElementById("check_email").innerHTML = '<i class="far fa-check-circle"></i>';
				else if (this.responseText == "KO_EXIST")
					document.getElementById("check_email").innerHTML = '<br><i class="far fa-times-circle"> L\'adresse mail est déjà utilisée</i>';
				else if (this.responseText == "KO")
					document.getElementById("check_email").innerHTML = '<br><i class="far fa-times-circle"> L\'adresse mail est incorrecte</i>';
				else if (this.responseText == "SAME")
					document.getElementById("check_email").innerHTML = "";
				enabled_submit();
			}
		};
		xmlhttp.open("GET", "index.php?action=member_space&email=" + str, true);
		xmlhttp.send();
	}
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
				else if (this.responseText == "SAME")
					document.getElementById("check_password").innerHTML = '<br><i class="far fa-times-circle"> Le mot de passe est identique au précédent</i>';
				else
					document.getElementById("check_password").innerHTML = '<br><i class="far fa-times-circle"> Le mot de passe doit contenir au moins 6 caractères dont une majuscule, une minuscule, un chiffre et un caractère spécial</i>';
				enabled_submit();
			}
		};
		xmlhttp.open("GET", "index.php?action=member_space&password=" + str, true);
		xmlhttp.send();
	}
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

function select_all()
{
	var imgs = document.getElementsByClassName('checkbox');
	var button = document.getElementById('select');
	if (button.innerText == "Tout cocher")
	{
		Array.from(imgs).forEach(function(elem) {
			elem.checked = true;
		});
		button.innerText = "Tout décocher";
	}
	else if (button.innerText == "Tout décocher")
	{
		Array.from(imgs).forEach(function(elem) {
			elem.checked = false;
		});
		button.innerText = "Tout cocher";
	}
}
function check_img(id)
{
	if (document.getElementsByName(id)[0].checked == false)
		document.getElementsByName(id)[0].checked = true;
	else
		document.getElementsByName(id)[0].checked = false;
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
				i = 0;
				while (document.getElementsByClassName("success")[i])
				{
					document.getElementsByClassName("success")[i].style.display = "none";
					i++;
				}
			}, 6000);
}
