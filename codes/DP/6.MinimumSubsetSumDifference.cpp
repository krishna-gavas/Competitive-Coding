// Minimum sum partition

// Question:
// Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between 
// their sums is minimum.

// Input:
// 2
// 4
// 1 6 5 11
// 4
// 36 7 46 40
// Output: 
// 1
// 23

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> SubsetSum(int A[],int n, int sum){
    bool DP[n+1][sum+1];
    vector<bool> lastrow;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 && j!= 0)
                DP[i][j] = false;
            else if(j == 0)
                DP[i][j] = true;
            else if(A[i-1] <= j)
                DP[i][j] = (DP[i-1][j - A[i-1]]) || DP[i-1][j];
            else 
                DP[i][j] = DP[i-1][j];
            if(i==n)
                lastrow.push_back(DP[i][j]);
        }
    }
    return lastrow;
}

int MinimumSumPartition(int A[], int N, int sum){
    vector<bool> lastrow;
    int minSum = INT_MAX;
    lastrow = SubsetSum(A,N,sum);
    for(int i=0;i<(lastrow.size()/2)+1;i++){
        if(lastrow[i] == true)
            minSum = min(minSum, abs(sum - (2*i)));
    }
    return minSum;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,sum=0;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
            sum = sum + A[i];
        }
        cout<<MinimumSumPartition(A,N,sum)<<"\n";
	}
	return 0;
}