<?php
/**
 * @file
 * pps_slider.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function pps_slider_default_fe_block_settings() {
  $export = array();

  // pps_default
  $theme = array();

  $theme['views-slides-block'] = array(
    'module' => 'views',
    'delta' => 'slides-block',
    'theme' => 'pps_default',
    'status' => '1',
    'weight' => '0',
    'region' => 'header',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => -1,
  );

  $export['pps_default'] = $theme;

  // seven
  $theme = array();

  $theme['views-slides-block'] = array(
    'module' => 'views',
    'delta' => 'slides-block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
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
