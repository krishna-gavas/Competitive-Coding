// Implement strstr

// Question:
// Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates 
// the occurrence of the string x in the string s. The function returns and integer denoting the first occurrence 
// of the string x in s (0 based indexing).

// Example 1:
// Input:
// s = GeeksForGeeks, x = Fr
// Output: -1

// Example 2:
// Input:
// s = GeeksForGeeks, x = For
// Output: 5

// Your Task:
// You don't have to take any input. Just complete the strstr() function which takes two strings str, target as an 
// input parameter. The function returns -1 if no match if found else it returns an integer denoting the first 
// occurrence of the x in the string s.

#include <iostream>
#include <string>
using namespace std;

int strstr(string s, string x)
{
     int len = s.length();
     int len1 = x.length();
     int flag;
     for(int i=0;i<len;i++){
         if(s[i] == x[0]){
             flag = 0;
             for(int j=0;j<len1;j++){
                 if(s[i+j] == x[j]){

                 }
                 else{
                     flag = 1;
                     break;
                 }
             }
             if(flag == 0){
                 return i;
             }
         }
     }
     return -1;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string s,x;
        cin>>s>>x;
        int out = strstr(s,x);
        
        cout<<out<<endl;
	}
	return 0;
}