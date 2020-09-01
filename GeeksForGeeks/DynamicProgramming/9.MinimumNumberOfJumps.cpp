// Minimum number of jumps

// Create a DP[] array and initialize it with INT_MAX
// MinJumps: initialize DP[0]=0
//     for(i=1 to n)
//         for(j=0 to i-1)
//             if(j+A[j] reaches i && DP[j] != INT_MAX) then DP[i] = min(DP[i], DP[j]+1)
//     if(DP[n-1] == INT_MAX) then return -1
//     return DP[n-1]

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int MinJumps(int A[],int DP[], int n){
    DP[0] = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(i <= j + A[j] && DP[j] != INT_MAX){
                DP[i] = min(DP[i], DP[j]+1);
            }
        }
    }
    if(DP[n-1] == INT_MAX)
        return -1;
    return DP[n-1];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
        cin>>N;
        int A[N],DP[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
            DP[i] = INT_MAX;
        }
        cout<<MinJumps(A,DP,N)<<"\n";
	}
	return 0;
}