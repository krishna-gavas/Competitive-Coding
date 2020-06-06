// Array Subset of another array

// Create a map and insert all elements of array1 to it and initialize flag to 0.
// traverse every element of array2 and check if it is present in map if not then print No, make flag = 1 and break the loop
// if(flag == 0) then print Yes.

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int M,N,flag = 0;
        map<int, int> mp;
        cin>>M>>N;
        int A[M],B[N];
        for(int i=0;i<M;i++){
            cin>>A[i];
            mp.insert(make_pair(A[i], 1));
        }
        for(int i=0;i<N;i++)
            cin>>B[i];
        
        for(int i=0;i<N;i++){
            if(mp.find(B[i]) == mp.end()){
                cout<<"No\n";
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout<<"Yes\n";
    }
    return 0;
}

