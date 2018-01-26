# Insertion Sort

```
insertionSort(A, compare)
	for j = 1 until A.length
		key = A[j]
		i = j - 1
		while i >= 0 and compare(A[i], key) > 0
			A[i + 1] = A[i]
			i = i - 1
		A[i + 1] = key
```
