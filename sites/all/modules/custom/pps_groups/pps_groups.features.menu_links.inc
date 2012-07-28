<?php
/**
 * @file
 * pps_groups.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function pps_groups_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:groups/board
  $menu_links['main-menu:groups/board'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'groups/board',
    'router_path' => 'groups',
    'link_title' => 'Boards',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: main-menu:groups/comitee
  $menu_links['main-menu:groups/comitee'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'groups/comitee',
    'router_path' => 'groups',
    'link_title' => 'Comitees',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: main-menu:groups/workgroup
  $menu_links['main-menu:groups/workgroup'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'groups/workgroup',
    'router_path' => 'groups',
    'link_title' => 'Workgroups',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Boards');
  t('Comitees');
  t('Workgroups');


  return $menu_links;
}
