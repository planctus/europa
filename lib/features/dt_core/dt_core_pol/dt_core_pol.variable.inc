<?php
/**
 * @file
 * dt_core_pol.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function dt_core_pol_variable_realm_default_variables() {
  $realm_variables = array();

  // English.
  $realm_variables['language']['en'] = array(
    'site_name' => "European Commission",
    'site_slogan' => 'Commission and its priorities',
  );
  // Bulgarian.
  $realm_variables['language']['bg'] = array(
    "site_name" => "Европейска комисия",
    "site_slogan" => "Commission and its priorities",
  );
  // Czech.
  $realm_variables['language']['cs'] = array(
    "site_name" => "Evropská komise",
    "site_slogan" => "Commission and its priorities",
  );
  // Danish.
  $realm_variables['language']['da'] = array(
    "site_name" => "Europa-Kommissionen",
    "site_slogan" => "Commission and its priorities",
  );
  // German.
  $realm_variables['language']['de'] = array(
    "site_name" => "EU-Kommission",
    "site_slogan" => "Die Kommission und ihre Prioritäten",
  );
  // Estonian.
  $realm_variables['language']['et'] = array(
    "site_name" => "Euroopa Komisjon",
    "site_slogan" => "Commission and its priorities",
  );
  // Greek.
  $realm_variables['language']['el'] = array(
    "site_name" => "Ευρωπαϊκή Επιτροπή",
    "site_slogan" => "Commission and its priorities",
  );
  // Spanish.
  $realm_variables['language']['es'] = array(
    "site_name" => "Comisión Europea",
    "site_slogan" => "Commission and its priorities",
  );
  // French.
  $realm_variables['language']['fr'] = array(
    "site_name" => "Commission européenne",
    "site_slogan" => "La commission et ses priorités",
  );
  // Irish.
  $realm_variables['language']['ga'] = array(
    "site_name" => "An Coimisiún Eorpach",
    "site_slogan" => "Commission and its priorities",
  );
  // Croatian.
  $realm_variables['language']['hr'] = array(
    "site_name" => "Europska komisija",
    "site_slogan" => "Commission and its priorities",
  );
  // Italian.
  $realm_variables['language']['it'] = array(
    "site_name" => "Commissione europea",
    "site_slogan" => "La Commissione e le sue priorità",
  );
  // Latvian.
  $realm_variables['language']['lv'] = array(
    "site_name" => "Eiropas Komisija",
    "site_slogan" => "Commission and its priorities",
  );
  // Lithuanian.
  $realm_variables['language']['lt'] = array(
    "site_name" => "Europos Komisija",
    "site_slogan" => "Commission and its priorities",
  );
  // Hungarian.
  $realm_variables['language']['hu'] = array(
    "site_name" => "Európai Bizottság",
    "site_slogan" => "Commission and its priorities",
  );
  // Maltese.
  $realm_variables['language']['mt'] = array(
    "site_name" => "Kummissjoni Ewropea",
    "site_slogan" => "Commission and its priorities",
  );
  // Maltese.
  $realm_variables['language']['nl'] = array(
    "site_name" => "Europese Commissie",
    "site_slogan" => "Commission and its priorities",
  );
  // Polish.
  $realm_variables['language']['pl'] = array(
    "site_name" => "Komisja Europejska",
    "site_slogan" => "Commission and its priorities",
  );
  // Portuguese.
  $realm_variables['language']['pt-pt'] = array(
    "site_name" => "Comissão Europeia",
    "site_slogan" => "Commission and its priorities",
  );
  // Romanian.
  $realm_variables['language']['ro'] = array(
    "site_name" => "Comisia Europeană",
    "site_slogan" => "Commission and its priorities",
  );
  // Slovak.
  $realm_variables['language']['sk'] = array(
    "site_name" => "Európska komisia",
    "site_slogan" => "Commission and its priorities",
  );
  // Slovenian.
  $realm_variables['language']['sl'] = array(
    "site_name" => "Evropska komisija",
    "site_slogan" => "Commission and its priorities",
  );
  // Finnish.
  $realm_variables['language']['fi'] = array(
    "site_name" => "Euroopan komissio",
    "site_slogan" => "Commission and its priorities",
  );
  // Swedish.
  $realm_variables['language']['sv'] = array(
    "site_name" => "Europeiska kommissionen",
    "site_slogan" => "Commission and its priorities",
  );

  return $realm_variables;
}
