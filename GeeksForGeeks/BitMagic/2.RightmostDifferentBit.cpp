#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int M,N,pos=1;
	    cin>>M>>N;
        if(M == N){
            cout<<-1<<endl;
            continue;
        }
        int mask = 1;
	    while((M & mask) == (N & mask)){
            mask = mask << 1;
            pos++;
        }
		cout<<pos<<endl;
	}
	return 0;
}