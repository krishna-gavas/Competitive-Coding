// Kadane's Algorithm to find maximum subarray sum

// Question:
// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

// Input:
// The first line of input contains an integer T denoting the number of test cases. 
// The description of T test cases follows. The first line of each test case contains a single integer N denoting 
// the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of 
// the array.

// Output:
// Print the maximum sum of the contiguous sub-array in a separate line for each test case.

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
// 	if(i==0 && arr[i]<0) then localmax = globalmax = arr[0].
// 	if(arr[i] > arr[i] + localmax) then localmax = arr[i] else localmax = arr[i] + localmax.
// 	if(localmax > globalmax) then globalmax = localmax.
// print globalmax

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,lmax=0,gmax=0;
	    cin>>N;
	    long int arr[N];
	    for(long int i=0;i<N;i++)
	        cin>>arr[i];

		for(long int i=0;i<N;i++){
			if(i==0 && arr[i]<0){
				lmax = arr[0];
				gmax = arr[0];
			}
			
			if(arr[i] > (arr[i] + lmax))
				lmax = arr[i];
			else
				lmax = arr[i] + lmax;

			if(lmax > gmax)
				gmax = lmax;
		}

		cout<<gmax<<endl;
		
	}
	return 0;
}