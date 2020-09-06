// Sum of Middle Elements of two sorted arrays

// Question:
// Given 2 sorted arrays A and B of size N each. Print sum of middle elements of the array obtained after merging 
// the given arrays.

// Input:
// The first line contains T denoting the number of testcases. Then follows description of testcases.
// Each case begins with a single positive integer N denoting the size of array. The second line contains the N 
// space separated positive integers denoting the elements of array A. The third line contains N space separated 
// positive integers denoting the elements of array B.

// Output:
// For each testcase, print the sum of middle elements of two sorted arrays. The number of the elements in the 
// merged array are even so there will be 2 numbers in the center n/2 and n/2 +1. You have to print their sum.

// Example:
// Input :
// 1
// 5
// 1 2 4 6 10
// 4 5 6 9 12

// Output : 
// 11

// Solution:
// Merge(A,B,C,N): where A and B are of size N and C is result array of size 2N.
//     initialize i,j and k to 0.
//     while(i < n && j < n): if(A[i] <=B[j]) then C[k++] = A[i++] else C[k++] = B[j++]
//     while(i < n): C[k++] = A[i++]
//     while(j < n): C[k++] = B[j++]

#include <iostream>
using namespace std;

void Merge(int A[],int B[],int C[],int n){
	int i=0,j=0,k=0;
	while(i < n && j < n){
		if(A[i] <=B[j])				
			C[k] = A[i++];
		else{							
			C[k] = B[j++];
		}
		k = k + 1;
	}
	while(i < n)
		C[k++] = A[i++];
	while(j < n)
		C[k++] = B[j++];	
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N],B[N],C[2*N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<N;i++)
            cin>>B[i];
        Merge(A,B,C,N);
        cout<<C[N-1]+C[N]<<endl;
    }
    return 0;
}
