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

The class also provides a few usefull helper methodes:

```php
$date_object->isSameDate();
$date_object->isSameYear();
$date_object->isSameMonth();
$date_object->isSameDay();
```

Those can be used to conditionally format the date. Example:

```php
if ($date_object->isSameDate(TRUE)) {
  // Monday 1 April.
  $date_object->setFormat('sd_l sd_d sd_F');
}
elseif ($date_object->isSameDay()) {
  // Tuesday 17 March, 9.00 – 18.00 (CET).
  $date_object->setFormat('sd_l sd_d sd_F, sd_H:sd_i - ed_H:ed_i (sd_T)');
}
else {
  // Fallback. (Tuesday 17 March, 9.00 – Wednesday 18 March, 18.00 (CET)).
  $date_object->setFormat('sd_l sd_d sd_F, sd_H:sd_i - ed_l ed_d ed_F, ed_H:ed_i (sd_T)');
}
```
