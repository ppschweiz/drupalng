<?php
/**
 * @file
 * pps_domain.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function pps_domain_variable_realm_default_variables() {
$realm_variables = array();
  $realm_variables['domain']['partipirate_ch'] = array();
  $realm_variables['domain']['partitopirata_ch'] = array();
  $realm_variables['domain']['piratenpartei_ch'] = array();

return $realm_variables;
}
