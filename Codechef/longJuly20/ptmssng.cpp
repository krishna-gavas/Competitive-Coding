// Missing a Point

#include <iostream>
#include <set>

using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
        int N;
        cin>>N;
        int X[4*N],Y[4*N];
        set <int> s1,s2;
        for(int i=0; i<(4*N)-1; i++){
            cin>>X[i]>>Y[i];
            if(s1.find(X[i]) != s1.end())
                s1.erase(X[i]);
            else 
                s1.insert(X[i]);

            if(s2.find(Y[i]) != s2.end())
                s2.erase(Y[i]);
            else 
                s2.insert(Y[i]);
        }
        if(!s1.empty() && !s2.empty())
            cout<<*s1.begin()<<" "<<*s2.begin()<<endl;
    }
    return 0;
}