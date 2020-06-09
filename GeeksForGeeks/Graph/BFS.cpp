// BFS of Graph

// bfs(g, N): Create a queue and push first node to it and make visited[first node] = true.
//     while(queue is not empty): pop front of queue and store it in start, push start to result vector.
//         for(i=0 to size of g[start]): 
//             if(vis[g[start][i]] is false) then male vis[g[start][i]] = true and push g[start][i] to queue.
//     return result vector.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


vector <int> bfs(vector<int> g[], int N)
{
    vector<int> res;
    queue<int> q;
    bool *vis = new bool[N];
    memset(vis, false, N);
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        int start = q.front();
        res.push_back(start);
        q.pop();
        for(int i=0; i <g[start].size();i++){
            if(!vis[g[start][i]]){
                vis[g[start][i]] = true;
                q.push(g[start][i]);
            }
        }
    }
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

        vector<int> res = bfs(g, N);
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}

