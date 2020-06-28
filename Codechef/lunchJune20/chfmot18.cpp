// Chef and Demonetisation 

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int S,N,count=0,coin;
        cin>>S>>N;
        coin = N;
        while(S > 0){
            if(S == 1){
                count++;
                break;
            }
            while(coin > S)
                coin = coin-2;
            count = count + (S/coin);
            S = S % coin;
        }
        cout<<count<<"\n";
    }
}

