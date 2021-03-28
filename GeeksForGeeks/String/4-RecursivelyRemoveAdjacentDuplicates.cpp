// Recursively remove all adjacent duplicates in a string

// Question:
// Given a string s, recursively remove adjacent duplicate characters from the string s. The output string should 
// not have any adjacent duplicates.
 

// Input:
// The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each 
// test case contains a string str.

// Output:
// For each test case, print a new line containing the resulting string.

// Example:
// Input:
// 2
// geeksforgeek
// acaaabbbacdddd

// Output:
// gksforgk
// acac


// Solution:
// In RemoveAdjacent function check if there is any duplicate string 
// if no duplicate string is present return str2 else return RemoveAdjacent(str2)

#include <iostream>
#include <string>
using namespace std;

string RemoveAdjacent(string S){
        string S2;
        int len = S.length(),l=0,r,flag,last=0;

        for(int i=0;i<len;){
            int j=i+1;
            flag = 0;
            while((S[i] == S[j]) && (j<len)){
                j++;
                flag = 1;
                last = 1;
            }
            if(flag==1){

                l = j;
                i = j;
            }
            else{
                r = i;
                S2.append(S.substr(l,(r-l+1)));
                l = j;
                i++;
            }
        }
        if(last == 0)
            return S2;
        else 
            return RemoveAdjacent(S2);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string S,S2; 
        cin>>S;

        S2 = RemoveAdjacent(S);
 
        cout<<S2<<endl;
	}
	return 0;
}