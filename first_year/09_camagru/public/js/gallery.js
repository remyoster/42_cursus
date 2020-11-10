function deal_like(str)
{
	var xmlhttp = new XMLHttpRequest();
	xmlhttp.onreadystatechange = function() {
		if (this.readyState == 4 && this.status == 200) {
			var button = document.getElementById(str);
			var nb_like = document.getElementById('nb_like'+str);
			var value = parseInt(nb_like.innerHTML);
			if (this.responseText == "OK DISLIKE")
			{
				button.innerHTML = "<i class='far fa-thumbs-up'></i>";
				nb_like.innerHTML = value - 1;
			}
			else if (this.responseText == "OK LIKE")
			{
				button.innerHTML = "<i class='fas fa-thumbs-up'></i>";
				nb_like.innerHTML = value + 1;
			}
			else if (this.responseText == "KO")
			{
				if (document.getElementById('info_like'+str) === null)
				{
					var info = document.createElement("span");
					info.setAttribute("id", "info_like"+str);
					info.innerText = " Vous devez être authentifié pour liker";
					setTimeout(function () {
						info.style.display = "none"; }, 3000);
					button.after(info);
				}
				else
				{
					document.getElementById('info_like'+str).style.display = "";
					setTimeout(function () {
						document.getElementById('info_like'+str).style.display = "none"; }, 3000);
				}
			}
		}
	};
	xmlhttp.open("GET", "index.php?action=gallery&like="+str, true);
	xmlhttp.send();
}
function deal_comment(form)
{
	var comment = form.comment.value;
	var id = form.img_id.value;
	var token = form.token.value;
	if (comment != '' && id != '')
	{
		var xmlhttp = new XMLHttpRequest();
		xmlhttp.onreadystatechange = function() {
			if (this.readyState == 4 && this.status == 200) {
				if (this.responseText == "KO")
				{
					form.comment.value = "Vous devez être authentifié pour commenter";
					setTimeout(function() {
						form.comment.value = ""; }, 3000);
				}
				else if (this.responseText == "KO EMPTY")
					form.comment.value = "";
				else if (this.responseText == "KO XSS")
				{
					form.comment.value = "Votre message contient des caractères interdits.";
					setTimeout(function() {
						form.comment.value = ""; }, 3000);
				}
				else if (this.responseText == "TOO LONG")
				{
					form.comment.value = "Votre message est trop long (max:160)";
					setTimeout(function() {
						form.comment.value = ""; }, 3000);
				}
				else
				{
					var new_p = document.createElement("p");
					new_p.innerHTML = this.responseText;
					form.before(new_p);
					form.comment.value = "";
				}
			}
		};
		xmlhttp.open("POST", "index.php?action=gallery");
		xmlhttp.setRequestHeader("content-type", "application/x-www-form-urlencoded");
		xmlhttp.send('comment=' + comment + '&img_id=' + id + '&token=' + token);
	}
}
