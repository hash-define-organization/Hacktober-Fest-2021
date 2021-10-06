package main

import "fmt"

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

func main() {
	root := Node{1, nil, nil}
	root.left = &Node{2, nil, nil}
	root.right = &Node{3, nil, nil}
	root.left.left = &Node{4, nil, nil}
	root.left.right = &Node{5, nil, nil}
	root.right.left = &Node{6, nil, nil}
	root.right.right = &Node{7, nil, nil}
	fmt.Printf("Pre Order Traversal of the given tree is: ")
	root.preOrderTraversal()
	fmt.Println("")
	fmt.Printf("In Order Traversal of the given tree is: ")
	root.inOrderTraversal()
	fmt.Println("")
	fmt.Printf("Post Order Traversal of the given tree is: ")
	root.postOrderTraversal()
	fmt.Println("")

}
