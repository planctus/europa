## dt_date_format readme.

The dt_date_format extends the default date formatting.

By using the class DtDateRangeFormat you can provide a more extended version of date formatting. It diverges the time
into a start (sd_) and end date (ed_). 

All original date formats are supported.

Example:

```php
$date_object = new DtDateRangeFormat($start_date, $end_date, 'datestamp');
// Tuesday 17 March, 9.00 – 18.00 (CET).
$date_object->setFormat('sd_l sd_d sd_M, sd_H:sd_i - ed_H:ed_i (sd_T)');
echo $date_object->getformattedDateRange();
```

The class also provides a usefull helper methodes:

```php
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
```

Those can be used to conditionally format the date. Example:

```php
// Same date||day||hour (Tuesday 17 March).
if ($date_object->isSameDate(TRUE) || $date_object->isSameDate(FALSE, 'Ymd') || $date_object->isSameDate(FALSE, 'YmdHi')) {
  $date_object->setFormat('sd_l sd_j sd_F');
}
// Not the same day, but the same month.
elseif ($date_object->isSameDate(FALSE, 'Ym')) {
  $date_object->setFormat('sd_l sd_j - ed_l ed_j sd_F');
}
// Not the same day or month. (fallback).
else {
  $date_object->setFormat('sd_l sd_j sd_F - ed_l ed_j ed_F');
}
```
