// Set Bits

// Question
// Given a positive integer N, print count of set bits in it. 

// Input:
// The first line of input contains an integer T denoting the number of test cases. 
// Then T test cases follow. Each testcase contains single line of input containing the N.

// Output:
// For each test case, in a new line, print count of set bits in it.

// Example:
// Input:
// 2
// 6
// 11
// Output:
// 2
// 3

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,count=0;
	    cin>>N;
	    while(N > 0){
            if(N & 1)
                count++;
            N = N >> 1;
        }

		cout<<count<<endl;
		
	}
	return 0;
}