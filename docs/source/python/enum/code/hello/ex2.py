#!/usr/bin/env python3

from enum import Flag


class Weekday(Flag):
    MONDAY = 1 << 0
    TUESDAY = 1 << 1
    WEDNESDAY = 1 << 2
    THURSDAY = 1 << 3
    FRIDAY = 1 << 4
    SATURDAY = 1 << 5
    SUNDAY = 1 << 6


assert Weekday.MONDAY.value == 1
assert Weekday.TUESDAY.value == 2
assert Weekday.WEDNESDAY.value == 4
assert Weekday.THURSDAY.value == 8
assert Weekday.FRIDAY.value == 16
assert Weekday.SATURDAY.value == 32
assert Weekday.SUNDAY.value == 64

weekend = Weekday.SATURDAY | Weekday.SUNDAY
print(weekend)  # Weekday.SUNDAY|SATURDAY
print(repr(weekend))  # <Weekday.SUNDAY|SATURDAY: 96>
assert Weekday.SATURDAY in weekend
assert Weekday.SUNDAY in weekend
assert Weekday.MONDAY not in weekend
