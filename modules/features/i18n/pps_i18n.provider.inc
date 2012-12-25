<?php

/**
 * Identify language via current active domain
 *
 * @param $languages
 *   An array of valid language objects.
 *
 * @return
 *   A valid language code on success, FALSE otherwise.
 */
function pps_i18n_language_negotiation_language($languages) {
  $language = FALSE;
  // Get current active domain
  $domain = domain_get_domain();
  // Fetch domain configuration
  // For we are in an early bootstrap stage most APIs of contrib modules
  // are not jet loaded so we need to do it ourselves;
  $conf = db_select('domain_conf', 'dc')
    ->fields('dc', array('settings'))
    ->condition('domain_id', $domain['domain_id'])
    ->execute()
    ->fetchField();
  $conf = domain_unserialize($conf);

  // If no language is configured we fall back to the global default.
  if (!empty($conf['language_default'])) {
    $language = $conf['language_default'];
  }
  else {
    $language = language_default('language');
  }

  return $language;
}

/**
 * Return the domain language switcher block.
 */
function pps_i18n_language_negotiation_switcher($type, $path) {
  $languages = language_list();
  $language_domains = pps_i18n_language_domains();
  $links = array();

  foreach ($language_domains as $language_domain) {
    $language = $languages[$language_domain->language];
    $links[$language->language] = array(
      'href'       => $language_domain->scheme . '://' . $language_domain->subdomain,
      'title'      => $language->native,
      'language'   => $language,
      'attributes' => array('class' => array('language-link')),
    );
  }
  return $links;
}

/**
 * Rewrite URLs for the URL language provider.
 *
 * Take care the right domain is used for reach language.
 */
function pps_i18n_language_negotiation_url_rewrite(&$path, &$options) {
  $language_domains = pps_i18n_language_domains();

  // Language can be passed as an option, or we go for current URL language.
  if (!isset($options['language'])) {
    global $language_url;
    $options['language'] = $language_url;
  }
  // We allow only enabled languages here.
  elseif (!isset($language_domains[$options['language']->language])) {
    unset($options['language']);
    return;
  }

  if (isset($options['language'])) {
    if ($language_domain = $language_domains[$options['language']->language]) {
      // Get the domain for the given language.
      $domain = $language_domain->subdomain;

      // Prevent switching the to the main domain when using an alias
      // @todo: This only works for the current domain.
      // To solve this we need a environment specific variable that
      // holds the domain aliases that are specific to this environment.
      global $base_url;
      $host = 'http://' . str_replace(array('http://', 'https://'), '', $base_url);
      $host = parse_url($host, PHP_URL_HOST);
      $count = db_query('select count(*) from domain_alias where pattern = :pattern and domain_id = :id', array(
        ':id' => $language_domain->domain_id,
        ':pattern' => $host,
      ))->fetchField();
      if ($count != 0) {
        $domain = $host;
      }

      // Ask for an absolute URL for the language domain.
      $url_scheme = $language_domain->scheme;
      $options['absolute'] = TRUE;
      // Apply the appropriate protocol to the URL.
      $options['base_url'] = $url_scheme . '://' . $host;
    }
  }
}

/**
 * Language domain group
 *
 * Get alist of domains that belongs to the same language group as the
 * current active one.
 *
 * @return
 *   Array of domains
 *
 * @todo Replace with custom domain attribute.
 * Currently the module domain_type module is missused for this. Add a
 * custom attribute to the domain table instead so the domain_type is
 * free to group section pages, projects etc.
 */
function pps_i18n_language_domains() {
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['languages'] = &drupal_static(__FUNCTION__);
  }
  $language_domains = &$drupal_static_fast['languages'];

  if (!isset($language_domains)) {
    $domain = domain_get_domain();

    $query = db_select('domain', 'd');
    $query->fields('d', array('subdomain', 'scheme', 'domain_id'));
    $query->join('domain', 'dd', 'd.x_type = dd.x_type and dd.domain_id = :id',array(
      ':id' => $domain['domain_id'],
    ));
    $result = $query->execute()->fetchAllAssoc('domain_id');

    foreach ($result as $key => $language_domain) {
      $language = domain_conf_variable_get($key, 'language_default');
      $language_domain->language = $language;
      $language_domains[$language] = $language_domain;
    }
  }
  return $language_domains;
}
