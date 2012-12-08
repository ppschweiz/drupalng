<?php

class PPSUserMigration extends DrupalUser6Migration {

  /**
   * Overrides DrupalUser6Migration::complete().
   *
   * Add CAS association to user.
   */
  public function complete ($account, $row) {
    parent::complete ($account, $row);
    cas_user_operations_create_username(array($account->uid));
  }

  /**
   * Overrides DrupalUser6Migration::completeRollback().
   *
   * Remove CAS association on rollback.
   */
  public function completeRollback($entity) {
    cas_user_operations_remove_usernames(array($entity->uid));
  }
}