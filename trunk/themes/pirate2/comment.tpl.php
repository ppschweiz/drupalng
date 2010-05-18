<?php
// $Id: comment.tpl.php,v 1.3 2008/09/14 12:09:37 johnalbin Exp $

/**
 * @file comment.tpl.php
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $classes: A set of CSS classes for the DIV wrapping the comment.
     Possible values are: comment, comment-new, comment-preview,
     comment-unpublished, comment-published, odd, even, first, last,
     comment-by-anon, comment-by-author, or comment-mine.
 * - $content: Body of the post.
 * - $date: Date and time of posting.
 * - $links: Various operational links.
 * - $new: New comment marker.
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $submitted: By line with date and time.
 * - $title: Linked title.
 * - $unpublished: Is the comment unpublished?
 *
 * These two variables are provided for context.
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * @see template_preprocess_comment()
 * @see theme_comment()
 */
?>
<ul class="comment">
    <li class="cotermin">
        <h4><?=$month?></h4>
        <h5><?=$day?></h5>
    </li>
    <li class="cotext">
        <span class="user"><?=$author?></span>
        <h1><?= $title ?></h1>
        <?= $content ?>
        <div class="cofoleft">
           <span class="date"><?= $date ?></span>
        </div>
		<?php if ($picture): ?>
			<?php print $picture ?>
		<?php endif; ?>
    </li>
    <li class="clear"/>
</ul>
