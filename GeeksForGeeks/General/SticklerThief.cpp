//Based on DP
#include <iostream>
using namespace std;

int main() {
	int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int A[N];
        for(int i = 0 ; i < N ; i++)
            cin >> A[i];
        int DP[N];
        DP[0] = A[0];
        DP[1] = max(A[0],A[1]);
        for(int i=2;i<N;i++)
            DP[i] = max(DP[i-2]+A[i],DP[i-1]);
        cout<<DP[N-1]<<"\n";
    }
	return 0;
}