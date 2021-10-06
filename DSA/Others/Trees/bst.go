package main

import (
	"errors"
	"fmt"
)

type Node struct {
	data  int
	left  *Node
	right *Node
}

func (root *Node) preOrderTraversal() {
	if root != nil {
		fmt.Printf("%d ", root.data)
		root.left.preOrderTraversal()
		root.right.preOrderTraversal()
	}
	return
}

func (root *Node) inOrderTraversal() {
	if root != nil {
		root.left.inOrderTraversal()
		fmt.Printf("%d ", root.data)
		root.right.inOrderTraversal()
	}
	return
}

func (root *Node) postOrderTraversal() {
	if root != nil {
		root.left.postOrderTraversal()
		root.right.postOrderTraversal()
		fmt.Printf("%d ", root.data)
	}
	return
}

func (root *Node) Insert(data int) error {
	if root == nil {
		return errors.New("Tree Does not exist")
	}
	if root.data == data {
		return errors.New("This node data already exists")
	}
	if root.data > data {
		if root.left == nil {
			root.left = &Node{data: data}
			return nil
		}
		return root.left.Insert(data)
	}
	if root.data < data {
		if root.right == nil {
			root.right = &Node{data: data}
			return nil
		}
		return root.right.Insert(data)
	}
	return nil
}

// GetNode finds the Node for the given node data
func (root *Node) GetNode(data int) (Node, bool) {
	if root == nil {
		return Node{}, false
	}
	switch {
	case data == root.data:
		return *root, true
	case data < root.data:
		return root.left.GetNode(data)
	default:
		return root.right.GetNode(data)
	}
}

// Delete removes the Item with data from the tree
func (root *Node) Delete(data int) {
	root.remove(data)
}

func (root *Node) remove(data int) *Node {
	if root == nil {
		return nil
	}
	if data < root.data {
		root.left = root.left.remove(data)
		return root
	}
	if data > root.data {
		root.right = root.right.remove(data)
		return root
	}
	if root.left == nil && root.right == nil {
		root = nil
		return nil
	}
	if root.left == nil {
		root = root.right
		return root
	}
	if root.right == nil {
		root = root.left
		return root
	}

	smallestdataOnRight := root.right
	for {
		//find smallest data on the right side
		if smallestdataOnRight != nil && smallestdataOnRight.left != nil {
			smallestdataOnRight = smallestdataOnRight.left
		} else {
			break
		}
	}
	root.data = smallestdataOnRight.data
	root.right = root.right.remove(root.data)
	return root
}

func main() {

	root := &Node{data: 50}

	root.Insert(100)
	root.Insert(10)
	root.Insert(5)
	root.Insert(11)
	root.Insert(1000)
	root.Insert(5)
	root.Insert(1)

	value, found := root.GetNode(11)
	if found {
		fmt.Println(value.data)
	} else {
		fmt.Println("Not able to find the Node")
	}

	value, found = root.GetNode(101)
	if found {
		fmt.Println(value.data)
	} else {
		fmt.Println("Not able to find the Node")
	}

	root.Delete(11)
	root.preOrderTraversal()
	fmt.Println("")
	root.inOrderTraversal()
	fmt.Println("")
	root.postOrderTraversal()
	fmt.Println("")

}
