// Count distinct elements in every window


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> countDistinct(int A[], int n, int k){
    map<int, int> mp;
    map<int, int> :: iterator it;
    vector<int> result;
    int head = 0,size;
    for(int i=0;i<n;i++){
        if(i==0)
            head = i;
        if(i < k-1){
            mp[A[i]] = i;
        }
        else{
            mp[A[i]] = i;
            size = mp.size();
            result.push_back(size);
            if(mp[A[head]] == head)
                mp.erase(A[head]);
            head++;
        }
    }
    return result;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        int A[N];
        for(int i=0;i<N;i++) 
            cin>>A[i];
        vector<int> result = countDistinct(A,N,K);
        for(int i : result)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}

