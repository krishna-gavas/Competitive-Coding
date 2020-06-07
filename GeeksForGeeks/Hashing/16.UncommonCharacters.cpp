// Uncommon characters

// Create a map mp2 to store common characters of both the strings.
// Now create another map to store the uncommon character from both strings which are not present in mp2.

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str1,str2;
        map<char, int> mp1,mp2,mp3;
        map<char, int> :: iterator it;
        cin>>str1>>str2;
        int len1 = str1.length(), len2 = str2.length(),flag = 0;
        for(int i=0;i<len1;i++)
            mp1.insert(make_pair(str1[i], 1));
        
        for(int i=0;i<len2;i++){
            if(mp1.find(str2[i]) != mp1.end())
                mp2.insert(make_pair(str2[i], 1));
            else   
                mp3.insert(make_pair(str2[i], 1));   
        }
        for(it = mp1.begin(); it != mp1.end(); it++){
            if(mp2.find(it->first) == mp2.end())
                mp3.insert(make_pair(it->first, 1));
        }

        if(!mp3.empty()){
            for(it = mp3.begin(); it != mp3.end(); it++)
                cout<<it->first;
            cout<<"\n";
        }
    }
    return 0;
}

