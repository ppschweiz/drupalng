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
  // Get the default values from the .info file.
  $defaults = zen_theme_get_default_settings('pirate2');

  // Merge the saved variables and their default values.
  $settings = array_merge($defaults, $saved_settings);

  /*
   * Create the form using Forms API: http://api.drupal.org/api/6
   */
   
  print_r(locale_language_list('name'));
  print_r(locale_language_list('language'));
  
  $form = array();  
  foreach(locale_language_list('language') as $clang) 
  { 
    $form['socialnetworks_'.$clang] = array(
      '#type'          => 'fieldset',
      '#title'         => t('Social Networklinks in the footer, for language: '.$clang),
	  '#collapsible'   => TRUE
	  '#collapsed'     => TRUE
    );
    $form['socialnetworks_'.$clang]['rss_available_'.$clang] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Activate RSS Link'),
      '#default_value' => $settings['rss_available']
    );
    $form['socialnetworks_'.$clang]['rss_link_'.$clang] = array(
      '#type'          => 'textfield',
      '#title'         => t('RSS Link'),
      '#description'   => t('The fully qualified URL of the the RSS feed'),
      '#default_value' => $settings['rss_link'],
      '#size'          => 63,
      '#maxlength'     => 255,
    );
    $form['socialnetworks_'.$clang]['flickr_available_'.$clang] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Activate Flickr Link'),
      '#default_value' => $settings['flickr_available']
    );
    $form['socialnetworks_'.$clang]['flickr_link_'.$clang] = array(
      '#type'          => 'textfield',
      '#title'         => t('Flickr Link'),
      '#description'   => t('The fully qualified URL of the the Flickr gallery'),
      '#default_value' => $settings['flickr_link'],
      '#size'          => 63,
      '#maxlength'     => 255,
    ); 
    $form['socialnetworks_'.$clang]['myspace_available_'.$clang] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Activate MySpace Link'),
      '#default_value' => $settings['myspace_available']
    );
    $form['socialnetworks_'.$clang]['myspace_link_'.$clang] = array(
      '#type'          => 'textfield',
      '#title'         => t('MySpace Link'),
      '#description'   => t('The fully qualified URL of the the MySpace Account'),
      '#default_value' => $settings['myspace_link'],
      '#size'          => 63,
      '#maxlength'     => 255,
    );
	$form['socialnetworks_'.$clang]['youtube_available_'.$clang] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Activate YouTube Link'),
      '#default_value' => $settings['youtube_available']
    );
    $form['socialnetworks_'.$clang]['youtube_link_'.$clang] = array(
      '#type'          => 'textfield',
      '#title'         => t('YouTube Link'),
      '#description'   => t('The fully qualified URL of the the YouTube channel'),
      '#default_value' => $settings['youtube_link'],
      '#size'          => 63,
      '#maxlength'     => 255,
    );
	$form['socialnetworks_'.$clang]['twitter_available_'.$clang] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Activate Twitter Link'),
      '#default_value' => $settings['twitter_available']
    );
    $form['socialnetworks_'.$clang]['twitter_link_'.$clang] = array(
      '#type'          => 'textfield',
      '#title'         => t('Twitter Link'),
      '#description'   => t('The fully qualified URL of the the Twitter feed'),
      '#default_value' => $settings['twitter_link'],
      '#size'          => 63,
      '#maxlength'     => 255,
    );
	$form['socialnetworks_'.$clang]['facebook_available_'.$clang] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Activate Facebook Link'),
      '#default_value' => $settings['facebook_available']
    );
    $form['socialnetworks_'.$clang]['facebook_link_'.$clang] = array(
      '#type'          => 'textfield',
      '#title'         => t('Facebook Link'),
      '#description'   => t('The fully qualified URL of the the Facebook group'),
      '#default_value' => $settings['facebook_link'],
      '#size'          => 63,
      '#maxlength'     => 255,
    );
	$form['socialnetworks_'.$clang]['identica_available_'.$clang] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Activate Identica  Link'),
      '#default_value' => $settings['identica_available']
    );
    $form['socialnetworks_'.$clang]['identica_link_'.$clang] = array(
      '#type'          => 'textfield',
      '#title'         => t('Identica Link'),
      '#description'   => t('The fully qualified URL of the the Identica feed'),
      '#default_value' => $settings['identica_link'],
      '#size'          => 63,
      '#maxlength'     => 255,
    );
  }

  // Add the base theme's settings.
  $form += zen_settings($saved_settings, $defaults);

  // Remove some of the base theme's settings.
  unset($form['themedev']['zen_layout']);
  unset($form['themedev']['zen_wireframes']);
  unset($form['breadcrumb']);
  
  // Return the form
  return $form;
}
