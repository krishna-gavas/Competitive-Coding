// Chef Wars - Return of the Jedi  

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int H,P;
        cin>>H>>P;
        while(H > 0 && P > 0){
			H = H - P;
			P = P/2;
		}
		if(H > 0)
			cout<<0<<"\n";
		else if(P > 0)
			cout<<1<<"\n";
		else 
			cout<<1<<"\n";
	}
	return 0;
}