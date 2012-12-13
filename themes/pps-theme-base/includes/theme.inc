<?php

/**
 * @file
 * Custom theme functions and theme function overrides.
 */

/**
 * Overrides theme_links()
 *
 * Add icon class to certain links.
 *
 * @todo: Make mapping configurable.
 */
function pps_theme_base_links($vars) {
  $mappings = array(
    'node-readmore' => 'icon-eye',
    'comment-add' => 'icon-comment',
  );

  foreach ($vars['links'] as $key => $link) {
    if (array_key_exists($key, $mappings)) {
      $vars['links'][$key]['attributes']['class'][] = $mappings[$key];
    }
  }

  return adaptivetheme_links($vars);
}
