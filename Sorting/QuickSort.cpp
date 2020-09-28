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

void QuickSort(int a[], int p, int r) {
	if(p<r) {
		int q = PARTITION(a, p, r);
		QuickSort(a, p, q-1);
		QuickSort(a, q+1, r);
	}
}

int PARTITION(int a[], int p, int r) {
	int pivot = a[r];
	int i=p-1;
	for(int j=p; j<=r-1; j++) {
		if(a[j]<=pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[r]);
	return i+1;
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
