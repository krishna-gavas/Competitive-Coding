// Count pairs with given sum

// Question:
// Given an array of integers, and an integer  ‘K’ , find the count of pairs of elements in the array whose sum is 
// equal to 'K'.

// Input:
// First line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. 
// Each test case consists of two lines. First line of each test case contains 2 space separated integers N and K 
// denoting the size of array and the sum respectively. Second line of each test case contains N space separated 
// integers denoting the elements of the array.

// Output:
// Print the count of pairs of elements in the array whose sum is equal to the K.

// Example:
// Input
// 2
// 4 6
// 1  5  7 1
// 4 2
// 1 1 1 1
// Output
// 2
// 6

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int T;
	cin>>T;
	while(T--){
	    int N,K,count=0;
	    cin>>N>>K;
	    int A[N];
	    multiset<int> s;
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
            count = count + s.count(K - A[i]);
            s.insert(A[i]);
        }
		cout<<count<<"\n";
	}
	return 0;
}