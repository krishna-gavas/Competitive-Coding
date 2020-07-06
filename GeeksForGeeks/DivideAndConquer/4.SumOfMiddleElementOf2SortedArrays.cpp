// Sum of Middle Elements of two sorted arrays

// Merge(A,B,C,N): where A and B are of size N and C is result array of size 2N.
//     initialize i,j and k to 0.
//     while(i < n && j < n): if(A[i] <=B[j]) then C[k++] = A[i++] else C[k++] = B[j++]
//     while(i < n): C[k++] = A[i++]
//     while(j < n): C[k++] = B[j++]

#include <iostream>
using namespace std;

void Merge(int A[],int B[],int C[],int n){
	int i=0,j=0,k=0;
	while(i < n && j < n){
		if(A[i] <=B[j])				
			C[k] = A[i++];
		else{							
			C[k] = B[j++];
		}
		k = k + 1;
	}
	while(i < n)
		C[k++] = A[i++];
	while(j < n)
		C[k++] = B[j++];	
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N],B[N],C[2*N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<N;i++)
            cin>>B[i];
        Merge(A,B,C,N);
        cout<<C[N-1]+C[N]<<endl;
    }
    return 0;
}
