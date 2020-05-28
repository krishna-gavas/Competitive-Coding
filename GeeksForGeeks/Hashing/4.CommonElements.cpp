// Largest subarray with 0 sum

// create 3 maps namely mp1,mp2,mp3 for storing common elements.
// while inputting elements of A insert all elements into mp1.
// while inputting elements of B insert those elements of B into mp2 which are already present in mp1.
// while inputting elements of C insert those elements into mp3 which are present in mp2 and not present in mp3.
// if size of mp3 is 0 then print -1 else print content of mp3.

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        map<int, int> mp1,mp2,mp3;
        map<int, int> :: iterator it;
        int N1,N2,N3;
        cin>>N1>>N2>>N3;
        int A[N1],B[N2],C[N3];
        for(int i=0;i<N1;i++){
            cin>>A[i];
            if(mp1.find(A[i]) == mp1.end())
                mp1.insert(make_pair(A[i],1));
        }
        for(int i=0;i<N2;i++){
            cin>>B[i];
            if(mp1.find(B[i]) != mp1.end())
                mp2.insert(make_pair(B[i],1));
        }
        for(int i=0;i<N3;i++){
            cin>>C[i];
            if(mp2.find(C[i]) != mp2.end()  && mp3.find(C[i]) == mp3.end())
                mp3.insert(make_pair(C[i],1));
        }
        if(mp3.size()==0)
            cout<<-1;
        else{
            for(it=mp3.begin(); it!=mp3.end(); it++)
                cout<<it->first<<" ";
        }
        cout<<endl;
    }
    return 0;
}
