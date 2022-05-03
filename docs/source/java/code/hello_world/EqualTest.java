class EqualTest {
  public int i;

  public EqualTest(int a) {
    this.i = a;
  }

  public boolean equals(Object anObject) {
    if (this == anObject) {
      return true;
    }
    if (anObject instanceof EqualTest) {
      return this.i == ((EqualTest) anObject).i;
    }
    return false;
  }

  public static void main(String[] args) {
    EqualTest e1 = new EqualTest(10);
    EqualTest e2 = new EqualTest(10);

    System.out.println(e1 == e2); // false, compare the reference
    System.out.println(e1 != e2); // true
    System.out.println(e1.equals(e2)); // true, compare the contained value
  }
}
