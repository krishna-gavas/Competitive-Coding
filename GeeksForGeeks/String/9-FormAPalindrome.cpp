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

int countMin(string str);

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        cout << countMin(str) << endl;
    }
return 0;
}

// } Driver Code Ends

int LCS(string S1, string S2, int n){
	int DP[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				DP[i][j] = 0;
			else if(S1[i-1] == S2[j-1])
				DP[i][j] = 1 + DP[i-1][j-1];
			else 
				DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
		}
	}
	return DP[n][n];
}

int countMin(string S1){
    string S2 = S1;
    int n = S1.length();
	reverse(S2.begin(), S2.end());
    int len = LCS(S1,S2,n);
	int insertions = n - len;
	return insertions;
}