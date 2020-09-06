// K-th element of two sorted Arrays

// Question:
// Given two sorted arrays A and B of size M and N respectively and an element k. The task is to find the element 
// that would be at the k’th position of the final sorted array.

// Input:
// First line consists of test cases T. First line of every test case consists of 3 integers N, M and K, denoting 
// M number of elements in A, N number of elements in B and kth position element. Second and Third line of every 
// test case consists of elements of A and B respectively.

// Output:
// Print the element at the Kth position.

// Example:
// Input:
// 1
// 5 4 5
// 2 3 6 7 9
// 1 4 8 10

// Output:
// 6

// Solution:
// Merge(A,B,C,n,m): where A and B are of size N and M and C is result array of size N+M.
//     initialize i,j and k to 0.
//     while(i < n && j < m): if(A[i] <=B[j]) then C[k++] = A[i++] else C[k++] = B[j++]
//     while(i < n): C[k++] = A[i++]
//     while(j < m): C[k++] = B[j++]

#include <iostream>
using namespace std;

void Merge(int A[],int B[],int C[],int n,int m){
	int i=0,j=0,k=0;
	while(i < n && j < m){
		if(A[i] <=B[j])				
			C[k] = A[i++];
		else{							
			C[k] = B[j++];
		}
		k = k + 1;
	}
	while(i < n)
		C[k++] = A[i++];
	while(j < m)
		C[k++] = B[j++];	
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M,K;
        cin>>N>>M>>K;
        int A[N],B[M],C[N+M];
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<M;i++)
            cin>>B[i];
        Merge(A,B,C,N,M);
        cout<<C[K]<<endl;
    }
    return 0;
}
