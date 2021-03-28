// Reverse words in a given string(using '.' as delimiter)

// Question:
// Given a String of length S, reverse the whole string without reversing the individual words in it. Words are 
// separated by dots.

// Input:
// The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S 
// containing characters.

// Output:
// For each test case, in a new line, output a single line containing the reversed String.

// Example:
// Input:
// 2
// i.like.this.program.very.much
// pqr.mno

// Output:
// much.very.program.this.like.i
// mno.pqr

// len is the total length of the string
// len1 is length of substring

#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s);
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        cout<<reverseWords(s)<<endl;
    }
}// } Driver Code Ends


string reverseWords(string S1) 
{ 
    string S2;
    int r;
    int len = S1.length();
    for(int i = len-1;i>=0;i--){
        if(S1[i] == '.'){
            r = len - i;
            len = i -1;
            S2.append(S1.substr(i+1,r));
            S2.append(".");
        }
    }
    S2.append(S1.substr(0,len+1));
    return S2;
} 