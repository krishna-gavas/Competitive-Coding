#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,tax=0,bal,amt,net;
	    cin>>N;

        bal = N;

        if(bal > 1500000){
            amt = bal - 1500000;
            tax = tax + (amt*3)/10;
            bal = 1500000;
        }
        if(bal > 1250000){
            amt = bal - 1250000;
            tax = tax + (amt*25)/100;
            bal = 1250000;
        }
        if(bal > 1000000){
            amt = bal - 1000000;
            tax = tax + (amt*2)/10;
            bal = 1000000;
        }
        if(bal > 750000){
            amt = bal - 750000;
            tax = tax + (amt*15)/100;
            bal = 750000;
        }
        if(bal > 500000){
            amt = bal - 500000;
            tax = tax + (amt*1)/10;
            bal = 500000;
        }
        if(bal > 250000){
            amt = bal - 250000;
            tax = tax + (amt*5)/100;
            bal = 250000;
        }

        net = N - tax;
        cout<<net<<endl;   
		
	}
	return 0;
}