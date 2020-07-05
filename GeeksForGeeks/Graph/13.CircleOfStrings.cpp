// Circle of strings


#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,len,flag=0,flag1=0;
        cin>>N;
        set<char> s1,s2;
        vector<char> v;
        string str[N];
        for(int i=0;i<N;i++){
            cin>>str[i];
            len = str[i].length();
            if(len == 1)
                flag++;
            if(str[i][0] != str[i][len-1]){
                s1.insert(str[i][0]);
                s2.insert(str[i][len-1]);
            }
            else{
                flag1=1;
                v.push_back(str[i][0]);
            }
        }
        if(N==1 && flag1 == 1)
            cout<<1<<endl;
        else if((s1.empty() && s2.empty()) || s1 == s2 ){
            int flag2=0;
            if(s1.empty()){

            }
            else{
                for(int i=0;i<v.size();i++){
                    if(s1.find(v[i]) == s1.end()){
                        flag2 = 1;
                        break;
                    }
                }
                if(flag2 == 0)
                    cout<<1<<endl;
                else 
                    cout<<0<<endl;
            }
        }
        else 
            cout<<0<<endl;
    }
    return 0;
}