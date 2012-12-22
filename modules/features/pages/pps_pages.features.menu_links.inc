<?php
/**
 * @file
 * pps_pages.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function pps_pages_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:interactive
  $menu_links['main-menu:interactive'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'interactive',
    'router_path' => 'interactive',
    'link_title' => 'Interactive',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'menu-icon-hat',
        ),
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: main-menu:latest
  $menu_links['main-menu:latest'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'latest',
    'router_path' => 'latest',
    'link_title' => 'Latest',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'menu-icon-telescope',
        ),
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: main-menu:pirates
  $menu_links['main-menu:pirates'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'pirates',
    'router_path' => 'pirates',
    'link_title' => 'The Pirates',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'menu-icon-helm',
        ),
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: main-menu:positions
  $menu_links['main-menu:positions'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'positions',
    'router_path' => 'positions',
    'link_title' => 'Positions',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'menu-icon-compass',
        ),
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: main-menu:press
  $menu_links['main-menu:press'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'press',
    'router_path' => 'press',
    'link_title' => 'Press',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'menu-icon-bottle',
        ),
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Interactive');
  t('Latest');
  t('Positions');
  t('Press');
  t('The Pirates');


  return $menu_links;
}
