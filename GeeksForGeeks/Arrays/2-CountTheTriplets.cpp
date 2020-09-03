// Count the Triplets (using index array approach)

// Question:
// Given an array of distinct integers. The task is to count all the triplets such that sum of two elements
//  equals the third element.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
// Each test case consists of two lines. First line of each test case contains an Integer N denoting size of 
// array and the second line contains N space separated elements.

// Output:
// For each test case, print the count of all triplets, in new line. If no such triplets can form, print "-1".

// Example:
// Input:
// 2
// 4
// 1 5 3 2
// 3
// 3 2 7
// Output:
// 2
// -1

// Solution:
// Initialize count and flag to 0.
// make an index array to store elements as index values as index[arr[i]] = 1.
// for(i=0 to N-1):
// 	for(j=i+1 to N):
// 		if((index[arr[i]+arr[j]])==1): increment count and make flag = 1.
// if(flag == 1) then print count else print -1.

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,count=0,flag=0;
	    cin>>N;
	    long int arr[N];
		int* index = (int*)calloc(1000000, sizeof(int));
	    for(long int i=0;i<N;i++){
	        cin>>arr[i];
			index[arr[i]] = 1;
		}
		for(long int i=0;i<N-1;i++){
			for(long int j=i+1;j<N;j++){
				if((index[arr[i]+arr[j]])==1){
					count = count + 1;
					flag = 1;
				}
			}
		}
		if(flag==1)
			cout<<count<<endl;
		else
			cout<<-1<<endl;
		free(index);
	}
	return 0;
}