// Kadane's Algorithm to find maximum subarray sum

// Initialize localmax and globalmax to 0.
// for(i=0 to N):
// 	if(i==0 && arr[i]<0) then localmax = globalmax = arr[0].
// 	if(arr[i] > arr[i] + localmax) then localmax = arr[i] else localmax = arr[i] + localmax.
// 	if(localmax > globalmax) then globalmax = localmax.
// print globalmax

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