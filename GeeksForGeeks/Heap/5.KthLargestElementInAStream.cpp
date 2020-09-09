// Kth largest element in a stream

// Question:
// Given an input stream of n integers, find the kth largest element for each element in the stream.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
// Each test case contains two lines. The first line of each test case contains two space separated integers k and n. 
// Then in the next line are n space separated values of the array.

// Output:
// For each test case, in a new line, print the space separated values denoting the kth largest element at each 
// insertion, if the kth largest element at a particular insertion in the stream doesn't exist print -1.

// Example:
// Input:
// 2
// 4 6
// 1 2 3 4 5 6
// 1 2
// 3 4

// Output:
// -1 -1 -1 1 2 3
// 3 4

// Solution:
// Create a minHeap of size k and print the topmost element of the heap on each iteration.
// for( i=0 to N): 
//     if(i < K): if(i==0) make minHeap and push X to it else directly push X to it. 
//                if minHeap size is K print minHeap.front() else print -1
//     else: large = minHeap.front()
//         if(X > large): Pop from minHeap and push X to it.
//         print minHeap.front().

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int T;
    cin>>T;
    while(T--){
        int K,N,X,large;
        cin>>K>>N;
        vector<int> minHeap;
        for(int i=0;i<N;i++){
            cin>>X;
            if(i < K){
                if(i==0){
                    minHeap.push_back(X);
                    make_heap(minHeap.begin(), minHeap.end(), greater<int>()); 
                }
                else{
                    minHeap.push_back(X);
                    push_heap(minHeap.begin(), minHeap.end(), greater<int>()); 
                }

                if(minHeap.size() == K)
                    cout<<minHeap.front()<<" ";
                else 
                    cout<<-1<<" ";
            }   
            else {
                large = minHeap.front();
                if(X > large){
                    pop_heap(minHeap.begin(), minHeap.end(), greater<int>()); 
                    minHeap.pop_back();

                    minHeap.push_back(X);
                    push_heap(minHeap.begin(), minHeap.end(), greater<int>());
                }
                cout<<minHeap.front()<<" ";
            }
        }
        cout<<endl;
    }   
	return 0;
}