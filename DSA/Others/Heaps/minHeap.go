package main

import "fmt"

type MinHeap struct {
	heapArray []int
	size      int
	maxsize   int
}

func newMinHeap(maxsize int) *MinHeap {
	MinHeap := &MinHeap{
		heapArray: []int{},
		size:      0,
		maxsize:   maxsize,
	}
	return MinHeap
}

func (m *MinHeap) leaf(index int) bool {
	if index >= (m.size/2) && index <= m.size {
		return true
	}
	return false
}

func (m *MinHeap) parent(index int) int {
	return (index - 1) / 2
}

func (m *MinHeap) leftChild(index int) int {
	return 2*index + 1
}

func (m *MinHeap) rightChild(index int) int {
	return 2*index + 2
}

func (m *MinHeap) insert(item int) error {
	if m.size >= m.maxsize {
		return fmt.Errorf("Heap is Full")
	}
	m.heapArray = append(m.heapArray, item)
	m.size++
	m.upHeapify(m.size - 1)
	return nil
}

func (m *MinHeap) swap(first, second int) {
	temp := m.heapArray[first]
	m.heapArray[first] = m.heapArray[second]
	m.heapArray[second] = temp
}

func (m *MinHeap) upHeapify(index int) {
	for m.heapArray[index] < m.heapArray[m.parent(index)] {
		m.swap(index, m.parent(index))
	}
}

func (m *MinHeap) downHeapify(current int) {
	if m.leaf(current) {
		return
	}
	smallest := current
	leftChildIndex := m.leftChild(current)
	rightRightIndex := m.rightChild(current)
	//If current is smallest then return
	if leftChildIndex < m.size && m.heapArray[leftChildIndex] < m.heapArray[smallest] {
		smallest = leftChildIndex
	}
	if rightRightIndex < m.size && m.heapArray[rightRightIndex] < m.heapArray[smallest] {
		smallest = rightRightIndex
	}
	if smallest != current {
		m.swap(current, smallest)
		m.downHeapify(smallest)
	}
	return
}
func (m *MinHeap) buildMinHeap() {
	for index := ((m.size / 2) - 1); index >= 0; index-- {
		m.downHeapify(index)
	}
}

func (m *MinHeap) remove() int {
	top := m.heapArray[0]
	m.heapArray[0] = m.heapArray[m.size-1]
	m.heapArray = m.heapArray[:(m.size)-1]
	m.size--
	m.downHeapify(0)
	return top
}

func main() {
	inputArray := []int{100, 50, 20, 70, 90, 1000, 10}
	MinHeap := newMinHeap(len(inputArray))
	for i := 0; i < len(inputArray); i++ {
		MinHeap.insert(inputArray[i])
	}
	MinHeap.buildMinHeap()
	for i := 0; i < len(inputArray); i++ {
		fmt.Println(MinHeap.remove())
	}
}
