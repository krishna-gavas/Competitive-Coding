// 0-1 Knapsack using Top down approach 

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

int Knapsack(int wt[],int val[],int w,int n){
    int DP[n+1][w+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0)
                DP[i][j] = 0;
            else if(wt[i-1] <= j)
                DP[i][j] = max(val[i-1] + DP[i-1][j- wt[i-1]], DP[i-1][j]);
            else 
                DP[i][j] = DP[i-1][j];
        }
    }
    return DP[n][w];
}

int main() {
    int T;
    cin>>T;
    while(T--){
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