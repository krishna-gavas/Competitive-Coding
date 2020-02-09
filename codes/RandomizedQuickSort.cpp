#include <iostream>
#include <algorithm>
using namespace std;

int R_Partition(int A[],int l,int r){
    int ran = l + rand() % (r-l+1);
    swap(A[ran],A[r]);

    int x=A[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(A[j]<=x){
            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void R_QuickSort(int A[],int l,int r){
    int q;
    if(l < r){
        q = R_Partition(A,l,r);
        R_QuickSort(A,l,q-1);
        R_QuickSort(A,q+1,r);
    }
}

int main() {
    int N;
    srand(time(NULL));
	cin>>N;
    int arr[N];
	for(int i=0;i<N;i++)
        cin>>arr[i];

	R_QuickSort(arr,0,N-1);

    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
	return 0;
}