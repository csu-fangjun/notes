Install
=======

See `<https://go.dev/doc/install>`_

macos
-----

.. code-block:: bash

   cd ~/software
   wget https://go.dev/dl/go1.20.5.darwin-amd64.tar.gz
   tar xvf go1.20.5.darwin-amd64.tar.gz
   export PATH=~/software/go/bin:$PATH

   go install golang.org/x/tools/cmd/godoc
