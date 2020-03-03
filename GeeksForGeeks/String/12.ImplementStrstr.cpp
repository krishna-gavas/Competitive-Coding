// Implement strstr

#include <iostream>
#include <string>
using namespace std;

int strstr(string s, string x)
{
     int len = s.length();
     int len1 = x.length();
     int flag;
     for(int i=0;i<len;i++){
         if(s[i] == x[0]){
             flag = 0;
             for(int j=0;j<len1;j++){
                 if(s[i+j] == x[j]){

                 }
                 else{
                     flag = 1;
                     break;
                 }
             }
             if(flag == 0){
                 return i;
             }
         }
     }
     return -1;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string s,x;
        cin>>s>>x;
        int out = strstr(s,x);
        
        cout<<out<<endl;
	}
	return 0;
}