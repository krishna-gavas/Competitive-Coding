// Heap Sort



#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int arr[], int n, int i)  {
    // // Your Code Here
    int k=i,v=arr[k];
    bool heap = false;
    while(!heap && (2*(k+1) <= n)){
        int j = 2*(k+1);
        if(j < n)
            if(arr[j-1] <= arr[j])
                j = j + 1;
        if( v >= arr[j-1])
            heap = true;
        else
        {
            arr[k] = arr[j-1];
            k = j-1;
            arr[k] = v;
        }       
    }
    // int l = 2*i + 1;
    // int r = 2*i + 2;
    // int smallest = i;
    // if (l < n && arr[l] < arr[i]) smallest = l;
    // if (r < n && arr[r] < arr[smallest]) smallest = r;
    // if (smallest != i) {
    //     swap(arr[i], arr[smallest]);
    //     heapify(arr,smallest,n);
    // }
}

void buildHeap(int arr[], int n)  { 
    // Your Code Here
    for(int i=((n/2)-1);i>=0;i--)
        heapify(arr,n+1,i);
    
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