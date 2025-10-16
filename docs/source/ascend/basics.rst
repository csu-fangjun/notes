Basics
======

npu-smi
-------

.. code-block::

   npu-smi info

   # It's similar to nvida-smi

.. code-block::

  yyy@xxx:~$ npu-smi info

  +------------------------------------------------------------------------------------------------+
  | npu-smi 24.1.0                   Version: 24.1.0                                               |
  +---------------------------+---------------+----------------------------------------------------+
  | NPU   Name                | Health        | Power(W)    Temp(C)           Hugepages-Usage(page)|
  | Chip                      | Bus-Id        | AICore(%)   Memory-Usage(MB)  HBM-Usage(MB)        |
  +===========================+===============+====================================================+
  | 0     910B                | OK            | 68.5        40                0    / 0             |
  | 0                         | 0000:C1:00.0  | 0           2382 / 15038      0    / 32768         |
  +===========================+===============+====================================================+
  | 1     910B                | OK            | 65.1        41                0    / 0             |
  | 0                         | 0000:81:00.0  | 0           2353 / 15038      0    / 32768         |
  +===========================+===============+====================================================+
  | 2     910B                | OK            | 67.9        41                0    / 0             |
  | 0                         | 0000:41:00.0  | 0           2355 / 15038      0    / 32768         |
  +===========================+===============+====================================================+
  | 3     910B                | OK            | 65.6        41                0    / 0             |
  | 0                         | 0000:01:00.0  | 0           2352 / 15038      0    / 32768         |
  +===========================+===============+====================================================+
  | 4     910B                | OK            | 67.5        41                0    / 0             |
  | 0                         | 0000:C2:00.0  | 0           2353 / 15038      0    / 32768         |
  +===========================+===============+====================================================+
  | 5     910B                | OK            | 63.2        41                0    / 0             |
  | 0                         | 0000:82:00.0  | 0           2356 / 15038      0    / 32768         |
  +===========================+===============+====================================================+
  | 6     910B                | OK            | 66.6        41                0    / 0             |
  | 0                         | 0000:42:00.0  | 0           2380 / 15038      0    / 32768         |
  +===========================+===============+====================================================+
  | 7     910B                | OK            | 65.0        40                0    / 0             |
  | 0                         | 0000:02:00.0  | 0           2402 / 15038      124  / 32768         |
  +===========================+===============+====================================================+
  +---------------------------+---------------+----------------------------------------------------+
  | NPU     Chip              | Process id    | Process name             | Process memory(MB)      |
  +===========================+===============+====================================================+
  | No running processes found in NPU 0                                                            |
  +===========================+===============+====================================================+
  | No running processes found in NPU 1                                                            |
  +===========================+===============+====================================================+
  | No running processes found in NPU 2                                                            |
  +===========================+===============+====================================================+
  | No running processes found in NPU 3                                                            |
  +===========================+===============+====================================================+
  | No running processes found in NPU 4                                                            |
  +===========================+===============+====================================================+
  | No running processes found in NPU 5                                                            |
  +===========================+===============+====================================================+
  | No running processes found in NPU 6                                                            |
  +===========================+===============+====================================================+
  | 7       0                 | 87322         | python3                  | 109                     |
  +===========================+===============+====================================================+

atc
---

.. code-block::

  yyy@xxx:~$ cat /usr/local/Ascend/ascend-toolkit/set_env.sh

  export LD_LIBRARY_PATH=/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver:$LD_LIBRARY_PATH
  export ASCEND_TOOLKIT_HOME=/usr/local/Ascend/ascend-toolkit/latest
  export LD_LIBRARY_PATH=${ASCEND_TOOLKIT_HOME}/lib64:${ASCEND_TOOLKIT_HOME}/lib64/plugin/opskernel:${ASCEND_TOOLKIT_HOME}/lib64/plugin/nnengine:${ASCEND_TOOLKIT_HOME}/opp/built-in/op_impl/ai_core/tbe/op_tiling/lib/linux/$(arch):$LD_LIBRARY_PATH
  export LD_LIBRARY_PATH=${ASCEND_TOOLKIT_HOME}/tools/aml/lib64:${ASCEND_TOOLKIT_HOME}/tools/aml/lib64/plugin:$LD_LIBRARY_PATH
  export PYTHONPATH=${ASCEND_TOOLKIT_HOME}/python/site-packages:${ASCEND_TOOLKIT_HOME}/opp/built-in/op_impl/ai_core/tbe:$PYTHONPATH
  export PATH=${ASCEND_TOOLKIT_HOME}/bin:${ASCEND_TOOLKIT_HOME}/compiler/ccec_compiler/bin:${ASCEND_TOOLKIT_HOME}/tools/ccec_compiler/bin:$PATH
  export ASCEND_AICPU_PATH=${ASCEND_TOOLKIT_HOME}
  export ASCEND_OPP_PATH=${ASCEND_TOOLKIT_HOME}/opp
  export TOOLCHAIN_HOME=${ASCEND_TOOLKIT_HOME}/toolkit
  export ASCEND_HOME_PATH=${ASCEND_TOOLKIT_HOME}

.. code-block::

  cat /usr/local/Ascend/ascend-toolkit/latest/version.cfg

  # version: 1.0
  runtime_running_version=[7.6.0.1.220:8.0.0]
  compiler_running_version=[7.6.0.1.220:8.0.0]
  hccl_running_version=[7.6.0.1.220:8.0.0]
  opp_running_version=[7.6.0.1.220:8.0.0]
  toolkit_running_version=[7.6.0.1.220:8.0.0]
  aoe_running_version=[7.6.0.1.220:8.0.0]
  ncs_running_version=[7.6.0.1.220:8.0.0]
  runtime_upgrade_version=[7.6.0.1.220:8.0.0]
  compiler_upgrade_version=[7.6.0.1.220:8.0.0]
  hccl_upgrade_version=[7.6.0.1.220:8.0.0]
  opp_upgrade_version=[7.6.0.1.220:8.0.0]
  toolkit_upgrade_version=[7.6.0.1.220:8.0.0]
  aoe_upgrade_version=[7.6.0.1.220:8.0.0]
  ncs_upgrade_version=[7.6.0.1.220:8.0.0]
  runtime_installed_version=[7.6.0.1.220:8.0.0]
  compiler_installed_version=[7.6.0.1.220:8.0.0]
  hccl_installed_version=[7.6.0.1.220:8.0.0]
  opp_installed_version=[7.6.0.1.220:8.0.0]
  toolkit_installed_version=[7.6.0.1.220:8.0.0]
  aoe_installed_version=[7.6.0.1.220:8.0.0]
  ncs_installed_version=[7.6.0.1.220:8.0.0]

.. code-block::

  echo $PATH | grep ascend-toolkit

  /usr/local/Ascend/ascend-toolkit/latest/bin:/usr/local/Ascend/ascend-toolkit/latest/compiler/ccec_compiler/bin:/usr/local/Ascend/ascend-toolkit/latest/tools/ccec_compiler/bin

.. code-block::

  ls /usr/local/Ascend/ascend-toolkit/

  8.0  8.0.0  latest  set_env.sh

atc --help
---------

ascend tool chain

.. literalinclude:: ./code/atc-help.txt

atc
---

To show debug messages:

.. code-block::

  export ASCEND_SLOG_PRINT_TO_STDOUT=1


