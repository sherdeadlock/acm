# Queue

```
class Queue
	container = [MAXN]
	head = 0
	tail = 0
	size = 0

	enqueue(data)
		if size == MAXN
			throw "overflow"
		container[tail++] = data
		size++
		if tail == MAXN
			tail = 0

	dequeue()
		if size == 0
			throw "underfow"
		ret = container[head++]
		size--
		if head == MAXN
			head = 0
```
