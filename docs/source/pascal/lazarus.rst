Lazarus
=======

Follow `<https://wiki.freepascal.org/Installing_Lazarus_on_macOS>`_
to install Lazarus.

After installation on macOS, the directory
``/Applications/Lazarus/examples`` contains many examples.

We need to download two files from `<https://sourceforge.net/projects/lazarus/files/Lazarus%20macOS%20x86-64/>`_:

  - ``Lazarus-3.4-macosx-x86_64.pkg``
  - ``fpc-src-3.2.2-20210709-macosx.dmg``

``fpc-src`` is installed in ``/usr/local/share/src/fpc-3.2.2``.
The source code of ``fpc`` can also be found at `<https://github.com/fpc/FPCSource>`_

To reduce ``.exe`` file size:

  1. Select ``Project``, ``Project options...``, ``compiler options``, ``Debugging``
  2. Uncheck ``Generate info for the debugger (slower / increase exe size)``
  3. Check ``Strip symbols from exectuable``
  4. Note: We can create release and debug build mode instead of using the default mode.


See `<https://wiki.freepascal.org/Mac_Installation_FAQ>`_ to fix the following error::

  ld: framework not found Cocoa


whole program optimization: `<https://wiki.freepascal.org/Whole_Program_Optimization#Concrete_Lazarus_IDE_example>`_

 - Multiplatform Programming Guide

   `<https://wiki.freepascal.org/Multiplatform_Programming_Guide>`_

 - Application Bundle

   `<https://wiki.freepascal.org/Application_Bundle>`_

- `<https://wiki.lazarus.freepascal.org/Lazarus_Tutorial>`_

Marcos
------

- For operating systems: ``DARWIN`` for macOS and iOS
- See `<https://www.freepascal.org/docs-html/3.2.0/prog/progap7.html#x341-357000G>`_ for a complete list

Samples and tutorials
---------------------

  - `<https://wiki.lazarus.freepascal.org/Category:Tutorials>`_
  - `<https://wiki.lazarus.freepascal.org/Lazarus_Documentation>`_

  - Manual conversion of C headers to Pascal

    `<https://wiki.lazarus.freepascal.org/Creating_bindings_for_C_libraries#Manual_conversion_of_C_headers_to_Pascal>`_


TForm
-----

See `<https://wiki.lazarus.freepascal.org/Form_Tutorial>`_

To change the caption of the form, assign a string to its ``Caption`` property.

To add a hint to the form, we need to first change its property ``Hint``
and then set property ``ShowHint`` to true.

1. How to show a second form from the main form?

  - There are two methods.

    - (1) The form is created automatically by the application, which is the default behavior.
          If we want to disable auto creation, then we can either edit ``*.lpr`` or use
          menu -> project options -> form, disable auto creating the form.

          Note that the above code assumes the form is created automatically.


          .. code-block:: pascal

            // unit1.pas
            var
              r: Integer;
            begin
              r := Form2.ShowModal;

              case r of
                1: begin ShowMessage('1'); end;
                2: begin ShowMessage('2'); end;
                3: begin ShowMessage('3'); end;
              end;
            end;

            // unit2.pas
            // to exit form2, we can either use self.Close
            // or use
            //
            // Self.ModalResult := 10;
            //
            // we can assign any integer value to Self.ModalResult
            // and it will close the form immediately.

        `<https://lazarus-ccr.sourceforge.io/docs/lcl/forms/tmodalresult.html>`_
        and
        `<https://lazarus-ccr.sourceforge.io/docs/lazutils/uitypes/tmodalresult.html>`_
        and
        `<https://fossies.org/linux/lazarus/components/lazutils/uitypes.pas>`_
        define some constant, e.g., ``mrOK``, ``mrCancel``, etc.

        If we use ``Self.Close`` or click the ``X`` to close the Form, then
        the returned ``ModalResult`` is ``mrCancel``, which is 2.

    - (2) If the form is not created automatically, then we can use

        .. code-block:: pascal

            procedure TForm1.Button1Click(Sender: TObject);
            begin
              Form2:=TForm2.Create(Nil);  //Form2 is created
              Form2.ShowModal;            //Form2 is displayed
              FreeAndNil(Form2);          //Free Form2
            end;

2. How to create a new form dynamically?

  See `<https://wiki.lazarus.freepascal.org/Form_Tutorial#Generate_the_form_dynamically>`_

  .. code-block:: pascal

      procedure TForm1.Button1Click(Sender: TObject);
      var
        MyForm: TForm;
        MyButton: TButton;
      begin
        MyForm:=TForm.Create(nil);
        MyForm.SetBounds(100, 100, 220, 150);
        MyForm.Caption:='My dynamic created form';

        MyButton:=TButton.create(MyForm);
        MyButton.Caption:='Close my form';
        MyButton.SetBounds(10, 10, 200, 30);
        MyButton.Parent:=MyForm;

        MyButton.OnClick:=@MyButtonClick;

        MyForm.ShowModal;

        FreeAndNil(MyForm);
      end;

Tips for manual generation of controls
--------------------------------------

See `<https://wiki.lazarus.freepascal.org/LCL_Tips>`_


TButton
-------

See
  - `<https://wiki.freepascal.org/TButton>`_
  - `<https://lazarus-ccr.sourceforge.io/docs/lcl/stdctrls/tbutton.html>`_

Note that we can set its ``tag`` property. Several buttons
can share the same onclick event handler, we can use its ``tag`` attribute
to distinguish them.

**Example 1**:

