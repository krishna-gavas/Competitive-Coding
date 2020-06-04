// Longest consecutive subsequence

// Sort the input array and initialize count and max to 1.
// for(i=1 to N): if(A[i] == A[i-1]) then continue.
//     if(A[i] == A[i-1]+1) then increment count else count = 1.
//     if(count > max) then max = count.
// print max.

#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int N,count=1,max=1;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        sort(A,A+N);
        for(int i=1;i<N;i++){
            if(A[i] == A[i-1])
                continue;
            if(A[i] == A[i-1]+1)
                count++;
            else 
                count = 1;
            if(count > max)
                max = count;
        }
        cout<<max<<endl;
    }
    return 0;
}

