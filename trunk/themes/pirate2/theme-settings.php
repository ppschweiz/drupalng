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
function pirate2_settings($saved_settings) 
{
  global $language;

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
    '#title'         => t('Social Networklinks in the footer, for language: '.$language['name']),
  );
  $form['socialnetworks']['rss_available'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Activate RSS Link'),
    '#default_value' => $settings['rss_available']
  );
  $form['socialnetworks']['rss_link'] = array(
    '#type'          => 'textfield',
    '#title'         => t('RSS Link'),
    '#description'   => t('The fully qualified URL of the the RSS feed'),
    '#default_value' => $settings['rss_link'],
    '#size'          => 63,
    '#maxlength'     => 255,
  );
  $form['socialnetworks']['flickr_available'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Activate Flickr Link'),
    '#default_value' => $settings['flickr_available']
  );
  $form['socialnetworks']['flickr_link'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Flickr Link'),
    '#description'   => t('The fully qualified URL of the the Flickr gallery'),
    '#default_value' => $settings['flickr_link'],
    '#size'          => 63,
    '#maxlength'     => 255,
  );
  
  $form['socialnetworks']['myspace_available'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Activate MySpace Link'),
    '#default_value' => $settings['myspace_available']
  );
  $form['socialnetworks']['myspace_link'] = array(
    '#type'          => 'textfield',
    '#title'         => t('MySpace Link'),
    '#description'   => t('The fully qualified URL of the the MySpace Account'),
    '#default_value' => $settings['myspace_link'],
    '#size'          => 63,
    '#maxlength'     => 255,
  );  $form['socialnetworks']['youtube_available'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Activate YouTube Link'),
    '#default_value' => $settings['youtube_available']
  );
  $form['socialnetworks']['youtube_link'] = array(
    '#type'          => 'textfield',
    '#title'         => t('YouTube Link'),
    '#description'   => t('The fully qualified URL of the the YouTube channel'),
    '#default_value' => $settings['youtube_link'],
    '#size'          => 63,
    '#maxlength'     => 255,
  );  $form['socialnetworks']['twitter_available'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Activate Twitter Link'),
    '#default_value' => $settings['twitter_available']
  );
  $form['socialnetworks']['twitter_link'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Twitter Link'),
    '#description'   => t('The fully qualified URL of the the Twitter feed'),
    '#default_value' => $settings['twitter_link'],
    '#size'          => 63,
    '#maxlength'     => 255,
  );  $form['socialnetworks']['facebook_available'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Activate Facebook Link'),
    '#default_value' => $settings['facebook_available']
  );
  $form['socialnetworks']['facebook_link'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Facebook Link'),
    '#description'   => t('The fully qualified URL of the the Facebook group'),
    '#default_value' => $settings['facebook_link'],
    '#size'          => 63,
    '#maxlength'     => 255,
  );  $form['socialnetworks']['identica_available'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Activate Identica  Link'),
    '#default_value' => $settings['identica_available']
  );
  $form['socialnetworks']['identica_link'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Identica Link'),
    '#description'   => t('The fully qualified URL of the the Identica feed'),
    '#default_value' => $settings['identica_link'],
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
