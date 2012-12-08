<?php
/**
 * @file
 * pps_content_types.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pps_content_types_taxonomy_default_vocabularies() {
  return array(
    'media_companies' => array(
      'name' => 'Media Companies',
      'machine_name' => 'media_companies',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
