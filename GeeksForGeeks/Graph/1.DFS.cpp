// DFS of Graph

// dfs(g, N): Create a vector to store the result. Create a visited array and initialize it to false.
//     call myDFS(g,N,0,res,vis) and return the result vector

// myDFS(g,N,i,res,vis): make visited[i] = true, push i to result vector.
//     traverse the vector g[i] and if any of its adjacent nodes are unvisited then call myDFS(g,N,*it,res,vis).

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void myDFS(vector<int> g[], int N, int i,vector<int> &res,bool vis[]){
    vis[i] = true;
    res.push_back(i);
    vector<int> :: iterator it;
    for(it = g[i].begin(); it != g[i].end(); it++){
        if(!vis[*it]){
            myDFS(g,N,*it,res,vis);
        }
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    vector<int> res;
    bool *vis = new bool[N];
    // memset(vis, false, sizeof(vis));
    for (int i = 0; i < N; i++) 
        vis[i] = false;
    myDFS(g,N,0,res,vis);
    return res;
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,E;
        cin>>N>>E;
        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> res = dfs(g, N);
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}

