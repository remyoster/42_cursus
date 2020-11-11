$(document).ready(function ()
		{
			var ft_list = $('#ft_list');
			var master = $('#new');

			function add_note()
			{
				var quest = prompt("Please add a Todo franck");
				if (quest)
				{
					var i =0;
					var new_div = $('<div>'+quest+'</div>');
					ft_list.prepend(new_div);
				}
			}

			master.on({
				click: function (){add_note()}});
		});
