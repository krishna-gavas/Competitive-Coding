// Kth smallest element

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

long int Partition(long int A[],long int l,long int r,long int p){
	while(l<=r){
		while(A[l] < A[p]) 
			l = l + 1;
		while(A[r] > A[p]) 	
			r = r - 1;
		swap(A[l],A[r]);
	}
	swap(A[p],A[r]);
	return r;
}

long int QuickSelect(long int A[],long int l,long int r,long int k){
	int x,p;
	p = rand() % r;
	p = p + 1;
	cout<<"pivot "<<p<<endl;
	x = Partition(A,l,r,p);
	if(x == k)
		return A[x];
	else if(x > k)
		return QuickSelect(A,1,x-1,k);
	else
		return QuickSelect(A,x+1,r,k-x);
}

int main() {
	long int T;
	srand(time(NULL));
	cin>>T;
	while(T--){
	    long int N,K,out;
	    cin>>N;
	    long int arr[N];

	    for(long int i=1;i<=N;i++)
	        cin>>arr[i];

		cin>>K;
		out = QuickSelect(arr,1,N,K);

		cout<<out<<endl;
	}
	return 0;
}