<?php
/**
 * @file
 * pps_block.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function pps_block_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['locale-language'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'language',
    'module' => 'locale',
    'node_types' => array(),
    'pages' => '',
    'themes' => array(
      'pps_theme_base' => array(
        'region' => 'leaderboard',
        'status' => '1',
        'theme' => 'pps_theme_base',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['menu-menu-interlinks'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'menu-interlinks',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'themes' => array(
      'pps_theme_base' => array(
        'region' => 'leaderboard',
        'status' => '1',
        'theme' => 'pps_theme_base',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['system-powered-by'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'powered-by',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'themes' => array(
      'pps_theme_base' => array(
        'region' => 'footer',
        'status' => '1',
        'theme' => 'pps_theme_base',
        'weight' => '10',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
