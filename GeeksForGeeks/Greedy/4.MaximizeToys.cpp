// Maximize Toys

// Initialize cost and count to 0.
// Sort the array A.
// for(i=0 to N): if(cost > K) then break out of the loop. 
//     increase cost as cost + A[i] and increment count. 
// print count.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,K,cost=0,count=0;
        cin>>N>>K;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        sort(A,A+N);
        
        for(int i=0;i<N;i++){
            if(cost > K)
                break;
            cost = cost + A[i];
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
