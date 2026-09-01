chrono
======

- `<https://www.youtube.com/watch?v=P32hvk8b13M&ab_channel=CppCon>`_

    `<https://github.com/CppCon/CppCon2016/tree/master/Tutorials/A%20chrono%20Tutorial>`_

Everything is inside the namespace ``std::chrono``.

Differences between:
  - ``std::time_t``
  - ``std::tm``
  - ``std::time()``

``std::time()`` to get the number of elapsed seconds since the epoch time ``1970.1.1 00:00:00``.
The returned type is ``time_t``. Note its precision is in seconds.

``std::localtime`` converts ``time_t`` to a ``struct tm`` in local time.

``std::mktime()`` converts a ``struct tm`` into ``time_t`` in local time.

``std::asctime()`` converts a ``struct tm`` into a ``char*`` in local time.

``std::ctime()`` converts a ``time_t`` into a ``char*`` in local time.

``std::strftime`` is more powerful.

``std::this_thread::sleep_until`` takes a timepoint as argument, while
``std::this_thread::sleep_for`` takes a duration as argument.

After ``using namespace std::chrono_literals;`` or ``using std::chrono::operator""s``,
we can use ``auto s = 1s``.


.. literalinclude:: ./code/chrono/main.cc
   :language: c++
   :linenos:
   :caption: ./code/chrono/main.cc
