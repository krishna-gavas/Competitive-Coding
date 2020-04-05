// First non-repeating character in a stream

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    char in[n], out[n];
        vector<char> v1;
        vector<char> v2;
        for(int i=0;i<n;i++){
            cin>>in[i];
            if(find(v1.begin(), v1.end(), in[i]) != v1.end()){
                if(!v1.empty()){
                    out[i] = q.front();
                    q.pop();
                }
                else 
                    out[i] = '0';
            }
            else{
                v1.push_back(in[i]);
                while(!v1.empty()){
                    v2.push_back(v1.pop_back());
                }
                out[i] = q.front();
            }
        }

        for(int i=0;i<n;i++)
            if(out[i] == '0')
                cout<<-1<<" ";
            else 
                cout<<out[i]<<" ";
        cout<<"\n";
	}
	return 0;
}