<?php
// $Id: block.tpl.php,v 1.3 2007/08/07 08:39:36 goba Exp $
?>
	<?php  print $id.":".$block->module."<=>".$block->region; print_r(views_get_view($block->name)); ?>
	<?php if ($block->module == 'pirate_slider' || $block->module == 'pirate_actionbutton') { ?>
		<?php print $block->content; ?>
	<?php } else if ($is_front) { ?>
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

