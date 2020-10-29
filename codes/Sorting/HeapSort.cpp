#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int A[], int n, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int large = i;
    if(l < n && A[l] > A[i])
        large = l;
    if(r < n && A[r] > A[large])
        large = r;
    if(large != i){
        swap(A[i], A[large]);
        heapify(A, n, large);
    }
}

void buildHeap(int A[], int n){
    for(int i=(n/2)-1;i>=0;i--)
        heapify(A, n, i);
}


void heapSort(int A[], int n){
    buildHeap(A, n);
    for(int i=n-1;i>=0;i--){
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    heapSort(A, n);

    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<"\n";
	return 0;
}