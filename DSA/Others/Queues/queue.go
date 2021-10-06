package main

import "fmt"

type Queue []string

func (s *Queue) isEmpty() bool {
	return len(*s) == 0
}

// push a new value onto the queue
func (s *Queue) push(str string) {
	*s = append(*s, str)
}

// Remove and return top element of queue.
func (s *Queue) pop() (string, bool) {
	if s.isEmpty() { // Return false if queue is empty.
		return "Queue is empty", false
	} else {
		element := (*s)[0] // Index into the slice and obtain the element.
		*s = (*s)[1:]      // Remove it from the queue by slicing it off.
		return element, true
	}
}

func main() {
	var queue Queue

	queue.push("1")
	queue.push("2")
	queue.push("3")

	value, _ := queue.pop() // we can also use the second value returned by function pop to determine if the queue empty or not.
	fmt.Println(value)
	value, _ = queue.pop()
	fmt.Println(value)
	value, _ = queue.pop()
	fmt.Println(value)
	value, _ = queue.pop()
	fmt.Println(value)
}
