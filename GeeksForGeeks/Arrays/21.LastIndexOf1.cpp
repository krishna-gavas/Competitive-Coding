// Last index of One

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
    cin.ignore();
	while(T--){
        int pos = -1;
	    string str;
        getline(cin,str);
        int len = str.length();

        for(int i=(len-1);i>=0;i--){
            if(str[i] == '1'){
                pos = i;
                break;
            }
        }
        cout<<pos<<endl;
	}
	return 0;
}