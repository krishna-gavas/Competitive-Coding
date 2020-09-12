// Coin Change

// Question:
// Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of 
// S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, 
// there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, 
// there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

// Input: 
// The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first 
// line contains an integer 'M' denoting the size of array. The second line contains M space-separated integers 
// A1, A2, ..., AN denoting the elements of the array. The third line contains an integer 'N' denoting the cents.

// Output:
// Print number of possible ways to make change for N cents.

// Example:
// Input:
// 2
// 3
// 1 2 3
// 4
// 4
// 2 5 3 6
// 10

// Output:
// 4
// 5

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int CoinChange(int coin[],int sum, int N){
    int DP[N+1][sum+1];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 && j!= 0)
                DP[i][j] = 0;
            else if(j == 0)
                DP[i][j] = 1;
            else if(coin[i-1] <= j)
                DP[i][j] = (DP[i][j - coin[i-1]]) + DP[i-1][j];
            else 
                DP[i][j] = DP[i-1][j];
            // cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
    return DP[N][sum];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,sum;
        cin>>N;
        int coin[N];
        for(int i=0;i<N;i++)
            cin>>coin[i];
        cin>>sum;
        cout<<CoinChange(coin,sum,N)<<"\n";
	}
	return 0;
}