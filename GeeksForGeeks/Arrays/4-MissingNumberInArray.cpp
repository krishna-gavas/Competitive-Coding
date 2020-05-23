// Missing number in array

// Initialize sum = 0 and total = (N*(N+1))/2.
// find sum of all elements and store it in sum.
// print total-sum

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,sum=0,num,total;
	    cin>>N;
		total = (N*(N+1))/2;
	    long int arr[N];
	    for(long int i=0;i<N-1;i++){
	        cin>>arr[i];
			sum = sum + arr[i];
		}

		cout<<total-sum<<endl;
		
	}
	return 0;
}