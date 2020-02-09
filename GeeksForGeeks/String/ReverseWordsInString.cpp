// Reverse words in a given string(using '.' as delimiter)
// len is the total length of the string
// len1 is length of substring
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str1,str2;
        cin>>str1;
        int len = str1.length();
        int r,len1 = len-1;

		for(int i=len;i>=0;i--){
            if(str1[i] == '.'){
                r = len1 - i;
                len1 = i - 1;
                str2.append(str1.substr(i+1,r));
                str2.append(".");
            }
        }
        str2.append(str1.substr(0,len1+1));
        cout<<str2<<endl;
           
	}
	return 0;
}