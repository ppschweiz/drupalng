<?php

/**
 * @file
 * Views integration for Workbench.
 *
 * Provides a filter to display nodes by assigned section without
 * restricting access.
 *
 * @todo This does not work with exposed filter. Why?
 */

class pps_views_workbench_access_handler_filter_section extends workbench_access_handler_filter_access {

  function query() {
    static $node_types;

    // If workbench_access is not configured, do nothing.
    $active = workbench_access_get_active_tree();
    $tree = $active['tree'];
    if (empty($tree)) {
      return;
    }

    // Get node types that do not use workbench_access for access control.
    $node_types = array();
    foreach (node_type_get_names() as $type => $name) {
      if (!variable_get('workbench_access_node_type_' . $type, TRUE)) {
        $node_types[$type] = $type;
      }
    }

    // Here we start altering the query. All of our alters should be their own
    // where group.
    $group = $this->query->set_where_group('OR');


    if (!empty($this->value) && $this->value[0] != -5) {
      workbench_access_build_tree($tree, array_keys($this->value[0]));
    }

    // Build the workbench_access where clause.
    if (!empty($tree)) {
      // Since we allow multi-select, this has to be a subquery.
      $ids = array_keys($tree);
      $table = $active['access_scheme']['field_table'];
      $subquery = db_select($table, $table);
      $subquery->addField($table, 'nid');
      $subquery->distinct();
      $subquery->condition($table . '.' . $active['access_scheme']['query_field'], $ids, 'IN');
      $subquery->condition($table . '.access_scheme', $active['access_scheme']['access_scheme']);

      $this->query->add_where($group, "{$this->query->base_table}.nid", $subquery, 'IN');
    }

    // If not all node types use workbench access for permissions, add them here.
    if (!empty($node_types)) {
      $this->query->add_where($group, "{$this->query->base_table}.type", $node_types, 'IN');
    }
  }
}
