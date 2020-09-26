// Target Sum using Top down approach 

// Question: 
// Given an array A and sum s count the number of ways in which + and - are assigned such that we get sum as s 

// Input:
// 1
// 4(N) 1(sum)
// A[] 1 1 2 3
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
        int N,sum=0,s;
        cin>>N>>s;
        int A[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
            sum = sum + A[i];
        }
        int sumS1 = (s + sum)/2;
        cout<<subsetSumCount(A,sumS1,N)<<endl;
    }
}