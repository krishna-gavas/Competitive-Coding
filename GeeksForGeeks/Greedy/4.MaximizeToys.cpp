// Maximize Toys

// Question:
// Given an array arr of length N consisting cost of toys. Given an integer K depicting the amount with you. The 
// task is to Maximise the number of different toys you can have with K amount. 

// Example 1:

// Input: N = 7, K = 50
// arr = {1, 12, 5, 111, 200, 1000, 10}
// Output: 4

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function toyCount() which takes 
// the value N, K and the array arr and returns the maximum count of toys.

// Solution:
// Initialize cost and count to 0.
// Sort the array A.
// for(i=0 to N): if(cost > K) then break out of the loop. 
//     increase cost as cost + A[i] and increment count. 
// print count.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,K,cost=0,count=0;
        cin>>N>>K;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        sort(A,A+N);
        
        for(int i=0;i<N;i++){
            if(cost > K)
                break;
            cost = cost + A[i];
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
