<?php
// $Id: node.tpl.php,v 1.4.2.1 2009/05/12 18:41:54 johnalbin Exp $

/**
 * @file node.tpl.php
 *
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $picture: The authors picture of the node output from
 *   theme_user_picture().
 * - $date: Formatted creation date (use $created to reformat with
 *   format_date()).
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $name: Themed username of node author output from theme_user().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $submitted: themed submission information output from
 *   theme_node_submitted().
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $teaser: Flag for the teaser state.
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 */
?>
<?php if (!$teaser): ?>
	<div class="contbody">
<?php endifif;?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">
	<div class="node-inner">
		<?php if ($node->type != 'page') { ?>
			<ul>
				<li class="cotermin">
					<h4><?php print $month ?></h4>
					<h5><?php print $day ?></h5>
				</li>
				<?php if (!$page) { ?>
					<li class="cotext">
						<h1 class="title">
							<a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a>
						</h1>
						<?php print $content; ?>
					</li>
					<li class="cogoto">
					</li>
				<?php } else { ?>
					<li class="cotext">
						<div class="title">
							<h1 class="title">
								<?php print $title; ?>
							</h1>
						</div>
						<div class="author"><?php print $name; ?></div>
						<div class="clear"></div>
						<?php print $content; ?>
					</li>
				<?php } ?>
				<li class="clear"></li>
			</ul>
		<?php } else { ?>
			<h2 class="title">
				<a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a>
			</h2>
			<div class="content">
				<?php print $content; ?>
			</div>
		<?php } ?>		
	</div>
</div>
<?php if (!$teaser): ?>
	</div>
<?php endifif;?>

<?php if ($page): ?>
	<?php //if ($submitted || $terms): ?>
	<?php if ($terms): ?>
		<div class="meta">
			<?php if ($terms): ?>
				<div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
			<?php endif; ?>
		</div>
	<?php endif; ?>
	<?php print $links; ?>
<?php endif; ?>
 <!-- /node-inner, /node -->
