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
  $domain_aliases['piratenpartei_ch'] = array(
    'piratenpartei.dev' => array(
      'pattern' => 'piratenpartei.dev',
      'redirect' => '0',
      'machine_name' => 'piratenpartei_ch',
    ),
    'd7.piratenpartei.ch' => array(
      'pattern' => 'd7.piratenpartei.ch',
      'redirect' => '0',
      'machine_name' => 'piratenpartei_ch',
    ),
    'partipirate.ch' => array(
      'pattern' => 'partipirate.ch',
      'redirect' => '0',
      'machine_name' => 'piratenpartei_ch',
    ),
    'partitopirata.ch' => array(
      'pattern' => 'partitopirata.ch',
      'redirect' => '0',
      'machine_name' => 'piratenpartei_ch',
    ),
    'pirateparty.ch' => array(
      'pattern' => 'pirateparty.ch',
      'redirect' => '0',
      'machine_name' => 'piratenpartei_ch',
    ),
    'partipirate.dev' => array(
      'pattern' => 'partipirate.dev',
      'redirect' => '0',
      'machine_name' => 'piratenpartei_ch',
    ),
    'partitopirata.dev' => array(
      'pattern' => 'partitopirata.dev',
      'redirect' => '0',
      'machine_name' => 'piratenpartei_ch',
    ),
    'pirateparty.dev' => array(
      'pattern' => 'pirateparty.dev',
      'redirect' => '0',
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
  $domain_variables['piratenpartei_ch'] = array(
    'site_name' => 'Piratenpartei Schweiz»',
    'site_mail' => 'admin@example.com',
    'site_slogan' => 'Nullam quis risus eget urna mollis ornare vel eu leo.',
    'site_frontpage' => 'front',
    'anonymous' => 'Anonymous',
    'admin_theme' => 'seven',
    'date_default_timezone' => 'Europe/Zurich',
    'cache' => 0,
    'cache_lifetime' => '0',
    'maintenance_mode' => 0,
    'maintenance_mode_message' => 'Piraten Partei Schweiz is currently under maintenance. We should be back shortly. Thank you for your patience.',
    'language_default' => 'de',
    'menu_main_links_source' => 'main-menu',
    'menu_secondary_links_source' => '0',
    'menu_options_article' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_article' => 'main-menu:0',
    'menu_options_communique' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_communique' => 'main-menu:0',
    'menu_options_event' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_event' => 'main-menu:0',
    'menu_options_gallery' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_gallery' => 'main-menu:0',
    'menu_options_minutes' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_minutes' => 'main-menu:0',
    'menu_options_newsletter' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_newsletter' => 'main-menu:0',
    'menu_options_page' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_page' => 'main-menu:0',
    'menu_options_position' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_position' => 'main-menu:0',
    'menu_options_press_review' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_press_review' => 'main-menu:0',
    'menu_options_team' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_team' => 'main-menu:0',
    'menu_options_ballot' => array(
      'devel' => 0,
      'main-menu' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_ballot' => 'main-menu:0',
    'menu_options_panel' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_panel' => 'main-menu:0',
  );

  return $domain_variables;
}

/**
 * Implements hook_domain_theme_default_themes().
 */
function pps_domain_domain_theme_default_themes() {
  $domain_themes = array();
  $domain_themes['wipe-domain-tables'] = 'wipe-domain-tables';
  $domain_themes['piratenpartei_ch'] = array();

  return $domain_themes;
}
