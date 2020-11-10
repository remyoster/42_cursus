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
