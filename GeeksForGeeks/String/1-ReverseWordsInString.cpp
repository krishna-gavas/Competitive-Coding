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

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str1,str2;
        cin>>str1;
        int len = str1.length();
        int r,len1 = len-1;

		for(int i=len;i>=0;i--){
            if(str1[i] == '.'){
                r = len1 - i;
                len1 = i - 1;
                str2.append(str1.substr(i+1,r));
                str2.append(".");
            }
        }
        str2.append(str1.substr(0,len1+1));
        cout<<str2<<endl;
           
	}
	return 0;
}