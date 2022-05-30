#!/usr/bin/env python3

from enum import Enum


class Color(Enum):
    RED = 1
    GREEN = 2
    BLUE = 3
    #  BLUE = 4 # TypeError: Attempted to reuse key: 'BLUE'
    ALIAS_FOR_RED = 1  # Use @unique to disallow this
    MAX_COLOR = 4  # Note the naming convention


assert isinstance(Color.RED, Color)

assert str(Color(1)) == "Color.RED"
assert str(repr(Color(1))) == "<Color.RED: 1>"

assert Color.RED.name == "RED"
assert Color.BLUE.value == 3

print(list(Color))
print(type(list(Color)[0]))
for c in Color:
    print(c, type(c))

"""
[<Color.RED: 1>, <Color.GREEN: 2>, <Color.BLUE: 3>, <Color.MAX_COLOR: 4>]
<enum 'Color'>
Color.RED <enum 'Color'>
Color.GREEN <enum 'Color'>
Color.BLUE <enum 'Color'>
Color.MAX_COLOR <enum 'Color'>
"""

assert Color(1) == Color.RED
assert Color["RED"] == Color.RED
assert Color["ALIAS_FOR_RED"] == Color.RED

print(Color.__members__)
"""
{'RED': <Color.RED: 1>, 'GREEN': <Color.GREEN: 2>, 'BLUE': <Color.BLUE: 3>, 'ALIAS_FOR_RED': <Color.RED: 1>, 'MAX_COLOR': <Color.MAX_COLOR: 4>}
"""
