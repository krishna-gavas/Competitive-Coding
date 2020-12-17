// Subarray with given sum(Sliding window technique)

// Question:
// Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds 
// to a given number S.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
// Each test case consists of two lines. The first line of each test case is N and S, where N is the size of 
// array and S is the sum. The second line of each test case contains N space separated integers denoting the 
// array elements.

// Output:
// For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such 
// occuring subarray from the left if sum equals to subarray, else print -1.

// Example:
// Input:
// 2
// 5 12
// 1 2 3 7 5
// 10 15
// 1 2 3 4 5 6 7 8 9 10
// Output:
// 2 4
// 1 5

// Solution:
// Initialize flag,head and sum as 0.
// for(i=0 to N): sum = sum + arr[i].
// 	while( sum > S): sum = sum - arr[head] and increment head.
// 	if(sum == S) then print head+1 to i+1, make flag = 1 and break.
// if(flag == 0) then print -1;

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,S;
	    long int flag=0, start=0, sum=0;
	    cin>>N>>S;
	    long int A[N];
	    for(int i=0;i<N;i++)
	        cin>>A[i];
	    
	    for(int i=0;i<N;i++){
	        sum = sum + A[i];
	        while(sum > S){
	            sum = sum - A[start];
	            start++;
	        }
	        if(sum == S){
	            cout<<start+1<<" "<<i+1<<endl;
	            flag = 1;
	            break;
	        }
	    }
	    if(flag == 0)
	        cout<<-1<<endl;
	}
	return 0;
}
