// Coin Piles

// Question:
// There are N piles of coins each containing  Ai (1<=i<=N) coins.  Now, you have to adjust the number of coins in 
// each pile such that for any two pile, if a be the number of coins in first pile and b is the number of coins in 
// second pile then |a-b|<=K. In order to do that you can remove coins from different piles to decrease the number 
// of coins in those piles but you cannot increase the number of coins in a pile by adding more coins. Now, given 
// a value of N and K, along with the sizes of the N different piles you have to tell the minimum number of coins 
// to be removed in order to satisfy the given condition.
// Note: You can also remove a pile by removing all the coins of that pile.

// Input  
// The first line of the input contains T, the number of test cases. Then T lines follow. Each test case contains 
// two lines. The first line of a test case contains N and K. The second line of the test case contains N integers 
// describing the number of coins in the N piles.

// Output  
// For each test case output a single integer containing the minimum number of coins needed to be removed in a new line.   

// Example
// Input           
// 3
// 4 0
// 2 2 2 2
// 6 3
// 1 2 5 1 1 1
// 6 3
// 1 5 1 2 5 1

// Output        
// 0
// 1
// 2

// Solution: 
// Initialize remove to INT_MAX, fullpile and otherpile to 0 and sort the array.
// for(i=0 to N): make otherPile = fullPile and fullPile = fullPile + A[i]
//     for(j=N-1 down till j>i):
//         if(A[j]-A[i] > K) then make otherPile = otherPile + (A[j] - A[i] - K)
//     remove = min(remove, otherPile)
// print remove.


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,K,remove=INT_MAX,fullPile=0,otherPile=0;
        cin>>N>>K;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        sort(A,A+N);
        
        for(int i=0;i<N;i++){
            otherPile = fullPile;
            fullPile = fullPile + A[i];
            for(int j=N-1;j>i;j--){
                if(A[j]-A[i] > K)
                    otherPile = otherPile + (A[j] - A[i] - K);
            }
            remove = min(remove, otherPile);
        }
        cout<<remove<<endl;
    }
    return 0;
}
