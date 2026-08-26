The Rust Programming Language - book notes
==========================================

See `<https://rust-book.cs.brown.edu/>`_ and `<https://doc.rust-lang.org/book/>`_

Chapter 1 Installation
-----------------------

.. code-block::

   rustc --version

输出::

  rustc 1.93.1 (01f6ddf75 2026-02-11)

查看帮助和这本书: ``rustup doc``. 会打开一个浏览器页面，纯本地，无需联网。

可以查看的帮助举例：查看 ``str`` 的文档。可以查看代码里，任意一个函数或者类型的帮助文档。

如果想提前下载依赖，使用测试方法::

  cargo new test-dep
  cd test-dep
  cargo add sherpa-onnx@1.13.6
  cargo fetch

依赖默认保存在 ``~/.cargo/`` 目录下。可以通过设置环境变量 ``CARGO_HOME`` 来改变。
默认情况下, ``CARGO_HOME`` 是空的，如果用 ``export CARGO_HOME=$PWD/tmp``, 那么，下载下来的
依赖就存在``$PWD/tmp``::

  cd ./tmp

  find . -name "*sherpa*"

  ./registry/cache/index.crates.io-1949cf8c6b5b557f/sherpa-onnx-sys-1.13.6.crate
  ./registry/cache/index.crates.io-1949cf8c6b5b557f/sherpa-onnx-1.13.6.crate
  ./registry/index/index.crates.io-1949cf8c6b5b557f/.cache/sh/er/sherpa-onnx
  ./registry/index/index.crates.io-1949cf8c6b5b557f/.cache/sh/er/sherpa-onnx-sys
  ./registry/src/index.crates.io-1949cf8c6b5b557f/sherpa-onnx-1.13.6
  ./registry/src/index.crates.io-1949cf8c6b5b557f/sherpa-onnx-sys-1.13.6

对于通过 ``build.rs`` 下载的，需要 ``cargo check`` 或者 ``cargo build`` 等命令运行时，才会下载。
