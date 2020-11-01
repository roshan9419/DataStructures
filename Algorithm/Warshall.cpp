#include<bits/stdc++.h>
using namespace std;

int main() {

        cout << "Number of Nodes: ";
        int n;
        cin>>n;

        int **A = new int*[n];
        for(int i=0; i<n; i++)
                A[i] = new int[n];

        for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                        cin>>A[i][j];

        for(int k=0; k<n; k++) {
                for(int i=0; i<n; i++) {
                        for(int j=0; j<n; j++) {
                                A[i][j] = min(A[i][j], A[i][k]+A[k][j]);
                        }
                }
        }

        for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                        cout<<A[i][j]<<" ";
                }
                cout<<endl;
        }


        return 0;
}
