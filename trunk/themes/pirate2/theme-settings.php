<?php
// $Id: theme-settings.php,v 1.7 2008/09/11 09:36:50 johnalbin Exp $

// Include the definition of zen_settings() and zen_theme_get_default_settings().
include_once './' . drupal_get_path('theme', 'zen') . '/theme-settings.php';


/**
 * Implementation of THEMEHOOK_settings() function.
 *
 * @param $saved_settings
 *   An array of saved settings for this theme.
 * @return
 *   A form array.
 */
function pirate2_settings($saved_settings) {

  // Get the default values from the .info file.
  $defaults = zen_theme_get_default_settings('pirate2');

  // Merge the saved variables and their default values.
  $settings = array_merge($defaults, $saved_settings);

  /*
   * Create the form using Forms API: http://api.drupal.org/api/6
   */
  $form = array();  
    $form['socialnetworks'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Social Networklinks in the footer'),
  );
  $form['socialnetworks']['rss_available'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Activate RSS Link'),
    '#default_value' => FALSE,
  );
  $form['breadcrumb']['rss_link'] = array(
    '#type'          => 'textfield',
    '#title'         => t('RSS Link'),
    '#description'   => t('The fully qualified URL of the the RSS feed'),
    '#default_value' => '',
    '#size'          => 63,
    '#maxlength'     => 255,
  );
  $form['socialnetworks']['zen_breadcrumb'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Activate Flickr Link'),
    '#default_value' => FALSE,
  );
  $form['breadcrumb']['zen_breadcrumb_separator'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Flickr Link'),
    '#description'   => t('The fully qualified URL of the the Flickr gallery'),
    '#default_value' => '',
    '#size'          => 63,
    '#maxlength'     => 255,
  );

  // Add the base theme's settings.
  $form += zen_settings($saved_settings, $defaults);

  // Remove some of the base theme's settings.
  unset($form['themedev']['zen_layout']);
  unset($form['themedev']['zen_wireframes']);
  unset($form['breadcrumb']);
  
  // Return the form
  return $form;
}
