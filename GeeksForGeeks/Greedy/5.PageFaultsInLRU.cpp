// Page Faults in LRU

// Initialize pf=0 and create a vector lru to store the pages.
// for(i=0 to N): it = find A[i] in lru.
//     if(A[i] is present in lru) then delete A[i] from lru and push A[i] to lru.
//     else if(lru.size() == cap) then erase lru.begin() 
//         push A[i] to lru and increment pf. 
// print pf.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,cap,pf=0;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cin>>cap;
        
        vector<int> lru;
        vector<int> :: iterator it;
        for(int i=0;i<N;i++){
            it = find(lru.begin(), lru.end(), A[i]);
            if( it != lru.end()){
                lru.erase(it);
                lru.push_back(A[i]);
            }
            else{
                if(lru.size() == cap)
                    lru.erase(lru.begin());
                lru.push_back(A[i]);
                pf++;
            }
        }
        cout<<pf<<endl;
    }
    return 0;
}
