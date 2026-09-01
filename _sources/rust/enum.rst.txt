enum
====

.. code-block:: bash

  pub enum Option<T> {
      None,
      Some(T),
  }

  pub enum Result<T, E> {
      Ok(T),
      Err(E),
  }
