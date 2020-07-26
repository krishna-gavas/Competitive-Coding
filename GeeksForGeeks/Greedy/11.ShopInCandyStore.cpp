// Shop in Candy Store



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,K,minAmt=0,maxAmt=0;
        cin>>N>>K;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        sort(A,A+N);
        for(int i=0;i<N;i++)
            cout<<A[i]<<" ";
        cout<<endl;
        minAmt += A[0];
        maxAmt += A[N-1];
        for(int i=1;i<N-K;i++)
            minAmt += A[i];

        for(int i=N-2;i> K; i--)
            maxAmt += A[i];

        cout<<minAmt<<" "<<maxAmt<<"\n";
    }
    return 0;
}
