class MathTest {
  public static void main(String[] args) {
    System.out.println(Math.max(2, 3)); // 3
    System.out.println(Math.max(2, 3.5)); // 3.5
    System.out.println(Math.min(2, 3.5)); // 2
    System.out.println(Math.sqrt(6.25)); // 2.5
    System.out.println(Math.sqrt(9)); // 3.0, note it is a double
    System.out.println(Math.abs(-9)); // -9
    System.out.println(Math.abs(-9.0)); // -9.0
    System.out.println(Math.random()); // a number in the range [0, 1)
  }
}
