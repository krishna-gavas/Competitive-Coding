// Longest Palindrome in a String(Manacher's Algorithm)

// Question:
// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 
// 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome 
// if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

// Input:
// The first line of input consists number of the testcases. The following T lines consist of a string each.

// Output:
// In each separate line print the longest palindrome of the string given in the respective test case.

// Example:
// Input:
// 1
// aaaabbaa

// Output:
// aabbaa

// Solution:
// Create an array T to store string aba as $#a#b#a#@ and create another array P to store palindrome count at every character of T.
// Manacher's Algorithm: initialize Centre C=1, Right boundary R = 1 and maxlen = 0.
//     for(i=1 to n-1): mirror_of_i = 2*C -i.
//         if(i < R(i.e i lies within the boundary)) then P[i] = min(R-i, P[mirr])
//         while(T[i + (1+P[i])] == T[i - (1+P[i])]) increment P[i].
//         if(P[i] > maxlen) then maxlen = P[i].
//         if(i + P[i] > R) then update the centre C = i and also update right boundary R = i + P[i].
//     for(i=0 to n)(this is required to get the first occurence):
//         if(P[i] == maxlen):
//             if(i is odd) then l = (i-2)/2 and l = l - (maxlen/2 - 1) else l = (i-2)/2 - maxlen/2.
//             break from the loop.
//     print substring of str from l upto maxlen count.


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str;
        cin>>str;
        int len = str.length();
        if(len < 2){
            cout<<str<<endl;
            continue;
        }
        vector<char> T;
        T.push_back('$');
        T.push_back('#');
        int n=2,C=1,R=1,maxlen = 0;
        for(int i=0;i<len;i++){
            T.push_back(str[i]);
            T.push_back('#');
            n += 2;
        }
        T.push_back('@');
        n++;
        int P[n];
        for(int i=0;i<n;i++)
            P[i] = 0;

        for(int i=1;i<n-1;i++){
            int mirr = 2*C -i;
            if(i < R)
                P[i] = min(R-i, P[mirr]);
            
            while(T[i + (1+P[i])] == T[i - (1+P[i])])
                P[i]++;

            if(P[i] > maxlen)
                maxlen = P[i];
            if(i + P[i] > R){
                C = i;
                R = i + P[i];
            }
        }
        int l;
        for(int i=0;i<n;i++){
            if(P[i] == maxlen){
                if(i%2 == 1){
                    l = (i-2)/2;
                    l = l - (maxlen/2 - 1);
                }
                else{
                    l = (i-2)/2 - maxlen/2;
                }
                break;
            }
        }
        cout<<str.substr(l,maxlen)<<endl;
	}
	return 0;
}