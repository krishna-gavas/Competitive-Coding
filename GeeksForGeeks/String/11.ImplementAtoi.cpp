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

long int Atoi(string str){
    int flag=0,len = str.length();
    long int out;
    for(int i=0;i<len;i++){
        if(i==0 && str[i] == 45){
            flag = 1;
            continue;
        }
        if(str[i] >= '0' && str[i] <= '9'){
            if(i==0)
                out = str[i] - 48;
            else{
                out = out*10;
                out = out + (str[i] - 48);
            }
        }
        else{
            return -1;
        }
    }
    if(flag == 1)
        out = 0 - out;
    return out;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str;
        cin>>str;
        long int out = Atoi(str);
        
        cout<<out<<endl;
	}
	return 0;
}