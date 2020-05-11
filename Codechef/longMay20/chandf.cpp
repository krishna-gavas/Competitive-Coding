// Chef and Bitwise Product 

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int X,Y,Z=0,L,R,F=0,max=0;
        cin>>X>>Y>>L>>R;

        for(long int i=L;i<=R;i++){
            F = (X & i) * (Y & i);
            cout<<"i: "<<i<<"  F: "<<F<<endl;
            if(F > max){
                max = F;
                Z = i;
            }
        }
        cout<<Z<<"\n";
	}
	return 0;
}