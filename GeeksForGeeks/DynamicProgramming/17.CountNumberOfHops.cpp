// Count number of hops

// Question:
// A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top.
// for Example if n is 4 then ways are {1,1,1,1},{1,1,2},{1,2,1},{2,1,1},{2,2},{3,1},{1,3} so total 7 ways

// Input:
// The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each 
// testcase contains one line of input N denoting the total number of steps.

// Output:
// For each testcase, in a new line, print the number of ways to reach the top.

// Example:
// Input:
// 2
// 1
// 5
// Output:
// 1
// 13 

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int NumberOfHops(int n){
    int DP[n+1];
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    if(n < 4)
        return DP[n];
    else{
        for(int i=4;i<=n;i++)
            DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
        return DP[n];
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,sum=0;
        cin>>N;
        cout<<NumberOfHops(N)<<"\n";
	}
	return 0;
}