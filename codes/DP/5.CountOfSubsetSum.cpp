// Count of subsets with a given sum using Top down approach 

// Question: 
// Given an array A and sum s count the number od subsets whose sum is s

// Input:
// 1
// 6(N) 10(sum)
// A[] 2 3 5 6 8 10
// Output: 
// 3

#include <iostream>
#include <algorithm>
using namespace std;

int subsetSumCount(int A[],int sum,int n){
    int DP[n+1][sum+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 && j!=0)
                DP[i][j] = 0;
            else if(j==0)
                DP[i][j] = 1;
            else if(A[i-1] <= j)
                DP[i][j] = DP[i-1][j- A[i-1]] +  DP[i-1][j];
            else 
                DP[i][j] = DP[i-1][j];
        }
    }
    return DP[n][sum];
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,sum;
        cin>>N>>sum;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];

        cout<<subsetSumCount(A,sum,N)<<endl;
    }
}