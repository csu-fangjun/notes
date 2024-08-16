Lazarus
=======

Follow `<https://wiki.freepascal.org/Installing_Lazarus_on_macOS>`_
to install Lazarus.

We need to download two files from `<https://sourceforge.net/projects/lazarus/files/Lazarus%20macOS%20x86-64/>`_:

  - ``Lazarus-3.4-macosx-x86_64.pkg``
  - ``fpc-src-3.2.2-20210709-macosx.dmg``

``fpc-src`` is installed in ``/usr/local/share/src/fpc-3.2.2``.
The source code of ``fpc`` can also be found at `<https://github.com/fpc/FPCSource>`_

To reduce ``.exe`` file size:

  1. Select ``Project``, ``Project options...``, ``compiler options``, ``Debugging``
  2. Uncheck ``Generate info for the debugger (slower / increase exe size)``
  3. Check ``Strip symbols from exectuable``
  4. Note: We can create release and debug build mode instead of using the default mode.


See `<https://wiki.freepascal.org/Mac_Installation_FAQ>`_ to fix the following error::

  ld: framework not found Cocoa


whole program optimization: `<https://wiki.freepascal.org/Whole_Program_Optimization#Concrete_Lazarus_IDE_example>`_

 - Multiplatform Programming Guide

   `<https://wiki.freepascal.org/Multiplatform_Programming_Guide>`_

 - Application Bundle

   `<https://wiki.freepascal.org/Application_Bundle>`_

Marcos
------

- For operating systems: ``DARWIN`` for macOS and iOS
- See `<https://www.freepascal.org/docs-html/3.2.0/prog/progap7.html#x341-357000G>`_ for a complete list


macOS related
-------------

 - `Locating the macOS application resources directory <https://wiki.freepascal.org/Locating_the_macOS_application_resources_directory>`_


Info.plist
::::::::::

``Info.plist`` is short for information property list.

We can either use ``vim`` to edit ``Info.plist`` or use ``open Info.plist``
to start xcode to edit it.

References:

 - `Edit property lists <https://help.apple.com/xcode/mac/8.0/#/dev3f399a2a6>`_

    It shows how to use xcode to edit ``Info.plist``.

  - `About Info.plist Keys and Values <https://developer.apple.com/library/archive/documentation/General/Reference/InfoPlistKeyReference/Introduction/Introduction.html#//apple_ref/doc/uid/TP40009248-SW1>`_

  - `About Information Property List Files <https://developer.apple.com/library/archive/documentation/General/Reference/InfoPlistKeyReference/Articles/AboutInformationPropertyListFiles.html#//apple_ref/doc/uid/TP40009254-SW1>`_

Bundle Programming Guide
::::::::::::::::::::::::

  - `Introduction <https://developer.apple.com/library/archive/documentation/CoreFoundation/Conceptual/CFBundles/Introduction/Introduction.html#//apple_ref/doc/uid/10000123i>`_

  - `Application Bundles <https://developer.apple.com/library/archive/documentation/CoreFoundation/Conceptual/CFBundles/BundleTypes/BundleTypes.html#//apple_ref/doc/uid/10000123i-CH101-SW13>`_