.. code-block:: pascal

  // from https://wiki.lazarus.freepascal.org/Lazarus_Tutorial
  procedure TForm1.Button1Click(Sender: TObject);
  { Makes use of the Tag property, setting it to either 0 or 1}
  begin
    if Button1.tag = 0 then
    begin
      Button1.caption := 'Press again';
      Button1.tag := 1;
    end else
    begin
      Button1.caption := 'Press';
      Button1.tag := 0;
    end;
  end;

**Example 2**:

.. code-block:: pascal

  // from
  // https://wiki.lazarus.freepascal.org/TButton
  procedure TForm1.FormCreate(Sender: TObject);
  var
    i:       Integer;
    aButton: TButton;
  begin
    for i := 0 to 9 do begin                // create 10 Buttons
      aButton := TButton.Create(Self);      // create Button, Owner is Form1, where the button is released later
      aButton.Parent  := Self;              // determine where it is to be displayed
      aButton.Width   := aButton.Height;    // Width should correspond to the height of the buttons
      aButton.Left    := i * aButton.Width; // Distance from left
      aButton.Caption := IntToStr(i);       // Captions of the buttons (0.9)
      aButton.OnClick := @aButtonClick;     // the event handler for the button -> will be created yet
    end;
    Self.Height := aButton.Height;          // Height of the form should correspond to the height of the buttons
    Self.Width  := aButton.Width * 10;      // Width of the form to match the width of all buttons
  end;

  procedure TForm1.aButtonClick(Sender: TObject);
  const
    Cnt: Integer = 0;
  var
    i: Integer;
  begin
    if (Sender is TButton) and                  // called the event handler of a button out?
       TryStrToInt(TButton(Sender).Caption, i)  // then try to convert the label in a integer
    then begin
      Cnt := Cnt + i;                           // the adding counter is incremented by the number of entrechende
      Caption:='QuickAdd: '+IntToStr(Cnt);      // write the result to the caption of the form
    end;
  end;

TMemo
-----

Support multiline texts.

It has an attributes ``Lines``, which is of type ``TStringList``.
``Lines.Count`` returns number of lines. If it is 0, then
the text is empty. ``Lines.Add('a new line')`` to add a new line.
``Lines.Clear()`` to clear all lines.

See also `<https://wiki.lazarus.freepascal.org/TMemo>`_.

**Example 1**:

.. code-block:: pascal

  // from https://wiki.lazarus.freepascal.org/TMemo
  // assign a TStringList to a TMemo
  // Note that we have to call Free to free the stringlist
  procedure TForm1.Button1Click(Sender: TObject);
  var
    myStringList: TStringList;
  begin
    myStringList:=TStringList.Create;               //Create my StringList
    myStringList.Add('This is the first line.');    //add a line
    myStringList.Add('This is the second line.');
    myStringList.Add('This is the third line.');
    myStringList.Add('etc.');
    Memo1.Lines.Assign(myStringList);               //assign text content
    myStringList.Free;                              //free my StringList
  end;

**Example 2**:

.. code-block:: pascal

  procedure TForm1.Button1Click(Sender: TObject);
  begin
    Memo1.Lines.Clear;                              //delete all lines of Memo1
    Memo1.Lines.Add('This is the first line.');     //add a line
    Memo1.Lines.Add('This is the second line.');
    Memo1.Lines.Add('This is the third line.');
    Memo1.Lines.Add('etc.');
  end;

TListBox
--------

See `<https://wiki.lazarus.freepascal.org/TListBox>`_.

1. How to add an item
2. How to get the selected item
3. How to get multi-selected items

Dialogs
-------

See `<https://wiki.lazarus.freepascal.org/Dialog_Examples>`_.


1. ``ShowMessage``
2. ``Application.MessageBox``, we can provide several buttons, ask users to click
   one button, figure out which button is clicked, e.g., the yes or no button,
   execute some code.
3. ``MessageDlg``, like ``Application.MessageBox`` but we can specify which
   buttons to show to users. We should prefer this one.

4. ``QuestionDlg``: Users can customize the caption of the buttons.
5. There are also dialogues for accepts user inputs.

TMainMenu
---------

See `<https://wiki.lazarus.freepascal.org/TMainMenu>`_

Naming convention: ``MenuFile``, ``MenuFileOpen`` (for File -> Open), ``MenuHelp``.

macOS related
-------------

 - `Locating the macOS application resources directory <https://wiki.freepascal.org/Locating_the_macOS_application_resources_directory>`_


Info.plist
::::::::::

``Info.plist`` is short for information property list.

We can either use ``vim`` to edit ``Info.plist`` or use ``open Info.plist``
to start xcode to edit it.

References:

 - `Edit property lists <https://help.apple.com/xcode/mac/8.0/#/dev3f399a2a6>`_

    It shows how to use xcode to edit ``Info.plist``.

  - `About Info.plist Keys and Values <https://developer.apple.com/library/archive/documentation/General/Reference/InfoPlistKeyReference/Introduction/Introduction.html#//apple_ref/doc/uid/TP40009248-SW1>`_

  - `About Information Property List Files <https://developer.apple.com/library/archive/documentation/General/Reference/InfoPlistKeyReference/Articles/AboutInformationPropertyListFiles.html#//apple_ref/doc/uid/TP40009254-SW1>`_

Bundle Programming Guide
::::::::::::::::::::::::

  - `Introduction <https://developer.apple.com/library/archive/documentation/CoreFoundation/Conceptual/CFBundles/Introduction/Introduction.html#//apple_ref/doc/uid/10000123i>`_

  - `Application Bundles <https://developer.apple.com/library/archive/documentation/CoreFoundation/Conceptual/CFBundles/BundleTypes/BundleTypes.html#//apple_ref/doc/uid/10000123i-CH101-SW13>`_
