/*
Time Complexity:
BC - O(nlogn)
AC - O(nlogn)
WC - O(n^2) //if array is already sorted

O(1) - Space Complexity, In place algorithm

PIVOT NODE::
the element through which we are sorting, like we can take the last or first node, and elements to its left are smaller and elements after it must be greater

QuickSort(A, p, r) {
	if p<r {
		q = PARTITION(A, p, r)
		QuickSort(A, p, q-1)
		QuickSort(A, q+1, r)
	}
}
PARTITION(A, p, r) {
	x = A[r] //pivot
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
*/

#include<bits/stdc++.h>
using namespace std;

void print(int a[], int n);
void QuickSort(int a[], int p, int r);
int PARTITION(int a[], int p, int r);

void QuickSort(int a[], int start, int end) {
	if(start<end) {
		int pIndex = PARTITION(a, start, end);
		QuickSort(a, start, pIndex-1);
		QuickSort(a, pIndex+1, end);
	}
}

int PARTITION(int a[], int start, int end) {
	int pivot = a[end];
	int pIndex = start;
	for(int i=start; i<end; i++) {
		if(a[i]<=pivot) {
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	swap(a[pIndex], a[end]);
	return pIndex;
}

int main() {
	int a[10] = {2, 10, 9, 3, 5, 8, 6, 7, 1, 4};
	print(a, 10);
	QuickSort(a, 0, 9);
	print(a, 10);
	return 0;
}

void print(int a[], int n) {
	for(int i=0; i<n; i++) cout << a[i] << " ";
	cout << endl;
}
