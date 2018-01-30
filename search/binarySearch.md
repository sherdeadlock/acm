# Iterative

```
binarySearch(A, x)
	low = 0
	high = A.length - 1
	
	while low <= high
		mid = (low + height) / 2
		if x > A[mid]
			low = mid + 1
		else if x < A[mid]
			high = mid - 1
		else
			return mid
	return -1
```

# Recursion

```
binarySearch(A, x, low, high)
	if low > high
		return -1
	
	mid = (low + high) / 2
	if x > A[mid]
		return binarySearch(A, x, mid + 1, high)
	else if x < A[mid]
		return binarySearch(A, x, low, mid - 1)
	else
		return mid
```
