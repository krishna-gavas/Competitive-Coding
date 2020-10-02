// N meetings in one room

// Question:
// There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of 
// meeting i and F[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room?

// Input:
// The first line of input consists number of the test cases. The description of T test cases is as follows:
// The first line consists of the size of the array, second line has the array containing the starting time of all 
// the meetings each separated by a space, i.e., S [ i ]. And the third line has the array containing the finishing 
// time of all the meetings each separated by a space, i.e., F [ i ].

// Output:
// In each separate line print the order in which the meetings take place separated by a space.

// Example:
// Input:
// 2
// 6
// 1 3 0 5 8 5
// 2 4 6 7 9 9
// 8
// 75250 50074 43659 8931 11273 27545 50879 77924
// 112960 114515 81825 93424 54316 35533 73383 160252  

// Output:
// 1 2 4 5
// 6 7 1

// Solution:
// Create an array of struct meeting, store start and finish time in it and initialize count = 1.
// Create a vector res to store order in which meetings take place, and create a map to store finish time before sorting
// sort the array based on finish time.
// initialize finished = A[0].finish and push mp[A[0].finish] to res.
// for(i=1 to N):
//     if(A[i].start >= finished) then increment count, push mp[A[i].finish] to res and make finished = A[i].finish.
// print content of res.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct meeting{
    int start;
    int finish;
};

bool Sorter(meeting const& lhs,meeting const& rhs){
    return lhs.finish < rhs.finish;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,count=1,finished;
        cin>>N;
        meeting A[N];
        vector<int> res;
        map<int,int> mp;
        for(int i=0;i<N;i++)
            cin>>A[i].start;
        for(int i=0;i<N;i++){
            cin>>A[i].finish;
            mp.insert(make_pair(A[i].finish, i+1));
        }
        
        sort(A,A+N, &Sorter);

        finished = A[0].finish;
        res.push_back(mp[A[0].finish]);
        for(int i=1;i<N;i++){
            if(A[i].start >= finished){
                count++;
                res.push_back(mp[A[i].finish]);
                finished = A[i].finish;
            }
        }
        for(int i=0;i<count;i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
