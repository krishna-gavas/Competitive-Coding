// Bit Difference

// Question
// You are given two numbers A and B. Write a program to count number of bits needed to be 
// flipped to convert A to B.

// Input:
// The first line of input contains an integer T denoting the number of test cases. 
// T testcases follow. The first line of each test case is A and B separated by a space.

// Output:
// For each testcase, in a new line, print the number of bits needed to be flipped.

// Example:
// Input:
// 1
// 10 20
// Output:
// 4

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int A,B,N,count=0;
	    cin>>A>>B;
	    N = A ^ B;
        while(N > 0){
            if(N & 1)
                count++;
            N = N >> 1;
        }
		cout<<count<<endl;
	}
	return 0;
}