// Recursively remove all adjacent duplicates in a string
// In RemoveAdjacent function check if there is any duplicate string 
// if no duplicate string is present return str2 else return RemoveAdjacent(str2)

#include <iostream>
#include <string>
using namespace std;

string RemoveAdjacent(string str){
        string str2;
        int len = str.length(),l=0,r,flag=0,last=0;

        for(int i=0;i<len;){
            int j=i+1;
            flag = 0;
            while((str[i] == str[j]) && (j<len)){
                j++;
                flag = 1;
                last = 1;
            }
            if(flag==1){

                l = j;
                i = j;
            }
            else{
                r = i;
                str2.append(str.substr(l,(r-l+1)));
                l = j;
                i++;
            }
        }
        if(last == 0)
            return str2;
        else 
            return RemoveAdjacent(str2);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str1,str2; 
        cin>>str1;

        str2 = RemoveAdjacent(str1);
 
        cout<<str2<<endl;
	}
	return 0;
}