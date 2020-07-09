// Coin Piles

// Initialize remove to INT_MAX, fullpile and otherpile to 0 and sort the array.
// for(i=0 to N): make otherPile = fullPile and fullPile = fullPile + A[i]
//     for(j=N-1 down till j>i):
//         if(A[j]-A[i] > K) then make otherPile = otherPile + (A[j] - A[i] - K)
//     remove = min(remove, otherPile)
// print remove.


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,K,bound,remove=INT_MAX,fullPile=0,otherPile=0;
        cin>>N>>K;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        sort(A,A+N);
        
        for(int i=0;i<N;i++){
            otherPile = fullPile;
            fullPile = fullPile + A[i];
            for(int j=N-1;j>i;j--){
                if(A[j]-A[i] > K)
                    otherPile = otherPile + (A[j] - A[i] - K);
            }
            remove = min(remove, otherPile);
        }
        cout<<remove<<endl;
    }
    return 0;
}
