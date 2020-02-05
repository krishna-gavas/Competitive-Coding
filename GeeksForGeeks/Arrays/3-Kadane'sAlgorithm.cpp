#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,lmax=0,gmax=0;
	    cin>>N;
	    long int arr[N];
	    for(long int i=0;i<N;i++)
	        cin>>arr[i];

		for(long int i=0;i<N;i++){
			if(i==0 && arr[i]<0){
				lmax = arr[0];
				gmax = arr[0];
			}
			
			if(arr[i] > (arr[i] + lmax))
				lmax = arr[i];
			else
				lmax = arr[i] + lmax;

			if(lmax > gmax)
				gmax = lmax;
		}

		cout<<gmax<<endl;
		
	}
	return 0;
}