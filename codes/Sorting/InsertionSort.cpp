#include <iostream>
#include <algorithm>
using namespace std;

void InsertionSort(int A[], int n){
    for(int i=1;i<n;i++){
        int key = A[i];
        int j = i-1;
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = key;
    }
}

int main() {
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];

    InsertionSort(arr, N);

    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}