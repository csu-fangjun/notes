Basics
======


What is this GLIBCXX error?
---------------------------

See `<https://omairmajid.com/posts/2020-07-08-what-is-glibcxx-error/>`_

It shows how to build and use glibc.



.. code-block:: bash

   readelf --dyn-syms onnxruntime-linux-aarch64-1.16.3/lib/libonnxruntime.so | grep GLIBCXX

.. code-block:: bash

  $ readelf --dyn-syms onnxruntime-linux-aarch64-1.16.3/lib/libonnxruntime.so | grep GLIBCXX
     6: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND _Znam@GLIBCXX_3.4 (3)
     8: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND _ZNSo3putEc@GLIBCXX_3.4 (3)
    10: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND _ZNSt6chrono3_V212system_@GLIBCXX_3.4.19 (5)
    11: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND _ZNSt8__detail15_List_nod@GLIBCXX_3.4.15 (6)
    15: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND _ZNSirsERs@GLIBCXX_3.4 (3)
    16: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND _ZSt29_Rb_tree_insert_and@GLIBCXX_3.4 (3)
    19: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND _ZNSdD2Ev@GLIBCXX_3.4 (3)
