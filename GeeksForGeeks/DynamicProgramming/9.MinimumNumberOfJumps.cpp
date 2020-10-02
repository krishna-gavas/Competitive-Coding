// Minimum number of jumps

// Question:
// Given an array of integers where each element represents the max number of steps that can be made forward from 
// that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the 
// first element). If an element is 0, then cannot move through that element.

// Input: 
// The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a 
// number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.

// Output:
// For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print 
// "-1"(without quotes).

// Example:
// Input:
// 2
// 11
// 1 3 5 8 9 2 6 7 6 8 9
// 6
// 1 4 3 2 6 7
// Output:
// 3
// 2

// Solution:
// Create a DP[] array and initialize it with INT_MAX
// MinJumps: initialize DP[0]=0
//     for(i=1 to n)
//         for(j=0 to i-1)
//             if(j+A[j] reaches i && DP[j] != INT_MAX) then DP[i] = min(DP[i], DP[j]+1)
//     if(DP[n-1] == INT_MAX) then return -1
//     return DP[n-1]

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int MinJumps(int A[],int DP[], int n){
    DP[0] = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(i <= j + A[j] && DP[j] != INT_MAX){
                DP[i] = min(DP[i], DP[j]+1);
            }
        }
    }
    if(DP[n-1] == INT_MAX)
        return -1;
    return DP[n-1];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
        cin>>N;
        int A[N],DP[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
            DP[i] = INT_MAX;
        }
        cout<<MinJumps(A,DP,N)<<"\n";
	}
	return 0;
}