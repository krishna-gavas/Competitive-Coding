// Kth smallest element(using Heapsort)

#include <iostream>
#include <algorithm>
using namespace std;

void HeapAdjust(int A[],int i,int n){
    int k=i,v=A[k];
    bool heap = false;
    while(!heap && (2*k <= n)){
        int j = 2*k;
        if(j < n)
            if(A[j] < A[j+1])
                j = j + 1;
        if( v >= A[j])
            heap = true;
        else
        {
            A[k] = A[j];
            k = j;
            A[k] = v;
        }
        
    }
}

void HeapBottomUp(int A[],int n){
    for(int i=(n/2);i>=1;i--)
        HeapAdjust(A,i,n);      
}

int HeapSort(int A[],int n,int k){
    HeapBottomUp(A,n);          
    for(int i=n;i>0;i--){
		if(i == k)
			return A[1];
        swap(A[1],A[i]);
        HeapAdjust(A,1,i-1);    
    }
	return 0;
}

int main() {
	int T;
	srand(time(NULL));
	cin>>T;
	while(T--){
	    int N,K,out;
	    cin>>N;
	    int arr[N];

	    for(long int i=1;i<=N;i++)
	        cin>>arr[i];

		cin>>K;

		out = HeapSort(arr,N,K);

		cout<<out<<endl;
	}
	return 0;
}