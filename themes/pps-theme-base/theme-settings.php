<?php

/**
 * Implements hook_form_system_theme_settings_alter()
 *
 * Add a selection for provided logos and register a submit hook to
 * handle the selection.
 *
 * @see pps_theme_base_form_system_theme_settings_submit()
 */
function pps_theme_base_form_system_theme_settings_alter(&$form, &$form_state)  {
  $options = _pps_theme_base_default_logo_values();
  $path = $form['logo']['settings']['logo_path']['#default_value'];

  $form['logo']['default_logo']['#default_value'] = (string)array_key_exists($path, $options);

  $form['logo']['logo_selection'] = array(
    '#type' => 'radios',
    '#title' => t('Select site logo'),
    '#description' => t('Select one of the included logos.'),
    '#options' => $options,
    '#default_value' => $path,
    '#states' => array(
      'visible' => array(
        'input[name="default_logo"]' => array('checked' => TRUE),
      ),
    ),
  );
  array_unshift($form['#submit'], 'pps_theme_base_form_system_theme_settings_submit');
}

/**
 * Submit callback for form system_theme_settings
 *
 * Alter the values so that they appear the same as the unaltered form.
 *
 * @see pps_theme_base_form_system_theme_settings_alter()
 */
function pps_theme_base_form_system_theme_settings_submit(&$form, &$form_state)  {
  $values = $form_state['values'];
  $filename = $values['logo_selection'];
  if ($values['default_logo'] == 1) {
    $values['logo_path'] = $values['logo_selection'];
    $values['default_logo'] = 0;
  }
  $form_state['values'] = $values ;
}

/**
 * Get available files
 *
 * Search the logo path and build a options array ready to be used in a
 * radios form.
 *
 * @return
 *   Array with the file name as key an the an image element as value.
 *
 * @see pps_theme_base_form_system_theme_settings_alter()
 */
function _pps_theme_base_default_logo_values() {
  $base_path = drupal_get_path('theme', 'pps_theme_base') . '/images/logos/';
  $supported_ext = array('png', 'gif', 'jpg', 'jpeg');
  $dir = @opendir($base_path);
  while ($file = @readdir($dir)){
    if (!is_dir($base_path.$file)){
      $splitted = explode('.', $file);
      $ext = strtolower($splitted[count($splitted)-1]);
      if (in_array($ext, $supported_ext)) $files[] = $file;
    }
  }
  @closedir($base_path);
  sort($files);
  $options = array();
  foreach ($files as $file){
    $path = $base_path . $file;
    $options[$path] = theme('image', array('path' => $path));
  }

  return $options;
}