// Reverse Bits

// Question
// Given a 32 bit number x, reverse its binary form and print the answer in decimal.

// Input:
// The first line of input consists T denoting the number of test cases. 
// T testcases follow. Each test case contains a single 32 bit integer

// Output:
// For each test case, in a new line, print the reverse of integer.

// Example:
// Input:
// 2
// 1
// 5
// Output:
// 2147483648
// 2684354560

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,bit,out=0;
	    cin>>N;
        for(int i=0;i<32;i++){
            if(N & 1)
                bit = 1;
            else 
                bit = 0;
            N = N >> 1;
            out = out << 1;
            out = out | bit;
        }

		cout<<out<<endl;
		
	}
	return 0;
}