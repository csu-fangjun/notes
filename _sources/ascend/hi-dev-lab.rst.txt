HiDevLab
========

- 连接环境 `<https://www.hikunpeng.com/document/detail/zh/techcert/certtest/envapp/kunpeng_hidevlabeg_0002.html>`_

  install UniVPN

Install CANN
-------------

See `<https://www.hiascend.com/cann/download>`_

.. code-block::

  groupadd HwHiAiUser
  useradd -g HwHiAiUser -d /home/HwHiAiUser -m HwHiAiUser -s /bin/bash

  sudo apt-get update
  sudo apt-get install -y gcc python3 python3-pip linux-headers-$(uname -r)

  wget https://ascend-repo.obs.cn-east-2.myhuaweicloud.com/CANN/CANN%208.5.T63/Ascend-cann_8.5.0_linux-aarch64.run

  bash ./Ascend-cann_8.5.0_linux-aarch64.run --install

.. code-block::

  ===========
  = Summary =
  ===========

  Driver:  Not installed.
  CANN:    Ascend-cann_8.5.0_linux-aarch64 install success, installed in /usr/local/Ascend.

  Please make sure that the environment variables have been configured.
  -  To take effect for all users, you can add "source /usr/local/Ascend/cann-8.5.0/set_env.sh" to /etc/profile.
  -  To take effect for current user, you can exec command below: source /usr/local/Ascend/cann-8.5.0/set_env.sh or add "source /usr/local/Ascend/cann-8.5.0/set_env.sh" to ~/.bashrc.


.. code-block::

  wget https://ascend-repo.obs.cn-east-2.myhuaweicloud.com/CANN/CANN%208.5.T63/Ascend-cann-310p-ops_8.5.0_linux-aarch64.run
  bash ./Ascend-cann-310p-ops_8.5.0_linux-aarch64.run --install

.. code-block::

    ===========
    = Summary =
    ===========

    Driver:    Not installed.
    ops_310p:  Ascend-cann-310p-ops_8.5.0_linux-aarch64 install success, installed in /usr/local/Ascend.

    Please make sure that the environment variables have been configured.
    -  To take effect for all users, you can add "source /usr/local/Ascend/cann-8.5.0/set_env.sh" to /etc/profile.
    -  To take effect for current user, you can exec command below: source /usr/local/Ascend/cann-8.5.0/set_env.sh or add "source /usr/local/Ascend/cann-8.5.0/set_env.sh" to ~/.bashrc.

.. code-block::

   source /usr/local/Ascend/ascend-toolkit/set_env.sh
