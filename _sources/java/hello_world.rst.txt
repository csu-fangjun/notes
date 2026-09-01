
Hello world
===========

Look at the code `<https://github.com/openjdk/jdk/blob/master/src/java.base/share/classes/java/lang/System.java>`_
to learn the coding style of java.

All primitive types, such as ``int``, ``char``, and ``double`` begin with a lowercase.
All other types, such as ``String`` and ``Math``, begin with an uppercase.

.. code-block:: java

   package java.lang;

   // Class names looks like: MyClass
   public final class System {}

   // method name
   private static native void registerNatives();

   // constructor
   private System() {}

   // member variables
   public static final InputStream in = null;
   private static String notSupportedJnuEncoding;

   // constants
   private static final int NEVER = 1;

It using ``//`` and ``/**/`` as comments, same as C++.

.. literalinclude:: ./code/hello_world/Hello.java
   :language: java
   :caption: Hello.java

.. literalinclude:: ./code/hello_world/EqualTest.java
   :language: java
   :caption: EqualTest.java

.. literalinclude:: ./code/hello_world/Variables.java
   :language: java
   :caption: Variables.java

.. literalinclude:: ./code/hello_world/Strings.java
   :language: java
   :caption: Strings.java

.. literalinclude:: ./code/hello_world/MathTest.java
   :language: java
   :caption: MathTest.java

.. literalinclude:: ./code/hello_world/ArrayTest.java
   :language: java
   :caption: ArrayTest.java

TODOs
------

1. How to define an array? How to iterate an array?
2. What methods does the ``String`` class have
3. What are final variables?
4. How to define a package?
5. What is static import?
6. What is a lambda expression?
7. How to write comments using javadoc?
8. How to generate documentation from javadoc?
9. How to use a for-each loop?
10. How to import a class from another file?
