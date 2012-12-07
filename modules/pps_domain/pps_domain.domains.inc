<?php
/**
 * @file
 * pps_domain.domains.inc
 */

/**
 * Implements hook_domain_default_domains().
 */
function pps_domain_domain_default_domains() {
  $domains = array();
  $domains['wipe-domain-tables'] = 'wipe-domain-tables';
  $domains['partipirate_ch'] = array(
    'subdomain' => 'partipirate.ch',
    'sitename' => 'Parti Pirate Suisse',
    'scheme' => 'http',
    'valid' => '1',
    'weight' => '1',
    'is_default' => '0',
    'machine_name' => 'partipirate_ch',
  );
  $domains['partitopirata_ch'] = array(
    'subdomain' => 'partitopirata.ch',
    'sitename' => 'Partito Pirata Svizzero',
    'scheme' => 'http',
    'valid' => '1',
    'weight' => '2',
    'is_default' => '0',
    'machine_name' => 'partitopirata_ch',
  );
  $domains['piratenpartei_ch'] = array(
    'subdomain' => 'piratenpartei.ch',
    'sitename' => 'Piraten Partei Schweiz',
    'scheme' => 'http',
    'valid' => '1',
    'weight' => '-1',
    'is_default' => '1',
    'machine_name' => 'piratenpartei_ch',
  );

  return $domains;
}

/**
 * Implements hook_domain_alias_default_aliases().
 */
function pps_domain_domain_alias_default_aliases() {
  $domain_aliases = array();
  $domain_aliases['wipe-domain-tables'] = 'wipe-domain-tables';
  $domain_aliases['partipirate_ch'] = array(
    'partipirate.dev' => array(
      'pattern' => 'partipirate.dev',
      'redirect' => '0',
      'machine_name' => 'partipirate_ch',
    ),
  );
  $domain_aliases['partitopirata_ch'] = array(
    'partitopirata.dev' => array(
      'pattern' => 'partitopirata.dev',
      'redirect' => '0',
      'machine_name' => 'partitopirata_ch',
    ),
  );
  $domain_aliases['piratenpartei_ch'] = array(
    'piratenpartei.dev' => array(
      'pattern' => 'piratenpartei.dev',
      'redirect' => '0',
      'machine_name' => 'piratenpartei_ch',
    ),
    'pirateparty.ch' => array(
      'pattern' => 'pirateparty.ch',
      'redirect' => '1',
      'machine_name' => 'piratenpartei_ch',
    ),
  );

  return $domain_aliases;
}

/**
 * Implements hook_domain_conf_default_variables().
 */
function pps_domain_domain_conf_default_variables() {
  $domain_variables = array();
  $domain_variables['wipe-domain-tables'] = 'wipe-domain-tables';
  $domain_variables['partipirate_ch'] = array(
    'site_name' => 'Site-Install',
    'site_mail' => 'admin@example.com',
    'site_slogan' => '',
    'site_frontpage' => 'node',
    'anonymous' => 'Anonymous',
    'admin_theme' => 'seven',
    'date_default_timezone' => 'Europe/Zurich',
    'cache' => 0,
    'cache_lifetime' => '0',
    'maintenance_mode' => 0,
    'maintenance_mode_message' => 'Piraten Partei Schweiz is currently under maintenance. We should be back shortly. Thank you for your patience.',
    'language_default' => 'fr',
  );
  $domain_variables['partitopirata_ch'] = array(
    'site_name' => 'Site-Install',
    'site_mail' => 'admin@example.com',
    'site_slogan' => '',
    'site_frontpage' => 'node',
    'anonymous' => 'Anonymous',
    'admin_theme' => 'seven',
    'date_default_timezone' => 'Europe/Zurich',
    'cache' => 0,
    'cache_lifetime' => '0',
    'maintenance_mode' => 0,
    'maintenance_mode_message' => 'Piraten Partei Schweiz is currently under maintenance. We should be back shortly. Thank you for your patience.',
    'language_default' => 'it',
  );
  $domain_variables['piratenpartei_ch'] = array(
    'site_name' => 'Site-Install',
    'site_mail' => 'admin@example.com',
    'site_slogan' => '',
    'site_frontpage' => 'node',
    'anonymous' => 'Anonymous',
    'admin_theme' => 'seven',
    'date_default_timezone' => 'Europe/Zurich',
    'cache' => 0,
    'cache_lifetime' => '0',
    'maintenance_mode' => 0,
    'maintenance_mode_message' => 'Piraten Partei Schweiz is currently under maintenance. We should be back shortly. Thank you for your patience.',
    'language_default' => 'de',
  );

  return $domain_variables;
}

