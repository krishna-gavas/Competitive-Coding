// Equal sum partition problem using Top down approach 

// Question: 
// Given an array A check whether the array contains 2 partitions whose sum are equal

// Input:
// 1
// 4(N)
// A[] 1 5 11 5
// Output: 
// 1

// Solution:
// Calculate the sum of the array as sum
// if the sum is odd then the array can't be divided into equal sum partitions 
// else call subsetSum() with sum as sum/2;

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
        int N,sum=0;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
            sum = sum + A[i];
        }
        if(sum % 2 == 1)
            cout<<false<<endl;
        else 
            cout<<subsetSum(A,sum/2,N)<<endl;
    }
}