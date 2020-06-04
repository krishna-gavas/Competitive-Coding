// Swapping pairs make sum equal

// Create 2 vectors A and B to store elements of 2 arrays, calulate sums of both A and B as sum1 and sum2.
// calculate difference of sum1 and sum2 as diff. if diff is odd exit the corresponding test case.
// diff = diff/2.
// if(N < M) then find an element in B value is either (A[i] - diff) or (diff+A[i]) .if found then print 1 else print -1.
// else find an element in A value is either (B[i] - diff) or (diff+B[i]) .if found then print 1 else print -1.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,M,X,K,sum1=0,sum2=0,diff,flag=0;
        cin>>N>>M;
        vector<int> A,B;
        for(int i=0;i<N;i++){
            cin>>X;
            A.push_back(X);
            sum1 += X;
        }
        for(int i=0;i<M;i++){
            cin>>X;
            B.push_back(X);
            sum2 += X;
        } 
        diff = abs(sum1 - sum2);
        if(diff % 2 == 1){
            cout<<-1<<endl;
            continue;
        }
        diff = diff/2;

        if(N < M){
            for(int i=0;i<N;i++){
                if((find(B.begin(), B.end(), (A[i] - diff)) != B.end()) || (find(B.begin(), B.end(), (diff+A[i])) != B.end())){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                cout<<1<<endl;
            else 
                cout<<-1<<endl;
        }
        else{
            for(int i=0;i<M;i++){
                if((find(A.begin(), A.end(), (B[i] - diff)) != A.end()) || (find(A.begin(), A.end(), (diff+B[i])) != A.end())){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                cout<<1<<endl;
            else 
                cout<<-1<<endl;
        }
    
    }
    return 0;
}

