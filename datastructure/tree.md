# Binary Tree

```
class Node
	parent
	left
	right
	value

	search(x)
		if value == x
			return this

		if x < value
			return left.search(x)
		else
			return right.search(x)

	search_interative(x)
		node = this
		while node != null and node.value != x
			if x < node.value
				node = left
			else
				node = right
		return node
```
