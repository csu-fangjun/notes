package main

import "fmt"

func test1() {
	fmt.Println("---test1---")
	a := 1

	switch {
	case a == 1:
		fmt.Println("a is 1")
	case a == 2:
		fmt.Println("a is 2")
	default:
		fmt.Println("a is default")
	}
	// a is 1

	a = 11
	switch {
	case a == 11:
		fmt.Println("a is 11")
		fallthrough
	case a == 22:
		fmt.Println("a is 22")
	default:
		fmt.Println("a is default")
	}
	// a is 11
	// a is 12
}

func test2() {
	fmt.Println("---test2---")
	a := 10
	switch a {
	case 10:
		fmt.Println("a is 10")
	case 11:
		fmt.Println("a is 11")
	}

	// a is 10

	// no need to use default, like c/c++
	// no need to use break
}

func main() {
	test1()
	test2()
}
