// Chef and Price Control

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,K,lost=0;
        cin>>N>>K;
        int P[N];
        for(int i=0;i<N;i++){
            cin>>P[i];
            if(P[i] > K)
                lost += (P[i] - K);
        }
        cout<<lost<<"\n";
	}
	return 0;
}