// Chocolate Distribution Problem

// Solution:
// Given an array A of positive integers of size N, where each value represents number of chocolates in a packet. 
// Each packet can have variable number of chocolates. There are M students, the task is to distribute chocolate 
// packets such that :
// 1. Each student gets one packet.
// 2. The difference between the number of chocolates given to the students having packet with maximum chocolates 
// and student having packet with minimum chocolates is minimum.

// Input:
// The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. Each 
// test case consists of three lines. The first line of each test case contains an integer N denoting the number of 
// packets. Then next line contains N space separated values of the array A denoting the values of each packet. 
// The third line of each test case contains an integer m denoting the no of students.

// Output:
// For each test case in a new line print the minimum difference.

// Example:
// Input:
// 2
// 8
// 3 4 1 9 56 7 9 12
// 5
// 7
// 7 3 2 4 9 12 56
// 3

// Output:
// 6
// 2

// Solution:
// sort the array and initialize min to last element of array
// for(i=0 to N-M):
// 	dif = arr[i+M-1] - arr[i]
// 	if(dif < min) then min = dif

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,M,min,dif;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
        cin>>M;
        sort(arr,arr+N);
        min = arr[N-1];

        for(int i=0;i<=(N-M);i++){
            dif = arr[i+M-1] - arr[i];
            if(dif < min)
                min = dif;
        }

        cout<<min<<endl;
	}
	return 0;
}