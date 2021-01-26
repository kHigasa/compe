package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)
	if s[0] == s[1] && s[0] == s[2] {
		fmt.Println("Won")
	} else {
		fmt.Println("Lost")
	}
}
