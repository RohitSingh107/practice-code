package main

import (
	"fmt"
	"math/rand"
)

func playGame(numberToGuess int, n int) int {

	total := 0

	l := 0
	r := n

	for true {
		fmt.Printf("Guess the number between %v and %v: ", l, r)

		var x int
		fmt.Scan(&x)

    if x == -1 {
      fmt.Println("Quitting...")
      return -1
    }

		if x < numberToGuess {
			println("Incorrect. It is smaller.")
      l = x
		} else if x > numberToGuess {
			println("Incorrect. It is greater.")
      r = x
		} else {
			println("Correct!")
      return total
		}
    total++
	}

	return total
}

func main() {

	fmt.Print("Please enter your name and max numberToGuess: ")

	var name string
	var n int

	fmt.Scan(&name, &n)

	fmt.Printf("Welcome %v to Guessing game.\n", name)

	numberToGuess := rand.Intn(n)

	totalTrials := playGame(numberToGuess, n)
  fmt.Printf("You guess the number in %v guesses\n", totalTrials)

}
