// go mod tidy
// go build ./main.go

package main

import (
	"fmt"
	"unsafe"
)

// array has value semantics. Assignment is done by value copy
// array cannot be resized
func test1() {
	fmt.Println("---test1---")
	var a [2]int        // zero initialized
	fmt.Println(a)      // [0 0]
	fmt.Println(cap(a)) // 2
	fmt.Println(len(a)) // length

	for i := 0; i < len(a); i++ {
		fmt.Println(a[i])
	}
	// 0
	// 0

	// i is the index
	// v is the value
	for i, v := range a {
		fmt.Println(i, v)
	}
	// 0 0
	// 1 0

	// to ignore the index, use _
	for _, v := range a {
		fmt.Println(v)
	}

	// to ignore v
	for i := range a {
		fmt.Println(a[i])
	}

	// infer the array size automatically
	b := [...]int{1, 2, 3}
	fmt.Println(b) // [1 2 3]

	// c is a slice
	// b[start:end], end is exclusive
	// c contains b[0] and b[1]
	var c []int = b[0:2]
	fmt.Println(c, len(c)) // [1 2] 2

	// creates an array, and return a slice that references the array
	d := []int{1, 2}
	fmt.Println(d) // [1 2]
}

func test2() {
	fmt.Println("---test2---")
	// func make([]T, len, cap) []T
	a := make([]int, 0, 10)
	b := a

	c := []int{0, 1, 2, 3}
	fmt.Println("len(c)", len(c), "cap(c)", cap(c)) // len(c) 4 cap(c) 4

	d := []int{4, 5, 6, 7}
	e := []int{8, 9, 10, 11}
	// func append(s []T, x ...T) []T
	a = append(a, c...)
	a = append(a, d...)
	fmt.Println(a) // [0 1 2 3 4 5 6 7]
	b = b[0:10]
	fmt.Println(b) // [0 1 2 3 4 5 6 7 8 0 0]

	a = append(a, e...) // allocated new array
	fmt.Println(a)      // [0 1 2 3 4 5 6 7 8 9 10 11]
	fmt.Println(b)      // [0 1 2 3 4 5 6 7 8 0 0]
}

func test3() {
	fmt.Println("--test3--")

	// a slice is initialized to nil
	var a []int
	fmt.Println(a == nil)       // true
	fmt.Println(len(a), cap(a)) // 0, 0
	fmt.Println(a)              // []
	fmt.Printf("%#v\n", a)      // []int(nil)
	// fmt.Println(a[0])           // panic: runtime error: index out of range [0] with length 0

	b := new([]int)
	fmt.Println(b == nil)  // false
	fmt.Println(*b == nil) // true

	// the underlying array for c is of length 0 and capacity 0
	c := []int{}
	fmt.Println(c == nil)       // false
	fmt.Println(len(c), cap(c)) // 0, 0
	fmt.Println(c)              // []
	fmt.Printf("%#v\n", c)      // []int{}
	// fmt.Println(c[0])           // panic: runtime error: index out of range [0] with length 0

	d := []int(nil)
	fmt.Println(d == nil) // true
}

func test4() {
	fmt.Println("--test4--")
	var a []int
	fmt.Println(a == nil) // true
	a = append(a, 1)
	fmt.Println(a[0] == 1) // true

	var b []int = []int{}
	fmt.Println(b != nil) // true
	b = append(b, 2)
	fmt.Println(b[0] == 2) // true

	// the first argument of append() can be nil

	c := append([]int(nil), 1)
	fmt.Println(c[0] == 1) // true

	d := append([]int{}, 1)
	fmt.Println(d[0] == 1) // true

	f := []int{1, 2, 3}
	g := []int{10}
	for _, v := range f {
		g = append(g, v)
	}
	fmt.Println(g) // [10 1 2 3]

	h := []int{10}
	h = append(h, f...) // recommended approach to append a slice
	fmt.Println(h)      // [10 1 2 3]
}

func test5() {
	fmt.Println("---test5---")
	var a []int
	fmt.Println(a == nil) // true

	// pointer, length, capacity, 8 + 8 + 8 = 24 on a 64-bit computer
	fmt.Println(unsafe.Sizeof(a)) // 24
}

func test6() {
	fmt.Println("---test6---")
	var a []int
	b := []int{} // it is en error to use b := []int,  []int (type) is not an expression
	c := make([]int, 0)
	fmt.Printf("%#v\n", a) // []int(nil)
	fmt.Printf("%#v\n", b) // []int{}
	fmt.Printf("%#v\n", c) // []int{}

	d := make([]int, 1, 3)
	fmt.Println(len(d)) // 1
	fmt.Println(cap(d)) //3
	// fmt.Println(d[1])   // panic: runtime error: index out of range [1] with length 1

}

func main() {
	test1()
	test2()
	test3()
	test4()
	test5()
	test6()
}
