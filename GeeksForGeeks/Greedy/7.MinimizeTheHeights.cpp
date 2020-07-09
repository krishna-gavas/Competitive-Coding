// Minimize the heights

// Sort the Array.
// if(Largest - smallest < K) then print largest-smallest.
// else calculate average of largest and smallest.
//     for(i=0 to N): add K to elements less than average and subtract K from elements greater than average.
//     Again sort the array and print largest - smallest.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>K;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        sort(A,A+N);
        if(A[N-1] - A[0] < K)
            cout<<A[N-1] - A[0]<<endl;
        else{
            float avg = (A[0] + A[N-1])/2;
            for(int i=0;i<N;i++){
                if(A[i] < avg)
                    A[i] = A[i] + K;
                if(A[i] > avg)
                    A[i] = A[i] - K;
            }
            sort(A,A+N);
            cout<<abs(A[0] - A[N-1])<<endl;
        }
    }
    return 0;
}
