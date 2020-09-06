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

int main() {
	int T;
	cin>>T;
	cin.ignore();
	while(T--){
	    string str,str1,str2;
		int A[26] = {0};
		int B[26] = {0};
		getline(cin,str);

		int pos,len1,len2,flag=0,len = str.length();

		for(int i=0;i<len;i++){
            if(str[i] == ' '){
                pos = i;
				break;
            }
        }
		len1 = pos;
		len2 = len - pos - 1;
		str1 = str.substr(0,len1);
		str2 = str.substr(pos+1,len2);

		for(int i=0;i<len1;i++)
			A[str1[i] - 'a']++;

		for(int i=0;i<len2;i++)
			B[str2[i] - 'a']++;
           
		for(int i=0;i<26;i++){
			if(A[i] != B[i]){
				flag = 1;
				break;
			}
		}

		if(flag == 1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}