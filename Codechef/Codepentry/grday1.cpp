// Group Recreation

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,X,P;
        char dir,lan,L;
        cin>>N>>X;
        cin>>dir>>lan;
        if(dir == 'L')
            P = X;
        else if(dir == 'R')
            P = (N - X) + 1;

        if(P%2 == 1)
            L = lan;
        else{
            if(lan == 'H')
                L = 'E';
            else if(lan == 'E')
                L = 'H';
        }
        cout<<P<<" "<<L<<"\n";
	}
	return 0;
}