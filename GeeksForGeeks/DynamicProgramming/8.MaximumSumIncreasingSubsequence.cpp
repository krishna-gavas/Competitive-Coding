// Maximum sum increasing subsequence

// Create a DP[] array to store length of LIS and initialize it with A[i]
// MSIS: initialize len = A[0]
//     for(i=1 to N) initialize val = DP[i]
//         for(j=0 to i-1)
//             if(A[j] < A[i]) then DP[i] = max(DP[i], val+DP[j])
//         if(DP[i] > len) then len = DP[i]
//     return len


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int MSIS(int A[],int DP[], int n){
    int len = A[0];
    for(int i=1;i<n;i++){
        int val = DP[i];
        for(int j=0;j<i;j++){
            if(A[j] < A[i]){
                DP[i] = max(DP[i],val+DP[j]);
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
            DP[i] = A[i];
        }
        cout<<MSIS(A,DP,N)<<"\n";
	}
	return 0;
}