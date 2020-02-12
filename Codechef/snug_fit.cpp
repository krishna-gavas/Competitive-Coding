// School of Geometry 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	for(int j=0;j<T;j++){
	    long int N,sum=0;
        cin>>N;
        long int A[N],B[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<N;i++)
            cin>>B[i];

        sort(A,A+N);
        sort(B,B+N); 
        
        for(int i=0;i<N;i++){
            if(A[i] <= B[i])
                sum = sum + A[i];
            else
                sum = sum + B[i];
        }

        cout<<sum<<endl;
	}
	return 0;
}