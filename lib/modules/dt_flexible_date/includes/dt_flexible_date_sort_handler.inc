<?php

/**
 * @file
 * Contains dt_flexible_date_sort_handler.
 */

/**
 * Class for sorting results according flexible date field.
 */
class DtFlexibleDateSortHandler extends views_handler_sort {


  /**
   * The associated views query object.
   */
  public $query;

  /**
   * Called to add the sort to a query.
   */
  public function query() {

    $this->ensure_my_table();
    $field = $this->options['id'];
    $order = $this->options['order'];

    // Build order by clause.
    $date_value = $field . '_date';
    $date_granularity = $field . '_granularity';

    if ($order == 'ASC') {
      $orderby = '( if(' . $date_granularity . ' = \'year\', unix_timestamp(LAST_DAY(concat(year(FROM_UNIXTIME(' . $date_value . ')), \'-12-01\'))),' .
        'if(' . $date_granularity . ' = \'month\', unix_timestamp(LAST_DAY(concat(year(FROM_UNIXTIME(' . $date_value . ')), \'-\' , month(FROM_UNIXTIME(' . $date_value . ')) , \'-01\'))), ' .
        '' . $date_value . ')) )';
    }
    else {
      $orderby = '( if(' . $date_granularity . ' = \'year\', unix_timestamp(concat(year(FROM_UNIXTIME(' . $date_value . ')), \'-01-01\')),' .
        'if(' . $date_granularity . ' = \'month\', unix_timestamp(concat(year(FROM_UNIXTIME(' . $date_value . ')), \'-\' , month(FROM_UNIXTIME(' . $date_value . ')) , \'-01\')), ' .
        '' . $date_value . ')) )';
    }

    $this->query->orderby[] = [
      'field' => $orderby,
      'direction' => $order,
    ];
    $this->query->orderby[] = [
      'field' => 'FIELD (' . $date_granularity . ', \'day\', \'month\', \'year\')',
      'direction' => 'ASC',
    ];
  }

}
