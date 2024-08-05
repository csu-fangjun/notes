Data Types
==========


- ``Int``, ``Float``, ``Double``, ``String``

There are no implicit conversions between types.

Integer to string::

  let a = 3
  let b = "a is " + String(a)


String interpolation, use ``\(value)``. ``value`` can be an expression::
To get a lowercased string, use the method ``.lowercased()`` of a string variable.

  let s = 10
  let s2 = "s is \(s)"


Array of string::

  var arr = [1, 2, 3]
  # The type of arr is [Int]

  # to append a new value to arr
  arr.append(10)

  # to make it empty
  arr = []

  # Create an empty array
  var arr2: [Int] = []

Dictionary (string to int)::

  var d = ["one": 1, "two": 2]

  # type of d is [String: Int]

  # make d empty
  d = [:]

  # create an empty dict that maps string to int
  var d2: [String: Int] = [:]

To iterate an array::

  let values = [1, 2, 3]
  var s = 0
  for i in values {
    s += i
  }
  print(s)
  # s is 6

For loop (1)::

  var k = 0
  for i in 0..<4 {
    k += i
  }
  print(k)
  # k is 6
  # note: 0..<4 produces 0, 1, 2, 3
  # 4 is not included

For loop (2)::

  var k = 0
  for i in 0...4 {
    k += i
  }
  print(k)
  # k is 10
  # note: 0...4 produces 0, 1, 2, 3, 4
  # 4 is included

Optional types::

  var i: Int? = 1
  print(i == nil) // false

  // if i is not nil, then assign i to b
  // if i is nil, then assign 10 to b
  //
  var b = i ?? 10
  print(b) // b is 1

  i = nil
  b = i ?? 10
  print(b) // b is 10
