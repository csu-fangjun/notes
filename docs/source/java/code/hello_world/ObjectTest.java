class ObjectTest {
  int i = 10;

  ObjectTest(int k) {
    i = k;
  }

  public static void main(String[] args) {
    // error, no constructor with empty argument
    // ObjectTest o = new ObjectTest();
    //
    // We create an object with `new`
    ObjectTest o = new ObjectTest(100);

    System.out.println(o.i == 100); // true
    ObjectTest o2 = o; // shallow copy
    o2.i = 3;
    System.out.println(o.i == 3); // true

    // Note ArrayTest.java is in the same directory with this file
    // Need to use:
    //   javac ./ArrayTest.java
    //   javac ./ObjectTest.java
    //   java ./ObjectTest
    // ----
    // java ./ObjectTest.java won't work
    ArrayTest a = new ArrayTest();
  }
}
