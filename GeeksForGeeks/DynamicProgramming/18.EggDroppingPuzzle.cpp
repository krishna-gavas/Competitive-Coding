// Egg Dropping Puzzle

// Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such 
// that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical 
// floor in the worst case while using the best strategy.There are few rules given below. 

// An egg that survives a fall can be used again.
// A broken egg must be discarded.
// The effect of a fall is the same for all eggs.
// If the egg doesn't break at a certain floor, it will not break at any floor below.
// If the eggs breaks at a certain floor, it will break at any floor above.
// For more description on this problem see wiki page

// Input:
// The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive 
// integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

// Output:
// For each test case, print a single line containing one integer the minimum number of attempt you need in order 
// find the critical floor.

// Example:
// Input:
// 2
// 2 10
// 3 5

// Output:
// 4
// 3

// Solution:
// EggDropping: 
//     Base case: if either eggs are zero or there are 0 or 1 floors then store f in DP[e][f] abd return DP[e][f]
//     if DP[e][f] is already updated then return DP[e][f]
//     initialize attempts to INT_MAX 
//     for(k=1 to f): 
//         store DP[e-1][k-1] = EggDropping(e-1,k-1) and DP[e][f-k] = EggDropping(e,f-k)
//         temp = 1 + max(DP[e-1][k-1], DP[e][f-k])
//         attempts = min(attempts, temp)
//     return attempts

#include <iostream>
#include <climits>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int DP[100][100];

int EggDropping(int e,int f){
    if(e == 1 || f == 0 || f == 1){
        DP[e][f] = f;
        return DP[e][f];
    }
    if(DP[e][f] != -1)
        return DP[e][f];
    
    int attempts = INT_MAX;
    for(int k=1;k<=f;k++){
        if(DP[e-1][k-1] == -1)
            DP[e-1][k-1] = EggDropping(e-1,k-1);
        if(DP[e][f-k] == -1)
            DP[e][f-k] = EggDropping(e,f-k);
        int temp = 1 + max(DP[e-1][k-1], DP[e][f-k]);
        attempts = min(attempts, temp);
    }
    return attempts;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
        cin>>N>>K;
        memset(DP,-1,sizeof(DP));
        cout<<EggDropping(N,K)<<"\n";
	}
	return 0;
}