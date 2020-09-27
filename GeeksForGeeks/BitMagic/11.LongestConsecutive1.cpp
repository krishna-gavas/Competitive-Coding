// Longest Consecutive 1's

// Question:
// Given a number N. The task is to find the length of the longest consecutive 1s in its binary representation.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
// Each test case contains an integer N.

// Output:
// For each test case, in a new line, print the length of the longest consecutive 1's in N's binary representation.

// Example:
// Input:
// 2
// 14
// 222

// Output:
// 3 
// 4

// Solution:
// Initialize count = 0 
// while(N != 0) update N as N & (N << 1) (here the number of 1's reduce by 1 count)
//     increment count value 


#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,count=0;
	    cin>>N;
	    
	    while(N != 0){
	        N = N & (N << 1);
	        count++;
	    }
		cout<<count<<endl;
	}
	return 0;
}