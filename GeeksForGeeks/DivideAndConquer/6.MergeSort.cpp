// Merge Sort

// merge(A, l, m, r): Create an auxillary array B of size N and initialize i=l, j=m+1 and k=l. 
//     while(i <= m && j <= r): if(A[i] <=A[j]) then B[k++] = A[i++] else B[k++] = A[j++]
//     while(i <= m): B[k++] = A[i++]
//     while(j <= r): B[k++] = A[j++]
//     copy array B to A.

#include <iostream>
using namespace std;

void merge(int A[],int l,int mid,int r){
	int B[r+1];
	int i=l,j=mid+1,k=l;
	while(i <= mid && j <= r){
		if(A[i] <=A[j])				
			B[k] = A[i++];
		else{							
			B[k] = A[j++];
		}
		k = k + 1;
	}
	while(i <= mid)
		B[k++] = A[i++];
	while(j <= r)
		B[k++] = A[j++];

	for(int j=l;j<=r;j++)
		A[j] = B[j];	
}

void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
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
        mergeSort(A,0,N-1);
        for(int i=0;i<N;i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
    return 0;
}
