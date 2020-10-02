// Longest Common Substring

// Question:
// Given two strings X and Y. The task is to find the length of the longest common substring.

// Input:
// First line of the input contains number of test cases T. Each test case consist of three lines, first of which 
// contains 2 space separated integers N and M denoting the size of string X and Y strings respectively. 
// The next two lines contains the string X and Y.

// Output:
// For each test case print the length of longest  common substring of the two strings .

// Example:
// Input:
// 2
// 6 6
// ABCDGH
// ACDGHR
// 3 2
// ABC
// AC

// Output:
// 4
// 1

// Solution:
// LCSubstring:
//     Create a DP table and initialize the length of longest substring(len) as 0
//     for(i=0 to m+1)
//         for(j=0 to n+1)
//             if(it is first row or first column) then DP[i][j] = 0
//             else if(left and top values are equal) then DP[i][j] = DP[i-1][j-1] + 1
//             else then DP[i][j] = 0
//             if(DP[i][j] > len) then len = DP[i][j]
//     return len

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCSubstring(string X, string Y, int m, int n){
    int DP[m+1][n+1];
    int len=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                DP[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                DP[i][j] = DP[i-1][j-1] + 1;
            else 
                DP[i][j] = 0;
            if(DP[i][j] > len)
                len = DP[i][j];
        }
    }
    return len;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,M;
        cin>>N>>M;
        string X,Y;
        cin>>X>>Y;
        cout<<LCSubstring(X,Y,N,M)<<"\n";
	}
	return 0;
}