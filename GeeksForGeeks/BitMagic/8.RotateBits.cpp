// Rotate Bits

// Question:
// Given an integer N and an integer D, you are required to write a program to rotate the binary representation of 
// the integer N by D digits to the left as well as right and print the results in decimal values after each of the 
// rotation.
// Note: Integer N is stored using 16 bits. i.e. 12 will be stored as 0000.....001100.

// Input:
// First line of input contains a single integer T which denotes the number of test cases. Each test case contains 
// two space separated integers N and D where N denotes the number to be rotated and D denotes the number of digits 
// by which the number is required to be rotated.

// Output:
// For each testcase, in a new line, print the value of number N after rotating it to left by D digits in one line, 
// and second line prints the value of number N after rotating it to the right by D digits.

// Example:
// Input:
// 2
// 229 3
// 28 2
// Output:
// 1832
// 40988
// 112
// 7


#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int N,D;
        cin >> N >> D;
        bitset <16> b(N);
        
        D = D%16;
        
        cout << ((b<<D)|(b>>(16-D))).to_ullong()<<endl;
        cout << ((b>>D)|(b<<(16-D))).to_ullong()<<endl;
    }
    return 0;
}