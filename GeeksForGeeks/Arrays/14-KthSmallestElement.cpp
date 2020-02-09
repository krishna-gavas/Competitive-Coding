// Kth smallest element(not submitted)

#include <iostream>
#include <algorithm>
using namespace std;

int R_Partition(long int A[],long int l,long int r){
    long int ran = l + rand() % (r-l+1);
    swap(A[ran],A[r]);

    long int x=A[r];
    long int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(A[j]<=x){
            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

long int QuickSelect(long int A[],long int l,long int r,long int k){
	int p;
	p = R_Partition(A,l,r);
	if(p == k)
		return A[p];
	else if(p > k)
		return QuickSelect(A,1,p-1,k);
	else
		return QuickSelect(A,p+1,r,k);
}

int main() {
	long int T;
	srand(time(NULL));
	cin>>T;
	while(T--){
	    long int N,K,out;
	    cin>>N;
	    long int arr[N];

	    for(long int i=0;i<N;i++)
	        cin>>arr[i];

		cin>>K;

		out = QuickSelect(arr,1,N-1,K-1);

		cout<<out<<endl;
	}
	return 0;
}