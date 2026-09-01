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
  | 0     910B                | OK            | xx.x        xxx               0    / 0             |
  | 0                         | 1234:d0:12.1  | 0           xxxx / 1xxxx      0    / xxxxx         |
  +===========================+===============+====================================================+
  | NPU     Chip              | Process id    | Process name             | Process memory(MB)      |
  +===========================+===============+====================================================+
  | No running processes found in NPU 0                                                            |
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


fix errors
----------

.. code-block::

  [INFO] acl init success [INFO] open device 0 success [INFO] create new context
  [ACL ERROR] E19999: Inner Error! E19999:
  [PID: 3370899] 2025-10-17-18:40:43.617.804 Invalid opp version [8.3.T14.0.B101] or
  compiler_version [],Please check if it is within the required
  range[FUNC:CheckOsCpuInfoAndOppVersion][FILE:model_helper.cc][LINE:973]
  TraceBack (most recent call last): Assert ((error_code) == ge::SUCCESS)
  failed[FUNC:LoadExecutorFromModelData][FILE:api.cc][LINE:111]
  [Model][FromData]call gert::LoadExecutorFromModelDataWithMem load model from data failed,
  ge result[4294967295][FUNC:ReportCallError][FILE:log_inner.cpp][LINE:161]
  [ERROR] load model from file failed, model file is ./encoder.om
  [WARN] Check failed:processModel->LoadModelFromFile(modelPath), ret:1

I am using  ``ascendai/cann:latest`` from `<https://github.com/Ascend/cann-container-image>`_ in GitHub actions
It shows::

  source /usr/local/Ascend/ascend-toolkit/set_env.sh

  /usr/local/Ascend/ascend-toolkit/8.3.RC1.alpha003/fwkacllib/lib64/libascend_protobuf.so
  /usr/local/Ascend/ascend-toolkit/8.3.RC1.alpha003/fwkacllib/lib64/libascend_dump.so

And on my device, I have::

  cat /usr/local/Ascend/driver/version.info

  Version=24.1.0
  ascendhal_version=7.35.23
  aicpu_version=1.0
  tdt_version=1.0
  log_version=1.0
  prof_version=2.0
  dvppkernels_version=1.1
  tsfw_version=1.0
  Innerversion=V100R001C19SPC002B226
  compatible_version=[V100R001C13],[V100R001C15],[V100R001C17],[V100R001C18],[V100R001C19]
  compatible_version_fw=[7.0.0,7.6.99]
  package_version=24.1.0

``24.1.0`` requires ``CANN 8.0 / 8.1 LTS``, but i was using ``8.3.RC1.alpha003``, which is too new.

Switch to ``8.1.rc1-910b-ubuntu22.04-py3.10``. See `<https://github.com/Ascend/cann-container-image/tree/main/cann/8.1.rc1-910b-ubuntu22.04-py3.10>`_

- CANN 7.0.x supports 23.0.x, for 910/310
- CANN 7.1.x supports 23.1.x and 23.2x, for A310B, 910B
- CANN 8.0.x/8.1.x supports 24.0.x/24.1.x
- CANN 8.3.x supports 25.0.x/ 25.1.x
