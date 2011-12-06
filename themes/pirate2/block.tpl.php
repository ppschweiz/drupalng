<?php
// $Id: block.tpl.php,v 1.3 2007/08/07 08:39:36 goba Exp $
?>
	<?php if ($block->module == 'pirate_slider' || $block->module == 'pirate_actionbutton') { ?>
		<?php print $block->content; ?>
	<?php } else if ($is_front && $block->module == 'views') { 
		
		$view_id = explode("-",$block->delta);
		$view = views_get_view($view_id[0]);

		foreach($view->display as $display) 
		{
			if ($display->display_plugin == 'page' || $display->display_plugin == 'calendar') 
			{
				$pageurl = $display->display_options['path']; 
			}
			if ($display->display_plugin == 'feed' || $display->display_plugin == 'calendar_ical') 
			{
				$feedurl = $display->display_options['path']; 
			}
		}		
	?>
		<div class="kopf block block-<?php print $block->module; ?>" id="block-<?php print $block->module; ?>-<?php print $block->delta; ?>">
			<a class="goto" href="<?php print $pageurl; ?>"></a>
			<a class="rss" href="<?php print $feedurl; ?>"></a>
			<h1><?php print $block->subject; ?></h1>
			<div class="content">
				<?php print $block->content; ?>
			</div>
		</div>
	<?php } else { ?>
		<div class="content">
			<?php print $block->content; ?>
		</div>
	<?php }?>

