class Strings {
  public static void main(String[] args) {
    String s = "abc";
    System.out.println(s.length()); // 3
    System.out.println(s.toUpperCase()); // ABC
    System.out.println(s.toUpperCase().toLowerCase()); // abc
    System.out.println(s.indexOf("ab")); // 0
    System.out.println(s.indexOf("a")); // 0
    System.out.println(s.indexOf("bc")); // 1
    System.out.println(s.indexOf("bca")); // when not found, it is -1

    System.out.println(s.charAt(0) == 'a'); // true
    System.out.println(s + "123" == "abc123"); // false, == compares the reference
    System.out.println((s + "123").equals("abc123")); // true, compare the content
    System.out.println(s.concat("123").equals("abc123")); // true, compare the content
    System.out.println((s + 123).equals("abc123")); // true, compare the content
    System.out.println((123 + s).equals("123abc")); // true, compare the content
    s = "a\"b";
  }
}
;
