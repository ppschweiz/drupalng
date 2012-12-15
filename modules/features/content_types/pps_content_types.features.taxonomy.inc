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
    'event_types' => array(
      'name' => 'Event Types',
      'machine_name' => 'event_types',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-9',
    ),
    'media_companies' => array(
      'name' => 'Media Companies',
      'machine_name' => 'media_companies',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-8',
    ),
    'structure' => array(
      'name' => 'Site Structure',
      'machine_name' => 'structure',
      'description' => 'Vocabulary created automatically by Taxonomy csv import/export module',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-10',
    ),
  );
}
