// Form a palindrome(not submitted)

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
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str1,str2;
        cin>>str1;
        int len = str1.length();
        str2 = str1;
		reverse(str2.begin(), str2.end());
		cout<<str2;
           
	}
	return 0;
}