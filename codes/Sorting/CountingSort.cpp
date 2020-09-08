#include <iostream>
#include <algorithm>
using namespace std;

void CountingSort(int A[], int n, int range){
    int count[range+1],B[n];
    memset(count,0,sizeof(count));

    for(int i=0;i<n;i++)
        count[A[i]]++;
    for(int i=1;i<range+1;i++)
        count[i] = count[i] + count[i-1];    

    for(int i=0;i<n;i++){
        count[A[i]]--;
        B[count[A[i]]] = A[i];
    }
    for(int i=0;i<n;i++)
        A[i] = B[i];
}

int main() {
    int N,max=0;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    CountingSort(arr,N,max);

    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}