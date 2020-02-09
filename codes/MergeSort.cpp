#include <iostream>
#include <algorithm>
using namespace std;

void Merge(int A[],int l,int mid,int r){
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

void MergeSort(int A[],int l,int r){
	if(l < r){
		int mid = (l+r)/2;
		MergeSort(A,l,mid);
		MergeSort(A,mid+1,r);
		Merge(A,l,mid,r);
	}
}

int main() {
    int N;
	cin>>N;
    int arr[N];
	for(int i=0;i<N;i++)
        cin>>arr[i];

	MergeSort(arr,0,N-1);

    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
	return 0;
}