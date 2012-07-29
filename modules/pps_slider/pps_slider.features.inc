<?php
/**
 * @file
 * pps_slider.features.inc
 */

/**
 * Implements hook_views_api().
 */
function pps_slider_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pps_slider_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: slides
  $nodequeues['slides'] = array(
    'qid' => '3',
    'name' => 'slides',
    'title' => 'Slides',
    'subqueue_title' => '',
    'size' => '0',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
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
