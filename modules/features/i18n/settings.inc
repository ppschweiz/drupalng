<?php
/**
 * @file
 * Enable domain specific language negotiation
 *
 * This file needs to be included in settings.php.
 *
 * Domain Access in combination with url language negotiation does only
 * allow to negotiate by path. the following allows to define separate
 * language aliases for each domain.
 *
 * @todo Alter the domain settings form in order to set the variables
 * needed here.
 */

// When calling with drush, the function module_exists() is not yet
// loaded. But we do not care about languages in that context so we can
// just skip here.
if (function_exists('module_exists')) {
  // get the domain specific overrides.
  $domain = domain_get_domain();
  $override_variable = 'domain_alias_language_negotiation_' . $domain['domain_id'];
  $domain_overrides = variable_get($override_variable, array());

  // Initialize the language list.
  language_list();
  // get the reference to the static so we can manipulate the list for
  // only this one request.
  $languages = & drupal_static('language_list');

  // Replace the language domain for each override.
  foreach ($domain_overrides as $language => $domain) {
    if (array_key_exists($language, $languages['language'])) {
      $languages['language'][$language]->domain = $domain;
    }
  }

  // If there are any overrides, we expect domain negotiation is
  // appropriate, else path negotiation.
  $conf['locale_language_negotiation_url_part'] = empty($domain_overrides) ? 0 : 1;
}
