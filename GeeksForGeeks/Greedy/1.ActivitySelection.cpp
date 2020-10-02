// Activity Selection

// Question:
// Given N activities with their start and finish times. Select the maximum number of activities that can be 
// performed by a single person, assuming that a person can only work on a single activity at a time.
// Note : The start time and end time of two activities may coincide.

// Input:
// The first line contains T denoting the number of testcases. Then follows description of testcases. First line 
// is N number of activities then second line contains N numbers which are starting time of activies.Third line 
// contains N finishing time of activities.

// Output:
// For each test case, output a single number denoting maximum activites which can be performed in new line.

// Example:
// Input:
// 2
// 6
// 1 3 2 5 8 5
// 2 4 6 7 9 9
// 4
// 1 3 2 5
// 2 4 3 6

// Output:
// 4
// 4

// Solution:
// Create an array of struct activity, store start and finish time in it and initialize count = 1.
// sort the array based on finish time.
// initialize finished = A[0].finish.
// for(i=1 to N):
//     if(A[i].start >= finished) then increment count and make finished = A[i].finish.
// print count.

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct activity{
    int start;
    int finish;
};

bool Sorter(activity lhs,activity rhs){
    return lhs.finish < rhs.finish;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,count=1,finished;
        cin>>N;
        activity A[N];
        for(int i=0;i<N;i++)
            cin>>A[i].start;
        for(int i=0;i<N;i++)
            cin>>A[i].finish;
        
        sort(A,A+N,Sorter);

        finished = A[0].finish;
        for(int i=1;i<N;i++){
            if(A[i].start >= finished){
                count++;
                finished = A[i].finish;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
