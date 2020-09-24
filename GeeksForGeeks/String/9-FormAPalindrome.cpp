// Form a palindrome

// Question:
// Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
// For Example:
// ab: Number of insertions required is 1. bab or aba
// aa: Number of insertions required is 0. aa
// abcd: Number of insertions required is 3. dcbabcd

// Input:
// The first line of input contains an integer T denoting the number of test cases.
// The first line of each test case is S.

// Output:
// Print the minimum number of characters.

// Example:

// Input:
// 3
// abcd
// aba
// geeks

// Output:
// 3
// 0
// 3

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int LCS(string X, string Y, int m, int n){
	int DP[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				DP[i][j] = 0;
			else if(X[i-1] == Y[j-1])
				DP[i][j] = 1 + DP[i-1][j-1];
			else 
				DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
		}
	}
	return DP[m][n];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str1,str2;
        cin>>str1;
        int n,len,insertions;
		n = str1.length();
        str2 = str1;
		reverse(str2.begin(), str2.end());
        len = LCS(str1,str2,n,n);
		insertions = n - len;
		cout<<insertions<<"\n";
	}
	return 0;
}