// Chef in Fantasy League

#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
	    int N,S,dmin=999999,fmin=999999;
        cin>>N>>S;
        int P[N],R[N];
        int sum = 100 - S;
        for(int i=0;i<N;i++)
            cin>>P[i];
        for(int i=0;i<N;i++){
            cin>>R[i];
            if(R[i] == 0 && P[i] < dmin)
                dmin = P[i];
            else if(R[i] == 1 && P[i] < fmin)
                fmin = P[i];
        }
        if(dmin + fmin <= sum)
            cout<<"yes\n";
        else 
            cout<<"no\n";

    }
	return 0;
}