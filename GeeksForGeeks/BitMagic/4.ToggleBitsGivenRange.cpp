// Toggle bits given range

// Question
// Given a non-negative number N and two values L and R. The problem is to toggle the bits in the range L to R in 
// the binary representation of N, i.e, to toggle bits from the rightmost Lth bit to the rightmost Rth bit. A toggle 
// operation flips a bit 0 to 1 and a bit 1 to 0.

// Input:
// First line of input contains a single integer T which denotes the number of test cases. Then T test cases follows. 
// First line of each test case contains three space separated integers N, L and R.

// Output:
// For each test case , print the number obtained by toggling bits from the rightmost Lth bit to the rightmost Rth 
// bit in binary representation of N.

// Example:
// Input:
// 2
// 17 2 3
// 50 2 5
// Output:
// 23
// 44

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,L,R;
	    cin>>N>>L>>R;
		for(int i=L-1; i<R; i++){
            int temp =pow(2,i);
            N = N ^ temp;
        }
        cout<<N<<"\n";
	}
	return 0;
}