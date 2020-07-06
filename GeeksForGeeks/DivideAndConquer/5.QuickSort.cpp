// Quick Sort

// partition(A, low, high): choose pivot as first element and initialize i = r+1.
//     for(j=r down to l): 
//         if (A[j] > pivot) then decrement i and swap A[i] with A[j].
//     finally swap A[i-1] with A[l](i.e swap last element smaller than pivot with pivot)
//     return (i-1) (i.e position of pivot)

#include <iostream>
using namespace std;

int partition(int A[], int l, int r)   //Using first element as pivot
{
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

void quickSort(int A[],int low, int high){
    if (low < high)     {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        quickSort(A,0,N-1);
        for(int i=0;i<N;i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
    return 0;
}
