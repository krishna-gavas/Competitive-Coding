// Equlibrium point in an array
// initialize leftSum as 0 and rightSum as totalSum
// while accessing every element calulate leftSum and rightSum and compare both
// if both sums are equal print the respective position
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long int T;
	cin>>T;
	while(T--){
	    long int N;
	    cin>>N;
	    int arr[N],i=1,j=N-1,pos=-1,leftsum=0,rightsum=0;

	    for(long int i=0;i<N;i++){
	        cin>>arr[i];
			rightsum = rightsum + arr[i];
		}

		for(long int i=0;i<N;i++){
			rightsum = rightsum - arr[i];
			if(leftsum == rightsum){
				pos = i+1;
				break;
			}
			leftsum = leftsum + arr[i];
		}
		cout<<pos<<endl;
	}
	return 0;
}