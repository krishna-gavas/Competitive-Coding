// Leaders in an array

// Question:
// Given an array of positive integers. Your task is to find the leaders in the array.
// Note: An element of array is leader if it is greater than or equal to all the elements to its right side. Also, 
// the rightmost element is always a leader. 

// Input:
// The first line of input contains an integer T denoting the number of test cases. The description of T test cases 
// follows.
// The first line of each test case contains a single integer N denoting the size of array.
// The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

// Output:
// Print all the leaders.

// Example:
// Input:
// 3
// 6
// 16 17 4 3 5 2
// 5
// 1 2 3 4 0
// 5
// 7 4 5 7 3
// Output:
// 17 5 2
// 4 0
// 7 7 3

// Solution:
// Leader is an element such that all elements right to it are either smaller or equal
// access element in reverse order and compare it with max
// if it is greater than max then push it to stack
#include <iostream>
#include <stack>
using namespace std;
 
int main ()  
{  
	long int T;
	cin>>T; 
	while(T--){
	    long int N;
	    cin>>N;
	    int arr[N],flag=0;
	    stack <int> S;  

	    for(int i=0;i<N;i++)
	        cin>>arr[i];

		int max = arr[N-1];

		for(int i=N-1;i>=0;i--){
			if(arr[i] >= max){
				S.push(arr[i]);
				max = arr[i];
			}
		}

		while(flag == 0)
			if(S.empty())
				flag = 1;
			else{
				cout<<S.top()<<" ";
				S.pop();
			}
		cout<<endl;
	}    
    return 0;  
} 