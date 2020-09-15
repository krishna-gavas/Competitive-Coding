// Equlibrium point in an array

// Question:
// Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the 
// array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the 
// sum of elements after it.

// Input:
// The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. 
// First line of each test case contains an integer N denoting the size of the array. Then in the next line are 
// N space separated values of the array A.

// Output:
// For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium 
// point exists print -1.

// Example:
// Input:
// 2
// 1
// 1
// 5
// 1 3 5 2 2

// Output:
// 1
// 3

// Solution:
// initialize leftSum as 0 and rightSum as totalSum
// while accessing every element calulate leftSum and rightSum and compare both
// if both sums are equal print the respective position


#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long int T;
	cin>>T;
	while(T--){
	    long int N;
	    cin>>N;
	    int arr[N],i=1,j=N-1,pos=-1,leftsum=0,rightsum=0;

	    for(long int i=0;i<N;i++){
	        cin>>arr[i];
			rightsum = rightsum + arr[i];
		}

		for(long int i=0;i<N;i++){
			rightsum = rightsum - arr[i];
			if(leftsum == rightsum){
				pos = i+1;
				break;
			}
			leftsum = leftsum + arr[i];
		}
		cout<<pos<<endl;
	}
	return 0;
}