<?php
/**
 * @file
 * pps_block.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function pps_block_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-interlinks.
  $menus['menu-interlinks'] = array(
    'menu_name' => 'menu-interlinks',
    'title' => 'Interlinks',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Interlinks');


  return $menus;
}
