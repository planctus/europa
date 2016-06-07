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
   * Class constructor to set the initiatal timestamps.
   *
   * @param string $start_date
   *   The start date.
   * @param string $end_date
   *   The end date.
   * @param string $format
   *   The format of the date.
   */
  public function __construct($start_date, $end_date, $format) {
    $this->startDate = ($format == 'datestamp') ? $start_date : strtotime($start_date);
    $this->endDate = ($format == 'datestamp') ? $end_date : strtotime($end_date);
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
   * @return bool
   *   True/false.
   */
  public function isSameDate() {
    return format_date($this->getStartDate(), 'custom', 'dmY') == format_date($this->getEndDate(), 'custom', 'dmY');
  }

  /**
   * Checks if the start and end date are in the same month.
   *
   * @return bool
   *   True/false.
   */
  public function isSameYear() {
    return format_date($this->getStartDate(), 'custom', 'Y') == format_date($this->getEndDate(), 'custom', 'Y');
  }

  /**
   * Checks if the start and end date are in the same month (in the same year).
   *
   * @return bool
   *   True/false.
   */
  public function isSameMonth() {
    return $this->isSameYear() && format_date($this->getStartDate(), 'custom', 'm') == format_date($this->getEndDate(), 'custom', 'm');
  }

  /**
   * Checks if the start and end date are in the same day.
   *
   * @return bool
   *   True/false.
   */
  public function isSameDay() {
    return $this->isSameMonth() && $this->isSameYear() && format_date($this->getStartDate(), 'custom', 'd') == format_date($this->getEndDate(), 'custom', 'd');
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
    $days[] = format_date($this->startDate, 'custom', $format);
    if (!$this->isSameDay()) {
      $days[] = format_date($this->endDate, 'custom', $format);
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
    $days[] = format_date($this->startDate, 'custom', $format);
    if (!$this->isSameMonth()) {
      $days[] = format_date($this->endDate, 'custom', $format);
    }
    return $days;
  }

  /**
   * Format a date range using a specific format.
   *
   * @return string
   *   The formatted date.
   */
  public function formatDateRange() {
    // List of supported custom format parts.
    $custom_values = [
      'sd_d',
      'ed_d',
      'sd_D',
      'ed_D',
      'sd_M',
      'ed_M',
      'sd_H',
      'ed_H',
      'sd_i',
      'ed_i',
      'sd_T',
    ];

    $formatted = $this->getFormat();

    // Loop over and replace.
    foreach ($custom_values as $part) {
      if (strpos($formatted, $part) !== FALSE) {
        $date = substr($part, 0, 2) == 'sd' ? $this->startDate : $this->endDate;
        $formatted = str_replace($part, format_date($date, 'custom', substr($part, -1)), $formatted);
      }
    }

    return $formatted;
  }

}
