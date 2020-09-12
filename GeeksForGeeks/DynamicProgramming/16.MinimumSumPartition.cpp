// Minimum sum partition

// Question:
// Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their 
// sums is minimum.

// Input:
// The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first 
// line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers 
// A1, A2, ..., AN denoting the elements of the array.

// Output:
// In each seperate line print minimum absolute difference.

// Example:
// Input:
// 2
// 4
// 1 6 5 11
// 4
// 36 7 46 40

// Output: 
// 1
// 23

// Solution:
// MinimumSumPartition: create a vector lastrow and initialize minSum to INT_MAX
//     call SubsetSum(A,N,sum) and store its return value in lastrow vector
//     for(i=0 to (lastrow.size()/2))
//         if(lastrow[i] == true) then minSum = min(minSum, abs(sum - (2*i)))
//     return minSum

// SubsetSum: Create a DP table of size N+1 by sum+1 and a vector named lastrow
//     for(i=0 to N+1)
//         for(j=0 to sum+1)
//             initialize first row with false and first column with true
//             if(A[i-1] <= j) then DP[i][j] = (DP[i-1][j - A[i-1]]) || DP[i-1][j]
//             else DP[i][j] = DP[i-1][j]
//             if(i is last row ) then push DP[i][j] to lastrow vector
//     return lastrow

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