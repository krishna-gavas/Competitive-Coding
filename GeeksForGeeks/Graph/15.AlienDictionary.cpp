// Alien Dictionary

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string order;

bool dfs(vector<bool> adj[],int vis[],string sb, int i){
    vis[i] = 1;
    for(int j=0;j<26;j++){
        if(adj[i][j]){
            if(vis[j] == 1)
                return false;
            if(vis[j] == 0){
                if(!dfs(adj,vis,sb,j))
                    return false;
            }
        }
    }
    vis[i] = 2;
    sb = sb + char(i + 'a');
    return true;
}

string findOrder(string str[], int N, int K) {
    vector<bool> adj[26];
    int vis[26] = {-1};

    // Build Graph
    for(int i=0;i<N;i++){
        for(int j=0;j<str[i].length();j++)
            vis[str[i][j]-'a'] = 0;

        if(i > 0){
            string w1 = str[i-1], w2 = str[i];
            int len = min(w1.length(), w2.length());
            for(int j=0;j<len;j++){
                char c1 = w1[j], c2 = w2[j];
                if(c1 != c2){
                    adj[c1-'a'][c2-'a'] = true;
                    break;
                }
            }
        }
    }
    string sb;
    for(int i=0;i<26;i++){
        if(vis[i] == 0){
            if(!dfs(adj,vis,sb,i))
                return "";
        }
    }
    reverse(sb.begin(), sb.end());
    return sb;
}

bool f(string a, string b){
    int p1=0,p2=0;
    for(int i=0;i < min(a.size(), b.size()) && p1 == p2;i++){
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }
    if(p1 == p2 && a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N>>K;
        string str[N];
        for(int i=0;i<N;i++)
            cin>>str[i];
        string ss = findOrder(str, N, K);
        order = "";

        for(int i=0;i<ss.size();i++)
            order = order + ss[i];

        string temp[N];
        copy(str,str+N,temp);
        sort(temp, temp+N, f);

        bool f = true;
        for(int i=0;i<N;i++)
            if(str[i] != temp[i])
                f = false;

        cout<<f<<endl;

    }
    return 0;
}