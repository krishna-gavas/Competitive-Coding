// Swap all odd and even bits

// Question:
// Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the given number 
// is 23 (00010111), it should be converted to 43(00101011). Here, every even position bit is swapped with adjacent 
// bit on right side(even position bits are highlighted in binary representation of 23), and every odd position bit 
// is swapped with adjacent on left side.

// Input:
// The first line of input contains T, denoting the number of testcases. Each testcase contains single line.

// Output:
// For each testcase in new line, print the converted number.

// Example:
// Input:
// 2
// 23
// 2

// Output:
// 43
// 1

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