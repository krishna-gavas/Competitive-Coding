#include <iostream>
#include <algorithm>
using namespace std;

int Partition(int A[], int L, int R){
    int pivot = A[L];
    int i = R+1;

    for(int j=R; j>L; j--){
        if(A[j] > pivot){
            i--;
            swap(A[i], A[j]);
        }
    }
    swap(A[i-1], A[L]);
    return i-1;
}

void QuickSort(int A[], int L, int R){
    if(L < R){
        int Q = Partition(A,L,R);
        QuickSort(A,L,Q-1);
        QuickSort(A,Q+1,R);
    }
}

int main() {
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];

    QuickSort(arr,0,N-1);

    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}