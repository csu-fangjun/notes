package main

import (
	"fmt"
	"unsafe"
)

// int8 int16 int32 int64 int
// uint8 uint16 uint32 uint64 uint
//
// int != int32
// uint != uint32
//
// On 32-bit systems, int has 32 bits
// On 64-bit systems, int has 64 bits
func main() {
	var i8 int8 = 1
	fmt.Printf("i8 %[1]d %[1]T, %d\n", i8, unsafe.Sizeof(i8)) // int8 1 int8, 1

	i8 += 127                          // wrap around, same like c/c++
	fmt.Printf("i8 %[1]d %[1]T\n", i8) // int8 -128 int8

	// Note i has 8 bytes on my 64-bit macOS
	i := 10
	fmt.Printf("i %[1]d %[1]T, %d\n", i, unsafe.Sizeof(i)) // i 10 int, 8
	fmt.Printf("i/3 %[1]d %[1]T\n", i/3)                   // i/3 3 int, same as c/c++

	var i32 int32 = 100
	fmt.Printf("i32 %[1]d %[1]T, %d\n", i32, unsafe.Sizeof(i32)) // i32 100 int32, 4

	fmt.Printf("'%5d'\n", i32)  // '  100'
	fmt.Printf("'%05d'\n", i32) // '00100'
	fmt.Printf("'%-5d'\n", i32) // '100  '

}
