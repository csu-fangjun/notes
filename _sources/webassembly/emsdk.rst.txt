emsdk
=====

Install
-------

See `<https://emscripten.org/docs/getting_started/downloads.html>`_

.. code-block:: bash

   git clone https://github.com/emscripten-core/emsdk.git

   cd emsdk

   git pull

   ./emsdk install latest

   ./emsdk activate latest

   source ./emsdk_env.sh

   emcc -v

   # See https://emscripten.org/docs/getting_started/downloads.html

hello.cc
---------

.. code-block::

  emcc ./hello.cc
  # It generates a.out.js, a.out.wasm

  (py38) kuangfangjun:test-wasm$ ls
  a.out.js  a.out.wasm  hello.cc

  (py38) kuangfangjun:test-wasm$ file a.out.wasm
  a.out.wasm: WebAssembly (wasm) binary module version 0x1 (MVP)

  (py38) kuangfangjun:test-wasm$ ls -lh a.out.wasm
  -rwxr-xr-x 1 kuangfangjun root 156K Jul 27 15:10 a.out.wasm


.. code-block::

  emcc ./hello.cc -o hello.js
  # It generates hello.js, hello.wasm

Create a file ``test.html`` containing:

.. code-block:: bash

  <!doctype html>

  <html>
    <head>
      <meta charset="utf-8">
      <title>Emscripten:Hello world</title>
    </head>

    <body>
      <script src="hello.js"></script>
    </body>
  </html>

Start a python http web server ``python3 -m http.server 6006``, the log
is printed to the browser console.

Or use ``emrun ./hello.html``.

Also, we can use ``node`` to run it: ``node hello.js``.

Now delete ``hello.html`` and use

.. code-block:: bash

   emcc hello.cc -o hello.html
   # It will generate: hello.html, hello.js, hello.wasm


emscripten.h
------------

`<https://emscripten.org/docs/api_reference/emscripten.h.html>`_
