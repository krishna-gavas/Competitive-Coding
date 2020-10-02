// Longest Common Subsequence

// Question:
// Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of 
// uppercase.

// Input:
// First line of the input contains no of test cases  T,the T test cases follow.
// Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
// The next two lines contains the 2 string str1 and str2 .

// Output:
// For each test case print the length of longest  common subsequence of the two strings .

// Example:
// Input:
// 2
// 6 6
// ABCDGH
// AEDFHR
// 3 2
// ABC
// AC

// Output:
// 3
// 2

// Solution:
// LCS:
//     Create a DP table and initialize the length of longest substring(len) as 0
//     for(i=0 to m+1)
//         for(j=0 to n+1)
//             if(it is first row or first column) then DP[i][j] = 0
//             else if(left and top values are equal) then DP[i][j] = DP[i-1][j-1] + 1
//             else then DP[i][j] = max(DP[i-1][j], DP[i][j-1])
//     return DP[m][n]

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCS(string X, string Y, int m, int n){
    int DP[m+1][n+1];
    int len=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                DP[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                DP[i][j] = DP[i-1][j-1] + 1;
            else 
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }
    return DP[m][n];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,M;
        cin>>N>>M;
        string X,Y;
        cin>>X>>Y;
        cout<<LCS(X,Y,N,M)<<"\n";
	}
	return 0;
}