// Power of 2

// Question
// Given a positive integer N. The task is to check if N is a power of 2. That is N is 2x for some x.

// Input:
// The first line contains T denoting the number of test cases. Each test case contains a single positive integer N.

// Output:
// Print "YES" if it is a power of 2 else "NO" (Without the double quotes).

// Constraints:
// 1 <= T <= 100
// 0 <= N <= 1018

// Example:
// Input :
// 2
// 1
// 98

// Output :
// YES
// NO

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,count=0;
	    cin>>N;
		while(N > 0){
            if(N & 1)
                count++;
            N = N >> 1;
        }
        if(count == 1)
            cout<<"YES\n";
        else 
            cout<<"NO\n";
	}
	return 0;
}