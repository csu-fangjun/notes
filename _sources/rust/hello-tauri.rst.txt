Hello Tauri
===========

.. code-block::

  npm create tauri-app@latest

Name the project as ``hello_world`` and use default settings.

.. code-block::

  cd hello_world
  npm install
  npm run tauri build --release

For macOS, it generates both ``hello_world.app`` and ``hello_world_0.1.0_aarch64.dmg``.

.. code-block::

   npm run tauri dev
   npm run tauri dev -- --release
