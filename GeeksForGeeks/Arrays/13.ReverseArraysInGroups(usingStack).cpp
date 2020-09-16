// Reverse array in groups(Using Stack)

// Question:
// Given an array arr[] of positive integers of size N. Reverse every sub-array of K group elements.

// Input:
// The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. 
// Each test case consist of two lines of input. The first line of each test case consists of an integer 
// N(size of array) and an integer K separated by a space. The second line of each test case contains N space 
// separated integers denoting the array elements.

// Output:
// For each test case, print the modified array.

// Example:
// Input
// 2
// 5 3
// 1 2 3 4 5
// 6 2
// 10 20 30 40 50 60

// Output
// 3 2 1 5 4
// 20 10 40 30 60 50

// Solution:


#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,K;
	    cin>>N>>K;
	    long long int arr[N];
        stack<long long int> s;

	    for(long int i=0;i<N;i++)
	        cin>>arr[i];

		for(long int i=0;i<N;i++){   
			if(s.size() < K)
                s.push(arr[i]);
            else{
                while(!s.empty()){
                    cout<<s.top()<<" ";
                    s.pop();
                }
                s.push(arr[i]);
            }

		}

		while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
		
		cout<<endl;
	}
	return 0;
}