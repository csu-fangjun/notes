Install
=======

Kotlin to java online converter:
`<https://www.codeconvert.ai/kotlin-to-java-converter>`_.

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

.. literalinclude:: ./code/install/hello.kt
   :language: kotlin
   :caption: ./code/install/hello.kt

Usage 1
^^^^^^^

.. code-block:: bash

   kotlinc hello.kt

It will generate a binary file ``HelloKt.class`` and a folder ``META-INF``.

.. code-block:: bash

  $ javap HelloKt.class

The above command prints the following:

.. code-block::

  Compiled from "hello.kt"
  public final class HelloKt {
    public static final void main();
    public static void main(java.lang.String[]);
  }

We can use:

.. code-block::

   kotlin HelloKt.class

to execute it.

Usage 2
^^^^^^^

.. code-block:: bash

   kotlinc hello.kt -d hello.jar
   # or
   kotlinc hello.kt -include-runtime -d hello.jar

   # It can be run using:
   java -jar hello.jar
   kotlin -classpath ./hello.jar HelloKt

Note that ``hello.jar`` is actually a ``zip`` file.


kotlinc-jvm
-----------

To run kotlin inside an interactive shell, we can run the command:

.. code-block::

   kotlinc-jvm

or the command:

.. code-block::

   kotlinc

Naming convention
-----------------

- class: ClassName
- function: funcName
- variable: variableName
- filename extension: ``kt``
