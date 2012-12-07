<?php
/**
 * @file
 * pps_domain.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pps_domain_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_force_admin';
  $strongarm->value = '1';
  $export['domain_force_admin'] = $strongarm;

  return $export;
}
