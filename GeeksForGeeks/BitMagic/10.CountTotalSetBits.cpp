// Count Total Set Bits 

// Question:
// You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

// Input:
// The first line of input contains an integer T denoting the number of test cases. T testcases follow. The first 
// line of each test case is N.

// Output:
// For each testcase, in a new line, print the total count of all bits.

// Example:
// Input:
// 2
// 4
// 17
// Output:
// 5
// 35

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,count,sum=0;
	    cin>>N;
	    for(int i=1;i<=N;i++){
	        int x = i;
	        count = 0;
	        while(x > 0){
                if(x & 1)
                    count++;
                x = x >> 1;
            }
            sum = sum + count;
	    }
		cout<<sum<<endl;
		
	}
	return 0;
}