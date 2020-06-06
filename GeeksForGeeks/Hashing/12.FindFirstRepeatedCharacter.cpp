// Find first repeated character

// traverse every character of string str and check if that character is present in map if yes then print that character 
// else if either map is empty or character is not present then insert it into map.

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        map<char, int> mp;
        cin>>str;
        int len = str.length(), flag = 0;
        for(int i=0;i<len;i++){
            if(mp.empty() || (mp.find(str[i]) == mp.end()))
                mp.insert(make_pair(str[i], 1));
            else{
                cout<<str[i]<<"\n";
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout<<-1<<"\n";
    }
    return 0;
}

