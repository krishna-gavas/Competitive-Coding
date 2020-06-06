// Big Data

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string s1,s2;
        cin>>s1;
        int len = s1.length();
        int count = 1,intcount=0,charcount=0,len1,len2,count1 = 0, count2=0,out;
        for(int i=0;i<len;i++){
            if(s1[i] == s1[i+1] && i != (len - 1)){
                count++;
                continue;
            }
            else{
                s2.append(s1[i] + to_string(count));
                if(s1[i] >= '0' && s1[i] <= '9'){
                    intcount++;
                    count1 += count;
                }
                if(s1[i] >= 'a' && s1[i] <= 'z'){
                    charcount++;
                    count2 += count;
                }
                count = 1;
            }
        }
        len1 = (count1 * 32) + (count2 * 8);
        len2 = (intcount * 64) + (charcount * 40);
        out = len1 - len2;
        cout<<out<<"\n";
	}
	return 0;
}