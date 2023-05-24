using System.Diagnostics;
using System.Runtime.InteropServices;

class SpanTest {
  public static void Test() {
    TestByteArray();
    TestStackAlloc();
    TestGlobalAlloc();
  }
  public static void TestByteArray() {
    byte[] b = new byte[10];
    Span<byte> s = new Span<byte>(b);
    // s points to the memory holds by b
    s[0] = 10;
    Debug.Assert(b[0] == 10);

    // s2 = b[3:5]
    Span<byte> s2 = s.Slice(start:3, length: 2);
    s2[0] = 12;
    s2[1] = 13;
    Debug.Assert(b[3] == 12);
    Debug.Assert(b[4] == 13);
  }

  public static void TestStackAlloc() {
    Span<int> s = stackalloc int[10];
    s.Clear(); // set all contents to default(int);
    Debug.Assert(s.Length == 10);
  }

  public static void TestGlobalAlloc() {
    IntPtr p = Marshal.AllocHGlobal(sizeof(int) * 2);
    Span<int> s;
    unsafe {
      // p.ToPointer() returns void*, so it has to be used in void*
      s = new Span<int>(p.ToPointer(), 2);
      s[0] = 10;
      s[1] = 11;
    }

    int a = Marshal.ReadInt32(p);
    int b = Marshal.ReadInt32(p, sizeof(int));
    Debug.Assert(a == s[0]);
    Debug.Assert(b == s[1]);

    Marshal.FreeHGlobal(p);
  }
}
