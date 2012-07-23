<?php
/**
 * @file
 * pps_front_page.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function pps_front_page_default_fe_block_settings() {
  $export = array();

  // pps_default
  $theme = array();

  $theme['views-front_page-highlighted'] = array(
    'module' => 'views',
    'delta' => 'front_page-highlighted',
    'theme' => 'pps_default',
    'status' => '1',
    'weight' => '0',
    'region' => 'highlighted',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-front_page-promoted'] = array(
    'module' => 'views',
    'delta' => 'front_page-promoted',
    'theme' => 'pps_default',
    'status' => '1',
    'weight' => '-10',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-front_page-sticky'] = array(
    'module' => 'views',
    'delta' => 'front_page-sticky',
    'theme' => 'pps_default',
    'status' => '1',
    'weight' => '-11',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => -1,
  );

  $export['pps_default'] = $theme;

  // seven
  $theme = array();

  $theme['views-front_page-highlighted'] = array(
    'module' => 'views',
    'delta' => 'front_page-highlighted',
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

  $theme['views-front_page-promoted'] = array(
    'module' => 'views',
    'delta' => 'front_page-promoted',
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

  $theme['views-front_page-sticky'] = array(
    'module' => 'views',
    'delta' => 'front_page-sticky',
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
