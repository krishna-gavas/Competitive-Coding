// Detect cycle in an undirected graph

// isCyclic(adj, V): Create a result vector to store bfs traversal, Create a queue and push first element to it.
//     create a flag array(-1 means not in queue, 0 means in queue and 1 means visited) of size V and initialize it to -1.
//     initialize flag[first element] = 0;
//     while(queue is not empty or all Nodes are not yet visited): pop front of q and store it to start, push start to result vector and make flag[start] = 1.
//         for(it = g[start].begin() to g[start].end()): if(flag[*it] == 0) return true
//             else if(flag[*it] == -1) then push *it to q and make flag[*it] = 0.
//     return false;

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool isCyclic(vector<int> g[], int V)
{
    vector<int> res;
    vector<int> :: iterator it;
    queue<int> q;
    int flag[V],count=0,start;
    for (int i = 0; i < V; i++) 
        flag[i] = -1;
    q.push(0);
    flag[0] = 0;
    while(!q.empty() || count < V){
        if(q.empty()){
            q.push(start+1);
        }
        start = q.front();
        res.push_back(start);
        flag[start] = 1;
        q.pop();
        count++;
        for(it = g[start].begin(); it != g[start].end(); it++){
            if(flag[*it] == 0)
                return true;
            else if(flag[*it] == -1){
                q.push(*it);
                flag[*it] = 0;
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        vector<int> adj[V];

        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout<<isCyclic(adj, V)<<endl;
    }
    return 0;
}

