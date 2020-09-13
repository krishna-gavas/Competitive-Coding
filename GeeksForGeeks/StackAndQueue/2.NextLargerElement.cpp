// Next larger element

// Question:
// Given an array A of size N having distinct elements, the task is to find the next greater element for each element 
// of the array in order of their appearance in the array. If no such element exists, output -1 

// Input:
// The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. 
// Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The 
// Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

// Output:
// For each test case, print in a new line, the next greater element for each array element separated by space in order.

// Example:
// Input
// 2
// 4
// 1 3 2 4
// 4
// 4 3 2 1
// Output
// 3 4 4 -1
// -1 -1 -1 -1

// Solution:
// nextLarger: Create a stack s and also create an array B[] to store next larger element.
//     traverse the array from last to first:
//         at each traversal initialize next = arr[i];
//         while(stack is not empty and next > top of stack) then pop top most element
//         if(stack is empty) then insert -1 to B[i]
//         else insert top of stack to B[i]
//         finally push next to stack
//     print the contents of array B[]

#include <iostream>
#include <stack>
using namespace std;

void nextLarger(long long arr[], int n){
    stack <long long int> s;
    long long  B[n];
    long long int next;

    for(int i=n-1;i>=0;i--){
        next = arr[i];
        while(!s.empty() && next > s.top()){              
            s.pop();
        }
        if(s.empty())
            B[i] = -1;
        else 
            B[i] = s.top();

        s.push(next);
    }

    for(int i=0;i<n;i++)
        cout<<B[i]<<" ";
    cout<<"\n";
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    long long int arr[N];

	    for(int i=0;i<N;i++)
	        cin>>arr[i];

        nextLarger(arr, N);
	}
	return 0;
}