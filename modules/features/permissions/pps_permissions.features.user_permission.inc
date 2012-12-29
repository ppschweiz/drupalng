<?php
/**
 * @file
 * pps_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pps_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: access comments.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: access contextual links.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(),
    'module' => 'contextual',
  );

  // Exported permission: access inactive domains.
  $permissions['access inactive domains'] = array(
    'name' => 'access inactive domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: access site in maintenance mode.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access site reports.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: access workbench access by role.
  $permissions['access workbench access by role'] = array(
    'name' => 'access workbench access by role',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: administer actions.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer advanced pane settings.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer blocks.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
    'module' => 'block',
  );

  // Exported permission: administer cas.
  $permissions['administer cas'] = array(
    'name' => 'administer cas',
    'roles' => array(),
    'module' => 'cas',
  );

  // Exported permission: administer comments.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: administer content translations.
  $permissions['administer content translations'] = array(
    'name' => 'administer content translations',
    'roles' => array(),
    'module' => 'i18n_node',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: administer domains.
  $permissions['administer domains'] = array(
    'name' => 'administer domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: administer entity translation.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: administer image styles.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: administer languages.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(),
    'module' => 'locale',
  );

  // Exported permission: administer menu.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(),
    'module' => 'menu',
  );

  // Exported permission: administer menu attributes.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(),
    'module' => 'menu_attributes',
  );

  // Exported permission: administer mini panels.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(),
    'module' => 'panels_mini',
  );

  // Exported permission: administer modules.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer nodequeue.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(),
    'module' => 'nodequeue',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: administer page manager.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: administer pane access.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer panel-nodes.
  $permissions['administer panel-nodes'] = array(
    'name' => 'administer panel-nodes',
    'roles' => array(),
    'module' => 'panels_node',
  );

  // Exported permission: administer panels layouts.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer panels styles.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer pathauto.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: administer redirects.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(),
    'module' => 'redirect',
  );

  // Exported permission: administer site configuration.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer software updates.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer url aliases.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: administer workbench access.
  $permissions['administer workbench access'] = array(
    'name' => 'administer workbench access',
    'roles' => array(),
    'module' => 'workbench_access',
  );

  // Exported permission: assign domain editors.
  $permissions['assign domain editors'] = array(
    'name' => 'assign domain editors',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: assign workbench access.
  $permissions['assign workbench access'] = array(
    'name' => 'assign workbench access',
    'roles' => array(),
    'module' => 'workbench_access',
  );

  // Exported permission: batch update workbench access.
  $permissions['batch update workbench access'] = array(
    'name' => 'batch update workbench access',
    'roles' => array(),
    'module' => 'workbench_access',
  );

  // Exported permission: block IP addresses.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: change layouts in place editing.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: create article content.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create article content on assigned domains.
  $permissions['create article content on assigned domains'] = array(
    'name' => 'create article content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: create ballot content.
  $permissions['create ballot content'] = array(
    'name' => 'create ballot content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create ballot content on assigned domains.
  $permissions['create ballot content on assigned domains'] = array(
    'name' => 'create ballot content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: create communique content.
  $permissions['create communique content'] = array(
    'name' => 'create communique content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create communique content on assigned domains.
  $permissions['create communique content on assigned domains'] = array(
    'name' => 'create communique content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: create event content.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create event content on assigned domains.
  $permissions['create event content on assigned domains'] = array(
    'name' => 'create event content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: create gallery content.
  $permissions['create gallery content'] = array(
    'name' => 'create gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create gallery content on assigned domains.
  $permissions['create gallery content on assigned domains'] = array(
    'name' => 'create gallery content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: create mini panels.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(),
    'module' => 'panels_mini',
  );

  // Exported permission: create minutes content.
  $permissions['create minutes content'] = array(
    'name' => 'create minutes content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create minutes content on assigned domains.
  $permissions['create minutes content on assigned domains'] = array(
    'name' => 'create minutes content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: create newsletter content.
  $permissions['create newsletter content'] = array(
    'name' => 'create newsletter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create newsletter content on assigned domains.
  $permissions['create newsletter content on assigned domains'] = array(
    'name' => 'create newsletter content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: create panel content.
  $permissions['create panel content'] = array(
    'name' => 'create panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create panel content on assigned domains.
  $permissions['create panel content on assigned domains'] = array(
    'name' => 'create panel content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: create panel-nodes.
  $permissions['create panel-nodes'] = array(
    'name' => 'create panel-nodes',
    'roles' => array(),
    'module' => 'panels_node',
  );

  // Exported permission: create position content.
  $permissions['create position content'] = array(
    'name' => 'create position content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create position content on assigned domains.
  $permissions['create position content on assigned domains'] = array(
    'name' => 'create position content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: create press_review content.
  $permissions['create press_review content'] = array(
    'name' => 'create press_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create press_review content on assigned domains.
  $permissions['create press_review content on assigned domains'] = array(
    'name' => 'create press_review content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: create team content.
  $permissions['create team content'] = array(
    'name' => 'create team content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create team content on assigned domains.
  $permissions['create team content on assigned domains'] = array(
    'name' => 'create team content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: create url aliases.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: delete any article content.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any ballot content.
  $permissions['delete any ballot content'] = array(
    'name' => 'delete any ballot content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any communique content.
  $permissions['delete any communique content'] = array(
    'name' => 'delete any communique content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any event content.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any gallery content.
  $permissions['delete any gallery content'] = array(
    'name' => 'delete any gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any minutes content.
  $permissions['delete any minutes content'] = array(
    'name' => 'delete any minutes content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any newsletter content.
  $permissions['delete any newsletter content'] = array(
    'name' => 'delete any newsletter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any panel content.
  $permissions['delete any panel content'] = array(
    'name' => 'delete any panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any panel-nodes.
  $permissions['delete any panel-nodes'] = array(
    'name' => 'delete any panel-nodes',
    'roles' => array(),
    'module' => 'panels_node',
  );

  // Exported permission: delete any position content.
  $permissions['delete any position content'] = array(
    'name' => 'delete any position content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any press_review content.
  $permissions['delete any press_review content'] = array(
    'name' => 'delete any press_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any team content.
  $permissions['delete any team content'] = array(
    'name' => 'delete any team content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete article content on assigned domains.
  $permissions['delete article content on assigned domains'] = array(
    'name' => 'delete article content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete ballot content on assigned domains.
  $permissions['delete ballot content on assigned domains'] = array(
    'name' => 'delete ballot content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete communique content on assigned domains.
  $permissions['delete communique content on assigned domains'] = array(
    'name' => 'delete communique content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete domain content.
  $permissions['delete domain content'] = array(
    'name' => 'delete domain content',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete event content on assigned domains.
  $permissions['delete event content on assigned domains'] = array(
    'name' => 'delete event content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete gallery content on assigned domains.
  $permissions['delete gallery content on assigned domains'] = array(
    'name' => 'delete gallery content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete minutes content on assigned domains.
  $permissions['delete minutes content on assigned domains'] = array(
    'name' => 'delete minutes content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete newsletter content on assigned domains.
  $permissions['delete newsletter content on assigned domains'] = array(
    'name' => 'delete newsletter content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete own article content.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own ballot content.
  $permissions['delete own ballot content'] = array(
    'name' => 'delete own ballot content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own communique content.
  $permissions['delete own communique content'] = array(
    'name' => 'delete own communique content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own event content.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own gallery content.
  $permissions['delete own gallery content'] = array(
    'name' => 'delete own gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own minutes content.
  $permissions['delete own minutes content'] = array(
    'name' => 'delete own minutes content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own newsletter content.
  $permissions['delete own newsletter content'] = array(
    'name' => 'delete own newsletter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own panel content.
  $permissions['delete own panel content'] = array(
    'name' => 'delete own panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own panel-nodes.
  $permissions['delete own panel-nodes'] = array(
    'name' => 'delete own panel-nodes',
    'roles' => array(),
    'module' => 'panels_node',
  );

  // Exported permission: delete own position content.
  $permissions['delete own position content'] = array(
    'name' => 'delete own position content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own press_review content.
  $permissions['delete own press_review content'] = array(
    'name' => 'delete own press_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own team content.
  $permissions['delete own team content'] = array(
    'name' => 'delete own team content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete panel content on assigned domains.
  $permissions['delete panel content on assigned domains'] = array(
    'name' => 'delete panel content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete position content on assigned domains.
  $permissions['delete position content on assigned domains'] = array(
    'name' => 'delete position content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete press_review content on assigned domains.
  $permissions['delete press_review content on assigned domains'] = array(
    'name' => 'delete press_review content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete team content on assigned domains.
  $permissions['delete team content on assigned domains'] = array(
    'name' => 'delete team content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 3.
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: display drupal links.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: edit any article content.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any ballot content.
  $permissions['edit any ballot content'] = array(
    'name' => 'edit any ballot content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any communique content.
  $permissions['edit any communique content'] = array(
    'name' => 'edit any communique content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any event content.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any gallery content.
  $permissions['edit any gallery content'] = array(
    'name' => 'edit any gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any minutes content.
  $permissions['edit any minutes content'] = array(
    'name' => 'edit any minutes content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any newsletter content.
  $permissions['edit any newsletter content'] = array(
    'name' => 'edit any newsletter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any panel content.
  $permissions['edit any panel content'] = array(
    'name' => 'edit any panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any panel-nodes.
  $permissions['edit any panel-nodes'] = array(
    'name' => 'edit any panel-nodes',
    'roles' => array(),
    'module' => 'panels_node',
  );

  // Exported permission: edit any position content.
  $permissions['edit any position content'] = array(
    'name' => 'edit any position content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any press_review content.
  $permissions['edit any press_review content'] = array(
    'name' => 'edit any press_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any team content.
  $permissions['edit any team content'] = array(
    'name' => 'edit any team content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit domain content.
  $permissions['edit domain content'] = array(
    'name' => 'edit domain content',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: edit domain paths.
  $permissions['edit domain paths'] = array(
    'name' => 'edit domain paths',
    'roles' => array(),
    'module' => 'domain_path',
  );

  // Exported permission: edit own article content.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own ballot content.
  $permissions['edit own ballot content'] = array(
    'name' => 'edit own ballot content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own comments.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: edit own communique content.
  $permissions['edit own communique content'] = array(
    'name' => 'edit own communique content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own event content.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own gallery content.
  $permissions['edit own gallery content'] = array(
    'name' => 'edit own gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own minutes content.
  $permissions['edit own minutes content'] = array(
    'name' => 'edit own minutes content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own newsletter content.
  $permissions['edit own newsletter content'] = array(
    'name' => 'edit own newsletter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own panel content.
  $permissions['edit own panel content'] = array(
    'name' => 'edit own panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own panel-nodes.
  $permissions['edit own panel-nodes'] = array(
    'name' => 'edit own panel-nodes',
    'roles' => array(),
    'module' => 'panels_node',
  );

  // Exported permission: edit own position content.
  $permissions['edit own position content'] = array(
    'name' => 'edit own position content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own press_review content.
  $permissions['edit own press_review content'] = array(
    'name' => 'edit own press_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own team content.
  $permissions['edit own team content'] = array(
    'name' => 'edit own team content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 3.
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: flush caches.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: manipulate all queues.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(),
    'module' => 'nodequeue',
  );

  // Exported permission: manipulate queues.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(),
    'module' => 'nodequeue',
  );

  // Exported permission: notify of path changes.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: post comments.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: publish from assigned domain.
  $permissions['publish from assigned domain'] = array(
    'name' => 'publish from assigned domain',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: publish from default domain.
  $permissions['publish from default domain'] = array(
    'name' => 'publish from default domain',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: publish to any assigned domain.
  $permissions['publish to any assigned domain'] = array(
    'name' => 'publish to any assigned domain',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: set domain access.
  $permissions['set domain access'] = array(
    'name' => 'set domain access',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: skip comment approval.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: submit translations to localization server.
  $permissions['submit translations to localization server'] = array(
    'name' => 'submit translations to localization server',
    'roles' => array(),
    'module' => 'l10n_client',
  );

  // Exported permission: toggle field translatability.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: translate admin strings.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(),
    'module' => 'i18n_string',
  );

  // Exported permission: translate any entity.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: translate content.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(),
    'module' => 'translation',
  );

  // Exported permission: translate interface.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(),
    'module' => 'locale',
  );

  // Exported permission: translate node entities.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: translate user-defined strings.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(),
    'module' => 'i18n_string',
  );

  // Exported permission: update article content on assigned domains.
  $permissions['update article content on assigned domains'] = array(
    'name' => 'update article content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: update ballot content on assigned domains.
  $permissions['update ballot content on assigned domains'] = array(
    'name' => 'update ballot content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: update communique content on assigned domains.
  $permissions['update communique content on assigned domains'] = array(
    'name' => 'update communique content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: update event content on assigned domains.
  $permissions['update event content on assigned domains'] = array(
    'name' => 'update event content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: update gallery content on assigned domains.
  $permissions['update gallery content on assigned domains'] = array(
    'name' => 'update gallery content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: update minutes content on assigned domains.
  $permissions['update minutes content on assigned domains'] = array(
    'name' => 'update minutes content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: update newsletter content on assigned domains.
  $permissions['update newsletter content on assigned domains'] = array(
    'name' => 'update newsletter content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: update panel content on assigned domains.
  $permissions['update panel content on assigned domains'] = array(
    'name' => 'update panel content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: update position content on assigned domains.
  $permissions['update position content on assigned domains'] = array(
    'name' => 'update position content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: update press_review content on assigned domains.
  $permissions['update press_review content on assigned domains'] = array(
    'name' => 'update press_review content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: update team content on assigned domains.
  $permissions['update team content on assigned domains'] = array(
    'name' => 'update team content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: use on-page translation.
  $permissions['use on-page translation'] = array(
    'name' => 'use on-page translation',
    'roles' => array(),
    'module' => 'l10n_client',
  );

  // Exported permission: use page manager.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: use panels caching features.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use panels dashboard.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use panels in place editing.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use panels locks.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use text format migrate_html.
  $permissions['use text format migrate_html'] = array(
    'name' => 'use text format migrate_html',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: use text format migrate_plain.
  $permissions['use text format migrate_plain'] = array(
    'name' => 'use text format migrate_plain',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: use text format textile.
  $permissions['use text format textile'] = array(
    'name' => 'use text format textile',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: view date repeats.
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(),
    'module' => 'date_repeat_field',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: view pane admin links.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: view unpublished domain content.
  $permissions['view unpublished domain content'] = array(
    'name' => 'view unpublished domain content',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: view workbench access information.
  $permissions['view workbench access information'] = array(
    'name' => 'view workbench access information',
    'roles' => array(),
    'module' => 'workbench_access',
  );

  // Exported permission: view workbench taxonomy pages.
  $permissions['view workbench taxonomy pages'] = array(
    'name' => 'view workbench taxonomy pages',
    'roles' => array(),
    'module' => 'workbench_access',
  );

  return $permissions;
}
