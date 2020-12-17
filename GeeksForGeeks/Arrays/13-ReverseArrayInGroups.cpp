// Reverse array in groups
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
// calculate quotient,remainder and limit 
// access elements using a window of size K till limit is reached
// while accessing for each window swap first K/2 elements with last K/2 elements
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    void reverseInGroups(vector<long long>& arr, int N, int K){
        long int val=K,q,r,limit;
        q = N/K;
		r = N%K;
		limit = q * K;
		
		for(long int i=0;i<limit;i=i+val){   
			if(i%val == 0 && i != 0)
				K = K + (2*val);
			int lim;
			if(K%2 == 0)
				lim = (K/2) - 1;
			else
				lim = K/2;
			for(int j=i;j<=lim;j++)
				swap(arr[j],arr[K-j-1]);

		}

		if(r != 0){						// for remaining elements(if N is not multiple of K)
			int newlimit = limit + ((N-1-limit)/2);
			int j = N-1;
			for(int i=limit;i<=newlimit;i++)
				swap(arr[i],arr[j--]);
		}
    }
};

int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}