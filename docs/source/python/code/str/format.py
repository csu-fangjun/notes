#!/usr/bin/env python3

a = 1
b = 2
c = 3
assert "{}".format(a) == "1"
assert "{}".format(b) == "2"
assert "{0} {1} {foo}".format(a, b, foo=c) == "1 2 3"

# 1 - the first positional argument (counting from 0)
# foo - it is a keyword argument
# 0 - the zeros positional
assert "{1} {foo} {0}".format(a, b, foo=c) == "2 3 1"

assert "{0} {1} {0} {0}".format(a, b) == "1 2 1 1"

assert "skip braces {0} {{}}".format(a) == "skip braces 1 {}"
print("{}")  # {}
try:
    print("{} {}".format(a))
except IndexError as e:
    assert str(e) == "Replacement index 1 out of range for positional args tuple"

assert "{0:2}".format(a) == " 1"
assert "{0:02}".format(a) == "01"
assert "{0:03}".format(a) == "001"
assert "{0:1}".format(-1) == "-1"
assert "{0:2}".format(-1) == "-1"
assert "{0:3}".format(-1) == " -1"
assert "{0:03}".format(-1) == "-01"

assert "{0:.2f}".format(0.5) == "0.50"
assert "{0:.3f}".format(0.5) == "0.500"
