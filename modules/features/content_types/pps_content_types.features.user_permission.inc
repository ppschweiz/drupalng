<?php
/**
 * @file
 * pps_content_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pps_content_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: access comments.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(),
    'module' => 'comment',
  );

  return $permissions;
}
