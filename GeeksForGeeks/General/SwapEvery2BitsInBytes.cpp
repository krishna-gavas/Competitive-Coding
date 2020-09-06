// Swap every two bits in bytes

// Question:
// Swap all the pair of bits in a byte.
// Before swapping: 11-10-11-01
// After swapping: 11-01-11-10
// Input:
// The first line of the input contains an integer T denoting the number of test cases. Each test case contains 
// an unsigned integer x.

// Output:
// For each test case, the output is the integer after swapping the bits.

// Example:
// Input:
// 2
// 4
// 20
// Output:
// 8
// 40

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int X,Y;
	    cin>>X;
        bitset<8> bset(X);
        for(int i=0;i<8;i=i+2){
            bool temp = bset[i];
            bset[i] = bset[i+1];
            bset[i+1] = temp;
        }
		cout<<bset.to_ulong()<<endl;
		
	}
	return 0;
}