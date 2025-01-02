Install
=======

Install `<https://developer.huawei.com/consumer/cn/deveco-studio/>`_

macos
-----

.. code-block:: bash

   # How to upload files to the emulator from my macOS
   # https://developer.huawei.com/consumer/cn/forum/topic/0207152795297975671

   export PATH=/Users/fangjun/software/huawei/OpenHarmony/Sdk/10/toolchains:$PATH

   hdc -c file send ~/open-source/sherpa-onnx/lei-jun-test.wav /storage/media/100/local/files/Docs/Download/

   hdc shell
   cd /storage/media/100/local/files/Docs/Download/
   ls -lh


todo
----

`<https://medium.com/huawei-developers/building-a-note-app-with-arkui-and-arkts-on-harmonyos-67fd7c4c1086>`_

  - TabsController
  - aboutToAppear
  - changeTab
  - tagBarBuilder

Native侧实现文件访问开发实践
----------------------------

`<https://developer.huawei.com/consumer/cn/doc/best-practices-V5/bpta-file-native-side-V5#section1052945819523>`_

- 应用沙箱目录 `<https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/app-sandbox-directory-V5>`_

- Rawfile开发指导 `<https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/rawfile-guidelines-V5>`_



Node-API Development Process
----------------------------

See `<https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/use-napi-process-V5>`_

It has an example about calling ``Add()`` from C/C++.

资源分类与访问
--------------

`<https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/resource-categories-and-access-V5>`_

module.json5配置文件
--------------------

`<https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/module-configuration-file-V5>`_

Building an NDK Project with the DevEco Studio Template
--------------------------------------------------------

See `<https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/build-with-ndk-ide-V5>`_

It contains an example about adding abi filters.

Getting Started with the NDK
----------------------------

See `<https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ndk-development-overview-V5>`_

Node-API Overview
-----------------

See `<https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/napi-introduction-V5>`_

在 GitHub Action 上构建 HarmonyOS 应用
--------------------------------------

See `<https://www.phodal.com/blog/github-action-for-harmonyos/>`_


OpenHarmony Linux 环境 SDK 使用说明
-----------------------------------

See `<https://gitee.com/han_jin_fei/lycium/blob/master/doc/ohos_use_sdk/OHOS_SDK-Usage.md>`_

Command Line Tools for HarmonyOS
--------------------------------

See `<https://github.com/harmonyos-dev/hos-sdk>`_

贡献应用资源
------------

See `<https://repo.harmonyos.com/#/cn/help/contributeapp>`_

Rust登陆【华为鸿蒙】操作系统之Native模块开发
--------------------------------------------

See `<https://rustcc.cn/article?id=568d35d6-b782-49e9-b9b1-5d870d28f927>`_


简易Native C++ 示例
-------------------

  - `<https://developer.huawei.com/consumer/cn/codelabsPortal/carddetails/tutorials_NEXT-NativeTemplateDemo>`_
  - `<https://gitee.com/harmonyos_codelabs/NativeTemplate>`_

编译一份适用于鸿蒙ArkTs的so动态库教学，提供给第三方导入并使用
-------------------------------------------------------------

See `<https://blog.csdn.net/qq_17432441/article/details/134545608?spm=1001.2014.3001.5501>`_

鸿蒙ArkTs加载各种so动态链接库教程，包括适用于鸿蒙的动态库和通用linux动态链接库，堕胎级教程，一篇就够了，玩转so加载
------------------------------------------------------------------------------------------------------------------

See `<https://blog.csdn.net/qq_17432441/article/details/134564221>`_

The first example
-----------------

See `<https://device.harmonyos.com/en/docs/apiref/doc-guides/start-with-ets-0000001168323542>`_

It shows how to switch between two pages.

Linear Layout
-------------

See `<https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/arkts-layout-development-linear-V5>`_


RelativeContainer
--------------------

See `<https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/arkts-layout-development-relative-layout-V5>`_

 - Vertical: top, center, bottom
 - Horizontal: left, middle, right

.. code-block::

  RelativeContainer() {
     Text(this.message)
     .id('HelloWorld')
     .fontSize(50)
     .fontWeight(FontWeight.Bold)
     .alignRules({
       top: { anchor: '__container__', align: VerticalAlign.Top },
       left: { anchor: '__container__', align: HorizontalAlign.Start }
       })
     }

