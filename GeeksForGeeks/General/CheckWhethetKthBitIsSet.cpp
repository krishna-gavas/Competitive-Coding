// Check whether K-th bit is set or not

// Question
// Given a number N and a bit number K, check if Kth bit of N is set or not. A bit is called set if it is 1. 
// Position of set bit '1' should be indexed starting with 0 from RSB side in binary representation of the number. 
// Consider N = 4(100):  0th bit = 0, 1st bit = 0, 2nd bit = 1.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
// Each test case consists of two lines. The first line of each test case contain an integer  N. The second line 
// of each test case contains an integer  K.

// Output:
// Corresponding to each test case, print "Yes" (without quotes) if Kth  bit is set else print "No" (without quotes) 
// in a new line.

// Example:
// Input:
// 3
// 4
// 0
// 4
// 2
// 500
// 3

// Output:
// No
// Yes
// No

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,K,oldN,newN;
	    cin>>N>>K;
        oldN = N;
	    for(int i=0;i<K;i++){
            N = N >> 1;
        }
        if(N & 1){
            cout<<"Yes"<<"\n";
        }
        else{
            cout<<"No"<<"\n";
        }
		
	}
	return 0;
}