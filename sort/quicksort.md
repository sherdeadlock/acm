# Quick Sort

partition(A, p, r)
	i = p - 1
	for j = p to r - 1
		if A[j] <= A[r]
			i = i + 1
			swap(A[i], A[j])
	swap(A[i + 1], A[r])
	return i


quicksort(A, p, r)
	if p < r
		q = partition(A, p, r)
		quicksort(A, p, q - 1)
		quicksort(A, q + 1, r)

quicksort(A)
	quicksort(A, 0, A.length - 1)
