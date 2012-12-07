<?php

/**
 * Common mappings for the node migrations.
 */
class PPSNodeMigration extends DrupalNode6Migration {
  public function __construct (array $arguments) {
    $this->sourceFields['attachment_fids'] = t('File attachments');

    parent::__construct ($arguments);

    $this->addFieldMapping('field_attachements', 'attachment_fids')->sourceMigration('Files');
    $this->addFieldMapping('field_attachements:file_class')->defaultValue('MigrateFileFid');

    $this->addUnmigratedDestinations(array(
      'field_attachement:language',
      'field_attachement:description',
      'field_attachement:display',
    ));
  }


  public function prepareRow ($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->attachment_fids = Database::getConnection('default', $this->sourceConnection)
      ->select('upload', 'u')
      ->fields('u', array('fid'))
      ->condition('nid', $row->nid)
      ->condition('vid', $row->vid)
      ->orderBy('weight')
      ->execute()
      ->fetchCol();
  }
}

/**
 * Press review mappings and handling.
 *
 * @todo Get the attachment description.
 */
class PPSPressReviewMigration extends PPSNodeMigration {
  public function __construct(array $arguments) {
    $this->sourceFields['attachment_fids'] = t('File attachments');

    parent::__construct($arguments);

    $this->addFieldMapping('field_media_company', 2)
      ->sourceMigration('Media')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('field_date', 'field_date');
    $this->addUnmigratedSources(array(
      'field_date:value2',
    ));
    $this->addUnmigratedDestinations(array(
      'field_media_company:source_type',
      'field_media_company:create_term',
      'field_media_company:ignore_case',
    ));
  }
}
