// Hard Cash 

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,K;
        cin>>N>>K;
        long int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];

        long int i=0,j,sum=0,want;
        j = N-1;
        want =  K - (A[j] % K);
        while(i<=j){
            if(sum >= want){
                sum = sum - want;
                j--;
                want =  K - (A[j] % K);
            }
            else{
                sum = sum + (A[i] % K);
                i++;
            }
        }
        cout<<sum<<"\n";
	}
	return 0;
}