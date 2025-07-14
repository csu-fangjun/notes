package main

import (
	"fmt"
)

// iterate a slice
func test1() {
	fmt.Println("---test1---")
	a := []int{1, 2}
	for i := 0; i < len(a); i++ {
		fmt.Println(a[i])
	}
	// 1
	// 2

	// fmt.Println(i) // undefined: i
}

// iterate a slice
func test2() {
	fmt.Println("---test2---")
	a := []int{1, 2}

	// i is the index
	// v is the value
	// similar to enumerate() in Python
	for i, v := range a {
		fmt.Println(i, v)
	}
	// 0 1
	// 1 2
	// fmt.Println(i) // undefined: i
	// fmt.Println(v) // undefined: v
}

func test3() {
	fmt.Println("---test3---")
	a := []int{1, 2}

	// i is the index
	for i := range a {
		fmt.Println(i, a[i])
	}
	// 0 1
	// 1 2
}

func test4() {
	fmt.Println("---test4---")
	a := []int{1, 2}

	// i is the index
	for _, v := range a {
		fmt.Println(v)
	}
	// 1
	// 2
	// fmt.Println(i) // undefined: i
}

func test5() {
	fmt.Println("---test5---")
	a := []int{1, 2}

	i := 0
	for i < len(a) {
		fmt.Println(i, a[i])
		i += 1
	}
	// 0 1
	// 1 2
}

func test6() {
	fmt.Println("---test6---")
	a := []int{1, 2}

	i := 0
	for ; i < len(a); i += 1 {
		fmt.Println(i, a[i])
	}
	// 0 1
	// 1 2
	fmt.Println(i) // 2
}

func test7() {
	fmt.Println("---test7---")
	a := []int{1, 2}

	i := 0

	// like a while loop
	for {
		if i >= len(a) {
			break
		}
		fmt.Println(i, a[i])
		i += 1
	}
	// 0 1
	// 1 2
	fmt.Println(i) // 2
}

func test8() {
	// for go >= 1.22
	fmt.Println("---test8---")
	for i := range 3 {
		fmt.Println(i)
	}
	// 0
	// 1
	// 2
}

func main() {
	test1()
	test2()
	test3()
	test4()
	test5()
	test6()
	test7()
	test8()
}
