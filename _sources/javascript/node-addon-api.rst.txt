node-addon-api
==============

See also `<https://nodejs.github.io/node-addon-examples/getting-started/first/>`_

GYP documentation: `<https://gyp.gsrc.io/docs/UserDocumentation.md>`_

- `<https://github.com/mapbox/node-pre-gyp>`_

- `<https://github.com/bchr02/node-pre-gyp-github>`_

- `How to write a c++ node addon api with cmake-js and node-addon-api module <https://williamhoyle.ca/blog/2021/cmake-js>`_

- `Unlocking the Power of Native Modules in JavaScript: An Introductory Guide <https://daniel-boll.me/posts/going-native-on-javascript-1>`_
- `Mastering Native Node.js Addons with node-addon-api: A Comprehensive Guide <https://daniel-boll.me/posts/going-native-on-javascript-2/>`_

- `<https://github.com/nodejs/node-addon-api/blob/main/doc/object.md>`_

.. code-block:: bash

  # See https://www.npmjs.com/package/generator-napi-module
  npm install -g yo
  npm install -g generator-napi-module

.. code-block:: bash

  mkdir first
  cd first
  yo napi-module
  npm test

To install ``node-gyp``::

  npm install node-gyp

You will find the executable inside ``./node_modules/.bin/node-gyp``.

You can run::

  ./node_modules/.bin/node-gyp configure
  ./node_modules/.bin/node-gyp build


.. code-block:: bash

  node -p "require('node-addon-api')"

prints::

  {
    include: '"/Users/fangjun/open-source/notes/docs/source/javascript/code/node-addon-api/first/node_modules/node-addon-api"',
    gyp: '/Users/fangjun/open-source/notes/docs/source/javascript/code/node-addon-api/first/node_modules/node-addon-api/src/node_api.gyp:nothing',
    isNodeApiBuiltin: true,
    needsFlag: false
  }
