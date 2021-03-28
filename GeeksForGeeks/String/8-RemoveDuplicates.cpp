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

class Solution{
public:	
		
	string removeDups(string S) 
	{
	    string out = "";
	    int count[26] = {0};
	    int len = S.length();
	    for(int i=0;i<len;i++){
	        if(S[i] >= 'a' && S[i] <= 'z')
                if(count[S[i] - 'a']++ == 0)
                    out = out + S[i];
            else if(S[i] >= 'A' && S[i] <= 'Z')
                if(count[S[i] - 'A']++ == 0)
                    out = out + S[i];
        }
        return out;
	}
};


// { Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}