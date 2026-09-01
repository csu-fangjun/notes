gradle
=======

Install
-------

.. code-block::

   brew install gradle

   which grade

   # /opt/homebrew/bin/gradle

.. code-block::

  cat $(which gradle)

  #!/bin/bash
  JAVA_HOME="${JAVA_HOME:-/opt/homebrew/opt/openjdk/libexec/openjdk.jdk/Contents/Home}" exec "/opt/homebrew/Cellar/gradle/9.6.1/libexec/bin/gradle"  "$@"


Content of `/opt/homebrew/Cellar/gradle/9.6.1/libexec/bin/gradle`:

.. literalinclude:: ./code/gradle

A book: Get going with gradle
------------------------------

A book `<https://assets.tomgregory.com/get-going-with-gradle/get-going-with-gradle-book.pdf>`_

Basics
------

If a project uses gradle, run the following command to build it:

.. code-block::

   ./gradlew build

   # on windows, use
   ./gradlew.bat build

`./build.gradle.kts` in the project contains the build script

- ``kts``: kotlin script
- ``DSL``: domain specific language.



.. code-block::

   # show a list of available tasks
   ./gradlew tasks

   # show version
   ./gradlew --version

On macos, it prints::

  ./gradlew --version

  ------------------------------------------------------------
  Gradle 9.1.0
  ------------------------------------------------------------

  Build time:    2025-09-18 13:05:56 UTC
  Revision:      e45a8dbf2470c2e2474ccc25be9f49331406a07e

  Kotlin:        2.2.0
  Groovy:        4.0.28
  Ant:           Apache Ant(TM) version 1.10.15 compiled on August 25 2024
  Launcher JVM:  25.0.1 (Oracle Corporation 25.0.1+8-LTS-27)
  Daemon JVM:    Compatible with Java 21, Azul Zulu, nativeImageCapable=false (from gradle/gradle-daemon-jvm.properties)
  OS:            Mac OS X 15.5 aarch64

On windows, it prints::

  .\gradlew.bat --version

  ------------------------------------------------------------
  Gradle 9.6.1
  ------------------------------------------------------------

  Build time:    2026-06-26 14:25:50 UTC
  Revision:      309d128bd9fe8c0b71311878fc660b9cbaa07c51

  Kotlin:        2.3.21
  Groovy:        4.0.32
  Ant:           Apache Ant(TM) version 1.10.17 compiled on April 6 2026
  Launcher JVM:  21.0.7 (Oracle Corporation 21.0.7+8-LTS-245)
  Daemon JVM:    D:\software\jdk-21.0.7 (no Daemon JVM specified, using current Java home)
  OS:            Windows 10 10.0 amd64
