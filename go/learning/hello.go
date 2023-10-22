package main

import (
	"fmt"
	"math/rand"
)


func f() int {

  return 0
  
}


func main() {

	name := "Rohit"

	var n int

	fmt.Scan(&n)

  r := rand.Intn(n)

	fmt.Printf("Hello Go %v %v, %v", name, n, r)

}
