<?php
/**
 * @file
 * dt_test_flexible_date_content.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function dt_test_flexible_date_content_uuid_features_default_content() {
  $nodes = array();

  $nodes[] =  array(
  'title' => 'Test Date - year granularity',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 1,
  'sticky' => 0,
  'dt_node_settings_data' => 'a:2:{s:30:"dt_editorial_linguistic_review";i:0;s:27:"dt_editorial_content_review";i:0;}',
  'ds_switch' => '',
  'type' => 'dt_test_content_type',
  'language' => 'en',
  'created' => 1483436225,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '3886b725-4401-4c3f-b39c-759c0007d582',
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>test</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_test_flexible_date' => array(
    'und' => array(
      0 => array(
        'date' => 1483138800,
        'granularity' => 'year',
      ),
    ),
  ),
  'translations' =>  array(
    'original' => NULL,
    'data' => array(),
  ),
  'metatags' => array(
    'en' => array(
      'revisit-after' => array(
        'value' => 15,
        'period' => 'day',
      ),
    ),
  ),
  'entity_type' => 'node',
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'comment_count' => 0,
  'weight_weight' => FALSE,
  'print_html_display' => 1,
  'print_html_display_comment' => 0,
  'print_html_display_urllist' => 1,
  'print_mail_display' => 1,
  'print_mail_display_comment' => 0,
  'print_mail_display_urllist' => 1,
  'print_pdf_display' => 1,
  'print_pdf_display_comment' => 0,
  'print_pdf_display_urllist' => 1,
  'print_pdf_size' => NULL,
  'print_pdf_orientation' => NULL,
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-01-03 10:37:05 +0100',
  'user_uuid' => '8dfe256c-d44e-429b-ac06-581db34189ec',
);
  $nodes[] =  array(
  'title' => 'Test Date - Month granularity',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 1,
  'sticky' => 0,
  'dt_node_settings_data' => 'a:2:{s:30:"dt_editorial_linguistic_review";i:0;s:27:"dt_editorial_content_review";i:0;}',
  'ds_switch' => '',
  'type' => 'dt_test_content_type',
  'language' => 'en',
  'created' => 1483436185,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '3d6e8af2-d2f3-49ef-8dcc-488f6a281698',
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>test</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_test_flexible_date' => array(
    'und' => array(
      0 => array(
        'date' => 1483138800,
        'granularity' => 'month',
      ),
    ),
  ),
  'translations' =>  array(
    'original' => NULL,
    'data' => array(),
  ),
  'metatags' => array(
    'en' => array(
      'revisit-after' => array(
        'value' => 15,
        'period' => 'day',
      ),
    ),
  ),
  'entity_type' => 'node',
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'comment_count' => 0,
  'weight_weight' => FALSE,
  'print_html_display' => 1,
  'print_html_display_comment' => 0,
  'print_html_display_urllist' => 1,
  'print_mail_display' => 1,
  'print_mail_display_comment' => 0,
  'print_mail_display_urllist' => 1,
  'print_pdf_display' => 1,
  'print_pdf_display_comment' => 0,
  'print_pdf_display_urllist' => 1,
  'print_pdf_size' => NULL,
  'print_pdf_orientation' => NULL,
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-01-03 10:36:25 +0100',
  'user_uuid' => '8dfe256c-d44e-429b-ac06-581db34189ec',
);
  $nodes[] =  array(
  'title' => 'test date january - day granularity',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 1,
  'sticky' => 0,
  'dt_node_settings_data' => 'a:2:{s:30:"dt_editorial_linguistic_review";i:0;s:27:"dt_editorial_content_review";i:0;}',
  'ds_switch' => '',
  'type' => 'dt_test_content_type',
  'language' => 'en',
  'created' => 1483451478,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '68f5547a-9719-4859-9037-b74a54c074fd',
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>test</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_test_flexible_date' => array(
    'und' => array(
      0 => array(
        'date' => 1483311600,
        'granularity' => 'day',
      ),
    ),
  ),
  'translations' =>  array(
    'original' => NULL,
    'data' => array(),
  ),
  'metatags' => array(
    'en' => array(
      'revisit-after' => array(
        'value' => 15,
        'period' => 'day',
      ),
    ),
  ),
  'entity_type' => 'node',
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'comment_count' => 0,
  'weight_weight' => FALSE,
  'print_html_display' => 1,
  'print_html_display_comment' => 0,
  'print_html_display_urllist' => 1,
  'print_mail_display' => 1,
  'print_mail_display_comment' => 0,
  'print_mail_display_urllist' => 1,
  'print_pdf_display' => 1,
  'print_pdf_display_comment' => 0,
  'print_pdf_display_urllist' => 1,
  'print_pdf_size' => NULL,
  'print_pdf_orientation' => NULL,
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-01-03 14:51:18 +0100',
  'user_uuid' => '8dfe256c-d44e-429b-ac06-581db34189ec',
);
  $nodes[] =  array(
  'title' => 'test date January - month granularity',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 1,
  'sticky' => 0,
  'dt_node_settings_data' => 'a:2:{s:30:"dt_editorial_linguistic_review";i:0;s:27:"dt_editorial_content_review";i:0;}',
  'ds_switch' => '',
  'type' => 'dt_test_content_type',
  'language' => 'en',
  'created' => 1483451531,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '6997244d-735d-4648-9b5e-9dc636fab187',
  'body' => array(),
  'field_test_flexible_date' => array(
    'und' => array(
      0 => array(
        'date' => 1483311600,
        'granularity' => 'month',
      ),
    ),
  ),
  'translations' =>  array(
    'original' => NULL,
    'data' => array(),
  ),
  'metatags' => array(
    'en' => array(
      'revisit-after' => array(
        'value' => 15,
        'period' => 'day',
      ),
    ),
  ),
  'entity_type' => 'node',
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'comment_count' => 0,
  'weight_weight' => FALSE,
  'print_html_display' => 1,
  'print_html_display_comment' => 0,
  'print_html_display_urllist' => 1,
  'print_mail_display' => 1,
  'print_mail_display_comment' => 0,
  'print_mail_display_urllist' => 1,
  'print_pdf_display' => 1,
  'print_pdf_display_comment' => 0,
  'print_pdf_display_urllist' => 1,
  'print_pdf_size' => NULL,
  'print_pdf_orientation' => NULL,
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-01-03 14:52:11 +0100',
  'user_uuid' => '8dfe256c-d44e-429b-ac06-581db34189ec',
);
  $nodes[] =  array(
  'title' => 'Test Date - Day granularity',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 1,
  'sticky' => 0,
  'dt_node_settings_data' => 'a:2:{s:30:"dt_editorial_linguistic_review";i:0;s:27:"dt_editorial_content_review";i:0;}',
  'ds_switch' => '',
  'type' => 'dt_test_content_type',
  'language' => 'en',
  'created' => 1483436104,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'a85ef542-42fe-4cfd-b38a-020e3c719711',
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>test</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_test_flexible_date' => array(
    'und' => array(
      0 => array(
        'date' => 1483138800,
        'granularity' => 'day',
      ),
    ),
  ),
  'translations' =>  array(
    'original' => NULL,
    'data' => array(),
  ),
  'metatags' => array(
    'en' => array(
      'revisit-after' => array(
        'value' => 15,
        'period' => 'day',
      ),
    ),
  ),
  'entity_type' => 'node',
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'comment_count' => 0,
  'weight_weight' => FALSE,
  'print_html_display' => 1,
  'print_html_display_comment' => 0,
  'print_html_display_urllist' => 1,
  'print_mail_display' => 1,
  'print_mail_display_comment' => 0,
  'print_mail_display_urllist' => 1,
  'print_pdf_display' => 1,
  'print_pdf_display_comment' => 0,
  'print_pdf_display_urllist' => 1,
  'print_pdf_size' => NULL,
  'print_pdf_orientation' => NULL,
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-01-03 10:35:04 +0100',
  'user_uuid' => '8dfe256c-d44e-429b-ac06-581db34189ec',
);
  $nodes[] =  array(
  'title' => 'test date January - year granularity',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 1,
  'sticky' => 0,
  'dt_node_settings_data' => 'a:2:{s:30:"dt_editorial_linguistic_review";i:0;s:27:"dt_editorial_content_review";i:0;}',
  'ds_switch' => '',
  'type' => 'dt_test_content_type',
  'language' => 'en',
  'created' => 1483451671,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'd53d9c7d-bf37-4904-994b-7cdc27358fe2',
  'body' => array(),
  'field_test_flexible_date' => array(
    'und' => array(
      0 => array(
        'date' => 1483311600,
        'granularity' => 'year',
      ),
    ),
  ),
  'translations' =>  array(
    'original' => NULL,
    'data' => array(),
  ),
  'metatags' => array(
    'en' => array(
      'revisit-after' => array(
        'value' => 15,
        'period' => 'day',
      ),
    ),
  ),
  'entity_type' => 'node',
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'comment_count' => 0,
  'weight_weight' => FALSE,
  'print_html_display' => 1,
  'print_html_display_comment' => 0,
  'print_html_display_urllist' => 1,
  'print_mail_display' => 1,
  'print_mail_display_comment' => 0,
  'print_mail_display_urllist' => 1,
  'print_pdf_display' => 1,
  'print_pdf_display_comment' => 0,
  'print_pdf_display_urllist' => 1,
  'print_pdf_size' => NULL,
  'print_pdf_orientation' => NULL,
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-01-03 14:54:31 +0100',
  'user_uuid' => '8dfe256c-d44e-429b-ac06-581db34189ec',
);
  return $nodes;
}
