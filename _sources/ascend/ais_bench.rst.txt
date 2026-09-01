ais_bench
=========

Use Python >= 3.9 to install ais_bench!

See `<https://gitee.com/ascend/tools/tree/7526b3c5ae6e8217e15a61b4a15851de32630e1d/ais-bench_workload/tool/ais_bench>`_

See `<https://gitee.com/ascend/tools/tree/master/ais-bench_workload/tool/ais_bench>`_

.. code-block::

   source py310/bin/activate
   source /usr/local/Ascend/ascend-toolkit/set_env.sh
   git clone https://gitee.com/ascend/tools

   cd tools/ais-bench_workload/tool/ais_bench

   pip3 wheel ./backend/ -v
   pip3 wheel ./ -v
   pip3 install ./aclruntime-0.0.2-cp310-cp310-linux_aarch64.whl
   pip3 install ./ais_bench-0.0.2-py3-none-any.whl
