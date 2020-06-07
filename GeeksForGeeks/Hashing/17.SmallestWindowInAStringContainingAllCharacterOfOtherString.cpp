// Uncommon characters

// Create a map named need to store the characters of txt along with their count and initialize i,j,l,r with 0 and missing with len2.
// while(r < len1): if(need[str[r]] > 0) then decrement missing.
//     decrement value of need[str[r]] and increment r.
//     while( missing is 0): if(j==0 || (r-l) < (j-i)) then make i=l and j=r.
//         increment value of need[str[l]].
//         if(need[str[l]] > 0) then increment missing.
//         increment l.
// if(flag is 0) then print -1 else print substring of str1(from i to j).

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str,txt;
        map<char, int> need;
        cin>>str>>txt;
        int flag = 0;
        int len1 = str.length();
        int len2 = txt.length();
        for(int i=0;i<len2;i++){
            if(need.find(txt[i]) == need.end())
                need.insert(make_pair(txt[i], 1));
            else 
                need[txt[i]] = need[txt[i]] + 1;

        }
        int i=0,j=0,l=0,r=0,missing = len2;
        while(r < len1){
            if(need[str[r]] > 0){
                missing--;
            }
            need[str[r]] = need[str[r]] - 1;
            r++;
            while(missing == 0){
                flag = 1;
                if(j==0 || (r-l) < (j-i)){
                    i = l;
                    j = r;
                }
                need[str[l]] = need[str[l]] + 1;
                if(need[str[l]] > 0)
                    missing++;
                l++;
            }
        }
        if(flag == 0)
            cout<<-1<<endl;
        else
            cout<<str.substr(i,j-i)<<endl;
    }
    return 0;
}

