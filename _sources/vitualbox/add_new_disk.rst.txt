Add new disk
============

.. code-block:: bash

   sudo fdisk -l
   sudo fdisk /dev/sdb
   sudo mkfs.ext4 /dev/sdb1
   sudo mkdir /mnt/sdb
   sudo mount /dev/sdb1 /mnt/sdb

