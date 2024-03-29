<?php
/**
 * @file
 * Adativetheme implementation to present a Panels layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout.
 * - $css_id: unique id if present.
 * - $panel_prefix: prints a wrapper when this template is used in certain context,
 *   such as when rendered by Display Suite or other module - the wrapper is
 *   added by Adaptivetheme in the appropriate process function.
 * - $panel_suffix: closing element for the $prefix.
 *
 * @see adaptivetheme_preprocess_three_3x33()
 * @see adaptivetheme_preprocess_node()
 * @see adaptivetheme_process_node()
 */

// Ensure variables are always set. These are not set when inside a
// Field Collection using Display Suite, even though they are
// initialized in the templates preprocess function.
// This is a workaround, that may or may not go away.
$panel_prefix = isset($panel_prefix) ? $panel_prefix : '';
$panel_suffix = isset($panel_suffix) ? $panel_suffix : '';
?>
<?php print $panel_prefix; ?>
<div class="at-panel panel-display two_tree_two clearfix" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>

  <?php if ($content['two_tree_two_above_first'] || $content['two_tree_two_above_second']): ?>
    <div class="region region-two-tree-two-above-first">
        <div class="region-inner clearfix">
          <?php print $content['two_tree_two_above_first']; ?>
        </div>
    </div>
    <div class="region region-two-tree-two-above-second">
        <div class="region-inner clearfix">
          <?php print $content['two_tree_two_above_second']; ?>
        </div>
    </div>
  <?php endif; ?>

  <div class="region region-two-tree-two-first">
    <div class="region-inner clearfix">
      <?php print $content['two_tree_two_first']; ?>
    </div>
  </div>
  <div class="region region-two-tree-two-second">
    <div class="region-inner clearfix">
      <?php print $content['two_tree_two_second']; ?>
    </div>
  </div>
  <div class="region region-two-tree-two-third">
    <div class="region-inner clearfix">
      <?php print $content['two_tree_two_third']; ?>
    </div>
  </div>

  <?php if ($content['two_tree_two_below_first'] || $content['two_tree_two_below_second']): ?>
    <div class="region region-two-tree-two-first">
        <div class="region-inner clearfix">
          <?php print $content['two_tree_two_below_first']; ?>
        </div>
    </div>
    <div class="region region-two-tree-two-second">
        <div class="region-inner clearfix">
          <?php print $content['two_tree_two_below_second']; ?>
        </div>
    </div>
  <?php endif; ?>
</div>
<?php print $panel_suffix; ?>
