acl
===

- 动态Shape输入（设置Shape范围）

  `<https://www.hiascend.com/document/detail/zh/canncommercial/80RC2/developmentguide/appdevg/aclcppdevg/aclcppdevg_000044.html>`_


- 头文件和库文件说明

  `<https://www.hiascend.com/document/detail/zh/CANNCommunityEdition/83RC1alpha003/API/appdevgapi/aclcppdevg_03_1952.html>`_

  `<https://www.hiascend.com/document/detail/zh/canncommercial/82RC1/appdevg/acldevg/aclcppdevg_000000.html>`_

.. code-block::

  ls /usr/local/Ascend/ascend-toolkit/latest
  aarch64-linux  arm64-linux  bin       conf       hccl     lib64               opp  platform.ini  python                     runtime   toolkit  var
  acllib         atc          compiler  fwkacllib  include  mindstudio-toolkit  ops  pyACL         remove_latest_softlink.sh  test-ops  tools    version.cfg

.. code-block::

  ls /usr/local/Ascend/ascend-toolkit/latest/include

  acl        aclnn          aclnnop  amct  ascendc    experiment  flow_func   ge     hccl           llm_datadist  mstx    proto     securec.h      tiling     utils
  acldvppop  aclnn_kernels  aicpu    aoe   exe_graph  external    flow_graph  graph  kernel_tiling  mspti         parser  register  securectype.h  toolchain  version


.. code-block::

  ls /usr/local/Ascend/ascend-toolkit/latest/include/acl

  acl_base.h  acl_dump.h  acl.h  acl_mdl.h  acl_op_compiler.h  acl_op.h  acl_prof.h  acl_rt_allocator.h  acl_rt.h  acl_tdt.h  acl_tdt_queue.h  dvpp  error_codes  media  ops

.. code-block::

  ls /usr/local/Ascend/ascend-toolkit/latest/include/acl/ops

  acl_cblas.h  acl_dvpp.h  acl_fv.h

.. literalinclude:: ./code/acl-lib.txt
