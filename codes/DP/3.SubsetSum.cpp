// Subset using Top down approach 

// Question: 
// Given an array A and sum s check whether the array contains a subset whose sum is s

// Input:
// 1
// 5(N) 11(sum)
// A[] 2 3 7 8 10
// Output: 
// 1

#include <iostream>
#include <algorithm>
using namespace std;

int subsetSum(int A[],int sum,int n){
    bool DP[n+1][sum+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 && j!=0)
                DP[i][j] = false;
            else if(j==0)
                DP[i][j] = true;
            else if(A[i-1] <= j)
                DP[i][j] = DP[i-1][j- A[i-1]] ||  DP[i-1][j];
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

        bool contains = subsetSum(A,sum,N);
        cout<<contains<<endl;
    }
}