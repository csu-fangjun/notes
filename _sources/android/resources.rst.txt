Resources
=========

.. code-block::

  import androidx.annotation.StringRes

  data class Question(@StringRes val textResId: Int, val answer: Boolean)

Recommended to use ``@StringRes`` decoration, though it is not required.

To add a new id, use::

  android:id="@+id/my_button"

To reference a string, use::

  android:text="@string/my_string"
