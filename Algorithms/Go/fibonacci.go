package main

import "fmt"

func fibonacci() func() int {
	one := 0
	two := 1
	sum := 0

	return func() int {
		sum, one, two = one, two, one+two
		return sum
	}
}

func main() {
	f := fibonacci()

	// to get more numbers, change "10" for the expected number of values
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
