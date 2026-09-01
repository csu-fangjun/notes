Shared libs
===========

- `How to write shared libraries <https://www.akkadia.org/drepper/dsohowto.pdf>`_
- `<https://gcc.gnu.org/wiki/Visibility>`_

- Position Independent Code (PIC) in shared libraries

  `<https://eli.thegreenplace.net/2011/11/03/position-independent-code-pic-in-shared-libraries/>`_

- Position Independent Code (PIC) in shared libraries

  `<https://eli.thegreenplace.net/2011/11/03/position-independent-code-pic-in-shared-libraries>`_

- `OpenFST does not recognize FST type "vector" #1 <https://github.com/wincentbalin/compile-static-openfst/issues/1>`_

.. code-block::

   gcc commandline: -fvisibility=hidden

.. code-blcok:: cmake

   set(CMAKE_CXX_VISIBILITY_PRESET hidden)
   set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

   set(CMAKE_POSITION_INDEPENDENT_CODE ON)

   set_property(TARGET foo1 PROPERTY POSITION_INDEPENDENT_CODE ON)

   set_target_properties(foo_library
          PROPERTIES
              C_VISIBILITY_PRESET hidden
              CXX_VISIBILITY_PRESET hidden
   )

--whole-archive
---------------

See

  - `<https://ftp.gnu.org/old-gnu/Manuals/ld-2.9.1/html_node/ld_3.html>`_
  - `<https://stackoverflow.com/questions/805555/ld-linker-question-the-whole-archive-option>`_
  - `<https://jonathanhamberg.com/post/gcc-archive-linker-oddity/>`_

.. code-block:: bash

   g++ main.cc -Wl,--whole-archive -lhttp -Wl,--no-whole-archive -lhandlers


.. code-block:: cmake

   # https://jonathanhamberg.com/post/gcc-archive-linker-oddity/
   target_link_options(hal PUBLIC
          -Wl,--whole-archive libhal.a -Wl,--no-whole-archive
          )

