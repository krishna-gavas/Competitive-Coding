// No Change required 

#include <iostream>
using namespace std;

long int bee(long long int n,char g){
    if((n==1 || n==2 || n==3) && g=='m')
        return n;
    if((n==1 || n==2) && g=='f')
        return n+1;
    if(g =='m')
        return (2*n)-3;
    else
        return (2*n)-1;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    long long int N,out;
        char G;
        cin>>G>>N;

        out = bee(N,G);
        cout<<out<<endl;
        
	}
	return 0;
}