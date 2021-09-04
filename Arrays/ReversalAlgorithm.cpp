// Reversal Algorithm

#include <bits/stdc++.h>
using namespace std;
int reverse(int start, int end, int arr[]) {
    while (start <= end) {
        swap(arr[start++], arr[end--]);
    }
}

int printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int d = 6, n = 8;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8};
    printArr(arr, n);
    
    d = d % n;
    
    reverse(0, d - 1, arr);
    printArr(arr, n);
    
    reverse(d, n - 1, arr);
    printArr(arr, n);

    reverse(0, n - 1, arr);
    printArr(arr, n);
    return 0;
}
