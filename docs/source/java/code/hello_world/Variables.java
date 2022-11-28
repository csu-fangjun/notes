class Variables {
  public static void main(String[] args) {
    String msg = "Hello world";
    int i = 10;
    i++; // ok
    ++i; // ok
    // i-- // error, should be --i
    --i;
    int ii = i % 2;
    i = 10;
    ii = i / 3; // truncated
    System.out.println(ii); // 3
    ii += 2;
    System.out.println(ii); // 5
    // also has:
    // -=, &=, |=, >>=, <<=, ^=, /=, *=
    // Similar to C/C++

    /* float f = 1.25; // error: possible lossy conversion from double to float */
    // Caution: We have to use `1.25f` instead of `1.25` to assign a float variable
    float f = 1.25f;
    double d = 1.25;
    d = 1.25d; // also ok

    // f = d; // error: possible lossy conversion from double to float
    f = (float) d; // ok, explicit cast
    d = f; // ok

    char c = 'h'; // a character

    i = 10;
    System.out.println(msg);
    System.out.println(i); // 10
    System.out.println(f); // 1.25
    System.out.println(d); // 1.25
    System.out.println(c); // h

    // define multiple variable in the same line
    int i1 = 1, i2;
    // System.out.println(i2); // variable i2 might not have been initialized
    i2 = 3;
    System.out.println(i2); // 3
    boolean b = false;
    System.out.println(b); // false
    b = true;
    // b = 1; // error: int cannot be converted to boolean
    System.out.println(b); // true

    // byte b0 = 128; // error: lossy conversion from int to byte
    byte b0 = 127; // ok
    /* b0 = -129; // error: lossy conversion from int to type */
    b0 = -128; // ok

    // short s0 = 32768; // error: lssoy conversion from int to short
    short s0 = 32767; // ok
    // s0 = -32769; // error: lossy conversion fro int to short
    s0 = -32768; // ok

    // other types: int, long, float, double, boolean, char
    // Note: char has 2-byte
    // boolean has 1-bit
    // There are no unsigned integers !!

    // ternary operator :?
    System.out.println(2 > 3 ? "yes" : "no"); // no
  }
}
