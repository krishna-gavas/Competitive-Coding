// Rearrange array alternatively

// Question:
// Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively
// i.e first element should be max value, second should be min value, third should be second max, 
// fourth should be second min and so on...

// Input:
// First line of input conatins number of test cases T. First line of test case contain an integer denoting 
// the array size N and second line of test case contain N space separated integers denoting the array elements.

// Output:
// Output the modified array with alternated elements.

// Example: 
// Input:
// 2
// 6
// 1 2 3 4 5 6
// 11 
// 10 20 30 40 50 60 70 80 90 100 110

// Output:
// 6 1 5 2 4 3
// 110 10 100 20 90 30 80 40 70 50 60

// Solution:
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