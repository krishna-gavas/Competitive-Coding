// Minimum Swaps to Sort

// Question:
// Given an array of integers. Find the minimum number of swaps required to sort the array in non-decreasing order.

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
// Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N 
// space separated values of the array A[ ] .

// Output:
// For each test case in a new line output will be an integer denoting  minimum umber of swaps that are  
// required to sort the array.

// User Task:
// You don't need to read input or print anything. Your task is to complete the function minSwaps() which takes 
// the array arr[] and its size N as inputs and returns an integer denoting the minimum number of swaps required 
// to sort the array. If the array is already sorted, return 0. 

// Example(To be used only for expected output):
// Input:
// 2
// 5
// 1 5 4 3 2
// 4
// 8 9 16 15

// Output:
// 2
// 1

// Solution:
// minSwaps: Create an array of pairs ArrIndex[] such that first value is A[i] and second value is i
//     sort ArrIndex based on first value and create a visited array and initialize it with false
//     initialize swaps = 0
//     for(i=0 to 1):
//         if(ith node is visited or ith node does not contain any edges) then continue
//         initialize cycle with 0 and node with j
//         while(node is not visited): mark node as visited
//             update node value as ArrIndex[node].second and increment value of cycle
//         if(cycle > 0) then swaps += (cycle - 1)
//     return swaps

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(int A[], int n){
    pair<int, int> ArrIndex[n]; 
	for (int i = 0; i < n; i++) { 
		ArrIndex[i].first = A[i]; 
		ArrIndex[i].second = i; 
	} 
	
	sort(ArrIndex, ArrIndex + n); // sort by first
	
	vector<bool> vis(n, false); 

	int swaps = 0; 
	for (int i = 0; i < n; i++) 
	{ 
		if (vis[i] || ArrIndex[i].second == i) 
			continue; 
 
		int cycle = 0; 
		int node = i; 
		while (!vis[node]) 
		{ 
			vis[node] = 1; 
			node = ArrIndex[node].second; 
			cycle++; 
		} 
      
		if (cycle > 0) 
		{ 
			swaps += (cycle - 1); 
		} 
	} 
	return swaps;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<minSwaps(A,N)<<endl;
    }
}