window.addEventListener("DOMContentLoaded", function() {

	var width = document.getElementById('montage_wrapper').clientWidth;
	var height = document.getElementById('montage_wrapper').clientHeight;
	width > 800 ? width = 800 : width;
	height > 600 ? height = 600 : height;
	var constraints = { audio: false, video: { width: width, height: height, facingMode: "user" } }; 

	navigator.mediaDevices.getUserMedia(constraints)
		.then(function(mediaStream) {
			var video = document.querySelector('video');
			video.srcObject = mediaStream;
			if (document.getElementById('up_img'))
			{
				var yes = document.getElementById('montage_wrapper');
				yes.removeChild(yes.childNodes[3]);
			}
			video.onloadedmetadata = function(e) {
				video.play();
			};
		})
	.catch(function(err) { 
		if (document.getElementById('up_img'))
		{
			var yes = document.getElementById('montage_wrapper');
			yes.removeChild(yes.childNodes[1]);
		}
		else
			document.getElementById('montage_wrapper').innerHTML = "<p>Votre camera est désactivée ou inexistante. Vous pouvez uploader une image à la place</p>";
		image();
	});

	function image() {
		var form = document.createElement('FORM');
		form.name = 'upload_img';
		form.method = 'POST';
		form.action = 'index.php?action=montage';
		form.enctype = 'multipart/form-data';
		var upload_file = document.createElement('input');
		upload_file.type = 'file';
		upload_file.name = "img";
		var upload_limit = document.createElement('input');
		upload_limit.type = 'hidden';
		upload_limit.name = "MAX_FILE_FIZE";
		upload_limit.value = "1000000";
		var submit_button = document.createElement('input');
		submit_button.type = 'submit';
		submit_button.name = "submit";
		submit_button.value = "Envoyer";
		form.appendChild(upload_limit);
		form.appendChild(upload_file);
		var br = document.createElement('br');
		form.appendChild(br);
		form.appendChild(submit_button);
		document.getElementById('montage_wrapper').after(form);
	}

	function takepicture() {
		var width = document.getElementById('montage_wrapper').clientWidth;
		var height = document.getElementById('montage_wrapper').clientHeight;
		width > 800 ? width = 800 : width;
		height > 600 ? height = 600 : height;
		var img_tmp = document.getElementById('img_tmp');
		var cadre_tmp = document.getElementById('cadre_tmp');
		var cadre = document.getElementById('cadre');
		var up_img = document.getElementById('up_img');
		var video = document.getElementById('video');
		canvas.width = width;
		canvas.height = height;
		img_tmp.width = width;
		img_tmp.height = height;
		cadre_tmp.width = width;
		cadre_tmp.height = height;
		var x = parseInt(cadre.style.left.substring(0, cadre.style.left.length - 2));
		var y = parseInt(cadre.style.top.substring(0, cadre.style.top.length - 2));
		x ? x : x = 0;
		y ? y : y = 0;
		if (up_img)
		{
			canvas.getContext('2d').drawImage(up_img, 0, 0, width, height);
			img_tmp.getContext('2d').drawImage(up_img, 0, 0, width, height);
		}
		else if (video)
		{
			canvas.getContext('2d').drawImage(video, 0, 0, width, height);
			img_tmp.getContext('2d').drawImage(video, 0, 0, width, height);
		}
		cadre_tmp.getContext('2d').drawImage(cadre, x, y, cadre.width, cadre.height);
		canvas.getContext('2d').drawImage(cadre, x, y, cadre.width, cadre.height);
	}
	var shoot = document.getElementById('shoot');
	shoot.addEventListener('click', function(ev){
		document.getElementById('canvas').style.display = "block";
		document.getElementById('save').style.display = "block";
		takepicture();
		ev.preventDefault();
	}, false);
}, false);

function selecteimg(val)
{
	document.querySelector('input[value='+val).checked = true;
	selectecadre(val);
}

