// Minimum number of Coins

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,count=0;
        cin>>N;
        while(N > 2000){
            cout<<2000<<" ";
            N = N - 2000;
        }
        while(N > 500){
            cout<<500<<" ";
            N = N - 500;
        }
        while(N > 200){
            cout<<200<<" ";
            N = N - 200;
        }
        while(N > 100){
            cout<<100<<" ";
            N = N - 100;
        }
        while(N > 50){
            cout<<50<<" ";
            N = N - 50;
        }
        while(N > 20){
            cout<<20<<" ";
            N = N - 20;
        }
        while(N > 10){
            cout<<10<<" ";
            N = N - 10;
        }
        while(N > 5){
            cout<<5<<" ";
            N = N - 5;
        }
        while(N > 2){
            cout<<2000<<" ";
            N = N - 2;
        }
        while(N > 1){
            cout<<1<<" ";
            N = N - 1;
        }
        cout<<"\n";
	}
	return 0;
}