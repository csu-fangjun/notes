dotnet
======

.. code-block:: bash

  dotnet --list-sdks

  # Create a directory and create a file global.json in it
  # global.json contains the default sdk version to use
  dotnet new globaljson --sdk-version 6.0.100 --output FirstProject

  # Create an ASP.Net Core MVC web project, and put it inside the directory
  # FirstProject.
  dotnet new mvc --no-https --output FirstProject --framework net6.0

  # Create a solution named FirstProject and put it inside ./FirstProject
  dotnet new sln -o FirstProject

  # Add the project "FirstProject" to the solution "FirstProject"
  dotnet sln FirstProject add FirstProject

  # list supported projects
  dotnet new --list
