// Find all pairs with a given sum

// Create a map mp and store all elements of array B into it and sort array A.
// traverse every element of A and check if (X-A[i]) is present in map if yes then print the pair (A[i], X-A[i])

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,M,X,flag=0;
        map<int, int> mp;
        cin>>N>>M>>X;
        int A[N],B[M];
        for(int i=0;i<N;i++)
            cin>>A[i];

        for(int i=0;i<M;i++){
            cin>>B[i];
            mp.insert(make_pair(B[i], 1));
        }
        sort(A,A+N);
        for(int i=0;i<N;i++){
            if(mp.find(X - A[i]) != mp.end()){
                if(flag == 0)
                    cout<<A[i]<<" "<<X - A[i];
                else 
                    cout<<", "<<A[i]<<" "<<X - A[i];
                flag = 1;
            }
        }
        if(flag == 0)
            cout<<-1;
        
        cout<<"\n";
    }
    return 0;
}

