<?php
/**
 * @file
 * pps_block.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function pps_block_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-interlinks:http://chat.piratenpartei.ch/?channels=pps
  $menu_links['menu-interlinks:http://chat.piratenpartei.ch/?channels=pps'] = array(
    'menu_name' => 'menu-interlinks',
    'link_path' => 'http://chat.piratenpartei.ch/?channels=pps',
    'router_path' => '',
    'link_title' => 'Chat',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-interlinks:http://forum.piratenpartei.ch
  $menu_links['menu-interlinks:http://forum.piratenpartei.ch'] = array(
    'menu_name' => 'menu-interlinks',
    'link_path' => 'http://forum.piratenpartei.ch',
    'router_path' => '',
    'link_title' => 'Forum',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-interlinks:https://projects.piratenpartei.ch/
  $menu_links['menu-interlinks:https://projects.piratenpartei.ch/'] = array(
    'menu_name' => 'menu-interlinks',
    'link_path' => 'https://projects.piratenpartei.ch/',
    'router_path' => '',
    'link_title' => 'Internal colaboration',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Chat');
  t('Forum');
  t('Internal colaboration');


  return $menu_links;
}
