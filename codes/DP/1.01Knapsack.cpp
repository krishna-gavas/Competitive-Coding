// 0-1 Knapsack using recursive approach with memoization

// Input:
// 1
// 4(N) 7(W)
// wt[] 1 3 4 5
// val[] 1 4 5 7
// Output: 
// 9

#include <iostream>
#include <algorithm>
using namespace std;

int DP[101][101];

int Knapsack(int wt[],int val[],int w,int n){
    if(n == 0 || w == 0)
        return 0;
    if(DP[n][w] != -1)
        return DP[n][w];
    if(wt[n-1] <= w){
        DP[n][w] = max(val[n-1] + Knapsack(wt,val,w-wt[n-1],n-1), Knapsack(wt,val,w,n-1));
        return DP[n][w];
    }
    else{
        DP[n][w] = Knapsack(wt,val,w,n-1);
        return DP[n][w];
    }
}

int main() {
    int T;
    cin>>T;
    while(T--){
        memset(DP,-1,sizeof(DP));
        int N,W,maxProfit;
        cin>>N>>W;
        int wt[N],val[N];
        for(int i=0;i<N;i++)
            cin>>wt[i];
        for(int i=0;i<N;i++)
            cin>>val[i];

        maxProfit = Knapsack(wt,val,W,N);
        cout<<maxProfit<<endl;
    }
}