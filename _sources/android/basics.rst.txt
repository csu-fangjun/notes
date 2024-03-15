Basics
======

There are two tools: ``NDK`` and ``SDK``. Each tool has a version.

Android has a concept of ``Android native API level``.

There are three environment variables to set:

  - ``ANDROID_NDK_ROOT``
  - ``ANDROID_SDK_ROOT``
  - ``ANDROID_HOME``

The name of the app is determined by ``<application android:label`` in
``AndroidManifest.xml``. We can use ``@string/app_name``.

The title of the nav bar is determined by ``<activity android:label``
in ``AndroidManifest.xml``.


Button click:

.. code-block::

   val button: Button = findViewById(R.id.button1)
   button1.setOnclickListener {
     Toast.makeText(this, "Clicked me!", Toast.LengthShort).show()
   }

The menu is added in ``res/menu`` The directory ``res/menu`` is created by
us manually. After creating the directory, we can right click it, and select
``menu resource file``. If we name it ``main``, it will create a file ``main.xml``
inside ``res/menu``.  Inside ``main.xml``, each menu item contains something like
below:

.. code-block::

   <item android:id="@+id/add_item" android:title="Add" />

After creating ``main.xml``, click the menu ``Code -> Override Method``, select
``onCreateOptionsMenu``:

.. code-block:: bash

   menuInflater.inflace(R.menu.main, menu)
   return true

To define a function when a menu item is clicked, click the menu ``Code->Override Method``,
select ``onOptionsItemSelected``.

.. code-block::

   when (item.itemId) {
     R.id.add_item -> { xxx }
     R.id.remove_item -> { xxx }
   }
   return true

To destroy an activity, call ``finish()``.

TextView
--------

It is a label in other GUI.

.. code-block::

   <TextView
     android:id="@+id/textView"
     android:text="hello world"
     android:layout_width="match_parent"
     android:layout_height="wrap_content"
   />

To change the alignment, use ``android:gravity``.

.. code-block::

   android:gravity="center"
   // top, bottom, center, start, end
   // center_vertical|center_horizontal

To change the color, use ``android::textColor``

.. code-block::

   android::textColor="#00ff00"

To change the font size, use ``android::textSize="24sp"``

Button
------

.. code-block::

   <Button
     android:id="@+id/button"
     android:text="Button"
     android:textAllCaps="false"
     android:layout_width="match_parent"
     android:layout_height="wrap_content"
   />

EditText
--------

.. code-block::

   <EditText
     android:id="@+id/editText"
     android:layout_width="match_parent"
     android:layout_height="wrap_content"
     android:hint="this is some hint"
     android:maxLines="10"
   />

To get the text of EditText in the kotlin code, use:

.. code-block:: bash

   val inputText = editText.text.toString()

LinearLayout
------------

.. code-block::

   <LinearLayout
     android:orientation="vertical"
     android:layout_width="match_parent"
     android:layout_height="match_parent"
   />

``orientation`` can also be ``horizontal``.
