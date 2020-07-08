// Activity Selection

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

bool Sorter(activity const& lhs,activity const& rhs){
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
        
        sort(A,A+N, &Sorter);

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
