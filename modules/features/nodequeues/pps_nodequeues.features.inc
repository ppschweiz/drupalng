<?php
/**
 * @file
 * pps_nodequeues.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pps_nodequeues_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pps_nodequeues_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: highlighted
  $nodequeues['highlighted'] = array(
    'name' => 'highlighted',
    'title' => 'Highlighted',
    'subqueue_title' => '',
    'size' => '2',
    'link' => 'Add to Hotspot',
    'link_remove' => 'Remove from Hotspot',
    'owner' => 'smartqueue_domain',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '1',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'types' => array(
      0 => 'article',
      1 => 'communique',
      2 => 'event',
      3 => 'press_review',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
