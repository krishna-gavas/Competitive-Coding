// Trapping Rain Water

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[N],left[N],right[N];
        int water=0,lmax=0,rmax=0;

	    for(int i=0;i<N;i++)
	        cin>>arr[i];

        for(int i=1;i<N-1;i++){
            if(arr[i-1] > lmax)
                lmax = arr[i-1];
            left[i] = lmax;
        }
        int lim = N-2;
        for(int i=lim;i>0;i--){
            if(arr[i+1] > rmax)
                rmax = arr[i+1];
            right[i] = rmax;
        }

        for(int i=1;i<N-1;i++){
            if((left[i] <= right[i]) && (left[i] >= arr[i]))
                water = water + (left[i] - arr[i]);
            else if((left[i] > right[i]) && (right[i] >= arr[i]))
                water = water + (right[i] - arr[i]);
        }
        
		cout<<water<<endl;
		
	}
	return 0;
}