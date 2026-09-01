enum
====

.. code-block::

  enum class Weekday {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
  }

  for(day in Weekday.values()) {
    // day.ordinal: 0, 1, 2, 3, 4
    // day.name: Monday, Tuesday, Wednesday, Thursday
  }

  Weekday.valueOf("Monday") == Weekday.Monday
