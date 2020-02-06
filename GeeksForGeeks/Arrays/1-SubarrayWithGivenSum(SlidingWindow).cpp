// Subarray with given sum(Sliding window technique)
#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,S,flag=0,head=0,sum=0;		// initialize head and sum
	    cin>>N>>S;
	    long int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	        
	    for(int i=0;i<N;i++){
	        sum = sum + arr[i];          
	        while(sum > S){						// if subarray sum is greater shift head 
				sum = sum - arr[head];
				head++;
			}
			if(sum == S){
				cout<<head+1<<" "<<i+1<<endl;
				flag = 1;
				break;
			}
	    }
	    if(flag==0)
	        cout<<-1<<endl;
	}
	return 0;
}