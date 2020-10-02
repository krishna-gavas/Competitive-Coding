// Largest number possible

// Question:
// Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of 
// digits should be equals to 'S'.

// Example 1:
// Input: N = 2, S = 9
// Output: 90

// Example 2:
// Input: N = 3, S = 20
// Output: 992

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function findLargest() which takes 
// N and S as input parameters and returns the largest possible number. Return -1 if no such number is possible.

// Solution:
// if(S > N*9 or (S is 0 and N > 1)) then print -1.
// else 
//     while(S >= 0 && N > 0): if(S/10 > 0) then print 9 and subtract 9 from S.
//         else print (S % 10) and subtract (S % 10) from S.
//         decrement N;

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,S;
        cin>>N>>S;
        if(S > N*9 || (S == 0 && N > 1))
            cout<<-1;
        else{
            while(S >= 0 && N > 0){
                if(S/10 > 0){
                    cout<<9;
                    S = S - 9;
                }
                else{
                    cout<<S % 10;
                    S = S - (S % 10);
                }
                N--;
            }
        }
        cout<<endl;
    }
    return 0;
}
