package main

import "fmt"

type Stack []string

func (s *Stack) isEmpty() bool {
	return len(*s) == 0
}

// push a new value onto the stack
func (s *Stack) push(str string) {
	*s = append(*s, str)
}

// Remove and return top element of stack.
func (s *Stack) pop() (string, bool) {
	if s.isEmpty() { // Return false if stack is empty.
		return "Stack is empty", false
	} else {
		index := len(*s) - 1   // Get the index of the top most element.
		element := (*s)[index] // Index into the slice and obtain the element.
		*s = (*s)[:index]      // Remove it from the stack by slicing it off.
		return element, true
	}
}

func main() {
	var stack Stack

	stack.push("1")
	stack.push("2")
	stack.push("3")

	value, _ := stack.pop() // we can also use the second value returned by function pop to determine if the stack empty or not.
	fmt.Println(value)
	value, _ = stack.pop()
	fmt.Println(value)
	value, _ = stack.pop()
	fmt.Println(value)
	value, _ = stack.pop()
	fmt.Println(value)
}
