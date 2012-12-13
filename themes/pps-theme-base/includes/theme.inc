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
    'comment-add' => 'icon-chat',
    'comment-comments' => 'icon-comment',
    'comment-delete' => 'icon-trashcan',
    'comment-edit' => 'icon-pencil',
    'comment-reply' => 'icon-chat',
  );

  foreach ($vars['links'] as $key => $link) {
    if (array_key_exists($key, $mappings)) {
      $vars['links'][$key]['attributes']['class'][] = $mappings[$key];
    }
  }
  return adaptivetheme_links($vars);
}

/**
 * Overrides theme_menu_local_task()
 *
 * Add icon class to links.
 */
function pps_theme_base_menu_local_task($vars) {
  $mappings = array(
    'node/%/view' => 'icon-eye',
    'node/%/edit' => 'icon-pencil',
    'node/%/devel' => 'icon-wrench',
  );
  $path = !empty($vars['element']['#link']['path']) ? $vars['element']['#link']['path'] : NULL;
  if (array_key_exists($path, $mappings)) {
    $vars['element']['#link']['localized_options']['attributes']['class'][] = $mappings[$path];
  }
  return theme_menu_local_task($vars);
}