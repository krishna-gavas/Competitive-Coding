// Inversion of Array(using Mergesort technique)
// In Merge procedure if element(A[j]) in right array is smaller than A[i] in left array
// then add (number of elements from j to mid ) to inversion count
#include <iostream>
#include <algorithm>
using namespace std;
long long int counter = 0;

void Merge(int A[],int l,int mid,int r){
	int B[r+1];
	int i=l,j=mid+1,k=l;
	while(i <= mid && j <= r){
		if(A[i] <=A[j])					// Element in right array is greater
			B[k] = A[i++];
		else{							// Element in right array is smaller
			B[k] = A[j++];
			counter = counter + (mid - i + 1);
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
	int T;
	cin>>T;
	while(T--){
	    counter = 0;
	    int N;
	    cin>>N;
	    int arr[N];;
		for(int i=0;i<N;i++)
	        cin>>arr[i];

		MergeSort(arr,0,N-1);
		cout<<counter<<endl;		
	}
	return 0;
}