/**
 * Implements hook_domain_theme_default_themes().
 */
function pps_domain_domain_theme_default_themes() {
  $domain_themes = array();
  $domain_themes['wipe-domain-tables'] = 'wipe-domain-tables';
  $domain_themes['partipirate_ch'] = array(
    'bartik' => array(
      'theme' => 'bartik',
      'settings' => array(
        'toggle_logo' => 1,
        'toggle_name' => 1,
        'toggle_slogan' => 1,
        'toggle_node_user_picture' => 1,
        'toggle_comment_user_picture' => 1,
        'toggle_comment_user_verification' => 1,
        'toggle_favicon' => 1,
        'toggle_main_menu' => 1,
        'toggle_secondary_menu' => 1,
        'default_logo' => 1,
        'logo_path' => '',
        'logo_upload' => '',
        'default_favicon' => 1,
        'favicon_path' => '',
        'favicon_upload' => '',
        'scheme' => 'firehouse',
        'palette' => array(
          'top' => '#cd2d2d',
          'bottom' => '#cf3535',
          'bg' => '#ffffff',
          'sidebar' => '#f1f4f0',
          'sidebarborders' => '#ededed',
          'footer' => '#1f1d1c',
          'titleslogan' => '#fffeff',
          'text' => '#3b3b3b',
          'link' => '#d6121f',
        ),
        'theme' => 'bartik',
        'info' => array(
          'fields' => array(
            'top' => 'Header top',
            'bottom' => 'Header bottom',
            'bg' => 'Main background',
            'sidebar' => 'Sidebar background',
            'sidebarborders' => 'Sidebar borders',
            'footer' => 'Footer background',
            'titleslogan' => 'Title and slogan',
            'text' => 'Text color',
            'link' => 'Link color',
          ),
          'schemes' => array(
            'default' => array(
              'title' => 'Blue Lagoon (default)',
              'colors' => array(
                'top' => '#0779bf',
                'bottom' => '#48a9e4',
                'bg' => '#ffffff',
                'sidebar' => '#f6f6f2',
                'sidebarborders' => '#f9f9f9',
                'footer' => '#292929',
                'titleslogan' => '#fffeff',
                'text' => '#3b3b3b',
                'link' => '#0071B3',
              ),
            ),
            'firehouse' => array(
              'title' => 'Firehouse',
              'colors' => array(
                'top' => '#cd2d2d',
                'bottom' => '#cf3535',
                'bg' => '#ffffff',
                'sidebar' => '#f1f4f0',
                'sidebarborders' => '#ededed',
                'footer' => '#1f1d1c',
                'titleslogan' => '#fffeff',
                'text' => '#3b3b3b',
                'link' => '#d6121f',
              ),
            ),
            'ice' => array(
              'title' => 'Ice',
              'colors' => array(
                'top' => '#d0d0d0',
                'bottom' => '#c2c4c5',
                'bg' => '#ffffff',
                'sidebar' => '#ffffff',
                'sidebarborders' => '#cccccc',
                'footer' => '#24272c',
                'titleslogan' => '#000000',
                'text' => '#4a4a4a',
                'link' => '#019dbf',
              ),
            ),
            'plum' => array(
              'title' => 'Plum',
              'colors' => array(
                'top' => '#4c1c58',
                'bottom' => '#593662',
                'bg' => '#fffdf7',
                'sidebar' => '#edede7',
                'sidebarborders' => '#e7e7e7',
                'footer' => '#2c2c28',
                'titleslogan' => '#ffffff',
                'text' => '#301313',
                'link' => '#9d408d',
              ),
            ),
            'slate' => array(
              'title' => 'Slate',
              'colors' => array(
                'top' => '#4a4a4a',
                'bottom' => '#4e4e4e',
                'bg' => '#ffffff',
                'sidebar' => '#ffffff',
                'sidebarborders' => '#d0d0d0',
                'footer' => '#161617',
                'titleslogan' => '#ffffff',
                'text' => '#3b3b3b',
                'link' => '#0073b6',
              ),
            ),
            '' => array(
              'title' => 'Custom',
              'colors' => array(),
            ),
          ),
          'css' => array(
            0 => 'css/colors.css',
          ),
          'copy' => array(
            0 => 'logo.png',
          ),
          'gradients' => array(
            0 => array(
              'dimension' => array(
                0 => 0,
                1 => 0,
                2 => 0,
                3 => 0,
              ),
              'direction' => 'vertical',
              'colors' => array(
                0 => 'top',
                1 => 'bottom',
              ),
            ),
          ),
          'fill' => array(),
          'slices' => array(),
          'blend_target' => '#ffffff',
          'preview_css' => 'color/preview.css',
          'preview_js' => 'color/preview.js',
          'preview_html' => 'color/preview.html',
          'base_image' => 'color/base.png',
        ),
        'color_bartik_palette' => array(
          'top' => '#cd2d2d',
          'bottom' => '#cf3535',
          'bg' => '#ffffff',
          'sidebar' => '#f1f4f0',
          'sidebarborders' => '#ededed',
          'footer' => '#1f1d1c',
          'titleslogan' => '#fffeff',
          'text' => '#3b3b3b',
          'link' => '#d6121f',
        ),
        'color_bartik_stylesheets' => array(
          0 => 'public://color/bartik-01c86d5a/colors.css',
        ),
        'color_bartik_logo' => 'public://color/bartik-01c86d5a/logo.png',
        'color_bartik_files' => array(
          0 => 'public://color/bartik-01c86d5a/logo.png',
          1 => 'public://color/bartik-01c86d5a/colors.css',
        ),
      ),
      'status' => '1',
      'filepath' => 'bartik-01c86d5a',
    ),
  );
  $domain_themes['partitopirata_ch'] = array(
    'bartik' => array(
      'theme' => 'bartik',
      'settings' => array(
        'toggle_logo' => 1,
        'toggle_name' => 1,
        'toggle_slogan' => 1,
        'toggle_node_user_picture' => 1,
        'toggle_comment_user_picture' => 1,
        'toggle_comment_user_verification' => 1,
        'toggle_favicon' => 1,
        'toggle_main_menu' => 1,
        'toggle_secondary_menu' => 1,
        'default_logo' => 1,
        'logo_path' => '',
        'logo_upload' => '',
        'default_favicon' => 1,
        'favicon_path' => '',
        'favicon_upload' => '',
        'scheme' => 'plum',
        'palette' => array(
          'top' => '#4c1c58',
          'bottom' => '#593662',
          'bg' => '#fffdf7',
          'sidebar' => '#edede7',
          'sidebarborders' => '#e7e7e7',
          'footer' => '#2c2c28',
          'titleslogan' => '#ffffff',
          'text' => '#301313',
          'link' => '#9d408d',
        ),
        'theme' => 'bartik',
        'info' => array(
          'fields' => array(
            'top' => 'Header top',
            'bottom' => 'Header bottom',
            'bg' => 'Main background',
            'sidebar' => 'Sidebar background',
            'sidebarborders' => 'Sidebar borders',
            'footer' => 'Footer background',
            'titleslogan' => 'Title and slogan',
            'text' => 'Text color',
            'link' => 'Link color',
          ),
          'schemes' => array(
            'default' => array(
              'title' => 'Blue Lagoon (default)',
              'colors' => array(
                'top' => '#0779bf',
                'bottom' => '#48a9e4',
                'bg' => '#ffffff',
                'sidebar' => '#f6f6f2',
                'sidebarborders' => '#f9f9f9',
                'footer' => '#292929',
                'titleslogan' => '#fffeff',
                'text' => '#3b3b3b',
                'link' => '#0071B3',
              ),
            ),
            'firehouse' => array(
              'title' => 'Firehouse',
              'colors' => array(
                'top' => '#cd2d2d',
                'bottom' => '#cf3535',
                'bg' => '#ffffff',
                'sidebar' => '#f1f4f0',
                'sidebarborders' => '#ededed',
                'footer' => '#1f1d1c',
                'titleslogan' => '#fffeff',
                'text' => '#3b3b3b',
                'link' => '#d6121f',
              ),
            ),
            'ice' => array(
              'title' => 'Ice',
              'colors' => array(
                'top' => '#d0d0d0',
                'bottom' => '#c2c4c5',
                'bg' => '#ffffff',
                'sidebar' => '#ffffff',
                'sidebarborders' => '#cccccc',
                'footer' => '#24272c',
                'titleslogan' => '#000000',
                'text' => '#4a4a4a',
                'link' => '#019dbf',
              ),
            ),
            'plum' => array(
              'title' => 'Plum',
              'colors' => array(
                'top' => '#4c1c58',
                'bottom' => '#593662',
                'bg' => '#fffdf7',
                'sidebar' => '#edede7',
                'sidebarborders' => '#e7e7e7',
                'footer' => '#2c2c28',
                'titleslogan' => '#ffffff',
                'text' => '#301313',
                'link' => '#9d408d',
              ),
            ),
            'slate' => array(
              'title' => 'Slate',
              'colors' => array(
                'top' => '#4a4a4a',
                'bottom' => '#4e4e4e',
                'bg' => '#ffffff',
                'sidebar' => '#ffffff',
                'sidebarborders' => '#d0d0d0',
                'footer' => '#161617',
                'titleslogan' => '#ffffff',
                'text' => '#3b3b3b',
                'link' => '#0073b6',
              ),
            ),
            '' => array(
              'title' => 'Custom',
              'colors' => array(),
            ),
          ),
          'css' => array(
            0 => 'css/colors.css',
          ),
          'copy' => array(
            0 => 'logo.png',
          ),
          'gradients' => array(
            0 => array(
              'dimension' => array(
                0 => 0,
                1 => 0,
                2 => 0,
                3 => 0,
              ),
              'direction' => 'vertical',
              'colors' => array(
                0 => 'top',
                1 => 'bottom',
              ),
            ),
          ),
          'fill' => array(),
          'slices' => array(),
          'blend_target' => '#ffffff',
          'preview_css' => 'color/preview.css',
          'preview_js' => 'color/preview.js',
          'preview_html' => 'color/preview.html',
          'base_image' => 'color/base.png',
        ),
        'color_bartik_palette' => array(
          'top' => '#4c1c58',
          'bottom' => '#593662',
          'bg' => '#fffdf7',
          'sidebar' => '#edede7',
          'sidebarborders' => '#e7e7e7',
          'footer' => '#2c2c28',
          'titleslogan' => '#ffffff',
          'text' => '#301313',
          'link' => '#9d408d',
        ),
        'color_bartik_stylesheets' => array(
          0 => 'public://color/bartik-6f33bc0f/colors.css',
        ),
        'color_bartik_logo' => 'public://color/bartik-6f33bc0f/logo.png',
        'color_bartik_files' => array(
          0 => 'public://color/bartik-6f33bc0f/logo.png',
          1 => 'public://color/bartik-6f33bc0f/colors.css',
        ),
      ),
      'status' => '1',
      'filepath' => 'bartik-6f33bc0f',
    ),
  );
  $domain_themes['piratenpartei_ch'] = array();

  return $domain_themes;
}
