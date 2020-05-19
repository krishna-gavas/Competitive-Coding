// Kth largest element in a stream

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