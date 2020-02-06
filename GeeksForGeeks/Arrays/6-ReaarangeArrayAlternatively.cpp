// Rearrange array alternatively
// for even position:
//					A[i] = A[i] + ((A[max] % M) * M)
// for odd position:
//					A[i] = A[i] + ((A[min] % M) * M)
// min and max are pointers pointing to start and end of array
// M is any number greater than the maximum element in the array A

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N;
	    cin>>N;
	    long int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];

		long int min=0,max=N-1,M=arr[N-1]+1;		// M = Largest element + 1

		for(int i=0;i<N;i++){
			if(i%2 == 0){
				arr[i] = arr[i] + ((arr[max] % M) * M);
				max--;
			}
			else{
				arr[i] = arr[i] + ((arr[min] % M) * M);
				min++;
			}
			cout<<arr[i]/M<<" ";
		}

		cout<<endl;
		
	}
	return 0;
}