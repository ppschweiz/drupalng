<?php do { list($key, $val) = each($menu); } while( $val && !$val['link']['in_active_trail'] ); ?>
<? if ($val) { recursive_subnavigation($val, 0); } ?>

<?php
        function recursive_subnavigation($submenu, $level)
        {
		if($submenu)
		{
			print ($level == 0) ? "<ul class=\"cosubnav\">" : "<ul>";
			$active = ($submenu['link']['in_active_trail'] && !is_sub_active($submenu['below'])) ? " class=\"aktiv\"" : "";
			
			print "<li".$active.">";
			print l($submenu['link']['title'], $submenu['link']['href']);
			print "</li>";
			foreach($submenu['below'] as $menuitem) 
			{
				recursive_subnavigation($menuitem, $level + 1);
			}
			print "</ul>";
		}
	}

	function is_sub_active($submenu) 
	{
		foreach($submenu as $menuitem) 
		{
			if($menuitem['link']['in_active_trail'])
				return 1;
		}
		return 0;
	}
?>
