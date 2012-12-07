<?php

/**
 * @file
 * Drupal settings
 */

/**
 * Database
 */
$databases = array (
  'default' => array (
    'default' => array (
      'database' => 'drupal',
      'username' => 'drupal',
      'password' => '',
      'host' => '127.0.0.1',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

/**
 * No access to update.php
 */
$update_free_access = FALSE;

/**
 * Salt for one-time login links and cancel links, form tokens, etc.
 */
$drupal_hash_salt = 'EqplikHf17BrH6COUStvPOttilhlUKz4XkmuliLhbXQ';

/**
 * PHP settings:
 */

/**
 * Ensure garbage collection is enabled
 */
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);

/**
 * Set session lifetime (in seconds)
 */
ini_set('session.gc_maxlifetime', 200000);

/**
 * Set session cookie lifetime (in seconds)
 */
ini_set('session.cookie_lifetime', 2000000);

/**
 * Variable overrides:
 */
// admin/appearance
$conf['admin_theme'] = 'seven';

// Misc
$conf['maintenance_theme'] = 'seven';

/**
 * Reverse Proxy Configuration:
 */
# $conf['reverse_proxy'] = TRUE;
# $conf['reverse_proxy_addresses'] = array('a.b.c.d', ...);
# $conf['reverse_proxy_header'] = 'HTTP_X_CLUSTER_CLIENT_IP';


/**
 * String overrides:
 */
# $conf['locale_custom_strings_en'][''] = array(
#   'forum'      => 'Discussion board',
#   '@count min' => '@count minutes',
# );

/**
 *
 * IP blocking:
 */
$conf['blocked_ips'] = array();

/**
 * Fast 404 pages:
 */
$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';

/**
 * No file system operations
 */
$conf['allow_authorize_operations'] = FALSE;

/**
 * Allow environment specific overrides
 */
$local_settings_filename = dirname(__FILE__) . DIRECTORY_SEPARATOR . 'local.settings.php';
if (file_exists($local_settings_filename)) {
  require_once $local_settings_filename;
}

$conf['install_profile'] = 'minimal';
