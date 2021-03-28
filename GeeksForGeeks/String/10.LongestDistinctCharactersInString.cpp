// Longest Distinct characters in string

// Question:
// Given a string S, find length of the longest substring with all distinct characters.  For example, for 
// input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.

// Input:
// The first line of input contains an integer T denoting the number of test cases.
// The first line of each test case is String str.

// Output:
// Print length of smallest substring with maximum number of distinct characters.
// Note: The output substring should have all distinct characters.

// Example:
// Input:
// 2
// abababcdefababcdab
// geeksforgeeks

// Output:
// 6
// 7

// Solution:
// Initialize max,curlen and start to 0, set len = str.length().
// for(i=0 to len): 
//     if(v1 contains str[i])
//         if(curlen > max) then max = curlen.
//         store index of str[i] into index , initialize count=1, it1 and it2 to v1.begin.
//         increment it2 and count till it2 = it.
//         increment it2 and if(it1 == it2) then v1.erase(it1) else v1.erase(it1,it2).
//         push str[i] to v1, increment curlen and make curlen = curlen - count.
//     else: 
//         push str[i] to v1, increment curlen and if(curlen > max) then max = curlen.
// print max.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubstrDitinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDitinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends
int longestSubstrDitinctChars (string S)
{
        int len = S.length();
        int max = 0, curlen = 0;
        vector<char> v;
        vector<char> :: iterator it,it1;
        
        for(int i=0;i<len;i++){
            it = find(v.begin(), v.end(), S[i]);
            if(it != v.end()){
                int count = 1;
                it1 = v.begin();
                
                while(it1 != it){
                    it1++;
                    count++;
                }
                if(it == v.begin())
                    v.erase(it);
                else
                    v.erase(v.begin(), ++it);
                v.push_back(S[i]);
                curlen++;
                curlen = curlen - count;
            }
            else{
                v.push_back(S[i]);
                curlen++;
            }
            if(curlen > max)
                max = curlen;
        }
        return max;
}