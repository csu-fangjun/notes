using System.IO;
using System;
using System.Diagnostics;

public static class FileTest {
  public static void Test() {
    TestExists();
    TestPath();
    TestDirectory();
    Console.WriteLine("FileTest.done");
  }

  public static void TestExists() {
    Debug.Assert(File.Exists("./FileTest.cs") == true);
  }

  public static void TestPath() {
    Debug.Assert(Path.HasExtension("a.txt") == true);
    Debug.Assert(Path.HasExtension("a") == false);

    // /Users/fangjun/open-source/notes/docs/source/csharp/code/Hello/a.txt
    Console.WriteLine(Path.GetFullPath("a.txt"));

    // /var/folders/fw/cg40_07j7cb18_p_ymf0zhkr0000gn/T/
    Console.WriteLine(Path.GetTempPath());

    // /var/folders/fw/cg40_07j7cb18_p_ymf0zhkr0000gn/T/tmpAINkzd.tmp
    Console.WriteLine(Path.GetTempFileName());

    Console.WriteLine(Path.ChangeExtension("a.txt", "bin") == "a.bain");
  }

  public static void TestDirectory() {
    // /Users/fangjun/open-source/notes/docs/source/csharp/code/Hello
    Console.WriteLine(Directory.GetCurrentDirectory());
  }

}
