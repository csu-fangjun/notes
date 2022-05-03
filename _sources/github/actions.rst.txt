GitHub actions
==============

Run GitHub actions locally
--------------------------

It is time-consuming to use GitHub action to test whether the current
workflow is working. `<https://github.com/nektos/act>`_ provides a tool
to test workflows locally. Refer to the above repository for installation.

.. hint::

  The script `<https://github.com/nektos/act/blob/master/install.sh>`_ is
  worth reading.

Hello world
-----------

The following shows an exmaple workflow.

.. literalinclude:: ./code/actions/env.yml
  :language: yaml
  :lines: 5-
  :caption: ./code/actions/env.yml

Every workflow has an optional name and some conditions on which it will run.
A workflow consists of a list of jobs. A job is run on an environment specified by
``runs-on``. Inside a job there are a list of steps.

The following shows how to use ``act`` to run the above workflow locally.

.. code-block::

  $ act -l -W ./actions/
  Stage  Job ID   Job name  Workflow name      Workflow file  Events
  0      foo_job  foo_job   My first workflow  env.yml        push

  $ act -W ./actions/
  [My first workflow/foo_job] 🚀  Start image=node:16-buster-slim
  [My first workflow/foo_job]   🐳  docker pull image=node:16-buster-slim platform= username= forcePull=false
  [My first workflow/foo_job]   🐳  docker create image=node:16-buster-slim platform= entrypoint=["/usr/bin/tail" "-f" "/dev/null"] cmd=[]
  [My first workflow/foo_job]   🐳  docker run image=node:16-buster-slim platform= entrypoint=["/usr/bin/tail" "-f" "/dev/null"] cmd=[]
  [My first workflow/foo_job]   🐳  docker exec cmd=[mkdir -m 0777 -p /var/run/act] user=root workdir=
  [My first workflow/foo_job] ⭐  Run Test 1
  [My first workflow/foo_job]   🐳  docker exec cmd=[bash --noprofile --norc -e -o pipefail /var/run/act/workflow/0.sh] user= workdir=
  | foo is hello
  | BAR is world
  [My first workflow/foo_job]   ✅  Success - Test 1
