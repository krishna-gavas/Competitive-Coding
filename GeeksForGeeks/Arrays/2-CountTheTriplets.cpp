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

class Solution{
public:	
	
	int countTriplet(int A[], int n)
	{
	    int index[100000] = {0};
	    int count = 0;
	    for(int i=0;i<n;i++)
	        index[A[i]] = 1;
	        
	    for(int i=0;i<n-1;i++){
	        for(int j=i+1;j<n;j++){
	            if(index[A[i] + A[j]] == 1){
	                count++;
	            }
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}