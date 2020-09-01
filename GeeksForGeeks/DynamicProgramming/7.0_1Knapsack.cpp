// 0-1 Knapsack

// Create a DP table and initialize it with -1
// Knapsack:
//     if(N==0 || W==0) return 0
//     if(DP[N][W] != -1) i.e. if DP table entry is updated then return DP[N][W]
//     if(wt[N-1] <= W) then DP[N][W] = max(Knapsack(including item N-1), Knapsack(excluding item N-1))
//         return DP[N][W]
//     else DP[N][W] = Knapsack(excluding item N-1)
//         return DP[N][W]

#include <iostream>
#include <string.h> //For memset function
#include <algorithm>
using namespace std;

int DP[1001][1001];

int Knapsack(int val[],int wt[],int W,int N){
    if(N==0 || W==0)
        return 0;
    if(DP[N][W] != -1)
        return DP[N][W];
    if(wt[N-1] <= W){
        DP[N][W] = max(val[N-1]+Knapsack(val,wt,W-wt[N-1],N-1), Knapsack(val,wt,W,N-1));
        return DP[N][W];
    }
    else{
        DP[N][W] = Knapsack(val,wt,W,N-1);
        return DP[N][W];
    }    
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,W;
        cin>>N>>W;
        int val[N],wt[N];
        for(int i=0;i<N;i++)
            cin>>val[i];
        for(int i=0;i<N;i++)
            cin>>wt[i];
        memset(DP,-1,sizeof(DP));
        cout<<Knapsack(val,wt,W,N)<<"\n";
	}
	return 0;
}