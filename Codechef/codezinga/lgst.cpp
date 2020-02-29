#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N,Q,flag =0;
	cin>>N>>Q;

    long int d[N],S;
    for(int i=0;i<N;i++)
        cin>>d[i];

    sort(d,d+N);

    for(int i=0;i<Q;i++){
        cin>>S;
        int j;
        for(j=N-1;j>=0;j--){
            if(d[j] <= S){
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout<<-1<<"\n";
        else 
            cout<<d[j]<<"\n";
        cout<<"\n";
    }
    
	
	return 0;
}