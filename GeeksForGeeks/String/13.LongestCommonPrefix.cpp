// Longest Common Prefix in an Array

// Question:
// Given a array of N strings, find the longest common prefix among all strings present in the array.

// Input:
// The first line of the input contains an integer T which denotes the number of test cases to follow. Each test 
// case contains an integer N. Next line has space separated N strings.

// Output:
// Print the longest common prefix as a string in the given array. If no such prefix exists print 
// "-1"(without quotes).

// Example:
// Input:
// 2
// 4
// geeksforgeeks geeks geek geezer
// 3
// apple ape april

// Output:
// gee
// ap

// Solution:
// Initialize count=0, flag=0, min=1000 and input N.
// input array of strings and also find string with minimum length and store it in str and its length in min.
// for(i=0 to min):
//     for(j=0 to N): if(arr[j][i] != str[i]) then flag=1 and break from loop 
//     increment count
// if count = 0 then print -1 else print str.substr(0,count)


#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,count=0,flag=0,min=1000;
        cin>>N;
        string arr[N],str;
        for(int i=0;i<N;i++){
            cin>>arr[i];
            int len = arr[i].length();
            if(len < min){
                min = len;
                str = arr[i];
            }
        }
        
        for(int i=0;i<min;i++){
            for(int j=0;j<N;j++){
                if(arr[j][i] == str[i]){
                    // Nothing here
                }
                else{
                    flag = 1;
                    break;
                }               
            }
            if(flag == 1)
                break;
            count++;
        }
        if(count==0)
            cout<<-1<<endl;
        else
            cout<<str.substr(0,count)<<endl;
           
	}
	return 0;
}