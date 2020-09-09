// Does Array Represent Heap 

// Question:
// Given an array A of size N, the task is to check if the given array represents a Binary Max Heap.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
// Each test case contains two lines. The first line of input contains an integer N denoting the size of the array. 
// Then in the next line are N space separated array elements.

// Output:
// If array represents a Binary Max Heap, print "1", else print "0" (without quotes).

// Example:
// Input:
// 2
// 6
// 90 15 10 7 12 2
// 6
// 9 15 10 7 12 11

// Output:
// 1
// 0

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N, flag=1;
	    cin>>N;
	    int A[N];
	    for(int i=1;i<=N;i++)
	        cin>>A[i];
	    for(int i=(N/2); i>=1; i--){
	        int j = 2*i;
	        if(j < N && A[j] < A[j+1])
	            j = j+1;
	        if(A[i] < A[j]){
	            flag = 0;
	            break;
	        }
	    }
	    if(flag == 1)
	        cout<<1<<"\n";
	    else
	        cout<<0<<"\n";
	}
	return 0;
}