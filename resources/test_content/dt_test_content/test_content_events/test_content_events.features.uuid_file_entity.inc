<?php

/**
 * @file
 * test_content_events.features.uuid_file_entity.inc
 */

/**
 * Implements hook_uuid_features_default_file_entities().
 */
function test_content_events_uuid_features_default_file_entities() {
  $files = array();

  $files[] = array(
    'filename' => 'dummy-576x1024-white.jpg',
    'uri' => 'public://dummy-576x1024-white.jpg',
    'filemime' => 'image/jpeg',
    'filesize' => 50984,
    'status' => 1,
    'type' => 'image',
    'uuid' => '121fa10e-c8ec-49c8-88f6-88ae82cdeacd',
    'field_file_image_alt_text' => array(),
    'field_file_image_title_text' => array(),
    'field_caption' => array(),
    'translations' => (object) array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'file',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1467621782,
          'entity_uuid' => '121fa10e-c8ec-49c8-88f6-88ae82cdeacd',
          'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
        ),
      ),
    ),
    'metatags' => array(
      'en' => array(
        'revisit-after' => array(
          'value' => 15,
          'period' => 'day',
        ),
      ),
    ),
    'rdf_mapping' => array(),
    'metadata' => array(
      'height' => 1024,
      'width' => 576,
    ),
    'alt' => '',
    'title' => '',
    'height' => 1024,
    'width' => 576,
    'uuid_features_packaged_file_path' => 'assets/dummy-576x1024-white.jpg',
    'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
  );
  $files[] = array(
    'filename' => 'Dummy image 2',
    'uri' => 'public://dummy-600x900-goemetry.jpg',
    'filemime' => 'image/jpeg',
    'filesize' => 235832,
    'status' => 1,
    'type' => 'image',
    'uuid' => '1bca4f03-390e-4f5e-bf42-2fc16aef2d78',
    'field_file_image_alt_text' => array(
      'und' => array(
        0 => array(
          'value' => 'Dummy image 2',
          'format' => NULL,
        ),
      ),
    ),
    'field_file_image_title_text' => array(
      'und' => array(
        0 => array(
          'value' => 'Dummy image 2',
          'format' => NULL,
        ),
      ),
    ),
    'field_caption' => array(
      'und' => array(
        0 => array(
          'value' => 'Dummy image 2',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => (object) array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'file',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1467380636,
          'entity_uuid' => '1bca4f03-390e-4f5e-bf42-2fc16aef2d78',
          'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
        ),
      ),
    ),
    'metatags' => array(
      'en' => array(
        'revisit-after' => array(
          'value' => 15,
          'period' => 'day',
        ),
      ),
    ),
    'rdf_mapping' => array(),
    'metadata' => array(
      'height' => 900,
      'width' => 600,
    ),
    'alt' => 'Dummy image 2',
    'title' => 'Dummy image 2',
    'height' => 900,
    'width' => 600,
    'uuid_features_packaged_file_path' => 'assets/dummy-600x900-goemetry.jpg',
    'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
  );
  $files[] = array(
    'filename' => 'dummy-375x500-menu.jpg',
    'uri' => 'public://dummy-375x500-menu.jpg',
    'filemime' => 'image/jpeg',
    'filesize' => 21770,
    'status' => 1,
    'type' => 'image',
    'uuid' => '5403a9af-6c21-4a64-9f92-215e39d29230',
    'field_file_image_alt_text' => array(),
    'field_file_image_title_text' => array(),
    'field_caption' => array(),
    'translations' => (object) array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'file',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1467621762,
          'entity_uuid' => '5403a9af-6c21-4a64-9f92-215e39d29230',
          'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
        ),
      ),
    ),
    'metatags' => array(
      'en' => array(
        'revisit-after' => array(
          'value' => 15,
          'period' => 'day',
        ),
      ),
    ),
    'rdf_mapping' => array(),
    'metadata' => array(
      'height' => 500,
      'width' => 375,
    ),
    'alt' => '',
    'title' => '',
    'height' => 500,
    'width' => 375,
    'uuid_features_packaged_file_path' => 'assets/dummy-375x500-menu.jpg',
    'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
  );
  $files[] = array(
    'filename' => '1500x350.png',
    'uri' => 'public://1500x350.png',
    'filemime' => 'image/png',
    'filesize' => 18672,
    'status' => 1,
    'type' => 'image',
    'uuid' => '74103801-0e9e-4b7d-8c67-1d31735a4246',
    'field_file_image_alt_text' => array(),
    'field_file_image_title_text' => array(),
    'field_caption' => array(),
    'translations' => (object) array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'file',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1467637294,
          'entity_uuid' => '74103801-0e9e-4b7d-8c67-1d31735a4246',
          'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
        ),
      ),
    ),
    'metatags' => array(
      'en' => array(
        'revisit-after' => array(
          'value' => 15,
          'period' => 'day',
        ),
      ),
    ),
    'rdf_mapping' => array(),
    'metadata' => array(
      'height' => 350,
      'width' => 1500,
    ),
    'alt' => '',
    'title' => '',
    'height' => 350,
    'width' => 1500,
    'uuid_features_packaged_file_path' => 'assets/1500x350.png',
    'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
  );
  $files[] = array(
    'filename' => 'Dummy image 1',
    'uri' => 'public://dummy-683x1024-map.jpg',
    'filemime' => 'image/jpeg',
    'filesize' => 152679,
    'status' => 1,
    'type' => 'image',
    'uuid' => 'b9fdd119-46b3-4e2f-ade5-4a0e4eb0fdb0',
    'field_file_image_alt_text' => array(
      'und' => array(
        0 => array(
          'value' => 'Dummy image 1',
          'format' => NULL,
        ),
      ),
    ),
    'field_file_image_title_text' => array(
      'und' => array(
        0 => array(
          'value' => 'Dummy image 1',
          'format' => NULL,
        ),
      ),
    ),
    'field_caption' => array(
      'und' => array(
        0 => array(
          'value' => 'Dummy image 1 Dummy image 1Dummy image 1 Dummy image 1 Dummy image 1 Dummy image 1 Dummy image 1',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => (object) array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'file',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1467702349,
          'entity_uuid' => 'b9fdd119-46b3-4e2f-ade5-4a0e4eb0fdb0',
          'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
        ),
      ),
    ),
    'metatags' => array(
      'en' => array(
        'title' => array(
          'value' => '[current-page:title] | [site:name]',
          'default' => '[current-page:title] | [site:name]',
        ),
        'description' => array(
          'value' => '[site:name] - [site:slogan]',
          'default' => '[site:name] - [site:slogan]',
        ),
        'abstract' => array(
          'value' => '',
          'default' => '',
        ),
        'keywords' => array(
          'value' => 'European Commission, European Union, EU',
          'default' => 'European Commission, European Union, EU',
        ),
        'robots' => array(
          'value' => array(
            'index' => 'index',
            'follow' => 'follow',
            'noindex' => 0,
            'nofollow' => 0,
            'noarchive' => 0,
            'nosnippet' => 0,
            'noodp' => 0,
            'noydir' => 0,
            'noimageindex' => 0,
            'notranslate' => 0,
          ),
          'default' => array(
            'index' => 'index',
            'follow' => 'follow',
            'noindex' => 0,
            'nofollow' => 0,
            'noarchive' => 0,
            'nosnippet' => 0,
            'noodp' => 0,
            'noydir' => 0,
            'noimageindex' => 0,
            'notranslate' => 0,
          ),
        ),
        'news_keywords' => array(
          'value' => '',
          'default' => '',
        ),
        'standout' => array(
          'value' => '',
          'default' => '',
        ),
        'rating' => array(
          'value' => '',
          'default' => '',
        ),
        'referrer' => array(
          'value' => '',
          'default' => '',
        ),
        'rights' => array(
          'value' => '',
          'default' => '',
        ),
        'image_src' => array(
          'value' => '',
          'default' => '',
        ),
        'canonical' => array(
          'value' => '[current-page:url:absolute]',
          'default' => '[current-page:url:absolute]',
        ),
        'shortlink' => array(
          'value' => '[current-page:url:unaliased]',
          'default' => '[current-page:url:unaliased]',
        ),
        'publisher' => array(
          'value' => '',
          'default' => '',
        ),
        'author' => array(
          'value' => '',
          'default' => '',
        ),
        'original-source' => array(
          'value' => '',
          'default' => '',
        ),
        'prev' => array(
          'value' => '',
          'default' => '',
        ),
        'next' => array(
          'value' => '',
          'default' => '',
        ),
        'revisit-after' => array(
          'value' => 15,
          'period' => 'day',
          'default' => 15,
        ),
        'content-language' => array(
          'value' => '[dt_tokens:dt_content_language]',
          'default' => '[dt_tokens:dt_content_language]',
        ),
        'geo.position' => array(
          'value' => '',
          'default' => '',
        ),
        'geo.placename' => array(
          'value' => '',
          'default' => '',
        ),
        'geo.region' => array(
          'value' => '',
          'default' => '',
        ),
        'icbm' => array(
          'value' => '',
          'default' => '',
        ),
        'refresh' => array(
          'value' => '',
          'default' => '',
        ),
        'dcterms.title' => array(
          'value' => '[current-page:title]',
          'default' => '[current-page:title]',
        ),
        'dcterms.creator' => array(
          'value' => '',
          'default' => '',
        ),
        'dcterms.subject' => array(
          'value' => '',
          'default' => '',
        ),
        'dcterms.description' => array(
          'value' => '',
          'default' => '',
        ),
        'dcterms.publisher' => array(
          'value' => '',
          'default' => '',
        ),
        'dcterms.contributor' => array(
          'value' => '',
          'default' => '',
        ),
        'dcterms.date' => array(
          'value' => '',
          'default' => '',
        ),
        'dcterms.type' => array(
          'value' => 'Text',
          'default' => 'Text',
        ),
        'dcterms.format' => array(
          'value' => 'text/html',
          'default' => 'text/html',
        ),
        'dcterms.identifier' => array(
          'value' => '[current-page:url:absolute]',
          'default' => '[current-page:url:absolute]',
        ),
        'dcterms.source' => array(
          'value' => '',
          'default' => '',
        ),
        'dcterms.language' => array(
          'value' => '',
          'default' => '',
        ),
        'dcterms.relation' => array(
          'value' => '',
          'default' => '',
        ),
        'dcterms.coverage' => array(
          'value' => '',
          'default' => '',
        ),
        'dcterms.rights' => array(
          'value' => '',
          'default' => '',
        ),
        'fb:admins' => array(
          'value' => '',
          'default' => '',
        ),
        'fb:app_id' => array(
          'value' => '',
          'default' => '',
        ),
        'og:type' => array(
          'value' => 'website',
          'default' => 'website',
        ),
        'og:url' => array(
          'value' => '[current-page:url:absolute]',
          'default' => '[current-page:url:absolute]',
        ),
        'og:title' => array(
          'value' => '[current-page:title]',
          'default' => '[current-page:title]',
        ),
        'og:determiner' => array(
          'value' => '',
          'default' => '',
        ),
        'og:description' => array(
          'value' => '[site:name] - [site:slogan]',
          'default' => '[site:name] - [site:slogan]',
        ),
        'og:updated_time' => array(
          'value' => '',
          'default' => '',
        ),
        'og:see_also' => array(
          'value' => '',
          'default' => '',
        ),
        'og:image' => array(
          'value' => '',
          'default' => '',
        ),
        'og:image:url' => array(
          'value' => '',
          'default' => '',
        ),
        'og:image:secure_url' => array(
          'value' => '',
          'default' => '',
        ),
        'og:image:type' => array(
          'value' => '',
          'default' => '',
        ),
        'og:image:width' => array(
          'value' => '',
          'default' => '',
        ),
        'og:image:height' => array(
          'value' => '',
          'default' => '',
        ),
        'og:latitude' => array(
          'value' => '',
          'default' => '',
        ),
        'og:longitude' => array(
          'value' => '',
          'default' => '',
        ),
        'og:street_address' => array(
          'value' => '',
          'default' => '',
        ),
        'og:locality' => array(
          'value' => '',
          'default' => '',
        ),
        'og:region' => array(
          'value' => '',
          'default' => '',
        ),
        'og:postal_code' => array(
          'value' => '',
          'default' => '',
        ),
        'og:country_name' => array(
          'value' => '',
          'default' => '',
        ),
        'og:email' => array(
          'value' => '',
          'default' => '',
        ),
        'og:phone_number' => array(
          'value' => '',
          'default' => '',
        ),
        'og:fax_number' => array(
          'value' => '',
          'default' => '',
        ),
        'og:locale' => array(
          'value' => '',
          'default' => '',
        ),
        'og:locale:alternate' => array(
          'value' => '',
          'default' => '',
        ),
        'article:author' => array(
          'value' => '',
          'default' => '',
        ),
        'article:publisher' => array(
          'value' => '',
          'default' => '',
        ),
        'article:section' => array(
          'value' => '',
          'default' => '',
        ),
        'article:tag' => array(
          'value' => '',
          'default' => '',
        ),
        'article:published_time' => array(
          'value' => '',
          'default' => '',
        ),
        'article:modified_time' => array(
          'value' => '',
          'default' => '',
        ),
        'article:expiration_time' => array(
          'value' => '',
          'default' => '',
        ),
        'profile:first_name' => array(
          'value' => '',
          'default' => '',
        ),
        'profile:last_name' => array(
          'value' => '',
          'default' => '',
        ),
        'profile:username' => array(
          'value' => '',
          'default' => '',
        ),
        'profile:gender' => array(
          'value' => '',
          'default' => '',
        ),
        'og:audio' => array(
          'value' => '',
          'default' => '',
        ),
        'og:audio:secure_url' => array(
          'value' => '',
          'default' => '',
        ),
        'og:audio:type' => array(
          'value' => '',
          'default' => '',
        ),
        'book:author' => array(
          'value' => '',
          'default' => '',
        ),
        'book:isbn' => array(
          'value' => '',
          'default' => '',
        ),
        'book:release_date' => array(
          'value' => '',
          'default' => '',
        ),
        'book:tag' => array(
          'value' => '',
          'default' => '',
        ),
        'og:video' => array(
          'value' => '',
          'default' => '',
        ),
        'og:video:secure_url' => array(
          'value' => '',
          'default' => '',
        ),
        'og:video:width' => array(
          'value' => '',
          'default' => '',
        ),
        'og:video:height' => array(
          'value' => '',
          'default' => '',
        ),
        'og:video:type' => array(
          'value' => '',
          'default' => '',
        ),
        'video:actor' => array(
          'value' => '',
          'default' => '',
        ),
        'video:actor:role' => array(
          'value' => '',
          'default' => '',
        ),
        'video:director' => array(
          'value' => '',
          'default' => '',
        ),
        'video:writer' => array(
          'value' => '',
          'default' => '',
        ),
        'video:duration' => array(
          'value' => '',
          'default' => '',
        ),
        'video:release_date' => array(
          'value' => '',
          'default' => '',
        ),
        'video:tag' => array(
          'value' => '',
          'default' => '',
        ),
        'video:series' => array(
          'value' => '',
          'default' => '',
        ),
        'ESS_GF' => array(
          'value' => '',
          'default' => '',
        ),
        'ESS_RF' => array(
          'value' => '',
          'default' => '',
        ),
      ),
    ),
    'rdf_mapping' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'metadata' => array(
      'height' => 1024,
      'width' => 683,
    ),
    'alt' => 'Dummy image 1',
    'title' => 'Dummy image 1',
    'height' => 1024,
    'width' => 683,
    'pathauto_perform_alias' => FALSE,
    'uuid_features_packaged_file_path' => 'assets/dummy-683x1024-map.jpg',
    'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
  );
  $files[] = array(
    'filename' => '350x1500.png',
    'uri' => 'public://350x1500.png',
    'filemime' => 'image/png',
    'filesize' => 17816,
    'status' => 1,
    'type' => 'image',
    'uuid' => 'c3eccd87-b1f2-40db-9661-c29d7ae0ea56',
    'field_file_image_alt_text' => array(),
    'field_file_image_title_text' => array(),
    'field_caption' => array(),
    'translations' => (object) array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'file',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1467637275,
          'entity_uuid' => 'c3eccd87-b1f2-40db-9661-c29d7ae0ea56',
          'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
        ),
      ),
    ),
    'metatags' => array(
      'en' => array(
        'revisit-after' => array(
          'value' => 15,
          'period' => 'day',
        ),
      ),
    ),
    'rdf_mapping' => array(),
    'metadata' => array(
      'height' => 1500,
      'width' => 350,
    ),
    'alt' => '',
    'title' => '',
    'height' => 1500,
    'width' => 350,
    'uuid_features_packaged_file_path' => 'assets/350x1500.png',
    'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
  );
  $files[] = array(
    'filename' => 'dummy-200x200-reddots.jpg',
    'uri' => 'public://dummy-200x200-reddots.jpg',
    'filemime' => 'image/jpeg',
    'filesize' => 24574,
    'status' => 1,
    'type' => 'image',
    'uuid' => 'd494bfed-5661-467b-a311-4e14d93e41d8',
    'field_file_image_alt_text' => array(),
    'field_file_image_title_text' => array(),
    'field_caption' => array(),
    'translations' => (object) array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'file',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1467621992,
          'entity_uuid' => 'd494bfed-5661-467b-a311-4e14d93e41d8',
          'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
        ),
      ),
    ),
    'metatags' => array(
      'en' => array(
        'revisit-after' => array(
          'value' => 15,
          'period' => 'day',
        ),
      ),
    ),
    'rdf_mapping' => array(),
    'metadata' => array(
      'height' => 200,
      'width' => 200,
    ),
    'alt' => '',
    'title' => '',
    'height' => 200,
    'width' => 200,
    'uuid_features_packaged_file_path' => 'assets/dummy-200x200-reddots.jpg',
    'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
  );
  $files[] = array(
    'filename' => 'dummy-540x960-circus.jpg',
    'uri' => 'public://dummy-540x960-circus.jpg',
    'filemime' => 'image/jpeg',
    'filesize' => 112682,
    'status' => 1,
    'type' => 'image',
    'uuid' => 'd8b881a6-8f5d-4587-8122-64d689ac7a99',
    'field_file_image_alt_text' => array(),
    'field_file_image_title_text' => array(),
    'field_caption' => array(),
    'translations' => (object) array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'file',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1467621802,
          'entity_uuid' => 'd8b881a6-8f5d-4587-8122-64d689ac7a99',
          'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
        ),
      ),
    ),
    'metatags' => array(
      'en' => array(
        'revisit-after' => array(
          'value' => 15,
          'period' => 'day',
        ),
      ),
    ),
    'rdf_mapping' => array(),
    'metadata' => array(
      'height' => 960,
      'width' => 540,
    ),
    'alt' => '',
    'title' => '',
    'height' => 960,
    'width' => 540,
    'uuid_features_packaged_file_path' => 'assets/dummy-540x960-circus.jpg',
    'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
  );
  $files[] = array(
    'filename' => 'dummy-454x280-utrecht.jpg',
    'uri' => 'public://dummy-454x280-utrecht.jpg',
    'filemime' => 'image/jpeg',
    'filesize' => 60584,
    'status' => 1,
    'type' => 'image',
    'uuid' => 'e995eb2e-f1ba-412c-9de5-c6eb472f4003',
    'field_file_image_alt_text' => array(),
    'field_file_image_title_text' => array(),
    'field_caption' => array(),
    'translations' => (object) array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'file',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1467621822,
          'entity_uuid' => 'e995eb2e-f1ba-412c-9de5-c6eb472f4003',
          'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
        ),
      ),
    ),
    'metatags' => array(
      'en' => array(
        'revisit-after' => array(
          'value' => 15,
          'period' => 'day',
        ),
      ),
    ),
    'rdf_mapping' => array(),
    'metadata' => array(
      'height' => 280,
      'width' => 454,
    ),
    'alt' => '',
    'title' => '',
    'height' => 280,
    'width' => 454,
    'uuid_features_packaged_file_path' => 'assets/dummy-454x280-utrecht.jpg',
    'user_uuid' => '77c75ce2-683f-4b8a-8caa-17af2705ba2c',
  );
  return $files;
}
