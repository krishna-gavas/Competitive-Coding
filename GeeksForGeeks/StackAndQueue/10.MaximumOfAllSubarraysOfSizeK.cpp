// Maximum of all subarrays of size k

// Question:
// Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

// Input:
// The first line of input contains an integer T denoting the number of test cases. The first line of each test case 
// contains a single integer N denoting the size of array and the size of subarray K. The second line contains N 
// space-separated integers A1, A2, ..., AN denoting the elements of the array.

// Output:
// Print the maximum for every subarray of size k.

// Example:
// Input:
// 2
// 9 3
// 1 2 3 1 4 5 2 3 6
// 10 4
// 8 5 10 7 9 4 15 12 90 13

// Output:
// 3 3 4 5 5 5 6
// 10 10 10 15 15 90 90

#include <iostream>
#include <deque>
using namespace std;

// void printKMax(int arr[], int n, int k) 
// { 
// 	std::deque<int> Qi(k); 
// 	int i; 
// 	for (i = 0; i < k; ++i) { 
// 		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
// 			Qi.pop_back(); // Remove from rear 
// 		Qi.push_back(i); 
// 	} 
// 	for (; i < n; ++i) { 
// 		cout << arr[Qi.front()] << " "; 
// 		while ((!Qi.empty()) && Qi.front() <= i - k) 
// 			Qi.pop_front(); // Remove from front of queue 

// 		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
// 			Qi.pop_back(); 
// 		Qi.push_back(i); 
// 	} 
// 	cout << arr[Qi.front()]; 
// }

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
        cin>>N>>K;
        int A[N];
        deque <int> pos;
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<K;i++){
            while ((!pos.empty()) && A[i] >= A[pos.back()]) 
                pos.pop_back(); // Remove from rear 
            pos.push_back(i); 
        }
        for(int i=K;i<N;i++){
            cout<<A[pos.front()]<<" ";

            while ((!pos.empty()) && pos.front() <= i - K) 
                pos.pop_front(); // Remove from front of queue 

            while ((!pos.empty()) && A[i] >= A[pos.back()]) 
                pos.pop_back(); 
            pos.push_back(i); 
        }
        cout<<A[pos.front()]<<"\n";
	}
	return 0;
}