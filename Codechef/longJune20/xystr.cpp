// Chef and String

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string s;
        cin>>s;
        int len = s.length(),pair=0;
        for(int i=0;i<len-1;i++){
            if( (s[i]=='x' && s[i+1]=='y') || (s[i]=='y' && s[i+1]=='x')){
                pair++;
                i++;
            }
        }
        cout<<pair<<"\n";
	}
	return 0;
}