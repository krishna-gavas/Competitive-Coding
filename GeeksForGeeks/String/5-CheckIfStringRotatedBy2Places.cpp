// Check if string is rotated by two places

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str1,str2,temp;
        cin>>str1;
        cin>>str2;
        int len1 = str1.length(),len2 = str2.length();
        int flag = 0;
 
        temp.append(str1.substr(2,len1-2));
        temp.append(str1.substr(0,2));
        if(temp == str2)
            flag=1;
        else{
            temp.clear();
            temp.append(str1.substr(len1-2,2));
            temp.append(str1.substr(0,len1-2));
            if(temp == str2)
                flag=1;
        }

        if(flag == 1)
            cout<<1<<endl;
        else
            cout<<0<<endl;
	}
	return 0;
}