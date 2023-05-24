using System.Diagnostics;
using System.Runtime.InteropServices;

/*
We have to add to ./Hello.csproj
  <AllowUnsafeBlocks>true</AllowUnsafeBlocks>
*/

public class UnsafeTest {
  class MyStruct {
    public int A;
    public char B;
  }

  public static void TestPointer() {
    // for a primitive (unmanaged type)
    int a = 3;
    unsafe {
      int*p = &a;
      *p = 10;
      Debug.Assert(a == 10);
      a = 20;
      Debug.Assert(p[0] == 20); // like C/C++
    }

    // now for an array. We have to ensure the address of the array
    // is not moved by using fixed. This is also called a pin operation.
    unsafe {
      byte[] b = new byte[5];
      fixed(byte*p = &b[0]) {
        // p is a constant inside this block due to the usage of fixed.
        // That is, p is a fixed variable
        //
        // Note: We can also use (byte*p = b)
        p[0] = 10;
        Debug.Assert(b[0] == 10);

        b[1] = 20;
        Debug.Assert(*(p+1) == 20);
        Debug.Assert(p[1] == 20);
        Console.WriteLine($"address of p: 0x{(long)p:X}");
        Console.WriteLine($"address of p+1: 0x{(long)(p+1):X}");
      }
    }

    // test struct
    MyStruct s = new MyStruct {A=10, B='B'};
    unsafe {
      MyStruct* p = &s;
      Debug.Assert(p->A == 10); // similar to C/C++
      Debug.Assert(p->B == 'B');
      p->B = 'C';
      Debug.Assert(s.B == 'C');
    }

    // from stackalloc
    unsafe {
      int*p = stackalloc int[3];
      // the content is uninitialized
      p[0] = 10;
      ++p;
      p[0] = 20;
      ++p;
      Debug.Assert(p[-2] == 10);
      Debug.Assert(p[-1] == 20);
    }


    IntPtr pp = Marshal.AllocHGlobal(sizeof(int));
    unsafe {
      int* p = (int*)pp.ToPointer();
      p[0] = 10;
    }
    int i = Marshal.ReadInt32(pp);
    Debug.Assert(i == 10);

    Marshal.FreeHGlobal(pp);


  }
}
