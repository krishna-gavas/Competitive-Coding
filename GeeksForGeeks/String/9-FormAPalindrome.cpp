// Form a palindrome(not submitted)

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
        str2 = str1;
		reverse(str2.begin(), str2.end());
		cout<<str2;
           
	}
	return 0;
}