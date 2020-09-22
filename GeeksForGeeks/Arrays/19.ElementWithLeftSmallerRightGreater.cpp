// Element with left side smaller and right side greater

// Question:
// Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller 
// and all right elements to it are greater than it.
// Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each 
// test case consists of two lines. First line of each test case contains an Integer N denoting size of array and 
// the second line contains N space separated array elements.

// Output:
// For each test case, in a new line print the required element. If no such element present in array then print -1.

// Example:
// Input:
// 3
// 4
// 4 2 5 7
// 3
// 11 9 12
// 6
// 4 3 2 7 8 9

// Output:
// 5
// -1
// 7

// Solution:
// create 2 arrays namely min and max 
// store the elements in max array by traversing from left to right
// store the elements in min array by traversing from right to left 
// traverse the array from left to right and if min[i] == max[i] then make ele = min[i] and break out of the loop

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,ele=-1;
	    cin>>N;
	    int A[N],min[N],max[N];
        int big = 0;
	    for(int i=0;i<N;i++){
	        cin>>A[i];
            if(A[i] > big)
                big = A[i];
            max[i] = big;
        }
        int small = A[N-1];
        for(int i=N-1;i>=0;i--){
            if(A[i] < small)
                small = A[i];
            min[i] = small;
        }
        for(int i=0;i<N;i++){
            if(min[i] == max[i] && i!=0 && i!=(N-1)){
                ele = min[i];
                break;
            }
        }
        cout<<ele<<endl;
	}
	return 0;
}