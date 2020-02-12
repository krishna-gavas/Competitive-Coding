// Remove Duplicates(not submitted)

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int T;
    cin>>T;
	while(T--){
	    string str1,str2;
        cin.ignore();
        getline(cin,str1);
        int len = str1.length();
		map<char, int> map1;
		for(int i=0;i<len;i++){
            if(map1.count(str1[i]) == 1){
                // 
            }
            else{
                map1.insert(pair<char, int>(str1[i], 1));
                str2.append(str1.substr(i,1));
                // cout<<str1[i];
            }
        }
        cout<<str2<<endl;
	}
	return 0;
}