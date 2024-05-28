Package
=======

Dart packages can be found at `<https://pub.dev/>`_.

example
-------

.. code-block:: yaml

  name: my_app

  environment:
    sdk: '^3.4.0'

  dependencies:
    js: ^0.6.0
    intl: ^0.17.0

Save it to ``pubspec.yaml``, and run::

  dart pub get

It prints::

  Resolving dependencies...
  Downloading packages...
  + clock 1.1.1
  + intl 0.17.0 (0.19.0 available)
  + js 0.6.7 (0.7.1 available)
  + meta 1.15.0
  + path 1.9.0
  Changed 5 dependencies!
  2 packages have newer versions incompatible with dependency constraints.
  Try `dart pub outdated` for more information.

To add a new dependency from the command line, run::

  dart pub add vector_math

It prints::

  Resolving dependencies...
  Downloading packages...
    intl 0.17.0 (0.19.0 available)
    js 0.6.7 (0.7.1 available)
  + vector_math 2.1.4
  Changed 1 dependency!
  2 packages have newer versions incompatible with dependency constraints.
  Try `dart pub outdated` for more information.

It changes ``dependencies`` in ``pubspec.yaml`` to::

  dependencies:
    js: ^0.6.0
    intl: ^0.17.0
    vector_math: ^2.1.4

Note: There is a ``.dart_tool`` in the current directory generated automatically
by ``dart pub get``. Part of its is given below::

  {
    "configVersion": 2,
    "packages": [
      {
        "name": "clock",
        "rootUri": "file:///Users/fangjun/.pub-cache/hosted/pub.dev/clock-1.1.1",
        "packageUri": "lib/",
        "languageVersion": "2.12"
      },

To upgrade all dependencies::

  dart pub upgrade

To upgrade a specific dependency::

  dart pub upgrade

There is an automatically generated file ``pubspec.lock``.

See `<https://dart.dev/guides/libraries/create-packages>`_ to create a new package.

.. code-block:: bash

   dart create -t package hello

will create a directory ``hello``. There are template files in ``hello``.
