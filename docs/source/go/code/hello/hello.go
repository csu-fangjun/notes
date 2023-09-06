package main

import "fmt"
import "time"

func swap(a, b *int) {
	*a, *b = *b, *a
}

func main() {
	message := "hello world"
	fmt.Println(message)
	s := fmt.Sprintf("spintf: %s\n", message)
	fmt.Print(s)

	fmt.Printf("type of message: %T\n", message)

	now := time.Now()
	fmt.Printf("type of now: %T\n", now)
	for i := 0; i < 2; i++ {
		fmt.Println(i)
	}
	// fmt.Println(i) // undefined: i

	arr := []string{"hello", "world"}
	for i, v := range arr {
		fmt.Println(i, v) // 0 hello
		// 1 world
	}
	a := 1
	b := 2
	swap(&a, &b)
	fmt.Println(a, b)

}
