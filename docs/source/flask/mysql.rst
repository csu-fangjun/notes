MySQL
=====

Use the community edition.

Installation on macOS
---------------------

See `<https://dev.mysql.com/doc/mysql-macos-excerpt/5.7/en/macos-installation.html>`_

.. code-block:: bash

    tar xvf mysql-8.0.33-macos13-x86_64.tar.gz

    2023-05-28T15:14:16.627733Z 0 [System] [MY-013169] [Server] /Users/fangjun/software/mysql/mysql-8.0.33-macos13-x86_64/bin/mysqld (mysqld 8.0.33) initializing of server in progress as process 11553
    2023-05-28T15:14:16.629538Z 0 [Warning] [MY-010159] [Server] Setting lower_case_table_names=2 because file system for /Users/fangjun/software/mysql/mysql-8.0.33-macos13-x86_64/data/ is case insensitive
    2023-05-28T15:14:16.633467Z 1 [System] [MY-013576] [InnoDB] InnoDB initialization has started.
    2023-05-28T15:14:16.800011Z 1 [System] [MY-013577] [InnoDB] InnoDB initialization has ended.
    2023-05-28T15:14:17.600930Z 6 [Note] [MY-010454] [Server] A temporary password is generated for root@localhost: ;;Geh%7QmF%<
    2023-05-28T15:14:18.316658Z 0 [System] [MY-013172] [Server] Received SHUTDOWN from user <via user signal>. Shutting down mysqld (Version: 8.0.33).

    (py38) fangjuns-MacBook-Pro:mysql-8.0.33-macos13-x86_64 fangjun$ bin/mysql_ssl_rsa_setup --datadir ./data

    (py38) fangjuns-MacBook-Pro:mysql-8.0.33-macos13-x86_64 fangjun$ ./bin/mysql -u root -p
    # Enter the password generated in the above logs
    # After loging, change the password to test

    mysql> ALTER USER 'root'@localhost IDENTIFIED BY 'test';
    mysql> EXIT

