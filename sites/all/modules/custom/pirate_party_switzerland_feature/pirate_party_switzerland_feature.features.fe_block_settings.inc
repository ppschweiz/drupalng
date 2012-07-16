<?php
/**
 * @file
 * pirate_party_switzerland_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function pirate_party_switzerland_feature_default_fe_block_settings() {
  $export = array();

  // pps_default
  $theme = array();

  $theme['search-form'] = array(
    'module' => 'search',
    'delta' => 'form',
    'theme' => 'pps_default',
    'status' => '1',
    'weight' => '-8',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-login'] = array(
    'module' => 'user',
    'delta' => 'login',
    'theme' => 'pps_default',
    'status' => '1',
    'weight' => '-6',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-action_buttons-block'] = array(
    'module' => 'views',
    'delta' => 'action_buttons-block',
    'theme' => 'pps_default',
    'status' => '1',
    'weight' => '-11',
    'region' => 'tertiary_content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-slider-block'] = array(
    'module' => 'views',
    'delta' => 'slider-block',
    'theme' => 'pps_default',
    'status' => '1',
    'weight' => '-11',
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

  $theme['search-form'] = array(
    'module' => 'search',
    'delta' => 'form',
    'theme' => 'seven',
    'status' => '1',
    'weight' => '-10',
    'region' => 'dashboard_sidebar',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-login'] = array(
    'module' => 'user',
    'delta' => 'login',
    'theme' => 'seven',
    'status' => '1',
    'weight' => '10',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-action_buttons-block'] = array(
    'module' => 'views',
    'delta' => 'action_buttons-block',
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

  $theme['views-slider-block'] = array(
    'module' => 'views',
    'delta' => 'slider-block',
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
