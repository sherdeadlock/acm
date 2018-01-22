# LinkedList

```
class Node
	data
	next
	prev

	constructor(data)
		this.data = data

	append(node)
		// find tail
		tail = this
		while tail.next != NULL
			tail = tail.next
		// append node to the tail of list
		tail.next = node
		node.prev = tail

	insert(node)
		// find head
		head = this
		while head.prev != NULL
			head = head.prev
		// insert node into the head of list
		node.next = head
		head.prev = node

	delete(node)
		if node.prev != NULL
			node.prev.next = node.next
		if node.next != NULL
			node.next.prev = node.prev

	search(data)
		node = this
		while node != NULL and node.data == data
			node = node.next
		return node

class List
	sentinel // A sentinel is a dummy object that allows us to simplify boundary conditions.

	constructor()
		sentinel = Node(NULL)
		sentinel.next = sentinel
		sentinel.prev = sentinel

	insert(node)
		node.next = sentinel.next
		node.prev = sentinel
		sentinel.next.prev = node
		sentinel.next = node
```
