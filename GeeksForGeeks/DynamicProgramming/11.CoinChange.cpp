// Coin Change


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
            cout<<DP[i][j]<<" ";
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