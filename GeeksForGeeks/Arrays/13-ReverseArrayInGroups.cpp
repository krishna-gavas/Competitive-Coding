// Reverse array in groups
// calculate quotient,remainder and limit 
// access elements using a window of size K till limit is reached
// while accessing for each window swap first K/2 elements with last K/2 elements
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,K;
	    cin>>N>>K;
	    long long int arr[N];
		long int val=K,q,r,limit;
		q = N/K;
		r = N%K;
		limit = q * K;

	    for(long int i=0;i<N;i++)
	        cin>>arr[i];

		for(long int i=0;i<limit;i=i+val){
			if(i%val == 0 && i != 0)
				K = K + (2*val);
			int lim;
			if(K%2 == 0)
				lim = (K/2) - 1;
			else
				lim = K/2;
			for(int j=i;j<=lim;j++)
				swap(arr[j],arr[K-j-1]);

		}

		if(r != 0){						// for remaining elements(if N is not multiple of K)
			int newlimit = limit + ((N-1-limit)/2);
			int j = N-1;
			for(int i=limit;i<=newlimit;i++)
				swap(arr[i],arr[j--]);
		}

		for(long int i=0;i<N;i++)
	        cout<<arr[i]<<" ";
		
		cout<<endl;
	}
	return 0;
}