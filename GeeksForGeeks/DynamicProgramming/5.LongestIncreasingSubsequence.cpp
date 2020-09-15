// Longest Increasing Subsequence

// Question:
// Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence .
// The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's 
// elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This 
// subsequence is not necessarily contiguous, or unique.
// Note: Duplicate numbers are not counted as increasing subsequence.

// Input:
// The first line contains an integer T, depicting total number of test cases. Then following T lines contains an 
// integer N depicting the size of array and next line followed by the value of array.

// Output:
// For each testcase, in a new line, print the Max length of the subsequence in a separate line.

// Example:
// Input:
// 2
// 16
// 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
// 6
// 5 8 3 7 9 1

// Output:
// 6
// 3

// Solution:
// Create a DP[] array to store length of LIS and initialize it with 1
// LIS: initialize len = 1
//     for(i=1 to N)
//         for(j=0 to i-1)
//             if(A[j] < A[i]) then DP[i] = max(DP[i], DP[j]+1)
//         if(DP[i] > len) then len = DP[i]
//     return len


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LIS(int A[],int DP[], int n){
    int len = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(A[j] < A[i]){
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        if(DP[i] > len)
            len = DP[i];
    }
    return len;
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
            DP[i] = 1;
        }
        cout<<LIS(A,DP,N)<<"\n";
	}
	return 0;
}