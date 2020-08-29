#include <iostream>
#include <algorithm>
using namespace std;

void Merge(int A[],int L,int mid, int R){
    int B[R+1];
    int i=L,j=mid+1,k=L;
    while(i<=mid && j<=R){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else 
            B[k++] = A[j++];
    }
    while(i<= mid)
        B[k++] = A[i++];
    while(j<= R)
        B[k++] = A[j++];

    for(int j=L;j<=R;j++)
        A[j] = B[j];
}

void MergeSort(int A[], int L, int R){
    if(L < R){
        int mid = (L+R)/2;
        MergeSort(A,L,mid);
        MergeSort(A,mid+1,R);
        Merge(A,L,mid,R);
    }
}

int main() {
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];

    MergeSort(arr, 0, N-1);

    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}