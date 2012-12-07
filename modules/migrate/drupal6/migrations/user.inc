<?php

class PPSUserMigration extends DrupalUser6Migration {
  public function complete ($account, $row) {
    parent::complete ($account, $row);
    cas_user_operations_create_username(array($account->uid));
  }

  public function completeRollback($entity) {
    cas_user_operations_remove_usernames(array($entity->uid));
  }
}