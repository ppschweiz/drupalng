<?php
/**
 * @file
 * pirate_party_switzerland_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pirate_party_switzerland_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "resp_img" && $api == "default_resp_img_suffixs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pirate_party_switzerland_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pirate_party_switzerland_feature_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: action_buttons
  $nodequeues['action_buttons'] = array(
    'qid' => '1',
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

  // Exported nodequeues: slides
  $nodequeues['slides'] = array(
    'qid' => '2',
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
      1 => 'press_review',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function pirate_party_switzerland_feature_image_default_styles() {
  $styles = array();

  // Exported image style: action_button.
  $styles['action_button'] = array(
    'name' => 'action_button',
    'effects' => array(
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '92',
          'height' => '83',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: slide_image_desktop.
  $styles['slide_image_desktop'] = array(
    'name' => 'slide_image_desktop',
    'effects' => array(
      13 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '800',
          'height' => '249',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: slide_image_mobileland.
  $styles['slide_image_mobileland'] = array(
    'name' => 'slide_image_mobileland',
    'effects' => array(
      10 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '480',
          'height' => '249',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: slide_image_mobileport.
  $styles['slide_image_mobileport'] = array(
    'name' => 'slide_image_mobileport',
    'effects' => array(
      9 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '340',
          'height' => '249',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: slide_image_tabletland.
  $styles['slide_image_tabletland'] = array(
    'name' => 'slide_image_tabletland',
    'effects' => array(
      11 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '684',
          'height' => '249',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: slide_image_tabletport.
  $styles['slide_image_tabletport'] = array(
    'name' => 'slide_image_tabletport',
    'effects' => array(
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '768',
          'height' => '249',
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
function pirate_party_switzerland_feature_node_info() {
  $items = array(
    'action_button' => array(
      'name' => t('Action Button'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'press_review' => array(
      'name' => t('Press Review'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