function selectecadre(cadre) {
	var height = document.getElementById('montage_wrapper').clientHeight;
	var width = document.getElementById('montage_wrapper').clientWidth;
	width > 800 ? width = 800 : width;
	height > 600 ? height = 600 : height;
	if (document.getElementById('shoot').disabled == true)
	{
		document.getElementById('shoot').disabled = false;
		document.getElementById('shoot').innerHTML = "SHOOOOOOOOOOT !!!";
	}
	var elem_parent = document.getElementById("montage_wrapper");
	var child = document.getElementById('cadre');
	if (child)
		elem_parent.removeChild(child);
	var new_img = document.createElement("img");
	new_img.setAttribute('src', 'public/img/cadre/'+cadre+'.png');
	new_img.setAttribute('id', 'cadre');
	elem_parent.appendChild(new_img);
	new_img.addEventListener("wheel", function(event) {
		new_img.focus();
		var y = event.deltaY;
		var currentW = new_img.style.width;
		var currentH = new_img.style.height;
		currentW ? currentW : currentW = 100;
		currentH ? currentH : currentH = 100;
		if (y > 0)
		{
			newSizeH = parseInt(currentH) + 5;
			newSizeW = parseInt(currentW) + 5;
		}
		else
		{
			newSizeH = parseInt(currentH) - 5;
			newSizeW = parseInt(currentW) - 5;
		}
		if (newSizeH > 10 && newSizeH < 110 && newSizeW > 10 && newSizeW < 110)
		{
			event.target.style.width = newSizeW + "%";
			event.target.style.height = newSizeH + "%";
		}
	});
	new_img.addEventListener("click", function () {
		new_img.focus();
		document.body.addEventListener("keydown", function(event) {
			cadre = document.getElementById('cadre').style;
			if (event.keyCode == 39)
			{
				if (cadre.left)
				{
					str = cadre.left;
					str = str.substring(0, str.length - 2);
					str = parseInt(str);
					str < width ? str += 5 : str;
					cadre.left = str + "px";
				}
				else
					cadre.left = "10px";
			}
			else if (event.keyCode == 37)
			{
				if (cadre.left)
				{
					str = cadre.left;
					str = str.substring(0, str.length - 2);
					str = parseInt(str);
					str > -width ? str -= 5 : str;
					cadre.left = str + "px";
				}
				else
					cadre.left = "-10px";
			}
			else if (event.keyCode == 38)
			{
				if (cadre.top)
				{
					str = cadre.top;
					str = str.substring(0, str.length - 2);
					str = parseInt(str);
					str > -height ? str -= 5 : str;
					cadre.top = str + "px";
				}
				else
					cadre.top = "-10px";
			}
			else if (event.keyCode == 40)
			{
				if (cadre.top)
				{
					str = cadre.top;
					str = str.substring(0, str.length - 2);
					str = parseInt(str);
					str < height ? str += 5 : str;
					cadre.top = str + "px";
				}
				else
					cadre.top = "10px";
			}
		});
	});
}

function save_picture(str)
{
	var cadre = document.getElementById('canvas');
	var cadre_tmp = document.getElementById('cadre_tmp').toDataURL("image/png");
	var image = document.getElementById('img_tmp').toDataURL("image/png");
	document.getElementById('canvas').style.display = "none";
	document.getElementById('save').style.display = "none";
	xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
		if (this.readyState == 4 && this.status == 200)
		{
			var success = document.createElement("div");
			if (this.responseText)
			{
				success.setAttribute("class", "success");
				success.innerText = "Montage enregistré avec succès";
				new_montage = document.createElement("img");
				new_montage.setAttribute("src", this.responseText);
				new_montage.setAttribute("class", "previous_img");
				document.getElementsByTagName('h3')[0].after(new_montage);
			}
			else
			{
				success.setAttribute("class", "error");
				success.innerText = "Le montage n'a pas été enregistrer";
			}
			document.getElementById('shoot').after(success);
			time();
		}
	};
	xhr.open("POST", "index.php?action=montage");
	xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	xhr.send('cadre=' + cadre_tmp + '&image=' + image + '&width=' + cadre.width + '&height=' + cadre.height + '&id='+ str);
}

function time()
{
	setTimeout(function()
			{
				if (document.getElementsByClassName("success")[0])
					document.getElementsByClassName("success")[0].style.display = "none";
				if (document.getElementsByClassName("error")[0])
					document.getElementsByClassName("error")[0].style.display = "none";
			}, 6000);
}

window.onload = function()
{
	setTimeout(function()
			{
				var i = 0;
				while (document.getElementsByClassName("error")[i])
				{
					document.getElementsByClassName("error")[i].style.display = "none    ";
					i++;
				}
			}, 6000);
}
