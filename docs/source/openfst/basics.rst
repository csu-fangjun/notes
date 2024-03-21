Basics
======

The latest version as of 2023.03.21 is v1.8.3

`<https://github.com/csukuangfj/openfst-1.8.3/blob/master/BUILD.bazel>`_ lists
the build rules. The base lib is::

  cc_library(
      name = "base",
      srcs = [
          prefix_dir + "lib/compat.cc",
          prefix_dir + "lib/flags.cc",
      ],
      hdrs = [
          prefix_dir + "include/fst/compat.h",
          prefix_dir + "include/fst/flags.h",
          prefix_dir + "include/fst/icu.h",
          prefix_dir + "include/fst/lock.h",
          prefix_dir + "include/fst/log.h",
          prefix_dir + "include/fst/windows_defs.inc",
      ],
      defines = select({
          ":has_absl": ["OPENFST_HAS_ABSL=1"],
          "//conditions:default": [],
      }),
      includes = [prefix_dir + "include"],
      deps = select({
          ":has_absl": ["@com_google_absl//absl/synchronization"],
          "//conditions:default": [],
      }),
  )

compat.h
--------

.. code-block:: c++

  #if defined(__GNUC__) || defined(__clang__)
  #define OPENFST_DEPRECATED(message) __attribute__((deprecated(message)))
  #elif defined(_MSC_VER)
  #define OPENFST_DEPRECATED(message) [[deprecated(message)]]
  #else
  #define OPENFST_DEPRECATED(message)
  #endif
