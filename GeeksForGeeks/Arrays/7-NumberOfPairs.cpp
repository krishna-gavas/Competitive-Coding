// Number of pairs

#include <iostream>
#include <algorithm>
using namespace std;

long int upperBound(long int A,long int B[],long int N){
	long int L = 0;
	long int R = N-1;	
	while(L < R){
		long int mid = (L+R)/2;
		if((A < B[mid]) && A > B[mid - 1])
		    return mid;
		else if((A < B[mid]) && A < B[mid - 1])
			R = mid - 1;
		else
			L = mid + 1;
	}
	return L;
}

int main() {
	long int T;
	cin>>T;
	while(T--){
	    long long int M,N;
	    cin>>M>>N;
	    long int X[M],Y[N],freq[5]={0},count=0;

	    for(long int i=0;i<M;i++)
	        cin>>X[i];

		for(long int i=0;i<N;i++){
	        cin>>Y[i];
			if(Y[i]<5)
        		freq[Y[i]]++;
		}
		sort(Y,Y+N);

		for(long int i=0;i<M;i++){
			long int pos =0;
			if(X[i] == 0)
				continue;
			if(X[i] == 1){
				count = count + freq[0];
				continue;
			}


			pos = upperBound(X[i],Y,N);
			if(X[i] < Y[pos])
				count = count + N - pos;
			else
				count = count + 1;

			count = count + freq[0] + freq[1];

			if(X[i] == 2)
				count = count - (freq[3] + freq[4]);
			if(X[i] == 3)
				count = count + freq[2];

		}

		cout<<count<<endl;

		
	}
	return 0;
}