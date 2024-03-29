// go mod tidy
// go build ./main.go

package main

import "fmt"

// array has value semantics. Assignment is done by value copy
// array cannot be resized
func test1() {
	var a [2]int        // zero intiialized
	fmt.Println(a)      // [0 0]
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
	fmt.Println("---")
	// func make([]T, len, cap) []T
	a := make([]int, 0, 10)
	b := a

	c := []int{0, 1, 2, 3}
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

func main() {
	test1()
	test2()
}
