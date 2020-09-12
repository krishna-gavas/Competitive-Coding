// Subset Sum Problem

// SubsetSum: Create a DP table of size N+1 by sum+1
//     for(i=0 to N+1)
//         for(j=0 to sum+1)
//             initialize first row with false and first column with true
//             if(A[i-1] <= j) then DP[i][j] = (DP[i-1][j - A[i-1]]) || DP[i-1][j]
//             else DP[i][j] = DP[i-1][j]
//     return DP[N][sum]


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int SubsetSum(int A[],int sum, int N){
    bool DP[N+1][sum+1];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 && j!= 0)
                DP[i][j] = false;
            else if(j == 0)
                DP[i][j] = true;
            else if(A[i-1] <= j)
                DP[i][j] = (DP[i-1][j - A[i-1]]) || DP[i-1][j];
            else 
                DP[i][j] = DP[i-1][j];
        }
    }
    return DP[N][sum];
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
            sum += A[i];
        }
        if(sum%2 == 1)
            cout<<"NO\n";
        else{
            if(SubsetSum(A,sum/2,N) == true)
                cout<<"YES\n";
            else 
                cout<<"NO\n";
        }
	}
	return 0;
}