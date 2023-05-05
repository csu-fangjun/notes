Basics
======

- `Interop with Native Libraries <https://www.mono-project.com/docs/advanced/pinvoke>`_
- `Default marshalling for strings <https://learn.microsoft.com/en-us/dotnet/framework/interop/default-marshalling-for-strings>`_
- `cbrumme's WebLog <https://learn.microsoft.com/en-us/archive/blogs/cbrumme/>`_
- `.NET Standard <https://learn.microsoft.com/en-us/dotnet/standard/net-standard?tabs=net-standard-1-0>`_
- `Preprocessor symbols <https://learn.microsoft.com/en-us/dotnet/standard/frameworks#preprocessor-symbols>`_
- `Packaging Icon within the nupkg <https://github.com/NuGet/Home/wiki/Packaging-Icon-within-the-nupkg>`_
- `MSBuild reference for .NET SDK projects <https://learn.microsoft.com/en-us/dotnet/core/project-sdk/msbuild-props>`_


- `Visual Studio for Mac documentation <https://learn.microsoft.com/en-us/visualstudio/mac>`_
- `DllImportAttribute Class <https://learn.microsoft.com/en-us/dotnet/api/system.runtime.interopservices.dllimportattribute>`_
- `A Closer Look at Platform Invoke <https://learn.microsoft.com/en-us/previous-versions/aa719485(v=vs.71)>`_
- `Identifying Functions in DLLs <https://learn.microsoft.com/en-us/previous-versions/aa720146(v=vs.71)>`_

- `DllImportAttribute.CallingConvention Field <https://learn.microsoft.com/en-us/dotnet/api/system.runtime.interopservices.dllimportattribute.callingconvention>`_
- `C# Coding Conventions <https://learn.microsoft.com/en-us/dotnet/csharp/fundamentals/coding-style/coding-conventions>`_
- `IDisposable.Dispose Method <https://learn.microsoft.com/en-us/dotnet/api/system.idisposable.dispose?view=net-7.0>`_
- `Quickstart: Create and publish a package with the dotnet CLI <https://learn.microsoft.com/en-us/nuget/quickstart/create-and-publish-a-package-using-the-dotnet-cli>`_
- `Creating a NuGet package for a library with platform-specific API <https://habr.com/en/articles/565908/>`_
- `.NET RID Catalog <https://learn.microsoft.com/en-us/dotnet/core/rid-catalog>`_


Use the commandline
-------------------

.. code-block:: bash

  # To activate the developer commandline
  "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

.. code-block:: bash

   # it generates ./a.exe
   csc ./a.cs

.. code-block:: bash

   # it generates b.dll
   csc /target:library b.cs

   # it generates a.exe
   csc /r:b.dll a.cs

.. code-block:: bash

   dumbpin -exports sherpa-onnx-c-api.dll

If the name in the C++ function is Hello, we can use either:

.. code-block:: c#

   [DllImport("dllname")]
   void Hello();

or

.. code-block:: c#

   [DllImport("dllname", EntryPoint="Hello")]
   void HelloANewName();

Visual Studio for Mac
---------------------

After installation, start it and click ``Visual Stuido -> About Visual studio -> Show details``,
it will show the locations:

  - Runtime: ``/usr/local/share/dotnet/dotnet``
  - SDK: ``/usr/local/share/dotnet/sdk/7.0.203/Sdks``

.. code-block:: bash

  $ /usr/local/share/dotnet/dotnet

  Usage: dotnet [options]
  Usage: dotnet [path-to-application]

  Options:
    -h|--help         Display help.
    --info            Display .NET information.
    --list-sdks       Display the installed SDKs.
    --list-runtimes   Display the installed runtimes.

  path-to-application:
    The path to an application .dll file to execute.
