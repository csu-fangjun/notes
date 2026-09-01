The Rust Programming Language - book notes
==========================================

See `<https://rust-book.cs.brown.edu/>`_ and `<https://doc.rust-lang.org/book/>`_

看了这本书之后，要去看 `<https://doc.rust-lang.org/rust-by-example/index.html>`_
- `<https://rust-exercises.com/100-exercises/>`_

还要去看 `<https://doc.rust-lang.org/nomicon/intro.html>`_

- `<https://github.com/rust-lang/rustlings/>`_

.. code-block::

   cargo install rustlings
   mkdir tmp
   cd tmp
   rustlings init
   cd rustlings
   rustlings


Chapter 1 Installation
-----------------------

.. code-block::

   rustc --version

输出::

  rustc 1.93.1 (01f6ddf75 2026-02-11)

查看帮助: ``rustup doc``. 会打开一个浏览器页面，纯本地，无需联网。

可以查看的帮助举例：查看 ``str`` 的文档。可以查看代码里，任意一个函数或者类型的帮助文档。

如果想提前下载依赖，可以使用下面的方法 (新建一个项目，添加依赖，然后把依赖下载到cache 里之后，就可以删掉这个项目里。cache 是全局的)::

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

当前项目的缓存，存在当前目录 ``./target`` 下。

如果想删除缓存，可以直接删掉 ``~/.cargo/registry`` . 如果是删除项目当前目录下的 ``target`` 目录里的缓存，可以直接用
``cargo clean``.

Chapter 2 Programming a Guessing Game
-------------------------------------

- 直接输出，用 ``println!("hello world");``, string interpolation 用 ``println!("a is {a}");``.
- 展示了 Result 和 match 的用法
- rust 常规， 比较大小用 ``x.cmp(y)``, 配合 ``match``, 虽然，也可以用 ``if (a<b)`` 这种方式
- 演示了如何用 ``rand`` 这个 crate
- 查看帮助， 用 ``cargo doc --open``, 可以看项目里用到的所有的 crate 的帮助
- ``cargo check``, ``cargo build``, ``cargo run`` 的用法
- 循环用 ``loop``, ``break``, ``continue``
- ``if`` 语句，必须用 ``{}`` 括起来。可以写成 ``if a < b {}``, 不需要写成 ``if (a < b) {}``, 虽然不算错, 但编译时，会报 warnings, 提示没必要加 ``()``
- 从命令行输入 ``std::io`` 这个模块
- 字符串的 ``new``, ``trim``, ``parse`` (字符串转为数字)
- 创建一个项目，用 ``cargo new``, 自从生成 ``Cargo.toml``, ``src/main.rs``, 里面有一个hello word 的 main 程序

Chapter 3 Common Programming Concepts
-------------------------------------

- 有哪些基本数据类型
  - int: i32, u32, i8, u8, etc
  - float: f32, f64
  - bool, 一个字节
  - char, 4 个字节
- let 和 const 的区别
- 如何定义mutable 变量
- tuple 与数组的定义
   - tuple 可以有 x.0, x.1 等访问，也有 tupe destructure
   - 数组, runtime 会有out of boundary check
- 如何iterate 一个数组
- if, loop, while, for 的用法
- break, continue 的用法
- 如何定义一个函数
- 大括号是一个 expression, 虽然没有 ``?:`` 三元操作符，但是可以用 if/else 实现同样的效果，类似 kotlin 里的
