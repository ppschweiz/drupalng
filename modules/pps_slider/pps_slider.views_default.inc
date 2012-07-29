<?php
/**
 * @file
 * pps_slider.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pps_slider_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'slides';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Slides';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'slides' => 'slides',
    'highlighted' => 0,
    'action_buttons' => 0,
  );
  /* Field: Content: Slide Image */
  $handler->display->display_options['fields']['field_slider_image']['id'] = 'field_slider_image';
  $handler->display->display_options['fields']['field_slider_image']['table'] = 'field_data_field_slider_image';
  $handler->display->display_options['fields']['field_slider_image']['field'] = 'field_slider_image';
  $handler->display->display_options['fields']['field_slider_image']['label'] = '';
  $handler->display->display_options['fields']['field_slider_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slider_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slider_image']['settings'] = array(
    'image_style' => 'slider_mobileport',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_slider_image']['field_api_classes'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
  /* Field: Content: Slide Text */
  $handler->display->display_options['fields']['field_slider_text']['id'] = 'field_slider_text';
  $handler->display->display_options['fields']['field_slider_text']['table'] = 'field_data_field_slider_text';
  $handler->display->display_options['fields']['field_slider_text']['field'] = 'field_slider_text';
  $handler->display->display_options['fields']['field_slider_text']['label'] = '';
  $handler->display->display_options['fields']['field_slider_text']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slider_text']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_slider_text']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_slider_text']['alter']['absolute'] = 1;
  $handler->display->display_options['fields']['field_slider_text']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slider_text']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slider_text']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slider_text']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slider_text']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slider_text']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slider_text']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_slider_text']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slider_text']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slider_text']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slider_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slider_text']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slider_text']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slider_text']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slider_text']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slider_text']['field_api_classes'] = 0;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['slides'] = $view;

  return $export;
}
