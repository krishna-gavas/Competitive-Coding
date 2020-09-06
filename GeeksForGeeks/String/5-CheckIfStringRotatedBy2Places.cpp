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

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str1,str2,temp;
        cin>>str1;
        cin>>str2;
        int len1 = str1.length(),len2 = str2.length();
        int flag = 0;
 
        temp.append(str1.substr(2,len1-2));
        temp.append(str1.substr(0,2));
        if(temp == str2)
            flag=1;
        else{
            temp.clear();
            temp.append(str1.substr(len1-2,2));
            temp.append(str1.substr(0,len1-2));
            if(temp == str2)
                flag=1;
        }

        if(flag == 1)
            cout<<1<<endl;
        else
            cout<<0<<endl;
	}
	return 0;
}