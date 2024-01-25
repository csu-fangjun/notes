hello
=====


.. literalinclude:: ./code/hello2/ex.go
   :caption: ./code/hello2/ex.go
   :language: go

To run the program, use:

.. code-block:: bash

  go run ex.go

For recent version of go, ``go build`` will throw the following error:

.. code-block::

  $ go build
  go: cannot find main module, but found .git/config in /Users/fangjun/open-source/notes
          to create a module there, run:
          cd ../../../../.. && go mod init

But we can use ``go build ex.go``, which works fine and will generate an executable ``ex``.

To format the file ``in-place``, use ``go fmt ex.go``.

To see the help for a command, for instance the command for ``go fmt``, use ``go help fmt``.

To view the doc, run:

.. code-block:: bash

  gofmt
  # The above command is equivalent to
  gofmt -http localhost:6060
  # Then start your browser and visit http://localhost:6060

To install ``a tour of goo``, run

.. code-block::

   # see https://go.dev/tour/list
   go install golang.org/x/website/tour@latest


.. code-block::

   import "fmt"
   import "math/rand"

is equivalent to

.. code-block::

   import (
     "fmt"
     "math/rand"
   )

Format specifier:
  - ``%v``, for any value
  - ``%T``, print the type
  - ``%x``, same as C/C++
  - ``%s``, for string and byte slice

.. code-block::

   # to view the help information of the function fmt.Printf
   go doc fmt.Printf

