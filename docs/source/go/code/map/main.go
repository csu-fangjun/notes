package main

import "fmt"
import "sort"

func test1() {
	fmt.Println("---test1---")
	var a map[string]string

	// a zero initialized map equals to nil
	fmt.Println(a == nil)  // true
	fmt.Println(len(a))    // 0
	fmt.Printf("%#v\n", a) // map[string]string(nil)

	b := map[string]string{}
	fmt.Println(b == nil)  // false
	fmt.Println(len(b))    // 0
	fmt.Printf("%#v\n", b) // map[string]string{}

	// If the map does not contain the key it returns a zero initialized value.
	// Since the value type is string, the zero value is an empty string ""
	c := a["foo"]
	fmt.Printf("%q\n", c) // ""

	// If the left side has two values, the second element is false if the key
	// does not exist
	_, ok := a["foo"]
	fmt.Printf("%v %T\n", ok, ok) // false, bool

	if g, ok := a["bar"]; ok {
		fmt.Println("bar exists", g)
	} else {
		fmt.Println("bar does not exist") // bar does not exist
	}

	// a["bar"] = "zoo" // panic: assignment to entry in nil map

	// insert a new entry into the map
	b["bar"] = "zoo"

	if g, ok := b["bar"]; ok {
		fmt.Println("bar exists", g) // bar exists zoo
	} else {
		fmt.Println("bar does not exist")
	}
}

func test2() {
	fmt.Println("---test2---")
	a := map[string]string{
		"hello": "world",
		"foo":   "bar",
	}

	for key, value := range a {
		fmt.Printf("%s %q\n", key, value)
	}
	// Note: the output is not deterministic.
	//
	// hello "world"
	// foo "bar"

	b := make([]string, 0, len(a))
	for key := range a {
		b = append(b, key)
	}

	sort.Strings(b)
	for _, key := range b {
		fmt.Printf("%s %q\n", key, a[key])
	}
	// foo "bar"
	// hello "world"
}

func main() {
	test1()
	test2()
}
