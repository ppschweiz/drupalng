<?php
/**
 * @file
 * pps_content.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function pps_content_filter_default_formats() {
  $formats = array();

  // Exported format: Textile.
  $formats['textile'] = array(
    'format' => 'textile',
    'name' => 'Textile',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'textile' => array(
        'weight' => '-44',
        'status' => '1',
        'settings' => array(
          'textile_tags' => 0,
        ),
      ),
    ),
  );

  return $formats;
}
