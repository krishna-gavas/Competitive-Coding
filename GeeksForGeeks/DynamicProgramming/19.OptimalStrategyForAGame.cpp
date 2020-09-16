// Optimal Strategy For A Game

// Question:
// You are given an array A of size N. The array contains integers and is of even length. The elements of the array 
// represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.
// In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, 
// and receives the value of the coin.
// You need to determine the maximum possible amouint of money you can win if you go first.

// Input:
// The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains 
// two lines of input. The first line contains N denoting the size of the array. The second line contains N elements 
// of the array.

// Output:
// For each testcase, in a new line, print the maximum amout.

// Examples:
// Input:
// 2
// 4
// 5 3 7 10
// 4
// 8 15 3 7
// Output:
// 15
// 22

// Solution:
// Create a DP table and fill it diagonally 
// OptimalStrategy(i,j): Here player1 can select either ith number or jth number
//     if player1 selects i then player2 can select either i+1 or j
//         since even player2 is playing optimally we need to consider minimum of OS(i+2,j) and OS(i+1,j-1)
//     if player1 selects j then player2 can select i or j-1
//         so now we need to consider minimum of OS(i+1,j-1) and OS(i,j-2)

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int DP[102][102];

int OptimalStrategy(int A[], int i, int j,int DP[102][102],int n){
    
    if(i<0 || i>=n || j<0 || j>=n)
        return 0;
    if(i+1 == j){
        DP[i][j] = max(A[i], A[j]);
        return DP[i][j];
    }

    if(DP[i][j] != -1)
        return DP[i][j];

    DP[i][j] = max(A[i] + min(OptimalStrategy(A,i+2,j,DP,n),OptimalStrategy(A,i+1,j-1,DP,n)) , A[j] + min(OptimalStrategy(A,i+1,j-1,DP,n),OptimalStrategy(A,i,j-2,DP,n)));
    return DP[i][j];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        memset(DP,-1,sizeof(DP));
        cout<<OptimalStrategy(A,0,N-1,DP,N)<<"\n";
	}
	return 0;
}