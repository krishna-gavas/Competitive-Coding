// Anagram

// Question:
// Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings 
// are anagram of each other or not. An anagram of a string is another string that contains same characters, only 
// the order of characters can be different. For example, “act” and “tac” are anagram of each other.

// Input: 
// The first line of input contains an integer T denoting the number of test cases. Each test case consist of two 
// strings in 'lowercase' only, in a single line.

// Output:
// Print "YES" without quotes if the two strings are anagram else print "NO".

// Example:
// Input:
// 2
// geeksforgeeks forgeeksgeeks
// allergy allergic

// Output:
// YES
// NO

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

bool isAnagram(string S1, string S2){
    int A[26] = {0};
	int B[26] = {0};
    int len1 = S1.length();
    int len2 = S2.length();
    int flag=0;
    if(len1 != len2)
        return false;
    for(int i=0;i<len1;i++){
        A[S1[i] - 'a']++;
        B[S2[i] - 'a']++;
    }
    for(int i=0;i<26;i++){
		if(A[i] != B[i]){
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	    return false;
	else 
	    return true;
}


// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;

        if(isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}