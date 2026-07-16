npm
===

All packages can be found at `<https://npmjs.org/>`_.

TODO
----

Read the following packages:

  - `<https://github.com/martinandert/date-names>`_
  - `<https://github.com/dcousens/ordinal.js>`_
  - `<https://github.com/TooTallNate/node-wav>`_

npm init -y
-----------

.. code-block:: bash

   mkdir t
   cd t
   npm init -y

will generate a file ``package.json``:

.. code-block:: json

  {
    "name": "t",
    "version": "1.0.0",
    "description": "",
    "main": "index.js",
    "scripts": {
      "test": "echo \"Error: no test specified\" && exit 1"
    },
    "keywords": [],
    "author": "",
    "license": "ISC"
  }

mirror
------

.. code-block:: bash

  npm config set registry https://registry.npmmirror.com
  npm config get registry

To publish a new package for the first time
---------------------------------------------

Available files:

.. code-block::

  /Users/fangjun/open-source/piper-phonemize/scripts/npm
  (py312) fangjuns-MacBook-Pro:npm fangjun$ ls
  index.js                         package.json-2                   piper-phonemize-wasm-nodejs.wasm README.md
  package.json                     piper-phonemize-wasm-nodejs.js   piper-phonemize.node.js

Now run:

.. code-block::

  cd scripts/npm

  npm pack --dry-run

  npm login
  # It prints a URL, click it to open a browser

  npm publish --access public
  # Now you are ready to configure to publish it via github workflows
