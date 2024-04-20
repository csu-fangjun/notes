package main

import "fmt"

func testChar() {
	c := 'a'
	fmt.Printf("%[1]d %[1]c %[1]T\n", c) // 97 a int32

	var a rune = 'a'
	fmt.Printf("%[1]d %[1]c %[1]T\n", a) // 97 a int32

	// rune is an alias to int32
}

func main() {
	s := "hello"
	s2 := fmt.Sprintf("%s world", s) // hello world

	fmt.Println(s, s2) // hello hello world

	// use %q to surround the output with double quotes ""
	fmt.Printf("%q, %s\n", s, s) // "hello", hello

	// raw string inside ``, like R"()" in C++
	// can contain multiple lines
	s3 := `how\a\nyou`
	fmt.Println(s3) // how\a\n\you

	// for loop

	// utf-8 encoding of ä is 0xC3 0xA4
	// utf-32 encoding of ä is 0x000000E4

	// iterating the utf-8 encoded bytes array
	s = "aäa"
	for i := 0; i < len(s); i++ {
		fmt.Printf("%d 0x%x, %T\n", i, s[i], s[i])
	}
	// 0 0x61, uint8
	// 1 0xc3, uint8
	// 2 0xa4, uint8
	// 3 0x61, uint8
	fmt.Println("----")

	// use a range for loop;
	// returns a utf-8 encoded character in each iteration
	//
	// the type of i is int
	// note the type of c is int32
	for i, c := range s {
		fmt.Printf("%d 0x%x, %v, %s, %T\n", i, c, c, string(c), c)
	}
	// 0 0x61, 97, a, int32
	// 1 0xe4, 228, ä, int32
	// 3 0x61, 97, a, int32

	testChar()

}
