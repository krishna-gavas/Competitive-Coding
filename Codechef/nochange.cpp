// No Change required 

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,P,flag=0,q,r,d,pos;
        cin>>N>>P;
        long int D[N];
        int C[N];
        for(int i=0;i<N;i++){
            cin>>D[i];
            if((P % D[i]) != 0)
                flag = 1;
        }

        if(flag == 1){
            for(int i=0;i<N;i++){
                if((P % D[i]) != 0){
                    q = P / D[i];
                    d = (q+1) * (D[i]) - P;
                    C[i] = q+1;
                    pos = i;
                    break;
                }
                else
                    C[i] = 0;
            }
            cout<<"YES ";
            for(int i=0;i<=pos;i++)
                cout<<C[i]<<" ";
            for(int i=pos+1;i<N;i++)
                cout<<0<<" ";
            cout<<endl;
        }
        else
            cout<<"NO"<<endl;
	}
	return 0;
}