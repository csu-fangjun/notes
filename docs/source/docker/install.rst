Installation
============

macos
-----

Refer to `<https://docs.docker.com/desktop/mac/install/>`_.


Change directory to save images
-------------------------------

.. code-block:: bash

   docker info -f '{{ .DockerRootDir }}'
   mkdir -p /tmp/new-docker-root
   sudo vi /etc/docker/daemon.json

   cat /etc/docker/daemon.json
   {
      "data-root": "/tmp/new-docker-root"
   }

   sudo systemctl daemon-reload
   sudo systemctl restart docker
   docker info -f '{{ .DockerRootDir}}'

Run an image
------------

.. code-block:: bash

   sudo docker run -it pytorch/manylinux-builder:cuda10.2 /bin/bash

Map a host directory to docker container:

.. code-block:: bash
   sudo docker run -it -v /host/path:/container/path pytorch/manylinux-builder:cuda10.2 /bin/bash

copy data between container and host
------------------------------------

.. code-block:: bash

   sudo docker cp container:src_path dst_path
   sudo docker cp src_path container:dst_path

Use ``docker ps`` to view the container ID.

