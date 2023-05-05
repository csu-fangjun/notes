nuget
=====

vosk is using non-SDK style, while the latest .NET doc uses SDK style.

.. code-block:: bash

   msbuild ./t.csproj -t:targetName -p:Configuration=Release -verbosity:detail

.. code-block:: bash

   dotnet msbuild -property:TargetFramework=netcoreapp2.0 -preprocess:output.xml



References
----------

- `Walkthrough: Use MSBuild <https://learn.microsoft.com/en-us/visualstudio/msbuild/walkthrough-using-msbuild?view=vs-2022>`_
- `Build items <https://learn.microsoft.com/en-us/visualstudio/msbuild/walkthrough-using-msbuild?view=vs-2022#build-items>`_
- `MSBuild items <https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild-items?view=vs-2022>`_
- `ItemGroup element (MSBuild) <https://learn.microsoft.com/en-us/visualstudio/msbuild/itemgroup-element-msbuild?view=vs-2022>`_
- `Use wildcards to specify items <https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild-items?view=vs-2022#use-wildcards-to-specify-items>`_
- `How to: Exclude files from the build <https://learn.microsoft.com/en-us/visualstudio/msbuild/how-to-exclude-files-from-the-build?view=vs-2022>`_
- `MSBuild well-known item metadata <https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild-well-known-item-metadata?view=vs-2022>`_
- `How to: Select the files to build <https://learn.microsoft.com/en-us/visualstudio/msbuild/how-to-select-the-files-to-build?view=vs-2022>`_
- `.NET project SDKs <https://learn.microsoft.com/en-us/dotnet/core/project-sdk/overview>`_

Select file

.. code-block:: xml

   // All cs files in the current directory
   <CSFile Include="*.cs"/>

   // All files in the D drive
   <VBFile Include="D:/**/*.vb"/>

   // Include all cs files except the file DoNotBuild.cs
   <ItemGroup>
    <CSFile  Include="*.cs"  Exclude="DoNotBuild.cs"/>
   </ItemGroup>


   <Compile Include="*.cs" />
   <Compile Include="*.res" Exclude="Form1.cs"> // note: Form1.cs is included in the first statement

   <CSFile Include="Form1.cs"/>
   <CSFile Include ="File1.cs;File2.cs"/>
   <CSFile Include="*.cs"/>
   <JPGFile Include="Images\**\*.jpg"/>

   // All *.cs execpt Form2.cs and Fomr3.cs
   <CSFile Include="*.cs" Exclude="Form2.cs;Form3.cs"/>

   // all *.jpg files except the version2 directory
   <JPGFile
       Include="Images\**\*.jpg"
       Exclude = "Images\**\Version2\*.jpg"/>


   // Include only in Release build
   <Compile
      Include="Formula.vb"
      Condition=" '$(Configuration)' == 'Release' " />


- To reference an item metadata: ``%(<ItemMetadataName>)`` or  ``%(<ItemType.ItemMetaDataName>)``
- To reference a property, use ``$(property)``
- To reference an item, use ``@(item)``

.. code-block::

  <Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
      <ItemGroup>
          <Stuff Include="One.cs" >
              <Display>false</Display>
          </Stuff>
          <Stuff Include="Two.cs">
              <Display>true</Display>
          </Stuff>
      </ItemGroup>
      <Target Name="Batching">
          <Message Text="@(Stuff)" Condition=" '%(Display)' == 'true' "/>
      </Target>
  </Project>

  // Stuff is an item, so we use @(Stuff)
  // Display is an item metadata, so we use %(Display)
  // @(Stuff) is "One.cs;Two.cs"

Some well-known item metadata ``%(FullPath)``, ``%(Filename)``


