Basics
======

.. literalinclude:: ./code/basics.py
   :language: python
   :caption: ./code/basics.py


Write to a binary file in Python and read it from C/C++
-------------------------------------------------------


.. code-block:: python

  import numpy as np

  a = np.array([0.25, 0.35, 0.45], dtype=np.float32)
  with open("a.bin", "wb") as f:
      f.write(a.tobytes())

.. code-block:: c++

  #include <stdio.h>
  #include <vector>

  int main() {
    FILE *fp = fopen("./a.bin", "rb");
    fseek(fp, 0, SEEK_END);
    int32_t n = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("n: %d\n", n);

    std::vector<float> d(n / sizeof(float));
    fread(d.data(), sizeof(float), n, fp);
    fclose(fp);
    for (auto f : d) {
      printf("%f ", f);
    }
    printf("\n");

    return 0;
  }

Write to a binary file in C++ and read it from Python
------------------------------------------------------

.. code-block:: c++

    std::vector<float> v(100*560);
    FILE *fp = fopen("b.bin", "wb");
    fwrite(v.data(), sizeof(float), v.size(), fp);
    fclose(fp);

.. code-block:: python

  features = np.fromfile('./b.bin', dtype='uint8').view(np.float32).reshape(-1, 560)
