// Sort an array of 0's, 1's and 2's
// Maintain 3 variables low, high and mid
// low - all elements before low are 0
// mid - all elements between low and mid are 1
// high - all elements after high are 2

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long int T;
	cin>>T;
	while(T--){
	    long int N;
	    cin>>N;
	    int arr[N],l=0,m=0,h=N-1;

	    for(long int i=0;i<N;i++)
	        cin>>arr[i];

		for(m=0;m<=h;){
			if(arr[m] == 0){
				swap(arr[m],arr[l]);
				l++;
				m++;
			}
			else if(arr[m] == 2){
				swap(arr[m],arr[h]);
				h--;
			}
			else
				m++;
		}

		for(long int i=0;i<N;i++)
	        cout<<arr[i]<<" ";
		cout<<endl;
		
	}
	return 0;
}