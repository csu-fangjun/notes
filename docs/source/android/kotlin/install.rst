Install
=======

See `<https://kotlinlang.org/docs/command-line.html#run-scripts>`_

.. code-block:: bash

   wget https://github.com/JetBrains/kotlin/releases/download/v1.7.22/kotlin-compiler-1.7.22.zip
   cd $HOME/software
   mkdir kotlin
   cd kotlin
   unzip /path/to/kotlin-compiler-1.7.22.zip
   mv kotlinc 1.7.22
   export PATH=$HOME/software/kotlin/1.7.22/bin:$PATH

Hello world
-----------

Create a file ``hello.kt``:

.. code-block::

   fun main() {
     println("hello world")
   }

Usage 1
^^^^^^^

.. code-block:: bash

   kotlinc hello.kt

It will generate a binary ``hello.native``:

.. code-block:: bash

  $ ls -lh hello.native
  -rwxr-xr-x 1 kuangfangjun root 8.1K Mar 18  2022 hello.native

.. code-block:: bash

   readelf -d hello.native

It prints:

.. code-block:: bash

  Dynamic section at offset 0xe20 contains 24 entries:
    Tag        Type                         Name/Value
   0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]

Note: It depends only on ``libc``.

Usage 2
^^^^^^^

.. code-block:: bash

   kotlinc hello.kt -d hello.jar
   # or
   kotlinc hello.kt -include-runtime -d hello.jar

   # It can be run using:
   java -jar hello.jar
   kotlin -classpath ./hello.jar HelloKt


kotlinc-jvm
-----------

To run kotlin inside an interactive shell.
