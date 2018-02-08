# Stack

The stack implements LIFO policy.

```
class Stack
	top = 0
	container = newArray(MAXN)

	isEmpty()
		return top == 0

	push(data)
		top++
		if top > MAXN
			throw "overflow"
		else
			container[top] = data

	pop()
		if isEmpty()
			throw "underflow"
		else
			return container[top--]
```
