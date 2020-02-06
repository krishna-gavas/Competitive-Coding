// Missing number in array
#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,sum=0,num,total;
	    cin>>N;
		total = (N*(N+1))/2;
		cout<<total<<endl;
	    long int arr[N];
	    for(long int i=0;i<N-1;i++){
	        cin>>arr[i];
			sum = sum + arr[i];
		}

		cout<<total-sum<<endl;
		
	}
	return 0;
}