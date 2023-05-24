using System.IO;
using System.Diagnostics;

public static class FileTest {
  public static void Test() {
    TestExists();
    Console.WriteLine("FileTest.done");
  }

  public static void TestExists() {
    Debug.Assert(File.Exists("./FileTest.cs") == true);
  }

}
