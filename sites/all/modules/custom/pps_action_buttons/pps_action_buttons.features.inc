<?php
/**
 * @file
 * pps_action_buttons.features.inc
 */

/**
 * Implements hook_views_api().
 */
function pps_action_buttons_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pps_action_buttons_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: action_buttons
  $nodequeues['action_buttons'] = array(
    'qid' => '2',
    'name' => 'action_buttons',
    'title' => 'Action Buttons',
    'subqueue_title' => '',
    'size' => '3',
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
      0 => 'action_button',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function pps_action_buttons_image_default_styles() {
  $styles = array();

  // Exported image style: action_button.
  $styles['action_button'] = array(
    'name' => 'action_button',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '83',
          'height' => '83',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function pps_action_buttons_node_info() {
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
