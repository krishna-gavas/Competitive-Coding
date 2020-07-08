// N meetings in one room

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
