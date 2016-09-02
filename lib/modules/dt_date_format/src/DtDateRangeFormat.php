<?php

namespace Drupal\dt_date_format;

/**
 * Class DtDateRangeFormat.
 *
 * @package digital_transformation
 */
class DtDateRangeFormat {

  /**
   * The UNIX timestamp of the start date.
   *
   * @var int $startDate
   */
  private $startDate;

  /**
   * The UNIX timestamp of the start date.
   *
   * @var int $endDate
   */
  private $endDate;

  /**
   * The default formattings.
   *
   * The format to use for the time. This is a format specific to this class.
   *   We have the following additional options:
   *   sd_{date} or ed_{date} representing the StartDate and EndDate.
   *
   * @var array $format
   */
  private $format;

  /**
   * The date's timezone, falls back to drupal default.
   *
   * @var string $timezone
   */
  private $timezone;

  /**
   * The language code to use.
   *
   * @var string $language
   */
  private $language;

  /**
   * Class constructor to set the initiatal timestamps.
   *
   * @param string $start_date
   *   The start date.
   * @param string $end_date
   *   The end date.
   * @param string $type
   *   The format of the date.
   * @param string $timezone
   *   The timezone of the date.
   * @param string $language_code
   *   The language to render the date.
   */
  public function __construct($start_date, $end_date, $type, $timezone = NULL, $language_code = NULL) {
    // If the language is not set, we get the global.
    if (is_null($language_code)) {
      global $language;
    }
    $this->setStartDate(($type == 'datestamp') ? $start_date : strtotime($start_date));
    $this->setEndDate(($type == 'datestamp') ? $end_date : strtotime($end_date));
    $this->setTimezone(!is_null($timezone) ? $timezone : drupal_get_user_timezone());
    $this->setLanguage(!is_null($language_code) ? $language_code : $language->language);
  }

  /**
   * Sets the language.
   *
   * @param string $language
   *   The language to render the time in..
   */
  public function setLanguage($language) {
    $this->language = $language;
  }

  /**
   * Sets the timezone.
   *
   * @param string $timezone
   *   The timezone.
   */
  public function setTimezone($timezone) {
    $this->timezone = $timezone;
  }

  /**
   * Sets the start date as timestamp.
   *
   * @param int $start_date
   *   The start date as UNIX timestamp.
   */
  public function setStartDate($start_date) {
    $this->startDate = $start_date;
  }

  /**
   * Sets the end date as timestamp.
   *
   * @param int $end_date
   *   The end date as UNIX timestamp.
   */
  public function setEndDate($end_date) {
    $this->endDate = $end_date;
  }

  /**
   * Sets the language.
   *
   * @return string
   *   The language to render the time in..
   */
  public function getLanguage() {
    return $this->language;
  }

  /**
   * Sets the timezone.
   *
   * @return string
   *   The timezone.
   */
  public function getTimezone() {
    return $this->timezone;
  }

  /**
   * Gets the start date as timestamp.
   *
   * @return int
   *   The start date as UNIX timestamp.
   */
  public function getStartDate() {
    return $this->startDate;
  }

  /**
   * Gets the end date as timestamp.
   *
   * @return int
   *   The end date as UNIX timestamp.
   */
  public function getEndDate() {
    return $this->endDate;
  }

  /**
   * Setter for the date range formats.
   *
   * @param string $formats
   *   The format to use.
   */
  public function setFormat($formats) {
    $this->format = $formats;
  }

  /**
   * Getter for the date format.
   *
   * @return string
   *   The format to use.
   */
  private function getFormat() {
    return $this->format;
  }

  /**
   * Checks if the start and end date are equal.
   *
   * @param bool $strict
   *   To check in a strict way by comparing the timestamp.
   * @param string $format
   *   The format to compare for.
   *
   * @return bool
   *   True/false.
   */
  public function isSameDate($strict = FALSE, $format = 'dmY') {
    if (!$strict) {
      return $this->formatDate($this->getStartDate(), $format) == $this->formatDate($this->getEndDate(), $format);
    }
    return $this->getStartDate() == $this->getEndDate();
  }

  /**
   * Gets an array of days. It will return an array with 1 element if equal.
   *
   * @param string $format
   *   How to format the day.
   *
   * @return array
   *   Array with start and end date.
   */
  public function getDays($format = 'D') {
    $days[] = $this->formatDate($this->startDate, $format);
    // Check if it is the same day.
    if (!$this->isSameDate(FALSE, 'd')) {
      $days[] = $this->formatDate($this->endDate, $format);
    }
    return $days;
  }

  /**
   * Gets an array of months. It will return an array with 1 element if equal.
   *
   * @param string $format
   *   How to format the month.
   *
   * @return array
   *   Array with start and end date.
   */
  public function getMonths($format = 'M') {
    $months[] = $this->formatDate($this->startDate, $format);
    // Check if it is the same month.
    if (!$this->isSameDate(FALSE, 'm')) {
      $months[] = $this->formatDate($this->endDate, $format);
    }
    return $months;
  }

  /**
   * Gets an array of years. It will return an array with 1 element if equal.
   *
   * @param string $format
   *   How to format the year.
   *
   * @return array
   *   Array with start and end date.
   */
  public function getYears($format = 'Y') {
    $years[] = $this->formatDate($this->startDate, $format);
    // Check if it is the same month.
    if (!$this->isSameDate(FALSE, 'Y')) {
      $years[] = $this->formatDate($this->endDate, $format);
    }
    return $years;
  }

  /**
   * Gets the Formatted date range using a specific format.
   *
   * @return string
   *   The formatted date.
   */
  public function getformattedDateRange() {
    // Get the format to use.
    $formatted = $this->getFormat();

    // Match the start date, and replace the results.
    $start_date = [];
    if (preg_match_all('/sd_(\D)/', $formatted, $start_date)) {
      $start_date[1] = explode('%', $this->formatDate($this->getStartDate(), implode('%', $start_date[1])));
    }

    // Match the end date and replace the results.
    $end_date = [];
    if (preg_match_all('/ed_(\D)/', $formatted, $end_date)) {
      $end_date[1] = explode('%', $this->formatDate($this->getEndDate(), implode('%', $end_date[1])));
    }

    // Merry the 2 arrays, we add them up to preserve keys.
    $replacements = [
      'original' => array_merge($start_date[0], $end_date[0]),
      'formatted' => array_merge($start_date[1], $end_date[1]),
    ];

    // Return the fully formatted date.
    return str_replace($replacements['original'], $replacements['formatted'], $formatted);
  }

  /**
   * Helper method to format the date.
   *
   * @param int $date
   *   The date stamp to use.
   * @param string $format
   *   The format to use.
   *
   * @return string
   *   The formatted date string.
   */
  private function formatDate($date, $format) {
    return format_date($date, 'custom', $format, $this->getTimezone(), $this->getLanguage());
  }

}
