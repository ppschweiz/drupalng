<?php
// $Id: block.tpl.php,v 1.3 2007/08/07 08:39:36 goba Exp $
?>
	<?php if ($block->module == 'pirate_slider' || $block->module == 'pirate_actionbutton') { ?>
		<?php print $block->content; ?>
	<?php } else if ($is_front && $block->delta == view) { ?>
		$view_id = explode("-",$block->delta);
		$view = views_get_view($view_id[0]);

		print_r($view['display']);
	
		<div class="kopf block block-<?php print $block->module; ?>" id="block-<?php print $block->module; ?>-<?php print $block->delta; ?>">
			<a class="goto" href=""></a>
			<a class="rss" href=""></a>
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

