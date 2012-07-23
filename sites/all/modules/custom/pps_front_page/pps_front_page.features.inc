<?php
/**
 * @file
 * pps_front_page.features.inc
 */

/**
 * Implements hook_views_api().
 */
function pps_front_page_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pps_front_page_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: highlighted
  $nodequeues['highlighted'] = array(
    'qid' => '1',
    'name' => 'highlighted',
    'title' => 'Highlighted',
    'subqueue_title' => '',
    'size' => '4',
    'link' => 'Highlight',
    'link_remove' => 'Remove highlight',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '1',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'article',
      1 => 'page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
