// Check if two arrays are equal or not


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,X;
        cin>>N;
        vector<int> A,B;
        map<int, int> mp1,mp2;
        for(int i=0;i<N;i++){
            cin>>X;
            A.push_back(X);
        }
        for(int i=0;i<N;i++){
            cin>>X;
            B.push_back(X);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        if(A == B)
            cout<<1<<"\n";
        else 
            cout<<0<<"\n";
    }
    return 0;
}

