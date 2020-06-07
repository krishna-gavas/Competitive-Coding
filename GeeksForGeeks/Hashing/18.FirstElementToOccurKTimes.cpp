// First element to occur k times


#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K,flag=0;
        map<int, int> mp;
        cin>>N>>K;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];

        for(int i=0;i<N;i++){
                mp[A[i]]++;
        }
        for(int i=0;i<N;i++){
            if(mp[A[i]] == K){
                cout<<A[i]<<endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout<<-1<<endl;
    }
    return 0;
}

