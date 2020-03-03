// Longest Distinct characters in string

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str;
        cin>>str;
        int len = str.length();
        int max=0,curlen=0,start=0;
        vector<char> v1,v2;
        vector<char>::iterator it,it1,it2;

        for(int i=0;i<len;i++){
            if(find(v1.begin(), v1.end(), str[i]) != v1.end()){     // if vector contains str[i]
                if(curlen > max)
                    max = curlen;
                // cout<<i<<" "<<curlen<<endl;
                it = find(v1.begin(), v1.end(), str[i]);
                int index = distance(v1.begin(), it);
                int count = 1;
                it1 = v1.begin(); 
                it2 = v1.begin(); 

                while(it2 != it){
                    it2++;
                    count++;
                }
                it2++;
                if(it1 == it2)
                    v1.erase(it1);
                else
                    v1.erase(it1,it2);
                v1.push_back(str[i]);
                curlen++;
                curlen = curlen - count;
            }
            else{
                v1.push_back(str[i]);
                curlen++;
                if(curlen > max)
                        max = curlen;  
            }                     
        }   
        cout<<max<<endl;
	}
	return 0;
}