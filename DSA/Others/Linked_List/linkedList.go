package main

import (
	"errors"
	"fmt"
)

// Node represents a node of linked list
type Node struct {
	value int
	next  *Node
}

// LinkedList represents a linked list
type LinkedList struct {
	head *Node
	tail *Node
	len  int
}

// Insert inserts new node at the end of linked list
func (l *LinkedList) Insert(val int) {
	n := Node{}
	n.value = val
	if l.len == 0 {
		l.head = &n
		l.len++
		return
	}
	ptr := l.head
	for i := 0; i < l.len; i++ {
		if ptr.next == nil {
			ptr.next = &n
			l.len++
			return
		}
		ptr = ptr.next
	}
}

// InsertAfter inserts new node at given position
// For example if List=1->2->3->4 and we want to insert after 3rd position then InsertAfter(3,value) will give  List=1->2->3->value->4
func (l *LinkedList) InsertAfter(pos int, value int) {
	// create a new node
	newNode := Node{}
	newNode.value = value
	// validate the position
	if pos < 0 {
		return
	}
	if pos == 0 {
		l.head = &newNode
		l.len++
		return
	}
	if pos > l.len {
		return
	}
	n := l.GetAt(pos)
	newNode.next = n
	prevNode := l.GetAt(pos - 1)
	prevNode.next = &newNode
	l.len++
}

// Print displays all the nodes from linked list
func (l *LinkedList) Print() {
	if l.len == 0 {
		fmt.Println("No nodes in list")
	}
	ptr := l.head
	for i := 0; i < l.len; i++ {
		if i < l.len-1 {
			fmt.Print(ptr.value, " -> ")
		} else {
			fmt.Print(ptr.value)
		}
		ptr = ptr.next
	}
	fmt.Println("")
}

// Search returns node position with given value from linked list
// Index starts at 0
func (l *LinkedList) Search(val int) int {
	ptr := l.head
	for i := 0; i < l.len; i++ {
		if ptr.value == val {
			return i
		}
		ptr = ptr.next
	}
	return -1
}

// GetAt returns node at given position from linked list
func (l *LinkedList) GetAt(pos int) *Node {
	ptr := l.head
	if pos < 0 {
		return ptr
	}
	if pos > (l.len - 1) {
		return nil
	}
	for i := 0; i < pos; i++ {
		ptr = ptr.next
	}
	return ptr
}

// DeleteAt deletes node at given position from linked list
func (l *LinkedList) DeleteAt(pos int) error {
	// validate the position
	if pos < 0 {
		fmt.Println("position can not be negative")
		return errors.New("position can not be negative")
	}
	if l.len == 0 {
		fmt.Println("No nodes in list")
		return errors.New("No nodes in list")
	}
	prevNode := l.GetAt(pos - 1)
	if prevNode == nil {
		fmt.Println("Node not found")
		return errors.New("Node not found")
	}
	prevNode.next = l.GetAt(pos).next
	l.len = l.len - 1
	return nil
}

func main() {
	// **Index starts at 0 **
	head := LinkedList{}
	head.Insert(1)
	head.Insert(2)
	head.Insert(3)
	head.Insert(4)
	head.Print() // 1 -> 2 -> 3 -> 4
	head.InsertAfter(3, 100)
	head.Print()                // 1 -> 2 -> 3 -> 100 -> 4
	fmt.Println(head.Search(2)) // 1
	head.DeleteAt(2)
	head.Print()               // 1 -> 2 -> 100 -> 4
	fmt.Println(head.GetAt(2)) // &{100 0xc000010230}
}
