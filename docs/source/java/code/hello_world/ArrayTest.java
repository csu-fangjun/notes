class ArrayTest {
  public static void main(String[] args) {
    int[] a = {1, 2, 3};
    for (int i : a) {
      System.out.println(i);
    }
    /*
    1
    2
    3
     */
    System.out.println(a[0]); // 1
    System.out.println(a.length); // 3
    for (int i = 0; i != a.length; ++i) {
      System.out.println(a[i]);
    }
    /*
    1
    2
    3
         */
  }
}
