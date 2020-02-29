#include <iostream>
using namespace std;

int main() {
	int N,K,X;
	cin>>N>>K;
	cout<<"\n";
    int A[N],B[N];
    for(int i=0;i<N;i++)
        cin>>A[i];
    
    for(int i=0;i<N;i++){
        // if((A[i] ^ ~(A[i])) <= K){
        //     B[i] = ~(A[i]);
        //     cout<<B[i]<<" ";
        //     K = K - (A[i] ^ ~(A[i]));
        // }
        // else{
        //     X = A[i] ^ K;
        //     B[i] = X;
        //     cout<<B[i]<<" ";
        // }
        cout<<"not A "<<~(A[i])<<" a xor not a "<<(A[i] ^ ~(A[i]))<<endl;
    }
	
	return 0;
}