// Roman Number to Integer

// Question:
// Given an string in roman no format (s)  your task is to convert it to integer .

// Input:
// The first line of each test case contains the no of test cases T. Then T test cases follow. Each test case 
// contains a string s denoting the roman no.

// Output:
// For each test case in a new line print the integer representation of roman number s. 

// Example:
// Input
// 2
// V
// III 
// Output
// 5
// 3

// Solution:
// Create a map containing roman letters and their corresponding interger values
// for each test case input a string and initialize sum = 0
//     for i=0 to string length do:
//         if( i is last character ) then num = int value of that character and i++
//         else if(int value of ith character < int value of (i+1)th character) then num = int value of (i+1)th - int value of ith character and i+=2
//         else num = int value of that character 
//         sum = sum + num 
//     print sum.


#include <iostream>
#include <string>
#include <map>
using namespace std;

int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends

// User fuunction teemplate for C++
// Returns decimal value of roman numaral
int romanToDecimal(string &S) {
    
    map<char, int> roman;
    roman.insert(pair<char, int>('I', 1));
    roman.insert(pair<char, int>('V', 5));
    roman.insert(pair<char, int>('X', 10));
    roman.insert(pair<char, int>('L', 50));
    roman.insert(pair<char, int>('C', 100));
    roman.insert(pair<char, int>('D', 500));
    roman.insert(pair<char, int>('M', 1000));
    
    int len = S.length(),num,sum=0;
    
    for(int i=0;i<len;){
        if(i == (len-1) || roman[S[i]] >= roman[S[i+1]]){
            num = roman[S[i]];
            i++;
        }
        else{
            num = roman[S[i+1]] - roman[S[i]];
            i = i+2;
        }
        sum = sum + num;
    }
    return sum;
}