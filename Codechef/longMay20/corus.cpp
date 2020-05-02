// Isolation Centers

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,Q,C;
        cin>>N>>Q;
        string S;
        cin>>S;
        int ch[26] = {0};
        for(int i=0;i<S.length();i++){
            ch[S[i] - 97]++;
        }
        for(int i=0;i<Q;i++){
            cin>>C;
            int minSize = 0;
            for(int j=0;j<26;j++){
                if(ch[j] > C)
                    minSize = minSize + (ch[j] - C);
            }
            cout<<minSize<<"\n";
        }
	}
	return 0;
}