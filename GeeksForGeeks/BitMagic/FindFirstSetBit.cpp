// Find First Set Bit

// Question
// Given an integer an N. The task is to print the position of first set bit found from right side in the binary 
// representation of the number.

// Input:
// The first line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. 
// The only line of the each test case contains an integer N.

// Output:
// For each test case print in a single line an integer denoting the position of the first set bit found form right 
// side of the binary representation of the number. If there is no set bit print "0".

// Example:
// Input:
// 2
// 18
// 12

// Output:
// 2
// 3

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,pos=0;
	    cin>>N;
	    while(N > 0){
	        pos++;
            if(N & 1)
                break;
            N = N >> 1;
        }
		cout<<pos<<endl;
	}
	return 0;
}