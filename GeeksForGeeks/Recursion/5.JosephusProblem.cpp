// Josephus problem

// josephus(n,k): if(n==1) return n
//     solution to josephus(n,k) is solution to josephus(n-1,k) and sword given to kth person(after skipping (k-1) )

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int josephus(int n, int k)
{
    if(n == 1)
        return n;
    return (josephus(n-1,k) + (k-1))%n +1;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,K,l;
        cin>>N>>K;
        cout<<josephus(N,K)<<endl;
    }
    return 0;
}
