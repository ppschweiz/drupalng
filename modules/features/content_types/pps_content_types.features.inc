<?php
/**
 * @file
 * pps_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pps_content_types_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pps_content_types_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Artikel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'ballot' => array(
      'name' => t('Ballot vote'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'communique' => array(
      'name' => t('Communiqué'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'gallery' => array(
      'name' => t('Image Gallery'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'minutes' => array(
      'name' => t('Minutes'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'newsletter' => array(
      'name' => t('Message in a bottle'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'position' => array(
      'name' => t('Political position'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'press_review' => array(
      'name' => t('Press Review'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
    'team' => array(
      'name' => t('Team page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
