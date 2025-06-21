cargo
=====

Before publish a crate, check `<https://doc.rust-lang.org/cargo/reference/publishing.html>`_

  - license
  - description
  - homepage
  - repository
  - readme

Find some examples of existing packages/crates.

.. code-block:: bash

   cargo publish --dry-run
   cargo package --list # check the files to be included for publishing

Default ``CARGO_HOMOE`` is the directory ``~/.cargo``
