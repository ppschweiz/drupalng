<?php
// $Id: block.tpl.php,v 1.3 2007/08/07 08:39:36 goba Exp $
?>
	<?php if ($is_front) { ?>
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

