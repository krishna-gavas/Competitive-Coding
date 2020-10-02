// Shop in Candy Store

// Question:
// In a candy store there are N different types of candies available  and the prices of all the N different types of 
// candies are provided to you.
// You are now provided with an attractive offer.
// You can buy a single candy from the store and get atmost K other candies ( all are different types ) for free.
// Now you have to answer two questions. Firstly, you have to tell what is the minimum amount of money you have to 
// spend to buy all the N different candies. Secondly, you have to tell what is the maximum amount of money you 
// have to spend to buy all the N different candies.
// In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.
 
// Input  
// The first line of the input contains T the number of test cases. Each test case consists of two lines. The first 
// line of each test case contains the values of N and K as described above.  Then in the next line N integers 
// follow denoting the price of each of the N different candies.

// Output 
// For each test case output a single line containing 2 space separated integers , the first denoting the minimum 
// amount of money required to be spent and the second denoting the maximum amount of money to be spent.
// Remember to output the answer of each test case in a new line.

// Example:
// Input    
//  1
//  4  2
//  3 2 1 4

// Output 
//  3 7

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,K,minAmt,maxAmt;
        cin>>N>>K;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        sort(A,A+N);
        
        minAmt = A[0];
        maxAmt = A[N-1];
        int temp1 = N-K;
        int temp2 = K;
        for(int i=1;i<temp1;i++){
            minAmt += A[i];
            temp1 = temp1 - K;
        }

        for(int i=N-2;i>= temp2; i--){
            maxAmt += A[i];
            temp2 = temp2 + K;
        }

        cout<<minAmt<<" "<<maxAmt<<"\n";
    }
    return 0;
}

