Coroutine
=========

Setup from commandline
----------------------

Refer to `<https://stackoverflow.com/questions/79103733/how-to-use-kotlinx-with-the-command-line-compiler-kotlinc>`_

Visit `<https://mvnrepository.com/artifact/org.jetbrains.kotlinx/kotlinx-coroutines-core-jvm>`_,
select a version, e.g., ``1.10.1``, and it goes to
`<https://mvnrepository.com/artifact/org.jetbrains.kotlinx/kotlinx-coroutines-core-jvm/1.10.1>`_.
Click the link `<https://repo1.maven.org/maven2/org/jetbrains/kotlinx/kotlinx-coroutines-core-jvm/1.10.1/kotlinx-coroutines-core-jvm-1.10.1.jar>`_.

.. hint::

   For android, it is ``kotlinx-coroutines-android``.
   For js, it is ``kotlinx-coroutines-core-js``.

.. literalinclude:: ./code/coroutine/Hello.kt
   :language: kotlin
   :caption: ./code/coroutine/Hello.kt

Run:

.. code-block:: bash

  kotlinc -cp ./kotlinx-coroutines-core-jvm-1.10.1.jar Hello.kt -d hello.jar

It gives the following error::

  kotlinx-coroutines-core-jvm-1.10.1.jar!/META-INF/kotlinx-coroutines-core.kotlin_module:
  error: module was compiled with an incompatible version of Kotlin.
  The binary version of its metadata is 2.1.0, expected version is 1.8.0.

``kotlinc --version`` prints::

  info: kotlinc-jvm 1.8.0 (JRE 17.0.5+9-LTS-191)

so we need to update our kotlin::

  cd $HOME/software/
  mkdir -p kotlin
  cd kotlin
  wget https://github.com/JetBrains/kotlin/releases/download/v2.1.0/kotlin-compiler-2.1.0.zip
  unzip kotlin-compiler-2.1.0.zip

  mv kotlinc 2.1.0
  export PATH=$HOME/software/kotlin/2.1.0/bin:$PATH

Then we can run::

  kotlinc -cp ./kotlinx-coroutines-core-jvm-1.10.1.jar Hello.kt -d hello.jar

It will generate a file ``hello.jar``.

.. code-block:: bash

   ls -lh hello.jar
   -rw-r--r--  1 fangjun  staff   4.0K Jan  1 16:20 hello.jar

We can run it with::

  kotlin -classpath ./hello.jar:./kotlinx-coroutines-core-jvm-1.10.1.jar  HelloKt

Alternatively, we can use::

  kotlinc -cp ./kotlinx-coroutines-core-jvm-1.10.1.jar Hello.kt -include-runtime -d hello.jar

``hello.jar`` is much larger than before::

  ls -lh hello.jar
  -rw-r--r--  1 fangjun  staff   4.6M Jan  1 16:22 hello.jar

Then we can use::

  java -classpath ./hello.jar:./kotlinx-coroutines-core-jvm-1.10.1.jar  HelloKt
  java -cp ./hello.jar:./kotlinx-coroutines-core-jvm-1.10.1.jar  HelloKt
  kotlin -cp ./hello.jar:./kotlinx-coroutines-core-jvm-1.10.1.jar  HelloKt
  kotlin -classpath ./hello.jar:./kotlinx-coroutines-core-jvm-1.10.1.jar  HelloKt

thread related functions
-------------------------

.. code-block::

   Thread.sleep(1000L) # sleep 1000ms, i.e., 1s

common suspendable functions
----------------------------

.. code-block::

   delay(1000L) # sleep 1000m, i.e., 1s

Predefined coroutine dispatcher
-------------------------------

- ``Dispatchers.Default``: Compute-intensive
- ``Dispatchers.IO``: File I/O, blocking socket I/O, etc
- ``Dispatchers.Main``: For UI thread

functions without a scope
--------------------------

- ``runBlocking``, it is not a ``suspend`` function, coroutine builder, scope builder
- ``coroutineScope()``, it is a ``suspend`` function, scope builder
- ``withContext()``, it is a ``suspend`` function

functions requiring a scope
----------------------------

- ``launch()``, e.g., ``GlobalScope.lanuch``, it is not a ``suspend`` function. coroutine builder
- ``async()``, e.g., ``GlobalScope.async``, it is not a ``suspend`` function. coroutine builder
