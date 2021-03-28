// Implement Atoi

// Question:
// Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to 
// an integer and returns it.

// Example 1:
// Input:
// str = 123
// Output: 123

// Example 2:
// Input:
// str = 21a
// Output: -1

// Your Task:
// Complete the function atoi() which takes a string as input parameter and returns integer value of it. if the 
// input string is not a numerical string then returns 1..

#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
    int atoi(string S)
    {
        int sign=0,len = S.length();
        long int out;
        for(int i=0;i<len;i++){
            if(i==0 && S[i] == 45){
                sign = 1;
                continue;
            }
            if(S[i] >= '0' && S[i] <= '9'){
                if(i==0)
                    out = S[i] - 48;
                else{
                    out = out*10;
                    out = out + (S[i] - 48);
                }
            }
            else{
                return -1;
            }
        }
        if(sign == 1)
            out = 0 - out;
        return out;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
} 