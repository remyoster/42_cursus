$(document).ready(function()
{
  var i = 0;
  if ((tab = getCookie()) != null)
  {
    var c = tab.length;
    var j = 0;
    var max = 0;
    while (j < c)
    {
      var div = tab[j].split('=');
      var new_div = $('<div>'+div[1]+'</div>');
      var pass = parseInt(div[0]);
      if (max < pass)
      {
        max = pass;
      }
      new_div.attr('id', pass);
      new_div.on({
         click: function(){del(pass)}});
      $('#ft_list').prepend(new_div);
      j++;
    }
    i = max + 1;
  }
  $('#new').click(function()
		  {
    var quest = prompt("Entrez votre nouveau Todo");
	if (quest.trim() && quest)
	{
      var new_div = $('<div>'+quest+'</div>');
      new_div.attr('id', i);
      new_div.on({
         click: function(){del(i)}});
      $('#ft_list').prepend(new_div);
      setCookie(i, quest, 30);
      i++;
    }
  });

  function del(e) 
  {
    if (confirm('Voulez vous vraiment supprimer?'))
    {
      $('#e').empty();
      deleteCookie(e);
      location.reload(true);
    }
  }

  function setCookie(id, value, exdays) 
  {
    var d = new Date();
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    var expires = "expires="+ d.toGMTString();
    document.cookie = id + "=" + value + ";" + expires + ";path=/";
  }

  function getCookie()
  {
    if (document.cookie.length > 0) {
      var tab = document.cookie.split(';');
      return (tab);
    }
  }

  function deleteCookie(id) 
  {
    document.cookie = id+"= ;"+"expires=Thu, 01 Jan 1970 00:00:00 GMT;path=/";
  }
});
