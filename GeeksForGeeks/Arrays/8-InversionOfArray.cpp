// Inversion of Array(using Mergesort technique)

// Question:
// Given an array of positive integers. The task is to find inversion count of array.

// Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If 
// array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is 
// the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Input:
// The first line of input contains an integer T denoting the number of test cases. The first line of each test 
// case is N, the size of array. The second line of each test case contains N elements.

// Output:
// Print the inversion count of array.

// Example:
// Input:
// 1
// 5
// 2 4 1 3 5

// Output:
// 3

// Solution:
// In Merge procedure if element(A[j]) in right array is smaller than A[i] in left array
// then add (number of elements from i to mid ) to inversion count
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