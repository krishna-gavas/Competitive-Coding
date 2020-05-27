// Josephus problem



#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,K,l;
        cin>>N>>K;
        l = N - pow(2,int(log2(N)));
        cout<<2*l+(K-1)<<endl;
    }
    return 0;
}
