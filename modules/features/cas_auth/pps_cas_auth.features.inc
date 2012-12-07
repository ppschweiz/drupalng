<?php
/**
 * @file
 * pps_cas_auth.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pps_cas_auth_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
