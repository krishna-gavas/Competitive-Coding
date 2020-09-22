// Last index of One

// Question:
// Given a string S consisting only '0's and '1's,  print the last index of the '1' present in it.

// Input:
// First line of the input contains the number of test cases T, T lines follow each containing a stream of characters.

// Output: 
// Corresponding to every test case, output the last index of 1. If 1 is not present, print "-1" (without quotes).

// Example:
// Input:
// 2
// 00001
// 0
// Output:
// 4
// -1

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
    cin.ignore();
	while(T--){
        int pos = -1;
	    string str;
        getline(cin,str);
        int len = str.length();

        for(int i=(len-1);i>=0;i--){
            if(str[i] == '1'){
                pos = i;
                break;
            }
        }
        cout<<pos<<endl;
	}
	return 0;
}