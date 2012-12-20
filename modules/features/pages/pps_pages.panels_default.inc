<?php
/**
 * @file
 * pps_pages.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function pps_pages_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'upcoming';
  $mini->category = '';
  $mini->admin_title = 'Upcoming';
  $mini->admin_description = 'Three blocks of five upcoming events each. The events are grouped by assemblies and political activities, regular tables and meetings.';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'three_3x33';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'three_33_top' => NULL,
      'three_33_first' => NULL,
      'three_33_second' => NULL,
      'three_33_third' => NULL,
      'three_33_bottom' => NULL,
      'default' => array(
        'style' => 'colored',
      ),
    ),
    'style' => 'default',
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'three_33_first';
    $pane->type = 'views_panes';
    $pane->subtype = 'events-upcoming';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'more_link' => 1,
      'items_per_page' => '5',
      'arguments' => array(
        'field_event_type_tid' => '41+42+43',
      ),
      'override_title' => 1,
      'override_title_text' => 'Nächste Anlässe',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['three_33_first'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'three_33_second';
    $pane->type = 'views_panes';
    $pane->subtype = 'events-upcoming';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'more_link' => 1,
      'items_per_page' => '5',
      'arguments' => array(
        'field_event_type_tid' => '44',
      ),
      'override_title' => 1,
      'override_title_text' => 'Nächste Stammtische',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['three_33_second'][0] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'three_33_third';
    $pane->type = 'views_panes';
    $pane->subtype = 'events-upcoming';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'more_link' => 1,
      'items_per_page' => '5',
      'arguments' => array(
        'field_event_type_tid' => '38+40+45',
      ),
      'override_title' => 1,
      'override_title_text' => 'Nächste Sitzungen',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['three_33_third'][0] = 'new-3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $mini->display = $display;
  $export['upcoming'] = $mini;

  return $export;
}
