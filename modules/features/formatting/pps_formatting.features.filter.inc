<?php
/**
 * @file
 * pps_formatting.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function pps_formatting_filter_default_formats() {
  $formats = array();

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => '1',
    'status' => '1',
    'weight' => '10',
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '1',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Textile.
  $formats['textile'] = array(
    'format' => 'textile',
    'name' => 'Textile',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_html' => array(
        'weight' => '-50',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'textile' => array(
        'weight' => '-46',
        'status' => '1',
        'settings' => array(
          'textile_tags' => 0,
        ),
      ),
      'filter_url' => array(
        'weight' => '-45',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
    ),
  );

  return $formats;
}
