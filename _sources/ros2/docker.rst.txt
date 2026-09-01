Docker
======

See

  - `<https://docs.ros.org/en/iron/Installation/Ubuntu-Install-Debians.html>`_
  - `<https://docs.ros.org/en/iron/Tutorials.html>`_

The QA forum is `<https://robotics.stackexchange.com/>`_


.. code-block:: bash

   docker pull osrf/ros2:nightly
   docker run -it osrf/ros2:nightly
   docker run --rm -it --network host --name ros2 -v /host/path:/container/path osrf/ros2:nightly /bin/bash
   # connect to the container
   docker exec -it ros2 /bin/bash

After starting the docker container,

.. code-block:: bash

   # rolling is the name of the distro
   #
   # which ros2 prints: /opt/ros/rolling/bin/ros2

   source /opt/ros/rolling/setup.bash

   ros2 run demo_nodes_cpp talker

   # In another terminal
   source /opt/ros/rolling/setup.bash
   ros2 run demo_nodes_py listener

.. code-block:: bash

   printenv | grep -i ROS

prints the following:

.. code-block::

  ROS_VERSION=2
  PKG_CONFIG_PATH=/opt/ros/rolling/lib/x86_64-linux-gnu/pkgconfig:/opt/ros/rolling/lib/pkgconfig
  ROS_PYTHON_VERSION=3
  ROSDISTRO_INDEX_URL=https://raw.githubusercontent.com/osrf/docker_images/master/ros2/nightly/nightly/index-v4.yaml
  AMENT_PREFIX_PATH=/opt/ros/rolling
  CMAKE_PREFIX_PATH=/opt/ros/rolling
  ROS_AUTOMATIC_DISCOVERY_RANGE=SUBNET
  COLCON_PREFIX_PATH=/opt/ros/rolling
  PYTHONPATH=/opt/ros/rolling/lib/python3.10/site-packages
  LD_LIBRARY_PATH=/opt/ros/rolling/opt/rviz_ogre_vendor/lib:/opt/ros/rolling/opt/mimick_vendor/lib:/opt/ros/rolling/lib
  PATH=/opt/ros/rolling/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
  ROS_DISTRO=rolling

See `<https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/>`_ to change the apt source.
Also see `<https://mirrors.tuna.tsinghua.edu.cn/help/ros2/>`_.

Install the package ``ros-rolling-turtlesim``:

.. code-block:: bash

   sudo apt update
   sudo apt install ros-rolling-turtlesim

   ros2 pkg -h

   # Check that it is installed
   ros2 pkg executables turtlesim

It prints:

.. code-bock::

  turtlesim draw_square
  turtlesim mimic
  turtlesim turtle_teleop_key
  turtlesim turtlesim_node

Now we can run

.. code-block::

   # ros2 run <package_name> <executable_name>

   ros2 run turtlesim turtlesim_node
   ros2 node list
   ros2 topic list
   ros2 service list
   ros2 action list
   ros2 node info <node_name>

Source code for ``turtlesim``: `<https://github.com/ros/ros_tutorials/tree/iron/turtlesim>`_
