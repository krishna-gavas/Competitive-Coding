#include <iostream>
#include <algorithm>
using namespace std;

void SelectionSort(int A[], int n){
    int min_id;

    for(int i=0;i<n-1; i++){
        min_id = i;
        for(int j=i+1; j<n;j++){
            if(A[j] < A[min_id])
                min_id = j;
        }
        swap(A[i], A[min_id]);
    }
}

int main() {
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];

    SelectionSort(arr,N);

    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}