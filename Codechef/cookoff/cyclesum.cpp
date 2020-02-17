#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    long int arr[N],sum[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];

        for(int j=0;j<N;j++){
            int lim = (j+N-1) % N;
            int lmax=0,gmax=0,count=0;
            int i = j;
        
            while(count < N){
                if(i==j && arr[i]<0){
                    lmax = arr[j];
                    gmax = arr[j];
                }			
                if(arr[i] > (arr[i] + lmax))
                    lmax = arr[i];
                else
                    lmax = arr[i] + lmax;

                if(lmax > gmax)
                    gmax = lmax;
                if(i==lim)
                    break;
                i = (i+1) % N;
                count++;
            }

            cout<<gmax<<" ";
            
        }
        cout<<endl;
		
	}
	return 0;
}