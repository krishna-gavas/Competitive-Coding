// Minimum indexed character

// Create a map to store all characters of patt.
// traverse every character of str and check if it is present in map if yes then print that character and break out of the loop.

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str,patt;
        map<char, int> mp;
        cin>>str>>patt;
        int len1 = str.length(), len2 = patt.length(),flag = 0;
        for(int i=0;i<len2;i++)
            mp.insert(make_pair(patt[i], 1));
        
        for(int i=0;i<len1;i++){
            if(mp.find(str[i]) != mp.end()){
                cout<<str[i]<<"\n";
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout<<"$\n";
    }
    return 0;
}

