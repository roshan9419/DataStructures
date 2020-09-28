//O(nlogn) (BC, AC, WC)
#include<bits/stdc++.h>
using namespace std;
void print(int a[], int n);
void merge(int a[], int L[], int R[], int nl, int nr);
void mergeSort(int a[], int n);

void merge(int a[], int L[], int R[], int nl, int nr) {
	int i,j,k;
	i=j=k=0;
	while(i<nl && j<nr) {
		if(L[i]<=R[j]) {
			a[k++] = L[i++];
		}
		else {
			a[k++] = R[j++];
		}
	}
	while(i<nl) a[k++] = L[i++];
	while(j<nr) a[k++] = R[j++];
}
void mergeSort(int a[], int n) {
	if(n==1) return;
	int mid = n/2;
	int L[mid], R[n-mid];
	
	for(int i=0; i<=mid; i++) L[i]=a[i];
	for(int i=mid; i<n; i++) R[i-mid]=a[i];
	mergeSort(L, mid);
	mergeSort(R, n-mid);
	merge(a, L, R, mid, n-mid);
}

int main() {
	int a[10] = {12,42,32,4,2,55,32,56,2,23};
	print(a,10);
	mergeSort(a,10);
	print(a,10);
}

void print(int a[], int n) {
	for(int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
