/*
QuickSort(A, p, r) {
	if p<r {
		q = PARTITION(A, p, r)
		QuickSort(A, p, q-1)
		QuickSort(A, q+1, r)
	}
}
PARTITION(A, p, r) {
	x = A[r]
	i = p-1
	for j=p to r-1 {
		if A[j]<=x {
			i = i+1
			swap(A[i], A[j])
		}
	}
	swap(A[i+1], A[r])
	return i+1
}

Time Complexity:
BC - O(nlogn)
AC - O(nlogn)
WC - O(n^2) //if array is already sorted

PIVOT NODE::
the element through which we are sorting, like we can take the last or first node, and elements to its left are smaller and elements after it must be greater


*/
