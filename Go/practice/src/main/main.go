package main

import (
	"fmt"
	"hello"
)

func test3() {

}

func test2() {
	fmt.Println("test")
}

func test1() {
	fmt.Println("test1")
}

func main() {
	x := '7'
	fmt.Println(string(x))
	hello.Hello()
	test2()
	test1()
}
