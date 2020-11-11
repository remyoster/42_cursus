function enabled_submit()
{
	if (document.getElementsByTagName('input')['pseudo_email'].value != "" && 
			document.getElementsByTagName('input')['password'].value != "")
		document.getElementsByTagName('input')['submit'].disabled=false;
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
