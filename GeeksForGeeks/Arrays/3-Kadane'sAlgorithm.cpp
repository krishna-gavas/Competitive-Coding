// Kadane's Algorithm to find maximum subAay sum

// Question:
// Given an Aay A of N integers. Find the contiguous sub-Aay with maximum sum.

// Input:
// The first line of input contains an integer T denoting the number of test cases. 
// The description of T test cases follows. The first line of each test case contains a single integer N denoting 
// the size of Aay. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of 
// the Aay.

// Output:
// Print the maximum sum of the contiguous sub-Aay in a separate line for each test case.

// Example:
// Input
// 2
// 5
// 1 2 3 -2 5
// 4
// -1 -2 -3 -4
// Output
// 9
// -1

// Solution:
// Initialize localmax and globalmax to 0.
// for(i=0 to N):
// 	if(i==0 && A[i]<0) then localmax = globalmax = A[0].
// 	if(A[i] > A[i] + localmax) then localmax = A[i] else localmax = A[i] + localmax.
// 	if(localmax > globalmax) then globalmax = localmax.
// print globalmax

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int A[N];
	    for(int i=0;i<N;i++)
	        cin>>A[i];
	    long int lmax = A[0], gmax = A[0];
	    for(int i=1;i<N;i++){
	        if(A[i] > (A[i] + lmax))
	            lmax = A[i];
	        else 
	            lmax = lmax + A[i];
	        gmax = max(gmax, lmax);
	    }
	    cout<<gmax<<endl;
	}
	return 0;
}