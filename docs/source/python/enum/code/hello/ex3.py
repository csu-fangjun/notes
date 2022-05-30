#!/usr/bin/env python3

from enum import Enum, Flag, auto


class Weekday(Flag):
    MONDAY = auto()  # start from 1
    TUESDAY = auto()
    WEDNESDAY = auto()
    THURSDAY = auto()
    FRIDAY = auto()
    SATURDAY = 128
    SUNDAY = auto()


assert Weekday.MONDAY.value == 1
assert Weekday.TUESDAY.value == 2
assert Weekday.WEDNESDAY.value == 4
assert Weekday.THURSDAY.value == 8
assert Weekday.FRIDAY.value == 16
assert Weekday.SATURDAY.value == 128
assert Weekday.SUNDAY.value == 256


class Color(Enum):
    RED = auto()  # start from 1
    GREEN = auto()
    BLUE = auto()
    YELLOW = 10
    WHITE = auto()


assert Color.RED.value == 1
assert Color.GREEN.value == 2
assert Color.BLUE.value == 3
assert Color.YELLOW.value == 10
assert Color.WHITE.value == 11
