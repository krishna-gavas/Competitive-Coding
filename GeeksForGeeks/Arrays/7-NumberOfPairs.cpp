// Number of pairs

// Create a frequency array which stores count from 0 to 4 , sort array Y and initialize count to 0.
// for(i=0 to M): count = count + Solve(X[i],Y,freq,M,N)
// print count.

// Solve(val,Y,freq,M,N): if(val is 0) return 0 and if(val is 1) return freq[0].
// 	pos = upper_bound(Y, Y+N, val) - Y.
// 	res = res + N - pos and res = res + freq[0] + freq[1].
// 	if(val is 2) then res = res - (freq[3] + freq[4])
// 	if(val is 3) then res = res + freq[2]
// 	return res.

#include <iostream>
#include <algorithm>
using namespace std;

long long int Solve(long long int val,long long int Y[],long long int freq[],long long int M, long long int N){
	long long int pos =0,res=0;
	if(val == 0)
		return 0;
	if(val == 1)
		return freq[0];

	pos = upper_bound(Y, Y+N, val) - Y;
	
	res = res + N - pos;

	res = res + freq[0] + freq[1];

	if(val == 2)
		res = res - (freq[3] + freq[4]);
	if(val == 3)
		res = res + freq[2];
	return res;
}

int main() {
	long long int T;
	cin>>T;
	while(T--){
	    long long int M,N;
	    cin>>M>>N;
	    long long int X[M],Y[N],freq[5]={0},count=0;
	    for(long long int i=0;i<M;i++)
			cin>>X[i];

		for(long long int i=0;i<N;i++){
	        cin>>Y[i];
			if(Y[i]<5)
        		freq[Y[i]]++;
		}
		sort(Y,Y+N);

		for(long long int i=0;i<M;i++){
			count = count + Solve(X[i],Y,freq,M,N);
		}

		cout<<count<<endl;

		
	}
	return 0;
}