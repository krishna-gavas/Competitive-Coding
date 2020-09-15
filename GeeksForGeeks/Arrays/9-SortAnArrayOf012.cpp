// Sort an array of 0's, 1's and 2's

// Question:
// Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

// Input:
// The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each 
// testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains 
// the elements of the array A separated by spaces.

// Output: 
// For each testcase, print the sorted array.

// Example:
// Input :
// 2
// 5
// 0 2 1 2 0
// 3
// 0 1 0

// Output:
// 0 0 1 2 2
// 0 0 1

// Solution:
// Maintain 3 variables low, high and mid
// low - all elements before low are 0
// mid - all elements between low and mid are 1
// high - all elements after high are 2
// for(mid = 0 to high):
// 	if(arr[mid] == 0) then swap(arr[mid],arr[low]) and increment both low and mid 
// 	else if(arr[mid] == 2) then swap(arr[mid],arr[high]) and decrement high
// 	else increment mid


for(mid=0;mid<=high;){
			if(arr[mid] == 0){
				swap(arr[mid],arr[low]);
				low++;
				mid++;
			}
			else if(arr[mid] == 2){
				swap(arr[mid],arr[high]);
				high--;
			}
			else
				mid++;
		}

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long int T;
	cin>>T;
	while(T--){
	    long int N;
	    cin>>N;
	    int arr[N],low=0,mid=0,high=N-1;

	    for(long int i=0;i<N;i++)
	        cin>>arr[i];

		for(mid=0;mid<=high;){
			if(arr[mid] == 0){
				swap(arr[mid],arr[low]);
				low++;
				mid++;
			}
			else if(arr[mid] == 2){
				swap(arr[mid],arr[high]);
				high--;
			}
			else
				mid++;
		}

		for(long int i=0;i<N;i++)
	        cout<<arr[i]<<" ";
		cout<<endl;
		
	}
	return 0;
}