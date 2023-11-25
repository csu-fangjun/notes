module
======

Nodejs supports both CommonJS and ESmodules.
Browsers supports only ESmodules.

CommonJS modules
----------------

Export a single function:

.. code-block:: javascript

  # mod1.js
  const mod1Function = () => console.log('Mod1 is alive!')
  module.exports = mod1Function


  # main.js
  mod1Function = require('./mod1.js')
  mod1Function()


Export more function:

.. code-block:: javascript

   # mod1.js
   const mod1Function = () => console.log('Mod1 is alive!')
   const mod1Function2 = () => console.log('Mod1 is rolling, baby!')

   module.exports = { mod1Function, mod1Function2 }

   # main.js
   ({ mod1Function, mod1Function2 } = require('./mod1.js'))
   mod1Function()
   mod1Function2()

ESmodules
---------

Use ``npm init -y`` to create ``package.json``:

.. code-block::

  {
    "name": "modulestestapp",
    "version": "1.0.0",
    "description": "",
    "main": "index.js",
    "scripts": {
      "test": "echo \"Error: no test specified\" && exit 1"
    },
    "keywords": [],
    "author": "",
    "license": "ISC",
    "type": "module"
  }

We need to manually add ``"type": "module"``.

Export a single function:

.. code-block:: javascript

  // mod1.js
  const mod1Function = () => console.log('Mod1 is alive!')
  export { mod1Function }

  // main.js
  import { mod1Function } from './mod1.js'
  // import { mod1Function } from 'mod1' // or use this one
  mod1Function()

Export two functions:

.. code-block:: javascript

  // mod1.js
  const mod1Function = () => console.log('Mod1 is alive!')
  const mod1Function2 = () => console.log('Mod1 is rolling, baby!')

  export { mod1Function, mod1Function2 }

  // main.js
  import { mod1Function, mod1Function2 } from './mod1.js'
  // import { mod1Function, mod1Function2 } from 'mod1' // or use this one
  mod1Function()
  mod1Function2()

  // main.js (rename imported functions)
  import { mod1Function as funct1, mod1Function2 as funct2 } from './mod1.js'
  funct1()
  funct2()

  // main.js (rename2)
  import * as mod1 from './mod1.js'
  mod1.mod1Function()
  mod1.mod1Function2()

Default export:

.. code-block:: javascript

  // mod1.js
  const mod1Function = () => console.log('Mod1 is alive!')
  const mod1Function2 = () => console.log('Mod1 is rolling, baby!')

  export default mod1Function
  export { mod1Function2 }

  // main.js
  import mod1Function, { mod1Function2 } from './mod1.js'
  // import mod1Function, { mod1Function2 } from 'mod1' // or use this one
  mod1Function()
  mod1Function2()

  // main.js (rename it to lalala for the default export)
  import lalala, { mod1Function2 } from './mod1.js'
  lalala()
  mod1Function2()

To use a module in html, use

.. code-block:: html

  <script src="./main.js" type="module"></script>

webpack
-------

To bundle all files of a module into a single file:

.. code-block:: bash

   npm install --save-dev webpack webpack-cli

.. code-block:: javascript

  /* webpack.config.js */
  const path = require('path');

  module.exports = {
    entry: './main.js',
    output: {
      path: path.resolve(__dirname, 'dist'),
      filename: 'bundle.js',
    },
  };

.. code-block:: json

  // package.json
  {
    "name": "testappv2",
    "version": "1.0.0",
    "description": "",
    "main": "main.js",
    "scripts": {
      "test": "echo \"Error: no test specified\" && exit 1",
      "build": "webpack"
    },
    "keywords": [],
    "author": "",
    "license": "ISC",
    "devDependencies": {
      "webpack": "^5.72.0",
      "webpack-cli": "^4.9.2"
    }
  }

After running ``npm run build``, it will generate ``dist/bundle.js``. We can use

.. code-block:: html

  <script src="./dist/bundle.js" type="module"></script>



See more at `<https://www.freecodecamp.org/news/modules-in-javascript/>`_

