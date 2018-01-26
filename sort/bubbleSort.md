# Bubble Sort


```
bubbleSort(A, compare)
	for i = 0 until A.length
		for j = A.length - 1 downto i + 1
			if compare(A[j], A[j - 1]) > 0
				swap(A[j], A[j - 1])
```
