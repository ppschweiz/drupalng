<?php
/**
 * @file
 * pps_action_buttons_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function pps_action_buttons_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function pps_action_buttons_feature_node_info() {
  $items = array(
    'action_button' => array(
      'name' => t('Action Button'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
