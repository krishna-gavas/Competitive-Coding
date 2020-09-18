// Kth smallest element(using Heapsort)

// Question:
// Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest 
// element in the given array. It is given that all array elements are distinct.

// Input:
// The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each 
// test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. 
// Second line contains N space separated integer denoting elements of the array. Third line of the test case 
// contains an integer K.

// Output:
// Corresponding to each test case, print the kth smallest element in a new line.

// Example:
// Input:
// 2
// 6
// 7 10 4 3 20 15
// 3
// 5
// 7 10 4 20 15
// 4
// Output:
// 7
// 15

#include <iostream>
#include <algorithm>
using namespace std;

void HeapAdjust(int A[],int i,int n){
    int k=i,v=A[k];
    bool heap = false;
    while(!heap && (2*k <= n)){
        int j = 2*k;
        if(j < n)
            if(A[j] < A[j+1])
                j = j + 1;
        if( v >= A[j])
            heap = true;
        else
        {
            A[k] = A[j];
            k = j;
            A[k] = v;
        }  
    }
}

void HeapBottomUp(int A[],int n){
    for(int i=(n/2);i>=1;i--)
        HeapAdjust(A,i,n);      
}

int HeapSort(int A[],int n,int k){
    HeapBottomUp(A,n);          
    for(int i=n;i>0;i--){
		if(i == k)
			return A[1];
        swap(A[1],A[i]);
        HeapAdjust(A,1,i-1);    
    }
	return 0;
}

int main() {
	int T;
	srand(time(NULL));
	cin>>T;
	while(T--){
	    int N,K,out;
	    cin>>N;
	    int arr[N];

	    for(long int i=1;i<=N;i++)
	        cin>>arr[i];

		cin>>K;

		out = HeapSort(arr,N,K);

		cout<<out<<endl;
	}
	return 0;
}