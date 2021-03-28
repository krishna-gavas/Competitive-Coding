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

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     int lenS = s.length();
     int lenX = x.length();
     int flag;
     for(int i=0;i<lenS;i++){
         if(s[i] == x[0]){
             flag = 0;
             for(int j=0;j<lenX;j++){
                 if(s[i+j] != x[j]){
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