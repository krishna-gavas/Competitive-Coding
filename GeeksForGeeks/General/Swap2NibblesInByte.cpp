// Swap two nibbles in a byte

// Question:
// Given a byte, swap the two nibbles in it. For example 100 is be represented as 01100100 in a byte (or 8 bits). 
// The two nibbles are (0110) and (0100). If we swap the two nibbles, we get 01000110 which is 70 in decimal.

// Input:
// The first line contains 'T' denoting the number of testcases. Each testcase contains a single positive integer X.

// Output:
// In each separate line print the result after swapping the nibbles.

// Example:
// Input:
// 2
// 100
// 129

// Output:
// 70
// 24

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int X,Y,leftN,rightN;
	    cin>>X;
        leftN = X;
        rightN = X;

        leftN = leftN & 240;
        rightN = rightN & 15;
        leftN = leftN >> 4;
        rightN = rightN << 4;


        Y = leftN | rightN;

		cout<<Y<<endl;
		
	}
	return 0;
}