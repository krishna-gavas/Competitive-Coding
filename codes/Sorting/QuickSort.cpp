#include <iostream>
#include <algorithm>
using namespace std;

// Using last element as pivot
// int Partition(int A[], int l, int r){  
//     int pivot = A[r];   
//     int i = (l - 1);  
  
//     for (int j = l; j <= r - 1; j++){    
//         if (A[j] < pivot)  {  
//             i++;  
//             swap(A[i],A[j]);  
//         }  
//     }  
//     swap(A[i + 1], A[r]);  
//     return (i + 1);  
// }

// Using first element as pivot
int Partition(int A[],int l,int r){
    int pivot =A[l];   
    int i = (r + 1);  
  
    for (int j = r; j > l; j--){   
        if (A[j] > pivot){  
            i--; 
            swap(A[i], A[j]);  
        }  
    }  
    swap(A[i - 1], A[l]);  
    return (i - 1);
}

void QuickSort(int A[],int l,int r){
    int q;
    if(l < r){
        q = Partition(A,l,r);
        QuickSort(A,l,q-1);
        QuickSort(A,q+1,r);
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
    cout<<endl;
	return 0;
}