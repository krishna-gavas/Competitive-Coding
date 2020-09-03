//Merge Two sorted array without extra space(Using gap approach)

// Question:
// Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size n and m. The task is to merge 
// the two sorted arrays into one sorted array (in non-decreasing order).

// Input:
// First line contains an integer T, denoting the number of test cases. First line of each test case contains two space separated integers X and Y, denoting the size of the two sorted arrays. Second line of each test case contains X space separated integers, denoting the first sorted array P. Third line of each test case contains Y space separated integers, denoting the second array Q.

// Output:
// For each test case, print (X + Y) space separated integer representing the merged array.

// Example:
// Input:
// 2
// 4 5
// 1 3 5 7
// 0 2 6 8 9
// 2 3
// 10 12
// 5 18 20

// Output:
// 0 1 2 3 5 6 7 8 9
// 5 10 12 18 20

#include <iostream>
using namespace std;

int nextGap(int n){
	if(n<=1)
		return 0;
	return n/2 + n%2;
}

int main(){
	int T;
	cin>>T;
	while(T--){
	    long int X,Y;
	    cin>>X>>Y;
	    long int A[X+Y];

	    for(int i=0;i<X+Y;i++)
	        cin>>A[i];

		int gap = nextGap(X+Y);

		while(gap){
			for(int i=0;i+gap<X+Y;i++){
				if(A[i+gap] < A[i])
					swap(A[i],A[i+gap]);
			}
			gap = nextGap(gap);
		}

		for(int i=0;i<X+Y;i++)
	        cout<<A[i]<<" ";
		
		cout<<endl;
	}
	return 0;
}