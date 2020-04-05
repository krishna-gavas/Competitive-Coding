// COVID Pandemic and Long Queue

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,start=0,end=0,flag=0,first=0;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<N;i++){
            if(A[i] == 1){
                if(first == 0)
                    start = i;
                else{
                    end = i;
                    if(abs(end - start) < 6 && start!=end){
                        flag = 1;
                        break;
                    }
                    start = end;
                }
                first = 1;
            }
        }
        if(flag == 1)
            cout<<"NO\n";
        else 
            cout<<"YES\n";
	}
	return 0;
}