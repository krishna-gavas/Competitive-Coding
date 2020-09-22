#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char,vector<pair<int,int> > > mp;
int vis[7][7];

bool checkWord(string str, char word[][7], int n, int m){
    vector<pair<int, int> > vec = mp[str[0]];
    vector<pair<int, int> > temp;
    int flag = 0;
    for(int k=0;k<vec.size();k++){
        int i1 = vec[k].first;
        int j1 = vec[k].second;
        int len = str.length();
        int p=1,i2,j2;
        memset(vis,0,sizeof(vis));
        vis[i1][j1] = 1;
        while(p < len){
            temp = mp[str[p]];
            flag = 0;
            for(int it=0;it<temp.size();it++){
                int i2 = temp[it].first;
                int j2 = temp[it].second;
                if(abs(i1-i2) <= 1 && abs(j1-j2) <=1 && !vis[i2][j2]){
                    vis[i2][j2] = 1;
                    i1 = i2;
                    j1 = j2;
                    flag = 1;
                }
                if(flag == 1)
                    break;
            }
            if(flag == 0)
                break;
            p++;
        }
    }
    if(flag == 1)
        return true;
    else 
        return false;
}

void wordBoggle(vector<string> dict, int x, char word[][7], int n, int m,vector<string> &res){
    for(int i=0;i<x;i++){
        string str = dict[i];
        if(checkWord(str,word,m,n))
            res.push_back(str);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x,N,M;
        cin>>x;
        string str;
        vector<string> dict,res;
        for(int i=0;i<x;i++){
            cin>>str;
            dict.push_back(str);
        }
        cin>>N>>M;
        char word[N][M];
        mp.clear();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>word[i][j];
                if(mp.find(word[i][j]) != mp.end()){
                    vector<pair<int, int> > vec = mp[word[i][j]];
                    vec.push_back({i,j});
                    mp[word[i][j]] = vec;
                }
                else{
                    mp[word[i][j]].push_back({i,j});
                }
            }
        }
        wordBoggle(dict,x,word,N,M,res);
        
    }
    return 0;
}