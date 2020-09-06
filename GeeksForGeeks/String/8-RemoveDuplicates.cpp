// Remove Duplicates

// Question:
// Given a string, the task is to remove duplicates from it. Expected time complexity O(n) where n is length of 
// input string and extra space O(1) under the assumption that there are total 256 possible characters in a string.

// Note: that original order of characters must be kept same. 

// Input: 
// First line of the input is the number of test cases T. And first line of test case contains a string.

// Output:  
// Modified string without duplicates and same order of characters.

// Example:
// Input:
// 2
// geeksforgeeks
// geeks for geeks

// Output:
// geksfor
// geks for

// Solution:
// create a char array as count[256] ={0}, input string and store string length in len.
// for( i=0 to len): if count[character] is zero increase count and print that character.

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
    cin>>T;
    cin.ignore();
	while(T--){
	    string str1;
		char count[256] ={0};
        getline(cin,str1);
        int len = str1.length();
		for(int i=0;i<len;i++){
            if(count[str1[i]]++ == 0){
                cout<<str1[i];
            }
        }
        cout<<endl;
	}
	return 0;
}