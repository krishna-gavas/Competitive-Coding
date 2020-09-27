// Number is sparse or not 

// Question:
// Given a number N, check whether it is sparse or not. A number is said to be a sparse number if in the binary 
// representation of the number no two or more consecutive bits are set.

// Input:
// The first line of input contains an integer T denoting the number of test cases. The first line of each test 
// case is number 'N'.

// Output:
// Print '1' if the number is sparse and '0' if the number is not sparse.

// Example:
// Input:
// 2
// 2
// 3

// Output:
// 1
// 0

// Solution:
// Initialize sparse as 0
// update N as N & (N << 1) (here the number of 1's reduce by 1 count)
// if(N == 0) make sparse = 1

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,sparse=0;
	    cin>>N;
	    
	    N = N & (N << 1);
	    if(N == 0)
	        sparse = 1;
		cout<<sparse<<endl;
	}
	return 0;
}