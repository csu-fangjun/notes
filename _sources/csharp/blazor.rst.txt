Blazor
======


Create a page:

.. code-block:: bash

   dotnet new razorcomponent -n Todo -o Pages

First TODO page:

.. literalinclude:: ./code/TodoItem.cs

.. literalinclude:: ./code/Todo.razor

On parameter set:

.. code-block::

   @page "/counter/{startingValue}"
   @code {

     private int currentCount = 0;

     [Parameter]
     private int startingValue { get; set; } = 0

     protected override void OnParametersSet()
     {
         currentCount = startingValue;
         base.OnParametersSet();
     }

   }
