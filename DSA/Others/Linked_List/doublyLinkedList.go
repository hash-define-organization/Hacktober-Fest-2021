package main

import (
	"errors"
	"fmt"
)

// Node represents a node of linked list
type Node struct {
	data interface{}
	prev *Node
	next *Node
}

// LinkedList represents a linked list
type LinkedList struct {
	head *Node
	tail *Node
	len  int
}

// GetHead return head of linked list
func (l *LinkedList) GetHead() *Node {
	return l.head
}

// GetTail return tail of linked list
func (l *LinkedList) GetTail() *Node {
	return l.tail
}

// Insert inserts new node at the end of linked list
func (l *LinkedList) Insert(val interface{}) {
	n := Node{}
	n.data = val
	if l.len == 0 {
		l.head = &n
		l.tail = &n
		l.len++
		return
	}
	l.tail.next = &n
	n.prev = l.tail
	l.tail = &n
	l.len++
}

// InsertAtStart inserts new node at the beggining of linked list
func (l *LinkedList) InsertAtStart(val interface{}) {
	n := Node{}
	n.data = val
	if l.len == 0 {
		l.head = &n
		l.tail = &n
		l.len++
		return
	}
	n.next = l.head
	n.prev = nil
	l.head.prev = &n
	l.head = &n
	l.len++
}

// InsertAt inserts new node at given position
func (l *LinkedList) InsertAt(pos int, value interface{}) {
	// create a new node
	newNode := Node{}
	newNode.data = value
	// validate the position
	if pos < 0 {
		fmt.Println("Position can not be negative, skipping insertion of: ", value)
		return
	}
	if pos == 0 && l.len == 0 {
		l.head = &newNode
		l.tail = &newNode
		l.len++
		return
	}
	if pos > l.len {
		fmt.Println("Position can not be greater than list size")
		return
	}
	n := l.GetAt(pos)
	if n != nil {
		n.prev = &newNode
	}
	newNode.next = n
	prevNode := l.GetAt(pos - 1)
	if prevNode != nil {
		prevNode.next = &newNode
	}
	newNode.prev = prevNode
	// change tail with newly added node only if no node present at given position
	if n == nil {
		l.tail = &newNode
	} else if pos == 0 {
		// change head with newly added node only if adding node at 0th position
		l.head = &newNode
	}
	l.len++
}

// Search returns node position with given value from linked list, -1 if node not found
func (l *LinkedList) Search(val interface{}) int {
	ptr := l.head
	for i := 0; i < l.len; i++ {
		if ptr.data == val {
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
		fmt.Println("Position: ", pos, " can not be negative, hence returning")
		return nil
	}
	if pos > (l.len - 1) {
		// fmt.Println("Position: ", pos, " can not be greater than list size, hence returning")
		return nil
	}
	for i := 0; i < pos; i++ {
		ptr = ptr.next
	}
	return ptr
}

// Print displays all the nodes from linked list using HEAD in forward direction
func (l *LinkedList) Print() {
	if l.len == 0 {
		fmt.Println("No nodes in list")
	}
	ptr := l.head
	for i := 0; i < l.len; i++ {
		if i < l.len-1 {
			fmt.Print(ptr.data, " -> ")
		} else {
			fmt.Print(ptr.data)
		}
		ptr = ptr.next
	}
	fmt.Println("")
}

// Reverse displays all the nodes from linked list using TAIL in backward direction
func (l *LinkedList) Reverse() {
	if l.len == 0 {
		fmt.Println("No nodes in list")
	}
	ptr := l.tail
	for i := 0; i < l.len; i++ {
		if i < l.len-1 {
			fmt.Print(ptr.data, " -> ")
		} else {
			fmt.Print(ptr.data)
		}
		ptr = ptr.prev
	}
	fmt.Println("")
}

// DeleteAt deletes node at given position from linked list
func (l *LinkedList) DeleteAt(pos int) error {
	// validate the position
	if pos < 0 {
		fmt.Println("position can not be negative")
		return errors.New("position can not be negative")
	} else if l.len == 0 {
		fmt.Println("No nodes in list")
		return errors.New("No nodes in list")
	} else if pos > (l.len - 1) {
		fmt.Println("Position: ", pos, " can not be greater than list size, hence returning")
		return errors.New("Position can not be greater than list size, hence returning")
	}
	// if position is first call DeleteAtFirst()
	if pos == 0 {
		return l.DeleteAtFirst()
	}

	// if position is last call DeleteAtEnd()
	if pos == (l.len - 1) {
		return l.DeleteAtEnd()
	}
	// get node from given position
	node := l.GetAt(pos)
	node.next.prev = node.prev
	node.prev.next = node.next
	l.len--
	return nil
}

// DeleteAtEnd deletes node at the end/tail position from linked list
func (l *LinkedList) DeleteAtEnd() error {
	// validate the position
	if l.len == 0 {
		fmt.Println("No nodes in list")
		return errors.New("No nodes in list")
	} else if l.len == 1 {
		l.head = nil
		l.tail = nil
		l.len--
		return nil
	}
	l.tail = l.tail.prev
	l.tail.next = nil
	l.len--
	return nil
}

// DeleteAtFirst deletes node at the first/head position from linked list
func (l *LinkedList) DeleteAtFirst() error {
	// validate the position
	if l.len == 0 {
		fmt.Println("No nodes in list")
		return errors.New("No nodes in list")
	} else if l.len == 1 {
		l.head = nil
		l.tail = nil
		l.len--
		return nil
	}
	l.head = l.head.next
	l.head.prev = nil
	l.len--
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
	head.InsertAt(3, 100)
	head.Print() // 1 -> 2 -> 3 -> 100 -> 4
	head.InsertAtStart(31)
	head.Print()                // 31 -> 1 -> 2 -> 3 -> 100 -> 4
	fmt.Println(head.Search(2)) // 2
	head.DeleteAt(2)
	head.Print()               // 31 -> 1 -> 3 -> 100 -> 4
	fmt.Println(head.GetAt(2)) // &{3 0xc00000c060 0xc00000c0e0}
}
