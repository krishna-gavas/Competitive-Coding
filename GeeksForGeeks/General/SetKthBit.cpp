// Set Kth Bit

// Question
// Given a number N and a value K. From the right, set the Kth bit in the binary representation of N. 
// The position of LSB(or last bit) is 0, second last bit is 1 and so on. 
// Also, 0 <= K < X, where X is the number of bits in the binary representation of N.

// Input:
// First line of input contains a single integer T, which denotes the number of test cases. 
// T test cases follows. First line of each testcase contains two space separated integers N and K.

// Output:
// For each test case, print the new number after setting the Kth bit of N.

// Example:
// Input:
// 2
// 10 2
// 15 3

// Output:
// 14
// 15

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
            newN = oldN;
        }
        else{
            newN = oldN + pow(2,K);
        }

		cout<<newN<<endl;
		
	}
	return 0;
}