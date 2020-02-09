#include <iostream>
#include <algorithm>
using namespace std;

void HeapAdjust(int A[],int i,int n){
    int k=i,v=A[k];
    bool heap = false;
    while(!heap && (2*k <= n)){
        int j = 2*k;
        if(j < n)
            if(A[j] < A[j+1])
                j = j + 1;
        if( v >= A[j])
            heap = true;
        else
        {
            A[k] = A[j];
            k = j;
            A[k] = v;
        }
        
    }
}

void HeapBottomUp(int A[],int n){
    for(int i=(n/2);i>=1;i--)
        HeapAdjust(A,i,n);      //built Heap starting with rightmost leaf
}

void HeapSort(int A[],int n){
    HeapBottomUp(A,n);          // function to create Heap
    for(int i=n;i>1;i--){
        swap(A[1],A[i]);
        HeapAdjust(A,1,i-1);    // function to rebuild the heap
    }
}

int main() {
    int N;
	cin>>N;
    int arr[N];
	for(int i=1;i<=N;i++)
        cin>>arr[i];

	HeapSort(arr,N);

    for(int i=1;i<=N;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
	return 0;
}