cann
====

- 快速安装CANN

  `<https://www.hiascend.com/document/detail/zh/CANNCommunityEdition/83RC1alpha003/softwareinst/instg/instg_quick.html?Mode=PmIns&OS=Debian&Software=cannToolKit>`_


First, use ``npu-smi info`` to check the driver version, and then select a version of CANN toolkit
that is compatible with the driver version.

.. code-block::

   source ~/py38/bin/activate
   ./Ascend-cann-toolkit_8.5.0.alpha001_linux-aarch64.run --full

   # To uninstall
   ./Ascend-cann-toolkit_8.5.0.alpha001_linux-aarch64.run --uninstall
   cd /usr/local/Ascend
   rm -rf ascend-toolkit/



Part of the installation logs:

.. code-block::

===========
= Summary =
===========

  Driver:   Installed in /usr/local/Ascend/driver.
  Toolkit:  Ascend-cann-toolkit_8.5.0.alpha001_linux-aarch64 install success, installed in /usr/local/Ascend.

  Please make sure that the environment variables have been configured.
  -  To take effect for all users, you can add "source /usr/local/Ascend/ascend-toolkit/set_env.sh" to /etc/profile.
  -  To take effect for current user, you can exec command below: source /usr/local/Ascend/ascend-toolkit/set_env.sh or add "source /usr/local/Ascend/ascend-toolkit/set_env.sh" to ~/.bashrc.

To fix the following error::

  + atc --model=./model.onnx --framework=5 --output=model --input_format=ND --input_shape=x:1,-1 --soc_version=Ascend910B
  ATC start working now, please wait for a moment.
  ...
  ATC run failed, Please check the detail log, Try 'atc --help' for more information
  E40001: Value [/usr] for environment variable [ld_library_path or ldconfig] is invalid when load python dynamic library.
          Solution: Reset the environment variable by referring to the installation guide.
          TraceBack (most recent call last):
          [GraphOpt][InitializeInner][InitTbeFunc] Failed to init tbe.[FUNC:InitializeInner][FILE:tbe_op_store_adapter.cc][LINE:1623]
          [SubGraphOpt][PreCompileOp][InitAdapter] InitializeAdapter adapter [tbe_op_adapter] failed! Ret [4294967295][FUNC:InitializeAdapter][FILE:op_store_adapter_manager.cc][LI
  NE:85]
          [SubGraphOpt][PreCompileOp][Init] Initialize op store adapter failed, OpsStoreName[tbe-custom].[FUNC:Initialize][FILE:op_store_adapter_manager.cc][LINE:126]
          [FusionMngr][Init] Op store adapter manager init failed.[FUNC:Initialize][FILE:fusion_manager.cc][LINE:124]
          PluginManager InvokeAll failed.[FUNC:Initialize][FILE:ops_kernel_manager.cc][LINE:96]
          OpsManager initialize failed.[FUNC:InnerInitialize][FILE:gelib.cc][LINE:237]
          GELib::InnerInitialize failed.[FUNC:Initialize][FILE:gelib.cc][LINE:165]

Run::

  # python3 -c "import ctypes; ctypes.CDLL('libpython3.10.so')"

  # find /root/miniconda3/ -name "libpython3.10.so"
  /root/miniconda3/pkgs/python-3.10.0-hc137634_5/lib/libpython3.10.so
  /root/miniconda3/envs/py310/lib/libpython3.10.so

  # export LD_LIBRARY_PATH=/root/miniconda3/envs/py310/lib:$LD_LIBRARY_PATH
