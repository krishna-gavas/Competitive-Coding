// Heap Sort

// heapSort(arr, n): call buildHeap(arr, n) and then 
//     for( i=last index to first index): swap(arr[0],arr[i]) and call heapify(arr, i, 0).

// buildHeap(arr, n): for(i=last parent node to first parent node) call heapify(arr,n,i).

// heapify(arr,n,i): initialize l = left child, r = right child and largest = i;
//     if(l < n and arr[l] > arr[i]) then largest = l.
//     if (r < n && arr[r] > arr[largest]) then largest = r.
//     if(largest != i) then swap(arr[i], arr[largest]) and call heapify(arr, n, largest).

#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int arr[], int n, int i)  {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if (l < n && arr[l] > arr[i]) 
        largest = l;
    if (r < n && arr[r] > arr[largest]) 
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)  { 
    for(int i=((n/2)-1);i>=0;i--)
       heapify(arr,n,i);
}

void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main() {
	int arr[1000000],n,T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        heapSort(arr, n);
        printArray(arr, n);
    }
}

