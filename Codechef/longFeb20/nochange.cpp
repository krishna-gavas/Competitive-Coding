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
        else{
            int flag2 = 0,sum=0;
            for(int i=N-1;i>0;i--){
                if((D[i] % D[i-1]) != 0){
                    flag2 = 1;
                    sum = sum + ((P/D[i])-1)*D[i];
                    C[i] = (P/D[i])-1;
                    C[i-1] = 0;
                    while(sum < P){
                        sum = sum + D[i-1];
                        C[i-1] = C[i-1] + 1;
                    }
                    pos = i-1;
                    break;
                }
                C[i] = 0;
            }
            if(flag2 == 0)
                cout<<"NO"<<endl;
            else{
                cout<<"YES ";
                for(int i=0;i<pos;i++)
                    cout<<0<<" ";
                for(int i=pos;i<N;i++)
                    cout<<C[i]<<" ";
                cout<<endl;
            }
        }
	}
	return 0;
}