#include <iostream>
#include <algorithm>
using namespace std;

void BubbleSort(int A[], int n){
    for(int i=0;i<n-1; i++){
        for(int j=0; j<n-i-1;j++){
            if(A[j] > A[j+1])
                swap(A[j], A[j+1]);
        }
    }
}

int main() {
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];

    BubbleSort(arr,N);

    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}