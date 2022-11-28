Install
=======

formatter
---------

Install `<https://github.com/google/google-java-format>`_

.. code-block:: bash

   wget https://github.com/google/google-java-format/releases/download/v1.15.0/google-java-format-1.15.0-all-deps.jar

Create a script with filename ``google-java-format``:

.. code-block::

  #!/usr/bin/env bash

  java -jar /ceph-sh0/fangjun/download/google-java-format-1.15.0-all-deps.jar $@

``chmod +x google-java-format`` and add the path to ``PATH``.


JDK
---

Go to `<https://www.oracle.com/java/technologies/downloads/#java17>`_ and download

.. code-block:: bash

   wget https://download.oracle.com/java/17/latest/jdk-17_linux-x64_bin.tar.gz
   mkdir /ceph-fj/fangjun/software/
   tar xvf jdk-17_linux-x64_bin.tar.gz -C /ceph-fj/fangjun/software

And then set the following environment variables:

.. code-block:: bash

  export JAVA_HOME=/ceph-fj/fangjun/software/jdk-17.0.3
  export PATH=$JAVA_HOME/bin:$JAVA_HOME

The source code of ``JDK`` can be download from

.. code-block:: bash

   git clone https://github.com/openjdk/jdk.git
