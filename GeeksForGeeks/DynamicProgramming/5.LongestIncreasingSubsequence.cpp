// Longest Increasing Subsequence

// Create a DP[] array to store length of LIS and initialize it with 1
// LIS: initialize len = 1
//     for(i=1 to N)
//         for(j=0 to i-1)
//             if(A[j] < A[i]) then DP[i] = max(DP[i], DP[j]+1)
//         if(DP[i] > len) then len = DP[i]
//     return len


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LIS(int A[],int DP[], int n){
    int len = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(A[j] < A[i]){
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        if(DP[i] > len)
            len = DP[i];
    }
    return len;
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
            DP[i] = 1;
        }
        cout<<LIS(A,DP,N)<<"\n";
	}
	return 0;
}