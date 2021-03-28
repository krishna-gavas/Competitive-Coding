// Check if string is rotated by two places

// Question:
// Given two strings a and b. The task is to find if a string 'a' can be obtained by rotating another string 'b' 
// by 2 places.

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. In the 
// next two line are two string a and b.

// Output:
// For each test case in a new line print 1 if the string 'a' can be obtained by rotating string 'b' by two places 
// else print 0.

// Example:
// Input:
// 2
// amazon
// azonam
// geeksforgeeks
// geeksgeeksfor

// Output:
// 1
// 0

#include <iostream>
#include <string>
using namespace std;

bool isRotated(string S1, string S2)
{
    string temp1,temp2;
    int len1 = S1.length(),len2 = S2.length();
    if(len1 < 2 || len2 < 2) 
        if(S1 == S2)
            return true;
        else 
            return false;
    temp1.append(S1.substr(2,len1-2));
    temp1.append(S1.substr(0,2));
    
    temp2.append(S1.substr(len1-2,2));
    temp2.append(S1.substr(0,len1-2));
    if(temp1 == S2 || temp2 == S2)
        return true;
    else
        return false;
}



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		cout<<isRotated(s,b)<<endl;
	}
	return 0;
}