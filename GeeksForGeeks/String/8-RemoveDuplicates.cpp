// Remove Duplicates

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int T;
    cin>>T;
    cin.ignore();
	while(T--){
	    string str1;
		char count[256] ={0};
        getline(cin,str1);
        int len = str1.length();
		for(int i=0;i<len;i++){
            if(count[str1[i]]++ == 0){
                cout<<str1[i];
            }
        }
        cout<<endl;
	}
	return 0;
}