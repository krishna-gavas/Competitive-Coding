// Josephus problem

// Question:
// Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is 
// killed in circle in a fixed direction.â€‹
// The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place 
// in the circle, you are the last one remaining and survive.

// Example 1:
// Input:
// n = 3 k = 2
// Output: 3

// Example 2:
// Input:
// n = 5 k = 3
// Output: 4

// Your Task:
// You don't need to read input or print anything. You are required to complete the function josephus () that takes 
// two parameters n and k and returns an integer denoting safe position.

// josephus(n,k): if(n==1) return n
//     solution to josephus(n,k) is solution to josephus(n-1,k) and sword given to kth person(after skipping (k-1) )

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int josephus(int n, int k)
{
    if(n == 1)
        return n;
    return (josephus(n-1,k) + (k-1))%n +1;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,K,l;
        cin>>N>>K;
        cout<<josephus(N,K)<<endl;
    }
    return 0;
}
