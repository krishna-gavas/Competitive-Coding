// Missing number in array

// Question:
// Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, 
// the missing number is to be found.

// Input:
// The first line of input contains an integer T denoting the number of test cases. For each test case 
// first line contains N(size of array). The subsequent line contains N-1 array elements.

// Output:
// Print the missing number in array.

// Example:
// Input:
// 2
// 5
// 1 2 3 5
// 10
// 1 2 3 4 5 6 7 8 10

// Output:
// 4
// 9

// Solution:
// Initialize sum = 0 and total = (N*(N+1))/2.
// find sum of all elements and store it in sum.
// print total-sum

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    long int sum = 0, total;
	    cin>>N;
	    int A[N-1];
	    total = (N * (N+1))/2;
	    for(int i=0;i<N-1;i++){
	        cin>>A[i];
	        sum = sum + A[i];
	    }
	    cout<<total-sum<<endl;
	}
	return 0;
}