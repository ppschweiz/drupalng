<?php
/**
 * @file
 * pps_action_buttons.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function pps_action_buttons_default_fe_block_settings() {
  $export = array();

  // pps_default
  $theme = array();

  $theme['views-action_buttons-block'] = array(
    'module' => 'views',
    'delta' => 'action_buttons-block',
    'theme' => 'pps_default',
    'status' => '1',
    'weight' => '0',
    'region' => 'tertiary_content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => -1,
  );

  $export['pps_default'] = $theme;

  // seven
  $theme = array();

  $theme['views-action_buttons-block'] = array(
    'module' => 'views',
    'delta' => 'action_buttons-block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => -1,
  );

  $export['seven'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
