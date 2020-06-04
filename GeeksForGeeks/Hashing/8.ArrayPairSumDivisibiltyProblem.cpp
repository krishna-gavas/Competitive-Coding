// Array Pair Sum Divisibility Problem

// Check if(N is odd) then print false
// else if(sum % K == 0) then print true else print false.

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K,sum=0;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
            sum += A[i];
        }
        cin>>K;
        if(N % 2 == 1)
            cout<<"False"<<endl;
        else{
            if(sum % k == 0)
                cout<<"True"<<endl;
            else 
                cout<<"False"<<endl;
        }
    }
    return 0;
}

