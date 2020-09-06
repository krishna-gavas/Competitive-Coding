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

int main() {
	int T;
	cin>>T;
    map<char, int> roman;
    roman.insert(pair<char, int>('I', 1));
    roman.insert(pair<char, int>('V', 5));
    roman.insert(pair<char, int>('X', 10));
    roman.insert(pair<char, int>('L', 50));
    roman.insert(pair<char, int>('C', 100));
    roman.insert(pair<char, int>('D', 500));
    roman.insert(pair<char, int>('M', 1000));

	while(T--){
	    string str1;
        cin>>str1;
        int len = str1.length(),num,sum=0;

        for(int i=0;i<len;){
            if(i == (len-1)){
                num = roman[str1[i]];
                i++;
            }
            else if(roman[str1[i]] < roman[str1[i+1]]){
                num = roman[str1[i+1]] - roman[str1[i]];
                i = i+2;
            }
            else{
                num = roman[str1[i]];
                i++;
            }
            sum = sum + num;
        }

        cout<<sum<<endl;
	}
	return 0;
}